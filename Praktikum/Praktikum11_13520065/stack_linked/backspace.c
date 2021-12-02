/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 11 November 2021
Topik Praktikum     : ADT Stack dan Queue menggunakan Linked List
Deskripsi           : Driver ADT Stack untuk mengecek kesamaan sequence
*/

#include <stdio.h>
#include "stack_linked.h"

int main() {
    /* KAMUS */
    int N, M;
    Stack S1, S2;
    ElType Val1, Val2, Temp;
    boolean isSama, isHabis;

    /* ALGORITMA */
    CreateStack(&S1);
    CreateStack(&S2);

    scanf("%d %d", &N, &M);
    while (N > 0) {
        scanf("%d", &Val1);
        if (Val1 == 0) {
            if (!isEmpty(S1)) {
                pop(&S1, &Temp);
            }
        } else {
            push(&S1, Val1);
        }
        N--;
    }

    while (M > 0) {
        scanf("%d", &Val2);
        if (Val2 == 0) {
            if (!isEmpty(S2)) {
                pop(&S2, &Temp);
            }
        } else {
            push(&S2, Val2);
        }
        M--;
    }

    isSama = true;
    while (!isEmpty(S1) && !isEmpty(S2) && isSama) {
        pop(&S1, &Val1);
        pop(&S2, &Val2);
        isSama = Val1 == Val2;
    }

    isHabis = isEmpty(S1) && isEmpty(S2);

    if (isSama && isHabis) {
        printf("Sama\n");
    } else {
        printf("Tidak sama\n");
    }
}