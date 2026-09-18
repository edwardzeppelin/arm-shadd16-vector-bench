# ARM Halving Vector Addition & Benchmark

Performance benchmark and verification framework for 16-bit signed halving vector addition (pairwise averaging), comparing scalar C reference logic against ARM ACLE `__shadd16` SIMD intrinsics.

## Key Features
* **Halving Addition (`(a + b) >> 1`)**: Computes the pairwise arithmetic average of vector elements without 16-bit overflow risk.
* **ARM ACLE Optimization**: Utilizes `__shadd16` packed SIMD instructions to process two 16-bit elements simultaneously.
* **Performance Benchmarking**: Measures CPU clock cycles (`clock()`) to compare execution time between Reference and SIMD implementations.
* **Assembly Analysis**: Configured with `-save-temps` in the Makefile to generate `.s` assembly files for compiler output inspection.

## Structure
* `add_vector_fast.c` — SIMD implementation using ARM `int16x2_t` and `__shadd16`.
* `add_vector_ref.c` — Scalar reference implementation executing `(src1[i] + src2[i]) >> 1`.
* `add_vector_tb.c` — Testbench with randomized vector inputs and runtime performance measurement.
* `add_vector.c` — Verification wrapper comparing output arrays element-by-element.
* `dsp-lecture.h` — Header file containing function prototypes and ARM SIMD includes.

## Build & Run

```bash
make
make test
```
