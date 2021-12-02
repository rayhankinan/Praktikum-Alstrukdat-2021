/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 1 September 2021
Topik Praktikum     : ADT Sederhana
Deskripsi           : Definisi fungsi dan prosedur ADT POINT
*/

#include <stdio.h>
#include <math.h>
#include "point.h"

#define PI acos(-1)

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    /* KAMUS */
    POINT P;

    /* ALGORITMA */
    Absis(P) = X;
    Ordinat(P) = Y;

    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
    /* KAMUS */
    float X, Y;

    /* ALGORITMA */
    scanf("%f %f", &X, &Y);
    *P = MakePOINT(X, Y);
}
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */    
{
    /* KAMUS */

    /* ALGORITMA */
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == (Ordinat(P2))));
}
boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}
boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
    /* KAMUS */

    /* ALGORITMA */
    return (Ordinat(P) == 0);
}
boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
    /* KAMUS */

    /* ALGORITMA */
    return (Absis(P) == 0);
}
int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
    /* KAMUS */
    int Q;

    /* ALGORITMA */
    if ((Absis(P) > 0) && (Ordinat(P) > 0)) {
        Q = 1;
    } else if ((Absis(P) < 0) && (Ordinat(P) > 0)) {
        Q = 2;
    } else if ((Absis(P) < 0) && (Ordinat(P) < 0)) {
        Q = 3;
    } else {
        Q = 4;
    }
    return Q;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */   
{
    /* KAMUS */

    /* ALGORITMA */
    P = MakePOINT(Absis(P) + 1, Ordinat(P));
    return P;
}           
POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
    /* KAMUS */

    /* ALGORITMA */
    P = MakePOINT(Absis(P), Ordinat(P) + 1);
    return P;
}
POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    /* KAMUS */

    /* ALGORITMA */
    P = MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY);
    return P;
}
POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
    /* KAMUS */

    /* ALGORITMA */
    if (SbX) {
        P = MakePOINT(Absis(P), -1 * Ordinat(P));
    } else {
        P = MakePOINT(-1 * Absis(P), Ordinat(P));
    }
    return P;
}
float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
    /* KAMUS */

    /* ALGORITMA */
    return sqrt((Absis(P) * Absis(P) + (Ordinat(P) * Ordinat(P))));
}
float Panjang (POINT P1, POINT P2)
/* Menghitung jarak dua point, yaitu antara P1 dengan P2 */
{
    /* KAMUS */

    /* ALGORITMA */
    return sqrt((Absis(P2) - Absis(P1)) * (Absis(P2) - Absis(P1)) + (Ordinat(P2) - Ordinat(P1)) * (Ordinat(P2) - Ordinat(P1)));
}
void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    /* KAMUS */

    /* ALGORITMA */
    *P = MakePOINT(Absis(*P) + deltaX, Ordinat(*P) + deltaY);
}
void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
    /* KAMUS */

    /* ALGORITMA */
    *P = MakePOINT(Absis(*P), 0);
}
void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
    /* KAMUS */

    /* ALGORITMA */
    *P = MakePOINT(0, Ordinat(*P));
}
void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
    /* KAMUS */

    /* ALGORITMA */
    *P = MirrorOf(*P, SbX);
}
void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
{
    /* KAMUS */
    float sudutRadian;

    /* ALGORITMA */
    sudutRadian = -1 * Sudut * PI / 180; /* Jika diputar searah jarum jam, sudut akan menjadi negatif */
    *P = MakePOINT(Absis(*P) * cos(sudutRadian) - Ordinat(*P) * sin(sudutRadian), Absis(*P) * sin(sudutRadian) + Ordinat(*P) * cos(sudutRadian)); 
}