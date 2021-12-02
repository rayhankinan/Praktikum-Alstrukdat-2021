/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 1 September 2021
Topik Praktikum     : ADT Sederhana
Deskripsi           : Driver ADT TIME untuk mengecek semua fungsi dan prosedur
*/

#include <stdio.h>
#include "time.h"

int main() {
    /* KAMUS */
    int N, i;
    TIME T1, T2, minTime, maxTime;

    /* ALGORITMA */
    minTime = MakeTIME(23, 59, 59);
    maxTime = MakeTIME(0, 0, 0);
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        printf("[%d]\n", i + 1);
        BacaTIME(&T1);
        BacaTIME(&T2);

        if (TLT(T1, T2)) {
            printf("%d\n", Durasi(T1, T2));
        } else {
            printf("%d\n", Durasi(T2, T1));
        }

        if (TLT(T1, minTime)) {
            minTime = T1;
        }
        if (TLT(T2, minTime)) {
            minTime = T2;
        }
        if (TGT(T1, maxTime)) {
            maxTime = T1;
        }
        if (TGT(T2, maxTime)) {
            maxTime = T2;
        }
    }
    TulisTIME(minTime);
    printf("\n");
    TulisTIME(maxTime);
    printf("\n");
}