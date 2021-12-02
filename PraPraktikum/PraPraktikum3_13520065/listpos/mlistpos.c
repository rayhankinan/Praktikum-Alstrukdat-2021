/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 7 September 2021
Topik Praktikum     : ADT List
Deskripsi           : Driver ADT ListPos untuk mengecek semua fungsi dan prosedur
*/

#include <stdio.h>
#include "boolean.h"
#include "listpos.h"

int main() {
    /* KAMUS */
    int i, lenl1, lenl2;
    ElType min, max, temp;
    ListPos l1, l2;

    /* ALGORITMA */
    printf("Masukkan list pertama:\n");
    readList(&l1);
    printf("List pertama: ");
    displayList(l1);
    printf("\n");
    extremes(l1, &max, &min);
    printf("Range list : %d - %d\n", min, max);
    lenl1 = length(l1);
    printf("Panjang list : %d\n", lenl1);
    if (isAllEven(l1)) {
        printf("Semua elemen pada list pertama adalah genap\n");
    }
    printf("\n");

    printf("Masukkan list kedua:\n");
    readList(&l2);
    printf("List kedua: ");
    displayList(l2);
    printf("\n");
    extremes(l1, &max, &min);
    printf("Range list : %d - %d\n", min, max);
    lenl2 = length(l2);
    printf("Panjang list : %d\n", lenl2);
    if (isAllEven(l2)) {
        printf("Semua elemen pada list kedua adalah genap\n");
    }
    printf("\n");

    if (isListEqual(l1, l2)) {
        printf("Kedua list memiliki elemen yang sama!\n");
        printf("\n");
    }

    if (length(l1) == length(l2)) {
        printf("Operasi penambahan antara list pertama dengan list kedua: ");
        displayList(plusMinusTab(l1, l2, true));
        printf("\n");
        printf("Operasi pengurangan antara list pertama dengan list kedua: ");
        displayList(plusMinusTab(l1, l2, false));
        printf("\n");
        printf("\n");
    }

    printf("Gabungkan elemen list kedua (sudah terurut) ke list pertama (sudah terurut) secara terurut:\n");
    sort(&l1, true);
    displayList(l1);
    printf(" ");
    sort(&l2, true);
    displayList(l2);
    printf("\n");
    while (!isFull(l1) && !isEmpty(l2)) {
        deleteLast(&l2, &temp);
        insertLast(&l1, temp);
        sort(&l1, true);
        displayList(l1);
        printf(" ");
        displayList(l2);
        printf("\n");
    }

    printf("\n");
}