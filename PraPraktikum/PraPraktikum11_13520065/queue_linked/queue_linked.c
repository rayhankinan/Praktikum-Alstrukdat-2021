/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 8 November 2021
Topik Praktikum     : ADT Stack dan Queue menggunakan Linked List
Deskripsi           : Definisi fungsi dan prosedur ADT Queue
*/

#include "queue_linked.h"

Address newNode(ElType x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NULL jika alokasi gagal */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Queue q)
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((ADDR_HEAD(q) == NULL) && (ADDR_HEAD(q) == NULL));
}
int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
{
    /* KAMUS */
    Address p;
    int N;

    /* ALGORITMA */
    N = 0;

    if (!isEmpty(q)) {
        p = ADDR_HEAD(q);
        do {
            N++;
            p = NEXT(p);
        } while (p != NULL);
    }

    return N;
}

/*** Kreator ***/
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
{
    /* KAMUS */

    /* ALGORITMA */
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x)
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = newNode(x);
    if (p != NULL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = p;
        } else {
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}
void dequeue(Queue *q, ElType *x)
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    *x = HEAD(*q);
    p = ADDR_HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    if (ADDR_HEAD(*q) == NULL) {
        ADDR_TAIL(*q) = NULL;
    }
    NEXT(p) = NULL;
    free(p);
}