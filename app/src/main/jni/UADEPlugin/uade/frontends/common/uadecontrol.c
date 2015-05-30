/* uadecontrol.c is a helper module to control uade core through IPC:

   Copyright (C) 2005 Heikki Orsila <heikki.orsila@iki.fi>

   This source code module is dual licensed under GPL and Public Domain.
   Hence you may use _this_ module (not another code module) in any way you
   want in your projects.
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <android/log.h>

#include <uade/uadecontrol.h>
#include <uade/uadeconstants.h>
#include <uade/songdb.h>
#include <uade/ossupport.h>
#include <uade/sysincludes.h>


static void subsong_control(int subsong, int command, struct uade_ipc *ipc);

void uade_change_subsong(struct uade_state *state)
{
    state->song->silence_count = 0;


    uade_lookup_volume_normalisation(state);


    subsong_control(state->song->cur_subsong, UADE_COMMAND_CHANGE_SUBSONG, &state->ipc);
}

int uade_read_request(struct uade_ipc *ipc)
{
    uint32_t left = UADE_MAX_MESSAGE_SIZE - sizeof(struct uade_msg);
    if (uade_send_u32(UADE_COMMAND_READ, left, ipc)) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "\ncannot send read command\n");
        return 0;
    }
    return left;
}

static int send_ep_options(struct uade_ep_options *eo, struct uade_ipc *ipc)
{
    if (eo->s > 0) {
        size_t i = 0;
        while (i < eo->s) {
            char *s = &eo->o[i];
            size_t l = strlen(s) + 1;
            assert((i + l) <= eo->s);
            if (uade_send_string
                (UADE_COMMAND_SET_PLAYER_OPTION, s, ipc)) {
                __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot send eagleplayer option.\n");
                return -1;
            }
            i += l;
        }
    }
    return 0;
}

void uade_send_filter_command(struct uade_state *state)
{
    struct uade_config *uadeconf = &state->config;
    struct uade_ipc *ipc = &state->ipc;

    int filter_type = uadeconf->filter_type;
    int filter_state = uadeconf->led_state;
    int force_filter = uadeconf->led_forced;

    if (uadeconf->no_filter)
        filter_type = 0;

    /* Note that filter state is not normally forced */
    filter_state = force_filter ? (2 + (filter_state & 1)) : 0;

    if (uade_send_two_u32s
        (UADE_COMMAND_FILTER, filter_type, filter_state, ipc)) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot setup filters.\n");
        exit(1);
    }
}

static void send_resampling_command(struct uade_ipc *ipc,
                    struct uade_config *uadeconf)
{
    const char *mode = uadeconf->resampler;
    if (mode != NULL) {
        if (strlen(mode) == 0) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Resampling mode may not be empty.\n");
            exit(1);
        }
        if (uade_send_string
            (UADE_COMMAND_SET_RESAMPLING_MODE, mode, ipc)) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot set resampling mode.\n");
            exit(1);
        }
    }
}

static void subsong_control(int subsong, int command, struct uade_ipc *ipc)
{
    assert(subsong >= 0 && subsong < 256);
    if (uade_send_u32(command, (uint32_t) subsong, ipc) < 0) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Could not change subsong\n");
        exit(1);
    }
}

void uade_set_subsong(int subsong, struct uade_ipc *ipc)
{
    subsong_control(subsong, UADE_COMMAND_SET_SUBSONG, ipc);
}

int uade_song_initialization(const char *scorename,
                 const char *playername,
                 const char *modulename,
                 struct uade_state *state)
{
    uint8_t space[UADE_MAX_MESSAGE_SIZE];
    struct uade_msg *um = (struct uade_msg *)space;
    struct uade_ipc *ipc = &state->ipc;
    struct uade_config *uc = &state->config;
    struct uade_song *us = state->song;

    if (uade_send_string(UADE_COMMAND_SCORE, scorename, ipc)) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot send score name.\n");
        goto cleanup;
    }

    if (uade_send_string(UADE_COMMAND_PLAYER, playername, ipc)) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot send player name.\n");
        goto cleanup;
    }

    if (uade_send_string(UADE_COMMAND_MODULE, modulename, ipc)) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot send module name.\n");
        goto cleanup;
    }

    if (uade_send_short_message(UADE_COMMAND_TOKEN, ipc)) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot send token after module.\n");
        goto cleanup;
    }

    if (uade_receive_message(um, sizeof(space), ipc) <= 0) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot receive acknowledgement.\n");
        goto cleanup;
    }

    if (um->msgtype == UADE_REPLY_CANT_PLAY) {
        if (uade_receive_short_message(UADE_COMMAND_TOKEN, ipc)) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE",
                "Can not receive token in main loop.\n");
            exit(1);
        }
        return UADECORE_CANT_PLAY;
    }

    if (um->msgtype != UADE_REPLY_CAN_PLAY) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Unexpected reply from uade: %u\n",
            (unsigned int)um->msgtype);
        goto cleanup;
    }

    if (uade_receive_short_message(UADE_COMMAND_TOKEN, ipc) < 0) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot receive token after play ack.\n");
        goto cleanup;
    }

    if (uc->ignore_player_check) {
        if (uade_send_short_message(UADE_COMMAND_IGNORE_CHECK, ipc) < 0) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot send ignore check message.\n");
            goto cleanup;
        }
    }

    if (uc->no_ep_end) {
        if (uade_send_short_message
            (UADE_COMMAND_SONG_END_NOT_POSSIBLE, ipc) < 0) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot send 'song end not possible'.\n");
            goto cleanup;
        }
    }

    uade_send_filter_command(state);

    send_resampling_command(ipc, uc);

    if (uc->speed_hack) {
        if (uade_send_short_message(UADE_COMMAND_SPEED_HACK, ipc)) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot send speed hack command.\n");
            goto cleanup;
        }
    }

    if (uc->use_ntsc) {
        if (uade_send_short_message(UADE_COMMAND_SET_NTSC, ipc)) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot send ntsc command.\n");
            goto cleanup;
        }
    }

    if (uc->frequency != UADE_DEFAULT_FREQUENCY) {
        if (uade_send_u32
            (UADE_COMMAND_SET_FREQUENCY, uc->frequency, ipc)) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot send frequency.\n");
            goto cleanup;
        }
    }

    if (uc->use_text_scope) {
        if (uade_send_short_message(UADE_COMMAND_USE_TEXT_SCOPE, ipc)) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE",	"Cannot send use text scope command.\n");
            goto cleanup;
        }
    }

    if (send_ep_options(&us->ep_options, ipc) ||
        send_ep_options(&uc->ep_options, ipc))
        goto cleanup;

    return 0;

      cleanup:
    return UADECORE_INIT_ERROR;
}

/*
void uade_spawn(struct uade_state *state, const char *uadename,
        const char *configname)
{
    uade_arch_spawn(&state->ipc, &state->pid, uadename);

    if (uade_send_string(UADE_COMMAND_CONFIG, configname, &state->ipc)) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Can not send config name: %s\n",
            strerror(errno));
        kill(state->pid, SIGTERM);
        state->pid = 0;
        abort();
    }
}
*/
