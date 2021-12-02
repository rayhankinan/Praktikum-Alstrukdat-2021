/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 9 September 2021
Topik Praktikum     : ADT List
Deskripsi           : Driver ADT ListPos untuk mengecek semua fungsi dan prosedur
*/

#include <stdio.h>
#include "listpos.h"

int main() {
    /* KAMUS */
    int N, Xindex;
    ElType X, minVal, medVal, maxVal;
    ListPos L;

    /* ALGORITMA */
    readList(&L);
    scanf("%d", &X);

    displayList(L);
    printf("\n");

    Xindex = indexOf(L, X);
    if (Xindex == IDX_UNDEF) {
        printf("%d tidak ada\n", X);
    } else {
        printf("%d\n", Xindex);
    }

    N = length(L);

    if (N > 0) {
        extremes(L, &maxVal, &minVal);

        sort(&L, true);

        if (N % 2 == 1) {
            medVal = ELMT(L, N / 2);
        } else {
            medVal = ELMT(L, N / 2 - 1);
        }
        
        if (X == maxVal) {
            printf("maksimum\n");
        }
        if (X == minVal) {
            printf("minimum\n");
        }
        if (X == medVal) {
            printf("median\n");
        }
    }
}