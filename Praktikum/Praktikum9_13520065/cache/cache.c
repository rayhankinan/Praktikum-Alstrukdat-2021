/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 28 Oktober 2021
Topik Praktikum     : List Linked
Deskripsi           : Implementasi List Linked sebagai cache pada komputer
*/

#include <stdio.h>
#include "list_linked.h"

int main() {
    /* KAMUS */
    List l;
    ElType x, temp;
    int i, N, Q;
    boolean found;

    /* ALGORITMA */
    CreateList(&l);

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        insertLast(&l, i + 1);
    }

    scanf("%d", &Q);
    while (Q > 0) {
        scanf("%d", &x);

        i = 0;
        found = false;
        while (i < N && !found) {
            found = getElmt(l, i) == x;
            if (!found) {
                i++;
            }
        }

        if (found) {
            deleteAt(&l, i, &temp);
            insertFirst(&l, x);

            printf("hit ");
            displayList(l);
            printf("\n");
        } else {
            deleteLast(&l, &temp);
            insertFirst(&l, x);

            printf("miss ");
            displayList(l);
            printf("\n");
        }

        Q--;
    }
}