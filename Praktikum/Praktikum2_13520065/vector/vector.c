/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 1 September 2021
Topik Praktikum     : ADT Sederhana
Deskripsi           : Definisi fungsi dan prosedur ADT VECTOR
*/

#include <stdio.h>
#include "vector.h"
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
VECTOR MakeVector(float x, float y)
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */
{
    /* KAMUS */
    VECTOR V;

    /* ALGORITMA */
    AbsisComponent(V) = x;
    OrdinatComponent(V) = y;
    return V;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v)
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */
{
    /* KAMUS */

    /* ALGORITMA */
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v)
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
{
    /* KAMUS */
    POINT p;

    /* ALGORITMA */
    p = MakePOINT(AbsisComponent(v), OrdinatComponent(v));
    return Jarak0(p);
}
VECTOR Add(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
{
    /* KAMUS */
    VECTOR c;

    /* ALGORITMA */
    c = MakeVector(AbsisComponent(a) + AbsisComponent(b), OrdinatComponent(a) + OrdinatComponent(b));
    return c;
}
VECTOR Substract(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
{
    /* KAMUS */
    VECTOR c;

    /* ALGORITMA */
    c = MakeVector(AbsisComponent(a) - AbsisComponent(b), OrdinatComponent(a) - OrdinatComponent(b));
    return c;
}
float Dot(VECTOR a, VECTOR b)
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
{
    /* KAMUS */

    /* ALGORITMA */
    return AbsisComponent(a) * AbsisComponent(b) + OrdinatComponent(a) * OrdinatComponent(b);
}
VECTOR Multiply(VECTOR v, float s)
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * a.x, s * a.y) */
{
    /* KAMUS */
    VECTOR c;

    /* ALGORITMA */
    c = MakeVector(s * AbsisComponent(v), s * OrdinatComponent(v));
    return c;
}