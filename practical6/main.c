#include <stdio.h>
#include "matmult.h"

#define N 5
#define P 3
#define Q 4

int main() {
    double A[N][P], B[P][Q], C[N][Q] = {0};

     for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            A[i][j] = i + j;
        }
    }

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < Q; j++) {
            B[i][j] = i - j;
        }
    }
    matmult(N, P, Q, A, B, C);
    printf("Matrix A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            printf("%6.2f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix B:\n");
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < Q; j++) {
            printf("%6.2f ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            printf("%6.2f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
