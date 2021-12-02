/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 7 Oktober 2021
Topik Praktikum     : ADT Queue
Deskripsi           : Driver ADT Queue untuk mengecek rata-rata waktu pengantrian
*/

#include <stdio.h>
#include "queue.h"

float avgElmt(Queue Q)
/* Menghasilkan rata-rata elemen dalam queue Q yang tidak kosong */
{
    /* KAMUS */
    int i, N;
    ElType val, sum;

    /* ALGORITMA */
    N = length(Q);

    sum = 0;
    for (i = 0; i < N; i++) {
        dequeue(&Q, &val);
        sum += val;
    }

    return ((float) sum) / ((float) N);
}

int main() {
    /* KAMUS */
    Queue Q;
    ElType val;
    int command;

    /* ALGORITMA */
    CreateQueue(&Q);


    do {
        scanf("%d", &command);

        if (command == 1) {
            scanf("%d", &val);
            if (isFull(Q)) {
                printf("Queue penuh\n");
            } else {
                enqueue(&Q, val);
            }
        }
        if (command == 2) {
            if (isEmpty(Q)) {
                printf("Queue kosong\n");
            } else {
                dequeue(&Q, &val);
            }
        }
    } while (command != 0);

    printf("%d\n", length(Q));

    if (length(Q) == 0) {
        printf("Tidak bisa dihitung\n");
    } else {
        printf("%.2f\n", avgElmt(Q));
    }
}