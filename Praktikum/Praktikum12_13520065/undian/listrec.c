/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 15 November 2021
Topik Praktikum     : ADT List Rekursif
Deskripsi           : Definisi fungsi dan prosedur ADT List
*/

#include "listrec.h"
#include <stdlib.h>

/* Manajemen Memori */
Address newNode(ElType x)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
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

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l)
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    return (l == NULL);
}
int isOneElmt(List l)
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    return (!isEmpty(l) && tail(l) == NULL);
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l)
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    return (INFO(l));
}
List tail(List l)
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    return (NEXT(l));
}
List konso(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = newNode(e);
    if (p != NULL) {
        NEXT(p) = l;
        return p;
    } else {
        return l;
    }
}
List konsb(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l)) {
        return newNode(e);
    } else {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}

/* Fungsi dan Prosedur Lain */
int length(List l)
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l)) {
        return 0;
    } else {
        return 1 + length(tail(l));
    }
}
void displayList(List l)
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
{
    /* KAMUS */

    /* ALGORITMA */
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}