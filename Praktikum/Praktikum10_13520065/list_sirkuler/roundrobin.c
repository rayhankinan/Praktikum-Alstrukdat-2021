/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 4 November 2021
Topik Praktikum     : Variasi ADT List Linear
Deskripsi           : Driver ADT Sirkuler untuk membuat simulasi "round robin"
*/

#include "list_circular.h"
#include <stdio.h>

void deleteRR(List *l, ElType tQ)
/* Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai aturan round robin, yaitu:
- jika INFO(last) > tQ, maka last "diantrikan" kembali sebagai first elemen dengan INFO(last) = INFO(last) - tQ
- jika INFO(last) <= tQ, maka deleteLast(l, x) dan menampilkan x ke layar */
/* I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
l terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir l diproses sesuai dengan aturan round-robin
l mungkin menjadi kosong. */
{
    /* KAMUS */
    Address last;
    ElType x;

    /* ALGORITMA */
    if (!isEmpty(*l)) {
        last = FIRST(*l);
        while (NEXT(last) != FIRST(*l)) {
            last = NEXT(last);
        }
        if (INFO(last) > tQ) {
            INFO(last) -= tQ;
            FIRST(*l) = last;
            printf("%d\n", tQ);
        } else {
            deleteLast(l, &x);
            printf("%d\n", x);
        }
    } else {
        printf("List kosong\n");
    }
}

float average(List l)
/* Menghasilkan nilai rata-rata elemen l. l tidak kosong */
{
    /* KAMUS */
    Address p;
    ElType sum;
    int N;

    /* ALGORITMA */
    p = FIRST(l);
    sum = 0;
    N = 0;

    while (NEXT(p) != FIRST(l)) {
        sum += INFO(p);
        N++;
        p = NEXT(p);
    }
    sum += INFO(p);
    N++;

    return (float) (((float) sum) / ((float) N));
}

int main() {
    /* KAMUS */
    List l;
    ElType TQ, TA;
    char Kode;

    /* ALGORITMA */
    CreateList(&l);

    do {
        scanf("%d", &TQ);
    } while (TQ <= 0);

    do {
        scanf(" %c", &Kode);

        if (Kode == 'A') {
            scanf("%d", &TA);
            if (TA > 0) {
                insertFirst(&l, TA);
            }
        } else if (Kode == 'D') {
            deleteRR(&l, TQ);
        } else if (Kode == 'F') {
            if (!isEmpty(l)) {
                printf("%.2f\n", average(l));
            } else {
                printf("Proses selesai\n");
            }
        } else {
            printf("Kode salah\n");
        }

    } while (Kode != 'F');
}