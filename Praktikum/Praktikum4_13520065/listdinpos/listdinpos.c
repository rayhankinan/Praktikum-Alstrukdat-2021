/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 16 September 2021
Topik Praktikum     : ADT List Dinamis
Deskripsi           : Definisi fungsi dan prosedur ADT ListDin (secara implisit)
*/

#include <stdlib.h>
#include <stdio.h>
#include "listdinpos.h"

#define IDX_MIN 0

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity + 1 */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */
{
    /* KAMUS */
    IdxType i;

    /* ALGORTIMA */
    BUFFER(*l) = (ElType *) malloc(capacity * sizeof(ElType));

    for (i = IDX_MIN; i < capacity; i++) {
        ELMT(*l, i) = VAL_UNDEF;
    }

    CAPACITY(*l) = capacity;
}

void dealocate(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */
{
    /* KAMUS */

    /* ALGORITMA */
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
{
    /* KAMUS */
    IdxType i;
    int N;

    /* ALGORITMA */
    N = 0;

    i = IDX_MIN;
    while (isIdxValid(l, i) && ELMT(l, i) != VAL_UNDEF) {
        i++;
        N++;
    }

    return N;
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    /* KAMUS */

    /* ALGORITMA */
    return (IdxType) length(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    /* KAMUS */

    /* ALGORITMA */
    return (i >= IDX_MIN && i < (IdxType) CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..getLastIdx(l) */
{
    /* KAMUS */

    /* ALGORITMA */
    return (i >= IDX_MIN && i <= getLastIdx(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    /* KAMUS */

    /* ALGORITMA */
    return (length(l) == 0);
}
/* *** Test list penuh *** */
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    /* KAMUS */

    /* ALGORITMA */
    return (length(l) == CAPACITY(l));
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
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    /* KAMUS */
    IdxType i;
    int N;

    /* ALGORITMA */
    do {
        scanf("%d", &N);
    } while (N < 0 || N > CAPACITY(*l));

    for (i = IDX_MIN; i < (IdxType) N; i++) {
        scanf("%d", &ELMT(*l, i));
    }
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
/* Prekondisi : l1 dan l2 memiliki nEff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen l1-l2 yang menghasilkan nilai <= 0 */
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
        i = IDX_MIN;
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
/* ***  Perhatian : List boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen list l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan VAL_UNDEF */
/* Menghasilkan indeks tak terdefinisi (VAL_UNDEF) jika list l kosong */
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
    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);

    for (i = IDX_MIN + 1; i <= getLastIdx(l); i++) {
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
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan Capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    CreateListDin(lOut, CAPACITY(lIn));

    for (i = IDX_MIN; i <= getLastIdx(lIn); i++) {
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

    for (i = IDX_MIN; i <= getLastIdx(l); i++) {
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

    for (i = IDX_MIN; i <= getLastIdx(l); i++) {
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

    i = IDX_MIN;
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
    for (i = IDX_MIN + 1; i <= getLastIdx(*l); i++) {
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
/* Proses: Menambahkan X sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    /* KAMUS */

    /* ALGORITMA */
    ELMT(*l, getLastIdx(*l) + 1) = val;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    *val = ELMT(*l, getLastIdx(*l));
    ELMT(*l, getLastIdx(*l)) = VAL_UNDEF;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num)
/* Proses : Menambahkan kapasitas sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    /* KAMUS */
    int prevCapacity;
    IdxType i;
    ListDin temp;

    /* ALGORITMA */
    copyList(*l, &temp);
    prevCapacity = CAPACITY(*l);

    dealocate(l);

    CreateListDin(l, prevCapacity + num);

    for (i = IDX_MIN; i <= getLastIdx(temp); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}

void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi kapasitas sebanyak num */
/* I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    /* KAMUS */
    int prevCapacity;
    IdxType i;
    ListDin temp;

    /* ALGORITMA */
    copyList(*l, &temp);
    prevCapacity = CAPACITY(*l);

    dealocate(l);

    CreateListDin(l, prevCapacity - num);

    for (i = IDX_MIN; i <= getLastIdx(temp); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}

void compactList(ListDin *l)
/* Proses : Mengurangi kapasitas sehingga nEff = Capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran Capacity = nEff */
{
    /* KAMUS */
    int prevNeff;
    IdxType i;
    ListDin temp;

    /* ALGORITMA */
    copyList(*l, &temp);
    prevNeff = length(*l);

    dealocate(l);

    CreateListDin(l, prevNeff);

    for (i = IDX_MIN; i <= getLastIdx(temp); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}