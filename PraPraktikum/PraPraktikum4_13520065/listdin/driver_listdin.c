#include <stdio.h>
#include "listdin.h"

int main() {
    /* KAMUS */
    int NMax, NExtra;
    ListDin l1, l2, sortedL1, sortedL2;
    ElType maxL1, minL1, maxL2, minL2, temp;
    IdxType i;

    /* ALGORITMA */
    printf("Masukkan jumlah maksimal elemen ListDin: ");
    scanf("%d", &NMax);

    CreateListDin(&l1, NMax);
    CreateListDin(&l2, NMax);

    printf("Masukkan ListDin pertama:\n");
    readList(&l1);

    printf("\n");
    printf("ListDin pertama: ");displayList(l1);printf("\n");

    if (!isEmpty(l1)){
        extremes(l1, &maxL1, &minL1);
        printf("Range ListDin pertama: (%d - %d)\n", minL1, maxL1);
        printf("Jumlah semua elemen pada ListDin pertama: %d\n", sumList(l1));
        printf("Frequency table ListDin pertama: \n");
        for (i = 0; i <= getLastIdx(l1); i++) {
            if (i == indexOf(l1, ELMT(l1, i))) {
                printf("%d : %d\n", ELMT(l1, i), countVal(l1, ELMT(l1, i)));
            }
        }
        if (isAllEven(l1)) {
            printf("Semua elemen ListDin pertama genap!\n");
        }
        if (isFull(l1)) {
            printf("ListDin pertama penuh!\n");
        }
        copyList(l1, &sortedL1);
        sort(&sortedL1, true);
        printf("ListDin pertama sorted: ");displayList(sortedL1);printf("\n");
    } else {
        printf("ListDin pertama kosong!\n");
    }
    printf("\n");

    compactList(&l1);

    printf("Masukkan ListDin kedua:\n");
    readList(&l2);

    printf("\n");
    printf("ListDin kedua: ");displayList(l2);printf("\n");

    if (!isEmpty(l2)){
        extremes(l2, &maxL2, &minL2);
        printf("Range ListDin kedua: (%d - %d)\n", minL2, maxL2);
        printf("Jumlah semua elemen pada ListDin kedua: %d\n", sumList(l2));
        printf("Frequency table ListDin kedua: \n");
        for (i = 0; i <= getLastIdx(l2); i++) {
            if (i == indexOf(l2, ELMT(l2, i))) {
                printf("%d : %d\n", ELMT(l2, i), countVal(l2, ELMT(l2, i)));
            }
        }
        if (isAllEven(l2)) {
            printf("Semua elemen ListDin kedua genap!\n");
        }
        if (isFull(l2)) {
            printf("ListDin kedua penuh!\n");
        }
        copyList(l2, &sortedL2);
        sort(&sortedL2, true);
        printf("ListDin kedua sorted: ");displayList(sortedL2);printf("\n");
    } else {
        printf("ListDin kedua kosong!\n");
    }
    printf("\n");
    
    compactList(&l2);

    if (length(l1) == length(l2)) {
        printf("ListDin pertama + ListDin kedua = ");displayList(plusMinusList(l1, l2, true));printf("\n");
        printf("ListDin pertama - ListDin kedua = ");displayList(plusMinusList(l1, l2, false));printf("\n");
    }
    if (isListEqual(l1, l2)) {
        printf("ListDin pertama = ListDin kedua\n");
    }

    growList(&l1, length(l2));

    NExtra = length(l2);

    for (i = 0; i < NExtra; i++) {
        deleteLast(&l2, &temp);
        insertLast(&l1, temp);
    }

    sort(&l1, true);

    printf("Concat kedua ListDin secara terurut: ");displayList(l1);printf("\n");

    dealocate(&l1);
    dealocate(&l2);
}