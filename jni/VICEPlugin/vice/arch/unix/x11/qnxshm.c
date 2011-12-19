/* qnxshm.c
 *
 * System V Shared Memory Emulation for QNX
 *
 */

#if defined(__QNX__) && !defined(__QNXNTO__)

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#include "qnxshm.h"

int shmget(key_t key, size_t size, int flags)
{
    return -1;
}

void *shmat(int shmid, const void *shmaddr, int shmflg)
{
}

int shmctl(int shmid, int cmd, struct shmid_ds * buf)
{
    return -1;
}

int shmdt(const void *addr)
{
    return -1;
}
#endif

#ifdef __QNXNTO__

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include "qnxshm.h"
#include <sys/stat.h>
#include <limits.h>

#define MODE 0777

#define SHMMAX 1024

struct shm_info {
    int shmid;
    key_t key;
    size_t size;
    void *addr;
};

static struct shm_info *ShmInfo;

static int shm_putinfo(struct shm_info * info);
static int shm_updinfo(int i, struct shm_info * info);
static int shm_getinfo(int shmid, struct shm_info * info);
static int shm_getinfobyaddr(const void *addr, struct shm_info * info);

static char *keytoname(key_t key, char *name)
{
    sprintf(name, "PgShm%x", key);
    return name;
}

static int shm_putinfo(struct shm_info * info)
{
    int i;

    if (ShmInfo == NULL) {
        ShmInfo = calloc(SHMMAX, sizeof(struct shm_info));
        if (ShmInfo == NULL) {
            return -1;
        }
        for (i = 0; i < SHMMAX; i++) {
            ShmInfo[i].shmid = -1;
        }
    }
    i = 0;
    while (i < SHMMAX && ShmInfo[i].shmid != -1) {
        i++;
    }
    if (i >= SHMMAX) {
        errno = ENOSPC;
        return -1;
    }
    memcpy(&ShmInfo[i], info, sizeof(struct shm_info));
    return i;
}

static int shm_updinfo(int i, struct shm_info * info)
{
    if (i >= SHMMAX) {
        return -1;
    }
    if (ShmInfo == NULL) {
        return -1;
    }
    memcpy(&ShmInfo[i], info, sizeof(struct shm_info));
    return i;
}

static int shm_getinfo(int shmid, struct shm_info * info)
{
    int i;

    if (ShmInfo == NULL) {
        return -1;
    }
    i = 0;
    while (i < SHMMAX && ShmInfo[i].shmid != shmid) {
        i++;
    }
    if (i >= SHMMAX) {
        return -1;
    }
    memcpy(info, &ShmInfo[i], sizeof(struct shm_info));
    return i;
}

static int shm_getinfobyaddr(const void *addr, struct shm_info * info)
{
    int i;

    if (ShmInfo == (struct shm_info *)-1) {
        return -1;
    }
    i = 0;
    while (i < SHMMAX && ShmInfo[i].addr != addr) {
        i++;
    }
    if (i >= SHMMAX) {
        return -1;
    }
    memcpy(info, &ShmInfo[i], sizeof(struct shm_info));
    return i;
}

void *shmat(int shmid, const void *shmaddr, int shmflg)
{
    struct shm_info info;
    int i;

    i = shm_getinfo(shmid, &info);
    if (i == -1) {
        errno = EACCES;
        return (void *)-1;
    }
    info.addr = mmap((void *)shmaddr, info.size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (info.addr == MAP_FAILED) {
        return info.addr;
    }
    if (shm_updinfo(i, &info) == -1) {
        errno = EACCES;
        return (void *)-1;
    }
    return info.addr;
}

int shmdt(const void *addr)
{
    struct shm_info info;

    if (shm_getinfobyaddr(addr, &info) == -1) {
        errno = EACCES;
        return -1;
    }
    return munmap((void *)addr, info.size);
}

int shmctl(int shmid, int cmd, struct shmid_ds * buf)
{
    struct shm_info info;
    char name[NAME_MAX + 1];
    int result;
    int fd;
    struct stat statbuf;

    switch (cmd) {
        case IPC_RMID:
            if (shm_getinfo(shmid, &info) == -1) {
                errno = EACCES;
                return -1;
            }
            close(info.shmid);
            keytoname(info.key, name);
            return shm_unlink(name);
        case IPC_STAT:
            keytoname(shmid, name);
            fd = shm_open(name, 0, MODE);
            if (fd >= 0) {
                result = fstat(fd, &statbuf);
                if (!result) {
                    buf->shm_nattch = statbuf.st_nlink - 2;
                }
                close(fd);
                return result;
            } else {
                buf->shm_nattch = 0;
                return 0;
            }
    }
    errno = EINVAL;
    return -1;
}

int shmget(key_t key, size_t size, int flags)
{
    char name[NAME_MAX + 1];
    int oflag = 0;
    struct shm_info info;

    if (flags & IPC_CREAT) {
        oflag |= O_CREAT;
    }
    if (flags & IPC_EXCL) {
        oflag |= O_EXCL;
    }
    if (flags & SHM_R) {
        if (flags & SHM_W) {
            oflag |= O_RDWR;
        } else {
            oflag |= O_RDONLY;
        }
    }
    info.shmid = shm_open(keytoname(key, name), oflag, MODE);
    if (info.shmid != -1) {
        info.key = key;
        info.size = size;
        info.addr = NULL;
        if (shm_putinfo(&info) == -1) {
            close(info.shmid);
            if ((oflag & (O_CREAT | O_EXCL)) == (O_CREAT | O_EXCL)) {
                shm_unlink(name);
            }
            return -1;
        }
    }
    ltrunc(info.shmid, size, SEEK_SET);
    return info.shmid;
}
#endif
