#include <stdint.h>
#include "com_ssb_droidsound_utils_FFT.h"
#include "fixedfft.h"

#define MAX_FFT_SIZE 4096

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

        /* Convert 16-bit stereo to real-valued mono input packing 2 values per int32 */
        for (int32_t i = 0; i < fftLen; i += 1) {
             int32_t mono1 = in[(i << 2) + 0] + in[(i << 2) + 1] >> 1;
             int32_t mono2 = in[(i << 2) + 2] + in[(i << 2) + 3] >> 1;
             tmp[i] = (mono1 << 16) | (mono2 & 0xffff);
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
