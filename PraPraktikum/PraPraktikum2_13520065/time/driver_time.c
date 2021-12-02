/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 1 September 2021
Topik Praktikum     : ADT Sederhana
Deskripsi           : Driver ADT TIME untuk mengecek semua fungsi dan prosedur
*/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main() {
    /* KAMUS */
    int N, i, j, NBeda, indexInput, indexInput2, jumlahDetik;
    char query;
    TIME *arrOfTime, timeElmt, timeElmt2;

    /* ALGORITMA */
    printf("Masukkan jumlah time yang ingin dimasukkan: ");
    scanf("%d", &N);

    arrOfTime = (TIME *) malloc(N * sizeof(TIME));

    for (i = 0; i < N; i++) {
        printf("\nMasukkan time ke-%d:\n", i + 1);
        BacaTIME(arrOfTime + i);

        timeElmt = *(arrOfTime + i);
        printf("Jam ");
        TulisTIME(timeElmt);
        printf(" berhasil dimasukkan.\n");
    }

    NBeda = 1;

    for (i = 1; i < N; i++) {
        for (j = 0; j < i; j++) {
            if (TEQ(*(arrOfTime + i), *(arrOfTime + j))) break;
        }
        if (i == j) NBeda++;
    }

    printf("\nTerdapat %d jumlah time yang berbeda.\n", NBeda);

    query = '\0';
    do {
        printf("\nArray of time:\n");
        for (i = 0; i < N; i++) {
            printf("Jam ke-%d : ", i + 1);
            TulisTIME(*(arrOfTime + i));
            printf("\n");
        }
        do {
            printf("\nList Operasi:\n");
            printf("Membandingkan dua element time: R\n");
            printf("Mengedit nilai element time: E\n");
            printf("Mencari durasi antara dua element time: D\n\n");
            printf("Masukkan index operasi: ");
            scanf(" %c", &query);
        } while (query != 'R' && query != 'E' && query != 'D');

        printf("\n");
        if (query == 'R') {
            do {
                printf("Masukkan index array (1/2): ");
                scanf("%d", &indexInput);
            } while(indexInput < 1 || indexInput > N);
            do {
                printf("Masukkan index array (2/2): ");
                scanf("%d", &indexInput2);
            } while(indexInput2 < 1 || indexInput2 > N);
            timeElmt = *(arrOfTime + indexInput - 1);
            timeElmt2 = *(arrOfTime + indexInput2 - 1);

            if (TEQ(timeElmt, timeElmt2)) {
                TulisTIME(timeElmt);
                printf(" = ");
                TulisTIME(timeElmt2);
            } else if (TLT(timeElmt, timeElmt2)) {
                TulisTIME(timeElmt);
                printf(" < ");
                TulisTIME(timeElmt2);
            } else {
                TulisTIME(timeElmt);
                printf(" > ");
                TulisTIME(timeElmt2);
            }

        } else if (query == 'E') {
            do {
                printf("Masukkan index array: ");
                scanf("%d", &indexInput);
            } while(indexInput < 1 || indexInput > N);

            printf("Masukkan jumlah detik yang ingin ditambahkan: ");
            scanf("%d", &jumlahDetik);

            if (jumlahDetik == 1) {
                *(arrOfTime + indexInput - 1) = NextDetik(*(arrOfTime + indexInput - 1));
            } else if (jumlahDetik == -1) {
                *(arrOfTime + indexInput - 1) = PrevDetik(*(arrOfTime + indexInput - 1));
            } else if (jumlahDetik > 1) {
                *(arrOfTime + indexInput - 1) = NextNDetik(*(arrOfTime + indexInput - 1), jumlahDetik);
            } else if (jumlahDetik < -1) {
                *(arrOfTime + indexInput - 1) = PrevNDetik(*(arrOfTime + indexInput - 1), -1 * jumlahDetik);
            }

            TulisTIME(*(arrOfTime + indexInput - 1));

        } else {
            do {
                printf("Masukkan index array (1/2): ");
                scanf("%d", &indexInput);
            } while(indexInput < 1 || indexInput > N);
            do {
                printf("Masukkan index array (2/2): ");
                scanf("%d", &indexInput2);
            } while(indexInput2 < 1 || indexInput2 > N);

            printf("%d detik", Durasi(*(arrOfTime + indexInput - 1), *(arrOfTime + indexInput2 - 1)));
        }
        printf("\n");

        do {
            printf("\nLanjutkan operasi? [Y/N] ");
            scanf(" %c", &query);
        } while(query != 'Y' && query != 'N');
    } while (query == 'Y');
    
    free(arrOfTime);

    return 0;
}