#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024 

int main() {
    float *A, *B, *C;
    int i, j, k;
    double time_spent;


    A = (float*) malloc(N * N * sizeof(float));
    B = (float*) malloc(N * N * sizeof(float));
    C = (float*) malloc(N * N * sizeof(float));


    for (i = 0; i < N * N; i++) {
        A[i] = 0.01f * i;
        B[i] = 0.02f * i;
    }


    clock_t start = clock();


    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            float sum = 0.0;
            for (k = 0; k < N; k++) {
                sum += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }


    clock_t end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;


    printf("Elapsed time: %.3f seconds\n", time_spent);


    free(A);
    free(B);
    free(C);

    return 0;
}
