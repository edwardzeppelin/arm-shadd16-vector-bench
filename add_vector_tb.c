#include "dsp-lecture.h"
#include <stdio.h>

void
random_vector(int_fast16_t n, int16_t * v)
{
  uint_fast16_t i;
  for(i=0; i<n; i++)
    v[i] = mrand48();
}

void
add_vector_tb_q15(long int seed, unsigned runs)
{
  unsigned run;
  uint_fast16_t i, n;

  int16_t * dst = NULL;
  int16_t * dst_ref = NULL;
  int16_t * src1 = NULL;
  int16_t * src2 = NULL;

  srand48(seed);

  for (run=0; run<runs; run++) {
    n = lrand48() % N_MAX;
    dst = (int16_t *) realloc (dst, n*sizeof(int16_t));
    dst_ref = (int16_t *) realloc (dst_ref, n*sizeof(int16_t));
    src1 = (int16_t *) realloc (src1, n*sizeof(int16_t));
    src2 = (int16_t *) realloc (src2, n*sizeof(int16_t));

    random_vector (n, src1);
    random_vector (n, src2);

    clock_t refstart = clock();
    add_vector_ref_q15(n, dst_ref, src1, src2);
    clock_t reffinish = clock();

    clock_t ref = reffinish - refstart;
    printf("Ref: %ld \n", (long)ref);

    clock_t faststart = clock();
    add_vector_fast_q15(n, dst, src1, src2);
    clock_t fastfinish = clock();

    clock_t fast = fastfinish - faststart;
    printf("Fast: %ld \n", (long)fast);

    for (i=0; i<n; i++)
      if (dst[i] != dst_ref[i]) {
	fprintf (stderr, "Error: dst[%d] ref=0x%4.4x res=0x%4.4x\n",
		 i, dst_ref[i], dst[i]);
	exit(1);
      }
  }

  free (dst);
  free (src1);
  free (src2);
}

int
main()
{
  add_vector_tb_q15(4711, 100);
  printf("Success");
  return 0;
}
