### README for SIMD and Non-SIMD Convolution Calculation

This project demonstrates the use of SIMD (Single Instruction, Multiple Data) instructions for optimizing convolution calculations between two matrices of floating-point numbers. The project contains three main C programs: `init.c`, `simd.c`, and `simd_t.c`, each showcasing different methods of computation with varying levels of optimization.

#### Program Overview

1. **`init.c` (Baseline Convolution Calculation)**:
   - Implements a basic non-SIMD convolution operation between two 400x198 matrices stored in a file (`data.txt`).
   - The result is stored in a 1D array `ans[200]`.
   - The program measures and prints the elapsed computation time.
   - Outputs the result to `output.txt`.

2. **`simd.c` (SIMD Convolution without Timing)**:
   - Utilizes SIMD instructions (`_mm_mul_ps` and `_mm_add_ps`) to perform vectorized convolution calculations.
   - The arrays are aligned using `__attribute__((aligned(16)))` to ensure proper memory alignment for SIMD operations.
   - The computation uses SIMD to speed up the operations by processing 4 floating-point values simultaneously.
   - This version does not include time measurement.
   - Outputs the result to `output_simd_without_time.txt`.

3. **`simd_t.c` (SIMD Convolution with Timing)**:
   - Similar to `simd.c` but includes time measurement using `clock_gettime()`.
   - Measures the time taken to perform the convolution with SIMD instructions.
   - Outputs the computation time and the result to `output_simd.txt`.

#### File Descriptions

- **`data.txt`**: Input file containing the floating-point numbers that will be processed. The file is expected to have 400 rows and 198 columns of float data.
  
- **`output.txt`**: Output file from `init.c` containing the convolution results without SIMD optimization.

- **`output_simd_without_time.txt`**: Output file from `simd.c` containing the results of the SIMD optimized convolution without time measurement.

- **`output_simd.txt`**: Output file from `simd_t.c` containing the SIMD optimized convolution results and the elapsed time for the computation.

#### Compilation and Execution

- **Compiling**: You can compile the programs using the provided `Makefile`. It generates three executable files: `init.exe`, `simd.exe`, and `simd_t.exe`.

    ```bash
    make all
    ```

- **Running the programs**: After compilation, run each program using the following commands:

    ```bash
    ./init.exe   # Runs the basic (non-SIMD) convolution
    ./simd.exe   # Runs the SIMD optimized convolution (without timing)
    ./simd_t.exe # Runs the SIMD optimized convolution with timing
    ```

- **Cleaning**: To remove the compiled executables, run:

    ```bash
    make clean
    ```

#### Performance Comparison
- **`init.c`**: Baseline implementation using standard loops for convolution.
- **`simd.c` and `simd_t.c`**: Use SIMD instructions for improved performance, with `simd_t.c` additionally measuring the elapsed time.

#### Dependencies

- **GCC**: Ensure you have GCC installed with support for SSE (SIMD) instructions.
- **C Standard Library**: The programs rely on standard libraries (`stdio.h`, `stdlib.h`, `string.h`, `time.h`) and SIMD-specific headers (`xmmintrin.h`).

#### Notes

- The `data.txt` file must be formatted with floating-point numbers and properly structured to fit the 400x198 matrix size.
- Ensure that the system supports SIMD (SSE) instructions for `simd.c` and `simd_t.c` to execute correctly.

#### Future Improvements & Result

- Expand the program to support larger matrices.
- Explore AVX or AVX-512 instructions for further optimization.
- Compare SIMD performance across different platforms.
- NonSIMD version: Elapsed time: 0.025616 seconds
- SIMD version: Elapsed time: 0.011092 seconds
