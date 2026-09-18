#ifndef DSP_LECTURE_H
#define DSP_LECTURE_H

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <arm_acle.h>
#include <arm_neon.h>
#include <time.h>

#define N_MAX 65535

typedef struct { int16_t real,imag; } cint16_t;
typedef struct { int32_t real,imag; } cint32_t;

void add_vector_q15 (int_fast16_t n, int16_t *dst, int16_t * src1, int16_t * src2);
void add_vector_ref_q15 (int_fast16_t n, int16_t *dst, int16_t * src1, int16_t * src2);
void add_vector_fast_q15 (int_fast16_t n, int16_t *dst, int16_t * src1, int16_t * src2);

#endif /* DSP_LECTURE_H */
