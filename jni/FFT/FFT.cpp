#include <stdint.h>
#include "com_ssb_droidsound_utils_FFT.h"
#include "fixedfft.h"

JNIEXPORT void JNICALL Java_com_ssb_droidsound_utils_FFT_fft(JNIEnv *env, jclass klass, jshortArray jin, jshortArray jout)
{
        int32_t tmp[MAX_FFT_SIZE];

        int32_t fftLen = env->GetArrayLength(jin);
        fftLen >>= 2;
        if (fftLen < 0 || fftLen > MAX_FFT_SIZE) {
            return;
        }
        
        if (fftLen != env->GetArrayLength(jout)) {
           return;
        }


        jshort* in = (jshort *) env->GetPrimitiveArrayCritical(jin, NULL);
        if (in == NULL) {
            return;
        }

        int scale = LOG_FFT_SIZE;
        for (int32_t i = 1; i <= fftLen >> 1; i <<= 1, --scale);

        /* Convert 16-bit stereo to real-valued mono input packing 2 values per int32 */
        for (int32_t i = 0; i < fftLen >> 1; i += 1) {
            /* head sample */
            int32_t mh1 = in[(i << 2) + 0] + in[(i << 2) + 1] >> 1;
            int32_t mh2 = in[(i << 2) + 2] + in[(i << 2) + 3] >> 1;
            /* tail sample */
            int32_t j = fftLen - 1 - i;
            int32_t mt1 = in[(j << 2) + 0] + in[(j << 2) + 1] >> 1;
            int32_t mt2 = in[(j << 2) + 2] + in[(j << 2) + 3] >> 1;

            /* Get window function index, half of the table. */
            int32_t widx = i != 0 ? i : 1;
            int32_t w = MAX_FFT_SIZE / 4 - (widx << scale);
            int32_t ws = w >> 31;
            /* The combination of (w ^ x) - w reads the table in reverse
             * until element 0, then forwards. Resulting curve is -cos(). */
            int32_t cos = int16_t((twiddle[(w ^ ws) - ws] ^ ws) >> 16);
            /* Hamming window: 0.54 - 0.46 * cos() */
            int32_t win = 0x8a3d + ((0x75c3 * cos) >> 15);
            tmp[i] = ((mh1 * win) & 0xffff0000) | (((mh2 * win) >> 16) & 0xffff);
            tmp[j] = ((mt1 * win) & 0xffff0000) | (((mt2 * win) >> 16) & 0xffff);
        }
        env->ReleasePrimitiveArrayCritical(jin, in, 0);

        /* Calculate the FFT of the (real, real)FFT of the formatted FFT data. */
        fixed_fft_real(fftLen, tmp);

        /* Write back to input array as real, imag pairs. */
        jshort* out = (jshort *) env->GetPrimitiveArrayCritical(jout, NULL);
        if (out == NULL) {
            return;
        }
        /* We write only half of the FFT, because of the redundancy of the second half. */
        for (int32_t i = 0; i < fftLen >> 1; i += 1) {
             int32_t v = tmp[i];
             out[i << 1] = v >> 16;
             out[(i << 1) + 1] = v;
        }
        env->ReleasePrimitiveArrayCritical(jout, out, 0);
}
