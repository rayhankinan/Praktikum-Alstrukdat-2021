/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 16 September 2021
Topik Praktikum     : ADT List Dinamis
Deskripsi           : Melakukan operasi terhadap ADT ListDin
*/

#include <stdio.h>
#include "listdin.h"

int main() {
    /* KAMUS */
    ListDin L;
    ElType Temp;
    int C, Q, i, op, num;

    /* ALGORITMA */
    scanf("%d", &C);
    CreateListDin(&L, C);

    readList(&L);

    scanf("%d", &Q);

    for (i = 0; i < Q; i++) {
        scanf("%d", &op);

        switch (op) {
            case 1:
                scanf("%d", &num);
                if (isFull(L)) {
                    printf("list sudah penuh\n");
                }
                else {
                    insertLast(&L, num);
                    printf("%d ", CAPACITY(L));
                    displayList(L);
                    printf("\n");
                }
                break;
            case 2:
                scanf("%d", &num);
                growList(&L, num);
                printf("%d ", CAPACITY(L));
                displayList(L);
                printf("\n");
                break;
            case 3:
                scanf("%d", &num);
                if (CAPACITY(L) < num) {
                    printf("list terlalu kecil\n");
                }
                else {
                    while (length(L) > CAPACITY(L) - num) {
                        deleteLast(&L, &Temp);
                    }
                    shrinkList(&L, num);
                    printf("%d ", CAPACITY(L));
                    displayList(L);
                    printf("\n");
                }
                break;
            case 4:
                compactList(&L);
                printf("%d ", CAPACITY(L));
                displayList(L);
                printf("\n");
                break;
        }
    }
}