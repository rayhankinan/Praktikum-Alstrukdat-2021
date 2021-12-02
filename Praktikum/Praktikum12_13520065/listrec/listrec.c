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

/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
ElType maxList (List l)
/* Mengirimkan nilai INFO(p) yang maksimum */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isOneElmt(l)) {
        return head(l);
    } else {
        if (head(l) > maxList(tail(l))) {
            return head(l);
        } else {
            return maxList(tail(l));
        }
    }
}

ElType minList (List l)
/* Mengirimkan nilai INFO(p) yang minimum */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isOneElmt(l)) {
        return head(l);
    } else {
        if (head(l) < minList(tail(l))) {
            return head(l);
        } else {
            return minList(tail(l));
        }
    }
}

ElType sumList (List l)
/* Mengirimkan total jumlah elemen List l */
{
    /* KAMUS */
    if (isEmpty(l)) {
        return 0;
    } else {
        return head(l) + sumList(tail(l));
    }
}

float averageList (List l)
/* Mengirimkan nilai rata-rata elemen list l */
{
    /* KAMUS */

    /* ALGORITMA */
    return (float) ((float) sumList(l) / (float) length(l));
}

/*** Operasi-Operasi Lain ***/
List inverseList (List l)
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l)) {
        return NULL;
    } else {
        return konsb(inverseList(tail(l)), head(l));
    }
}

void splitPosNeg (List l, List *l1, List *l2)
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */ 
/* l1 berisi semua elemen l yang positif atau 0, sedangkan l2 berisi
semua elemen l yang negatif; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l)) {
        *l1 = NULL;
        *l2 = NULL;
    } else {
        if (head(l) >= 0) {
            splitPosNeg(tail(l), l1, l2);
            *l1 = konso(*l1, head(l));
        } else {
            splitPosNeg(tail(l), l1, l2);
            *l2 = konso(*l2, head(l));
        }
    }
}

void splitOnX (List l, ElType x, List *l1, List *l2)
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang lebih kecil dari x, dengan urutan
kemunculan yang sama, l2 berisi semua elemen l yang tidak masuk ke
l1, dengan urutan kemunculan yang sama. */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l)) {
        *l1 = NULL;
        *l2 = NULL;
    } else {
        if (head(l) < x) {
            splitOnX(tail(l), x, l1, l2);
            *l1 = konso(*l1, head(l));
        } else {
            splitOnX(tail(l), x, l1, l2);
            *l2 = konso(*l2, head(l));
        }
    }
}

int compareList (List l1, List l2)
/* Menghasilkan: -1 jika l1 < l2, 0 jika l1 = l2, dan 1 jika l1 > l2 */
/* Jika l[i] adalah elemen l pada urutan ke-i dan |l| adalah panjang l: */
/* l1 = l2: |l1| = |l2| dan untuk semua i, l1[i] = l2[i] */
/* l1 < l2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari l1 dan l2, l1[i]<l2[i] atau: Jika pada semua elemen pada
urutan i yang sama, l1[i]=l2[i], namun |l1|<|l2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* l1>l2: kebalikan dari l1<l2 */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l1) && isEmpty(l2)) {
        return 0;
    } else if (isEmpty(l1) && !isEmpty(l2)) {
        return -1;
    } else if (!isEmpty(l1) && isEmpty(l2)) {
        return 1;
    } else if (head(l1) < head(l2)) {
        return -1;
    } else if (head(l1) > head(l2)) {
        return 1;
    } else {
        return compareList(tail(l1), tail(l2));
    }
}

boolean contain(List l, ElType x)
/* Menghasilkan true jika terdapat elemen x dalam l */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l)) {
        return false;
    } else if (head(l) == x) {
        return true;
    } else {
        return contain(tail(l), x);
    }
}

boolean isAllExist (List l1, List l2)
/* Menghasilkan true jika semua elemen dalam l1 terdapat dalam l2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika l1 kosong, maka hasilnya false. */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l1)) {
        return true;
    } else if (!contain(l2, head(l1))) {
        return false;
    } else {
        return isAllExist(tail(l1), l2);
    }
}