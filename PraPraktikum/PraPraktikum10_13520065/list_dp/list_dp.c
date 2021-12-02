/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 1 November 2021
Topik Praktikum     : Variasi ADT List Linear
Deskripsi           : Definisi fungsi dan prosedur ADT List dengan Double Pointer
*/

#include "list_dp.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list : */
/* List kosong : First(L) = NULL dan Last(L) = NULL */
/* Setiap elemen dengan Address P dapat diacu INFO(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((FIRST(l) == NULL) && (LAST(l) == NULL));
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. l sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    /* KAMUS */

    /* ALGORITMA */
    FIRST(*l) = NULL;
    LAST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL. */
/* Misalnya: menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL, PREV(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL. */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = (Address) malloc(sizeof(Node));

    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
        PREV(p) = NULL;
    }

    return p;
}
void deallocate (Address p)
/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */
{
    /* KAMUS */

    /* ALGORITMA */
    free(p);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val)
/* Mencari apakah ada elemen list dengan INFO(P)=val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
{
    /* KAMUS */
    Address p;
    boolean found;

    /* ALGORITMA */
    p = FIRST(l);
    found = false;

    while ((p != NULL) && (!found)) {
        found = INFO(p) == val;

        if (!found) {
            p = NEXT(p);
        }
    }

    return p;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = allocate(val);

    if (p != NULL) {
        NEXT(p) = FIRST(*l);
        if (!isEmpty(*l)) {
            PREV(FIRST(*l)) = p;
        } else {
            LAST(*l) = p;
        }
        FIRST(*l) = p;
    }
}
void insertLast(List *l, ElType val)
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = allocate(val);

    if (p != NULL) {
        PREV(p) = LAST(*l);
        if (!isEmpty(*l)) {
            NEXT(LAST(*l)) = p;
        } else {
            FIRST(*l) = p;
        }
        LAST(*l) = p;
    }
}
void insertAfter(List *L, Address p, Address pRec)
/* I.S. pRec pasti elemen list; p sudah dialokasi */
/* F.S. Insert p sebagai elemen sesudah elemen beralamat pRec */
{
    /* KAMUS */

    /* ALGORITMA */
    PREV(p) = pRec;
    NEXT(p) = NEXT(pRec);

    PREV(NEXT(pRec)) = p;
    NEXT(pRec) = p;
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen pertama di-dealokasi */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = FIRST(*l);
    *val = INFO(p);

    if (FIRST(*l) == LAST(*l)) {
        LAST(*l) = NULL;
    } else {
        PREV(NEXT(FIRST(*l))) = NULL;
    }
    FIRST(*l) = NEXT(FIRST(*l));
    deallocate(p);
}
void deleteLast(List *l, ElType *val)
/* I.S. list l tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen terakhir di-dealokasi */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = LAST(*l);
    *val = INFO(p);

    if (FIRST(*l) == LAST(*l)) {
        FIRST(*l) = NULL;
    } else {
        NEXT(PREV(LAST(*l))) = NULL;
    }
    LAST(*l) = PREV(LAST(*l));
    deallocate(p);
}
void deleteAfter(List *l, Address *pDel, Address pRec)
/* I.S. List tidak kosong. pRec adalah anggota list. 
        NEXT(pRec)!=NULL */
/* F.S. Menghapus NEXT(pRec): */
{
    /* KAMUS */

    /* ALGORITMA */
    *pDel = NEXT(pRec);

    if (*pDel != LAST(*l)) {
        NEXT(pRec) = NEXT(*pDel);
        PREV(NEXT(*pDel)) = pRec;
    } else {
        NEXT(pRec) = NULL;
        LAST(*l) = pRec;
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    printf("[");
    p = FIRST(l);
    while (p != NULL) {
        if (NEXT(p) == NULL) {
            printf("%d", INFO(p));
        } else {
            printf("%d,", INFO(p));
        }
        p = NEXT(p);
    }
    printf("]");
}
void displayListBackwards(List l)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    printf("[");
    p = LAST(l);
    while (p != NULL) {
        if (PREV(p) == NULL) {
            printf("%d", INFO(p));
        } else {
            printf("%d,", INFO(p));
        }
        p = PREV(p);
    }
    printf("]");
}