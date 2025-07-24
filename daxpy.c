#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

extern void asm_daxpy(int n, double* X, double* Y, double* Z, double A);

void c_daxpy(int n, double* X, double* Y, double* Z, double A) 
{
    for (int i = 0; i < n; i++) 
	{
        Z[i] = A * X[i] + Y[i];
    }
}

double rand_double(double min, double max) 
{
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

double benchmark(void (*kernel)(int, double*, double*, double*, double), int n, double* X, double* Y, double* Z, double A, int runs) 
{
    clock_t total = 0;
    for (int i = 0; i < runs; i++) 
	{
        clock_t start = clock();
        kernel(n, X, Y, Z, A);
        clock_t end = clock();
        total += (end - start);
    }
    return (double)total / runs / CLOCKS_PER_SEC;
}

int main() 
{
    int sizes[] = {1 << 20, 1 << 24, 1 << 28}; 
    int runs = 30;
    double A = rand_double(-10.0, 10.0);  

    for (int s = 0; s < 3; s++) 
	{
        int n = sizes[s];
        printf("\n=== DAXPY: n = 2^%d (%d elements) ===\n", (int)log2(n), n);
        printf("Scalar variable A = %.2f\n\n", A);

        double* X = (double*)malloc(sizeof(double) * n);
        double* Y = (double*)malloc(sizeof(double) * n);
        double* Z_C = (double*)malloc(sizeof(double) * n);
        double* Z_ASM = (double*)malloc(sizeof(double) * n);

        srand((unsigned int)time(NULL));
        for (int i = 0; i < n; i++) 
		{
            X[i] = rand_double(-100.0, 100.0);
            Y[i] = rand_double(-100.0, 100.0);
        }

        double time_c = benchmark(c_daxpy, n, X, Y, Z_C, A, runs);
        double time_asm = benchmark(asm_daxpy, n, X, Y, Z_ASM, A, runs);

        printf("  INDEX     X[i]      Y[i]      Z_C[i]     Z_ASM[i]\n");
        printf("----------------------------------------------------\n");
        for (int i = 0; i < 10 && i < n; i++) {
            printf("  %3d  %9.2f  %9.2f  %9.2f  %9.2f\n",
                   i, X[i], Y[i], Z_C[i], Z_ASM[i]);
        }

        int correct = 1;
        for (int i = 0; i < n; i++) 
		{
            if (fabs(Z_C[i] - Z_ASM[i]) > 1e-9) 
			{
                printf("\nMismatch at index %d: Z_C=%.2f Z_ASM=%.2f\n", i, Z_C[i], Z_ASM[i]);
                correct = 0;
                break;
            }
        }

        printf("\nC version average time:   %.6f s\n", time_c);
        printf("ASM version average time: %.6f s\n", time_asm);

        if (correct)
            printf("Correctness check: PASS\n");
        else
            printf("Correctness check: FAIL\n");

        free(X); free(Y); free(Z_C); free(Z_ASM);
    }

    return 0;
}
