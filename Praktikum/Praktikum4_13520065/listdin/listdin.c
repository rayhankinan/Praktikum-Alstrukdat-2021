/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 14 September 2021
Topik Praktikum     : ADT List Dinamis
Deskripsi           : Definisi fungsi dan prosedur ADT ListDin
*/

#include <stdlib.h>
#include <stdio.h>
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    /* KAMUS */

    /* ALGORITMA */
    BUFFER(*l) = (ElType *) malloc(capacity * sizeof(ElType));
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}

void dealocate(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    /* KAMUS */

    /* ALGORITMA */
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    /* KAMUS */

    /* ALGORITMA */
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    /* KAMUS */

    /* ALGORITMA */
    return (IdxType) (length(l) - 1); /*  Tetapi menurut definisi header: indeks yang digunakan [0..capacity-1] */ /* Ini masih diragukan*/
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i < (IdxType) CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
    return (i >= 0 && i <= getLastIdx(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
{
    /* KAMUS */

    /* ALGORITMA */
    return (NEFF(l) == 0); /* Tetapi menurut definisi header: list kosong: l.capacity = 0 */ /* Ini masih diragukan*/
}
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    /* KAMUS */

    /* ALGORITMA */
    return (NEFF(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    /* KAMUS */
    IdxType i;
    int N;

    /* ALGORITMA */
    do {
        scanf("%d", &N);
    } while(N < 0 || N > CAPACITY(*l));

    for (i = 0; i < (IdxType) N; i++) {
        scanf("%d", &ELMT(*l, i));
    }

    NEFF(*l) = N;
}
void displayList(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    printf("[");
    for (i = 0; i <= getLastIdx(l); i++) {
        if (i != getLastIdx(l)) {
            printf("%d,", ELMT(l, i));
        }
        else {
            printf("%d", ELMT(l, i));
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
    /* KAMUS */
    ListDin l;
    IdxType i;

    /* ALGORITMA */
    CreateListDin(&l, length(l1)); /* length(l1) == length(l2) */

    for (i = 0; i <= getLastIdx(l1); i++) {
        if (plus) {
            ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
        }
        else {
            ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }

    NEFF(l) = length(l1);

    return l;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
    /* KAMUS */
    IdxType i;
    boolean hasil;

    /* ALGORITMA */
    hasil = true;

    if (length(l1) != length(l2)) {
        hasil = false;
    }
    else {
        i = 0;
        while (i <= getLastIdx(l1) && hasil) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                hasil = false;
            }
            i++;
        }
    }

    return hasil;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
    /* KAMUS */
    IdxType i, index;

    /* ALGORITMA */
    index = IDX_UNDEF;
    i = 0;

    while (i <= getLastIdx(l) && index == IDX_UNDEF) {
        if (ELMT(l, i) == val) {
            index = i;
        }
        i++;
    }

    return index;
}

/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);

    for (i = 1; i <= getLastIdx(l); i++) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    CreateListDin(lOut, CAPACITY(lIn));

    NEFF(*lOut) = length(lIn);

    for (i = 0; i <= getLastIdx(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}
ElType sumList(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
    /* KAMUS */
    ElType hasil;
    IdxType i;

    /* ALGORITMA */
    hasil = 0;

    for (i = 0; i <= getLastIdx(l); i++) {
        hasil += ELMT(l, i);
    }

    return hasil;
}
int countVal(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
    /* KAMUS */
    int hasil;
    IdxType i;

    /* ALGORITMA */
    hasil = 0;

    for (i = 0; i <= getLastIdx(l); i++) {
        if (ELMT(l, i) == val) {
            hasil++;
        }
    }

    return hasil;
}
boolean isAllEven(ListDin l)
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
{
    /* KAMUS */
    boolean hasil;
    IdxType i;

    /* ALGORITMA */
    hasil = true;

    i = 0;
    while (i <= getLastIdx(l) && hasil) {
        if (ELMT(l, i) % 2 == 1) {
            hasil = false;
        }
        i++;
    }

    return hasil;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    /* KAMUS */
    IdxType i, pos;
    ElType temp;

    /* ALGORITMA */
    for (i = 1; i <= getLastIdx(*l); i++) {
        pos = i;
        if (asc) {
            while ((pos > 0) && (ELMT(*l, pos) < ELMT(*l, pos - 1))) {
                temp = ELMT(*l, pos);
                ELMT(*l, pos) = ELMT(*l, pos - 1);
                ELMT(*l, pos - 1) = temp;

                pos--;
            }
        } else {
            while ((pos > 0) && (ELMT(*l, pos) > ELMT(*l, pos - 1))) {
                temp = ELMT(*l, pos);
                ELMT(*l, pos) = ELMT(*l, pos - 1);
                ELMT(*l, pos - 1) = temp;

                pos--;
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    /* KAMUS */

    /* ALGORITMA */
    ELMT(*l, getLastIdx(*l) + 1) = val;
    NEFF(*l)++;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List lidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l)--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    /* KAMUS */
    int prevCapacity, prevNeff;
    IdxType i;
    ListDin temp;

    /* ALGORITMA */
    copyList(*l, &temp);
    prevCapacity = CAPACITY(*l);
    prevNeff = NEFF(*l);

    dealocate(l);

    CreateListDin(l, prevCapacity + num);
    NEFF(*l) = prevNeff;

    for (i = 0; i <= getLastIdx(*l); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}

void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    /* KAMUS */
    int prevCapacity, prevNeff;
    IdxType i;
    ListDin temp;

    /* ALGORITMA */
    copyList(*l, &temp);
    prevCapacity = CAPACITY(*l);
    prevNeff = NEFF(*l);

    dealocate(l);

    CreateListDin(l, prevCapacity - num);
    NEFF(*l) = prevNeff;

    for (i = 0; i <= getLastIdx(*l); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}

void compactList(ListDin *l)
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
{
    /* KAMUS */
    int prevNeff;
    IdxType i;
    ListDin temp;

    /* ALGORITMA */
    copyList(*l, &temp);
    prevNeff = NEFF(*l);

    dealocate(l);

    CreateListDin(l, prevNeff);
    NEFF(*l) = prevNeff;

    for (i = 0; i <= getLastIdx(*l); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}