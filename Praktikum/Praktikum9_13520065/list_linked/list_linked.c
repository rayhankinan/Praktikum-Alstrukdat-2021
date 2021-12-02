/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 28 Oktober 2021
Topik Praktikum     : ADT Linked List
Deskripsi           : Definisi fungsi dan prosedur ADT List
*/

#include <stdio.h>
#include "list_linked.h"

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    /* KAMUS */
    Address p;
    int ctr;

    /* ALGORITMA */
    ctr = 0;
    p = FIRST(l);

    while (ctr < idx) {
        p = NEXT(p);
        ctr++;
    }

    return INFO(p);
}

void setElmt(List *l, int idx, ElType val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
    /* KAMUS */
    Address p;
    int ctr;

    /* ALGORITMA */
    ctr = 0;
    p = FIRST(*l);

    while (ctr < idx) {
        p = NEXT(p);
        ctr++;
    }

    INFO(p) = val;
}

int indexOf(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
    /* KAMUS */
    Address p;
    int i, idx;

    /* ALGORITMA */
    idx = IDX_UNDEF;
    p = FIRST(l);
    i = 0;

    while ((p != NULL) && (idx == IDX_UNDEF)) {
        if (INFO(p) == val) {
            idx = i;
        } else {
            i++;
            p = NEXT(p);
        }
    }

    return idx;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = newNode(val);
    if (p != NULL) {
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLast(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    /* KAMUS */
    Address p, last;

    /* ALGORITMA */
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            last = FIRST(*l);
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    /* KAMUS */
    Address p, loc;
    int ctr;

    /* ALGORITMA */
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            ctr = 0;
            loc = FIRST(*l);
            while (ctr < idx - 1) {
                ctr++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
    /* KAMUS */
    Address p, loc;

    /* ALGORITMA */
    p = FIRST(*l);
    loc = NULL;

    while (NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }

    if (loc == NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
    /* KAMUS */
    Address p, loc;
    int ctr;

    /* ALGORITMA */
    if (idx == 0) {
        deleteFirst(l, val);
     } else {
        ctr = 0;
        loc = FIRST(*l);

        while (ctr < idx - 1) {
            ctr++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    /* KAMUS */
    Address p;
    int ctr;

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

int length(List l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    /* KAMUS */
    Address p;
    int ctr;

    /* ALGORITMA */
    ctr = 0;
    p = FIRST(l);

    while (p != NULL) {
        ctr++;
        p = NEXT(p);
    }

    return ctr;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    /* KAMUS */
    Address ptr;
    boolean found;

    /* ALGORITMA */
    ptr = FIRST(L);
    found = false;
    while ((ptr != NULL) && (!found)) {
        found = P == ptr;
        if (!found) {
            ptr = NEXT(ptr);
        }
    }

    return found;
}
Address searchPrec(List L, ElType X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    /* KAMUS */
    Address ptr, loc;
    boolean found;

    /* ALGORITMA */
    ptr = FIRST(L);
    loc = NULL;
    found = false;

    while ((ptr != NULL) && (!found)) {
        if (INFO(ptr) == X) {
            found = true;
        } else {
            loc = ptr;
            ptr = NEXT(ptr);
        }
    }

    return loc;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
ElType maxList(List l)
/* Mengirimkan nilai info(P) yang maksimum */
{
    /* KAMUS */

    /* ALGORITMA */
    return INFO(adrMax(l));
}
Address adrMax(List l)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    /* KAMUS */
    Address p, maxAddress;

    /* ALGORITMA */
    maxAddress = FIRST(l);
    p = NEXT(FIRST(l));

    while (p != NULL) {
        if (INFO(p) > INFO(maxAddress)) {
            maxAddress = p;
        }
        p = NEXT(p);
    }

    return maxAddress;
}
ElType minList(List l)
/* Mengirimkan nilai info(P) yang minimum */
{
    /* KAMUS */

    /* ALGORITMA  */
    return INFO(adrMin(l));
}
Address adrMin(List l)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    /* KAMUS */
    Address p, minAddress;

    /* ALGORITMA */
    minAddress = FIRST(l);
    p = NEXT(FIRST(l));

    while (p != NULL) {
        if (INFO(p) < INFO(minAddress)) {
            minAddress = p;
        }
        p = NEXT(p);
    }

    return minAddress;
}
float average(List l)
/* Mengirimkan nilai rata-rata info(P) */
{
    /* KAMUS */
    Address p;
    ElType sum;

    /* ALGORITMA */
    p = FIRST(l);
    sum = 0;

    while (p != NULL) {
        sum += INFO(p);
        p = NEXT(p);
    }

    return ((float) sum) / ((float) length(l));
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2)
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    /* KAMUS */
    Address p;
    List l3;

    /* ALGORITMA */
    CreateList(&l3);

    p = FIRST(l1);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    p = FIRST(l2);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    return l3;
}

void delAll(List *l)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
    /* KAMUS */
    ElType val;

    /* ALGORITMA */

    while (!isEmpty(*l)) {
        deleteFirst(l, &val);
    }
}

void inverseList(List *l)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    /* KAMUS */
    int i, N;
    ElType temp;

    /* ALGORITMA */

    N = length(*l);
    for (i = 0; i < N / 2; i++) {
        temp = getElmt(*l, i);
        setElmt(l, i, getElmt(*l, N - 1 - i));
        setElmt(l, N - 1 - i, temp);
    }
}

List fInverseList(List l)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemen list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    /* KAMUS */
    List lHasil;

    /* ALGORITMA */
    CreateList(&lHasil);
    cpAllocList(l, &lHasil);
    inverseList(&lHasil);

    return lHasil;
}

void copyList(List *l1, List *l2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
    /* KAMUS */

    /* ALGORITMA */
    CreateList(l2);
    FIRST(*l2) = FIRST(*l1);
}

List fCopyList(List l)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    /* KAMUS */
    List lHasil;
    Address p, prec, pHasil;
    boolean berhasil;

    /* ALGORITMA */
    lHasil = (Address) malloc(sizeof(Node));
    
    if (lHasil != NULL) {
        CreateList(&lHasil);

        berhasil = true;

        p = FIRST(l);
        prec = NULL;
        while (p != NULL && berhasil) {
            pHasil = newNode(INFO(p));
            if (pHasil != NULL) {
                if (prec == NULL) {
                    FIRST(lHasil) = pHasil;
                } else {
                    NEXT(prec) = pHasil;
                }
                p = NEXT(p);
            } else {
                delAll(&lHasil);
                berhasil = false;
            }
            prec = pHasil;
        }
    }

    return lHasil;
}

void cpAllocList(List lIn, List *lOut)
/* I.S. lIn sembarang. */
/* F.S. Jika semua alokasi berhasil,maka lOut berisi hasil copy lIn */
/* Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* lOut adalah list kosong jika ada alokasi elemen yang gagal */
{
    /* KAMUS */

    /* ALGORITMA */
    CreateList(lOut);
    *lOut = fCopyList(lIn);
}

void splitList(List *l1, List *l2, List l)
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */
{
    /* KAMUS */
    int i;
    Address p, pNew;

    /* ALGORITMA */
    CreateList(l1);
    CreateList(l2); 
    
    p = FIRST(l);

    i = 0;
    while (p != NULL) {
        pNew = newNode(INFO(p));
        if (pNew != NULL) {
            if (i < length(l) / 2) {
                insertLast(l1, INFO(pNew));
            } else {
                insertLast(l2, INFO(pNew));
            }
        }
        free(pNew);
        p = NEXT(p);
        i++;
    }
}