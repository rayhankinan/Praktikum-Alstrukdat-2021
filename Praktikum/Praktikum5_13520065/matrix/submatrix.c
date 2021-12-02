/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 23 September 2021
Topik Praktikum     : ADT Matrix
Deskripsi           : Driver ADT Matrix untuk mencari maksimal jumlah elemen pada submatrixnya
*/

#include <stdio.h>
#include "matrix.h"

int countIdxSubMatrix(int N, int M) {
    /* KAMUS */

    /* ALGORITMA */
    return (N - M + 1);
}

ElType sumSubMatrix(Matrix A, int M, Index idxRow, Index idxCol) {
    /* KAMUS */
    ElType sum;
    Index i, j;

    /* ALGORITMA */
    sum = 0;

    for (i = idxRow; i < idxRow + (Index) M; i++) {
        for (j = idxCol; j < idxCol + (Index) M; j++) {
            sum += ELMT(A, i, j);
        }
    }

    return sum;
}

int main() {
    /* KAMUS */
    int TC, N, M;
    Matrix KomplekPerumahan;
    Index i, j;
    ElType max;

    /* ALGORITMA */
    scanf("%d", &TC);

    while (TC > 0) {
        scanf("%d", &N);
        readMatrix(&KomplekPerumahan, N, N);
        scanf("%d", &M);

        max = 0;

        for (i = 0; i < (Index) countIdxSubMatrix(N, M); i++) {
            for (j = 0; j < (Index) countIdxSubMatrix(N, M); j++) {
                if (sumSubMatrix(KomplekPerumahan, M, i, j) > max) {
                    max = sumSubMatrix(KomplekPerumahan, M, i, j);
                }
            }
        }

        printf("%d\n", max);
        
        TC--;
    }
}