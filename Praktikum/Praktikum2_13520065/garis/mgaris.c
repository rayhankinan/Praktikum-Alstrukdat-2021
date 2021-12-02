/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 1 September 2021
Topik Praktikum     : ADT Sederhana
Deskripsi           : Driver ADT GARIS untuk mengecek semua fungsi dan prosedur
*/

#include <stdio.h>
#include "garis.h"

int main() {
    /* KAMUS */
    GARIS L1, L2;
    int index;
    float X, Y;

    /* ALGORITMA */
    printf("Masukkan garis 1:\n");
    BacaGARIS(&L1);

    printf("Panjang garis 1: %f\n", PanjangGARIS(L1));
    if (Absis(PAkhir(L1)) != Absis(PAwal(L1))) printf("Gradien garis 1: %f\n\n", Gradien(L1));

    printf("Masukkan garis 2:\n");
    BacaGARIS(&L2);
    printf("Panjang garis 2: %f\nGradien garis 2: %f\n\n", PanjangGARIS(L2), Gradien(L2));

    if (IsTegakLurus(L1, L2)) {
        printf("Kedua garis tegak lurus.\n\n");
    } else if (IsSejajar(L1, L2)) {
        printf("Kedua garis sejajar.\n\n");
    } else {
        printf("Kedua garis tidak tegak lurus maupun sejajar.\n\n");
    }

    printf("Lakukan operasi geser pada garis 1: ");
    scanf("%f %f", &X, &Y);
    GeserGARIS(&L1, X, Y);
    TulisGARIS(L1);
    printf("\n\n");

    printf("Lakukan operasi geser pada garis 2: ");
    scanf("%f %f", &X, &Y);
    GeserGARIS(&L2, X, Y);
    TulisGARIS(L2);
    printf("\n\n");
}