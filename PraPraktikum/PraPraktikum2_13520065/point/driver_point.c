/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 1 September 2021
Topik Praktikum     : ADT Sederhana
Deskripsi           : Driver ADT POINT untuk mengecek semua fungsi dan prosedur
*/

#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main() {
    /* KAMUS */
    int N, i, j, NBeda, indexInput, indexInput2;
    float deltaX, deltaY, sudut;
    char query, sumbu;
    boolean SbX;
    POINT *arrOfPoint, pointElmt;

    /* ALGORITMA */
    printf("Masukkan jumlah point yang ingin dimasukkan: ");
    scanf("%d", &N);

    arrOfPoint = (POINT *) malloc(N * sizeof(POINT));

    for (i = 0; i < N; i++) {
        printf("\nMasukkan point ke-%d: ", i + 1);
        BacaPOINT(arrOfPoint + i);

        pointElmt = *(arrOfPoint + i);
        TulisPOINT(pointElmt);

        if (IsOrigin(pointElmt)) {
            printf(" berada pada titik asal.");
        } else if (IsOnSbX(pointElmt)) {
            printf(" berada pada sumbu X.");
        } else if (IsOnSbY(pointElmt)) {
            printf(" berada pada sumbu Y.");
        } else {
            printf(" berada pada kuadran %d", Kuadran(pointElmt));
        }

        printf("\n");
    }

    NBeda = 1;

    for (i = 1; i < N; i++) {
        for (j = 0; j < i; j++) {
            if (EQ(*(arrOfPoint + i), *(arrOfPoint + j))) break;
        }
        if (i == j) NBeda++;
    }

    printf("\nTerdapat %d jumlah point yang berbeda.\n", NBeda);

    query = '\0';
    do {
        printf("\nArray of point:\n");
        for (i = 0; i < N; i++) {
            printf("point ke-%d : ", i + 1);
            TulisPOINT(*(arrOfPoint + i));
            printf("\n");
        }
        do {
            printf("\nLakukan fungsi atau prosedur? [F/P] ");
            scanf(" %c", &query);
        } while(query != 'F' && query != 'P');

        if (query == 'F') {
            do {
                printf("\nList Fungsi:\n");
                printf("Tambahkan absis point dengan satu: X\n");
                printf("Tambahkan ordinat point dengan satu: Y\n");
                printf("Tambahkan absis dan ordinat point sesuai input user: P\n");
                printf("Cerminkan point terhadap sumbu X atau Y: M\n");
                printf("Hitung jarak point terhadap titik (0,0): J\n");
                printf("Hitung panjang garis yang dibentuk dua point: L\n\n");
                printf("Masukkan index fungsi: ");
                scanf(" %c", &query);
            } while(query != 'X' && query != 'Y' && query != 'P' && query != 'M' && query != 'J' && query != 'L');
            
            printf("\n");
            if (query == 'X') {
                do {
                    printf("Masukkan index array: ");
                    scanf("%d", &indexInput);
                } while(indexInput < 1 || indexInput > N);
                TulisPOINT(NextX(*(arrOfPoint + indexInput - 1)));
            } else if (query == 'Y') {
                do {
                    printf("Masukkan index array: ");
                    scanf("%d", &indexInput);
                } while(indexInput < 1 || indexInput > N);
                TulisPOINT(NextY(*(arrOfPoint + indexInput - 1)));
            } else if (query == 'P') {
                do {
                    printf("Masukkan index array: ");
                    scanf("%d", &indexInput);
                } while(indexInput < 1 || indexInput > N);
                printf("Masukkan delta X dan delta Y (dipisah dengan spasi): ");
                scanf("%f %f", &deltaX, &deltaY);
                TulisPOINT(PlusDelta(*(arrOfPoint + indexInput - 1), deltaX, deltaY));
            } else if (query == 'M') {
                do {
                    printf("Masukkan index array: ");
                    scanf("%d", &indexInput);
                } while(indexInput < 1 || indexInput > N);
                do {
                    printf("Masukkan sumbu: [X/Y] ");
                    scanf(" %c", &sumbu);
                } while(sumbu != 'X' && sumbu != 'Y');
                SbX = sumbu == 'X';
                TulisPOINT(MirrorOf(*(arrOfPoint + indexInput - 1), SbX));
            } else if (query == 'J') {
                do {
                    printf("Masukkan index array: ");
                    scanf("%d", &indexInput);
                } while(indexInput < 1 || indexInput > N);
                printf("%f", Jarak0(*(arrOfPoint + indexInput - 1)));
            } else {
                do {
                    printf("Masukkan index array (1/2): ");
                    scanf("%d", &indexInput);
                } while(indexInput < 1 || indexInput > N);
                do {
                    printf("Masukkan index array (2/2): ");
                    scanf("%d", &indexInput2);
                } while(indexInput2 < 1 || indexInput2 > N);
                printf("%f", Panjang(*(arrOfPoint + indexInput - 1), *(arrOfPoint + indexInput2 - 1)));
            }
            
        } else {
            do {
                printf("\nList Prosedur:\n");
                printf("Geser absis dan ordinat point sesuai input user: G\n");
                printf("Ubah absis point menjadi nol: X\n");
                printf("Ubah ordinat point menjadi nol: Y\n");
                printf("Cerminkan point terhadap sumbu X atau Y: M\n");
                printf("Rotasi point terhadap titik (0,0): P\n\n");
                printf("Masukkan index procedure: ");
                scanf(" %c", &query);
            } while(query != 'G' && query != 'X' && query != 'Y' && query != 'M' && query != 'P');

            printf("\n");
            if (query == 'G') {
                do {
                    printf("Masukkan index array: ");
                    scanf("%d", &indexInput);
                } while(indexInput < 1 || indexInput > N);
                printf("Masukkan delta X dan delta Y (dipisah dengan spasi): ");
                scanf("%f %f", &deltaX, &deltaY);
                Geser(arrOfPoint + indexInput - 1, deltaX, deltaY);
                TulisPOINT(*(arrOfPoint + indexInput - 1));
            } else if (query == 'X') {
                do {
                    printf("Masukkan index array: ");
                    scanf("%d", &indexInput);
                } while(indexInput < 1 || indexInput > N);
                GeserKeSbX(arrOfPoint + indexInput - 1);
                TulisPOINT(*(arrOfPoint + indexInput - 1));
            } else if (query == 'Y') {
                do {
                    printf("Masukkan index array: ");
                    scanf("%d", &indexInput);
                } while(indexInput < 1 || indexInput > N);
                GeserKeSbY(arrOfPoint + indexInput - 1);
                TulisPOINT(*(arrOfPoint + indexInput - 1));
            } else if (query == 'M') {
                do {
                    printf("Masukkan index array: ");
                    scanf("%d", &indexInput);
                } while(indexInput < 1 || indexInput > N);
                do {
                    printf("Masukkan sumbu: [X/Y] ");
                    scanf(" %c", &sumbu);
                } while(sumbu != 'X' && sumbu != 'Y');
                SbX = sumbu == 'X';
                Mirror(arrOfPoint + indexInput - 1, SbX);
                TulisPOINT(*(arrOfPoint + indexInput - 1));
            } else {
                do {
                    printf("Masukkan index array: ");
                    scanf("%d", &indexInput);
                } while(indexInput < 1 || indexInput > N);
                printf("Masukkan sudut (dalam derajat): ");
                scanf("%f", &sudut);
                Putar(arrOfPoint + indexInput - 1, sudut);
                TulisPOINT(*(arrOfPoint + indexInput - 1));
            }
        }

        printf("\n");

        do {
            printf("\nLanjutkan operasi? [Y/N] ");
            scanf(" %c", &query);
        } while(query != 'Y' && query != 'N');

    } while(query == 'Y');

    free(arrOfPoint);

    return 0;
}