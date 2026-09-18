#include "dsp-lecture.h"
#include <limits.h> 

void
add_vector_ref_q15(int_fast16_t n, int16_t* dst, int16_t* src1, int16_t* src2)
{
    int_fast16_t i;
    for (i = 0; i < n; i++)
    {
        int32_t result32 = (int32_t)src1[i] + (int32_t)src2[i];
		
		result32 = result32 >> 1;

        if (result32 > INT16_MAX)
        {
            dst[i] = INT16_MAX; // 32767
        }
        else if (result32 < INT16_MIN)
        {
            dst[i] = INT16_MIN;
        }
        else
        {
            dst[i] = (int16_t)result32;
        }
    }
}