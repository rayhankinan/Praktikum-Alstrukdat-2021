/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 21 Oktober 2021
Topik Praktikum     : ADT Stack
Deskripsi           : Driver ADT Stack untuk menghitung penjumlahan integer besar
*/

#include "stack.h"
#include <stdio.h>

int angka(char CC) {
    /* KAMUS */

    /* ALGORITMA */
    return CC - 48;
}

char karakter(int N) {
    /* KAMUS */

    /* ALGORITMA */
    return N + 48;
}

int main() {
    /* KAMUS */
    Stack S1, S2, SPlus;
    ElType NPlus, N1, N2;
    char CC1, CC2;
    boolean Carry;

    /* ALGORITMA */
    CreateStack(&S1);
    CreateStack(&S2);

    do {
        scanf(" %c", &CC1);
        if (CC1 != '#') {
            push(&S1, angka(CC1));
        }
    } while (CC1 != '#');

    do {
        scanf(" %c", &CC2);
        if (CC2 != '#') {
            push(&S2, angka(CC2));
        }
    } while (CC2 != '#');

    CreateStack(&SPlus);

    Carry = false;
    while (!isEmpty(S1) && !isEmpty(S2)) {
        pop(&S1, &N1);
        pop(&S2, &N2);

        if (Carry) {
            push(&SPlus, (N1 + N2 + 1) % 10);
            if ((N1 + N2 + 1) / 10) {
                Carry = true;
            } else {
                Carry = false;
            }
        } else {
            push(&SPlus, (N1 + N2) % 10);
            if ((N1 + N2) / 10) {
                Carry = true;
            } else {
                Carry = false;
            }
        }
    }

    while (!isEmpty(S1)) {
        pop(&S1, &N1);
        if (Carry) {
            push(&SPlus, (N1 + 1) % 10);
            if ((N1 + 1) / 10) {
                Carry = true;
            } else {
                Carry = false;
            }
        } else {
            push(&SPlus, N1);
        }
    }

    while (!isEmpty(S2)) {
        pop(&S2, &N2);
        if (Carry) {
            push(&SPlus, (N2 + 1) % 10);
            if ((N2 + 1) / 10) {
                Carry = true;
            } else {
                Carry = false;
            }
        } else {
            push(&SPlus, N2);
        }
    }

    if (Carry) {
        push(&SPlus, 1);
        Carry = false;
    }

    while (!isEmpty(SPlus)) {
        pop(&SPlus, &NPlus);
        printf("%c", karakter(NPlus));
    }
    printf("\n");
}