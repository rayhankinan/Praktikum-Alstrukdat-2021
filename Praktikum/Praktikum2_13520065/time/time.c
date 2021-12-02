/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 1 September 2021
Topik Praktikum     : ADT Sederhana
Deskripsi           : Definisi fungsi dan prosedur ADT TIME
*/

#include <stdio.h>
#include "time.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S)
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59));
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
TIME MakeTIME (int HH, int MM, int SS)
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
{
    /* KAMUS */
    TIME T;

    /* ALGORITMA*/
    Hour(T) = HH;
    Minute(T) = MM;
    Second(T) = SS;

    return T;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T)
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */

{
    /* KAMUS */
    int h, m, s;

    /* ALGORITMA */
    do {
        scanf("%d %d %d", &h, &m, &s);
        if (!IsTIMEValid(h, m, s)) {
            printf("Jam tidak valid\n");
        }
    } while (!IsTIMEValid(h, m, s));
    *T = MakeTIME(h, m, s);
}

void TulisTIME (TIME T)
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
{
    /* KAMUS */

    /* ALGORITMA */
    printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T)
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    /* KAMUS */
    long jumlahDetik;

    /* ALGORITMA */
    jumlahDetik = 3600 * Hour(T) + 60 * Minute(T) + Second(T);
    return jumlahDetik;
}

TIME DetikToTIME (long N)
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
{
    /* KAMUS */
    TIME T;

    /* ALGORITMA */
    while (N < 0) N += 86400;
    T = MakeTIME((N % 86400) / 3600, (N % 3600) / 60, N % 60);
    return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1=T2, false jika tidak */
{
    /* KAMUS */

    /* ALGORITMA */
    return (TIMEToDetik(T1) == TIMEToDetik(T2));
}
boolean TNEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1 tidak sama dengan T2 */
{
    /* KAMUS */

    /* ALGORITMA */
    return (TIMEToDetik(T1) != TIMEToDetik(T2));
}
boolean TLT (TIME T1, TIME T2)
/* Mengirimkan true jika T1<T2, false jika tidak */
{
    /* KAMUS */

    /* ALGORITMA */
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}
boolean TGT (TIME T1, TIME T2)
/* Mengirimkan true jika T1>T2, false jika tidak */
{
    /* KAMUS */

    /* ALGORITMA */
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
}

/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T)
/* Mengirim 1 detik setelah T dalam bentuk TIME */
{
    /* KAMUS */
    TIME T1;

    /* ALGORITMA */
    T1 = DetikToTIME(TIMEToDetik(T) + 1);
    return T1;
}
TIME NextNDetik (TIME T, int N)
/* Mengirim N detik setelah T dalam bentuk TIME */
{
    /* KAMUS */
    TIME Tn;

    /* ALGORITMA */
    Tn = DetikToTIME(TIMEToDetik(T) + N);
    return Tn;
}
TIME PrevDetik (TIME T)
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
{
    /* KAMUS */
    TIME T1;

    /* ALGORITMA */
    T1 = DetikToTIME(TIMEToDetik(T) - 1);
    return T1;
}
TIME PrevNDetik (TIME T, int N)
/* Mengirim N detik sebelum T dalam bentuk TIME */
{
    /* KAMUS */
    TIME Tn;

    /* ALGORITMA */
    Tn = DetikToTIME(TIMEToDetik(T) - N);
    return Tn;
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh)
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
{
    /* KAMUS */
    long deltaS;

    /* ALGORITMA */
    if (TIMEToDetik(TAw) > TIMEToDetik(TAkh)) deltaS = 86400 + TIMEToDetik(TAkh) - TIMEToDetik(TAw);
    else deltaS = TIMEToDetik(TAkh) - TIMEToDetik(TAw);
    return deltaS;
}