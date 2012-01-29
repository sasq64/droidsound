#pragma once

#include <stdint.h>

#define LOG_FFT_SIZE 12
#define MAX_FFT_SIZE (1 << LOG_FFT_SIZE)

extern const int32_t twiddle[MAX_FFT_SIZE / 4];

void fixed_fft_real(int n, int32_t *v);
