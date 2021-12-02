/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 11 November 2021
Topik Praktikum     : ADT Stack dan Queue menggunakan Linked List
Deskripsi           : Driver ADT Queue untuk mengecek semua fungsi dan prosedur
*/

#include "queue_linked.h"
#include <stdio.h>

int main() {
    /* KAMUS */
    int N;
    Queue Q;
    ElType TFront, TBack;

    /* ALGORITMA */
    CreateQueue(&Q);

    scanf("%d", &N);

    while (N > 0) {
        scanf("%d", &TBack);

        while (!isEmpty(Q) && TBack - HEAD(Q) > 300) {
            dequeue(&Q, &TFront);
        }

        enqueue(&Q, TBack);

        printf("%d\n", length(Q));

        N--;
    }
}