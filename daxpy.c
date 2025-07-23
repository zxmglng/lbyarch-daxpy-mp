#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void asm_daxpy(int n, double a, double* x, double* y, double* z);

void c_daxpy(int n, double a, double* x, double* y, double* z) 
{
    for (int i = 0; i < n; i++) {
        z[i] = a * x[i] + y[i];
    }
}

int main() 
{
    int n = 1 << 20;  // You can change to 1<<24 or 1<<28
    double a = 2.0;
    double *x = malloc(n * sizeof(double));
    double *y = malloc(n * sizeof(double));
    double *z_c = malloc(n * sizeof(double));
    double *z_asm = malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) 
    {
        x[i] = i * 0.1;
        y[i] = i * 0.2;
    }

    // Time C
    clock_t start_c = clock();
    for (int i = 0; i < 30; i++) c_daxpy(n, a, x, y, z_c);
    clock_t end_c = clock();
    double time_c = (double)(end_c - start_c) / CLOCKS_PER_SEC / 30.0;

    // Time ASM
    clock_t start_asm = clock();
    for (int i = 0; i < 30; i++) asm_daxpy(n, a, x, y, z_asm);
    clock_t end_asm = clock();
    double time_asm = (double)(end_asm - start_asm) / CLOCKS_PER_SEC / 30.0;

    // Correctness check
    int correct = 1;
    for (int i = 0; i < n; i++) {
        if (fabs(z_c[i] - z_asm[i]) > 1e-9) {
            correct = 0;
            printf("Mismatch at index %d: C=%f ASM=%f\n", i, z_c[i], z_asm[i]);
            break;
        }
    }

    // Output summary
    printf("C time:   %.6f s\n", time_c);
    printf("ASM time: %.6f s\n", time_asm);
    printf("Correctness: %s\n", correct ? "PASS" : "FAIL");

    printf("First 10 z values (ASM):\n");
  
    for (int i = 0; i < 10; i++) 
    {
        printf("z[%d] = %f\n", i, z_asm[i]);
    }

    free(x);
    free(y);
    free(z_c);
    free(z_asm);
    return 0;
}
