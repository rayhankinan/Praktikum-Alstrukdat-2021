/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 1 September 2021
Topik Praktikum     : ADT Sederhana
Deskripsi           : Driver ADT VECTOR untuk mengecek semua fungsi dan prosedur
*/

#include <stdio.h>
#include "vector.h"

int main() {
    /* KAMUS */
    VECTOR A, B;
    float X, Y, s;

    /* ALGORITMA */
    printf("Masukkan vektor A: ");
    scanf("%f %f", &X, &Y);
    A = MakeVector(X, Y);
    printf("Magnitude dari vektor A: %f\n\n", Magnitude(A));

    printf("Masukkan vektor B: ");
    scanf("%f %f", &X, &Y);
    B = MakeVector(X, Y);
    printf("Magnitude dari vektor B: %f\n\n", Magnitude(B));

    printf("Masukkan skalar s: ");
    scanf("%f", &s);
    printf("\n");

    printf("A + B = ");
    TulisVector(Add(A, B));
    printf("\n");
    printf("A - B = ");
    TulisVector(Substract(A, B));
    printf("\n");
    printf("A * B = %f\n", Dot(A, B));
    printf("s * A = ");
    TulisVector(Multiply(A, s));
    printf("\n");
    printf("s * B = ");
    TulisVector(Multiply(B, s));
    printf("\n");
}