/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 20/09/2021
Topik Praktikum     : ADT Matrix
Deskripsi           : Definisi fungsi dan prosedur ADT Matrix
*/

#include <stdio.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    /* KAMUS */

    /* ALGORITMA*/
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
{
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    /* KAMUS */

    /* ALGORITMA */
    return (Index) (ROWS(m) - 1);
}
Index getLastIdxCol(Matrix m)
/* Mengirimkan Index kolom terbesar m */
{
    /* KAMUS */

    /* ALGORITMA */
    return (Index) (COLS(m) - 1);
}
boolean isIdxEff(Matrix m, Index i, Index j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i <= getLastIdxRow(m) && j >= 0 && j <= getLastIdxCol(m));
}
ElType getElmtDiagonal(Matrix m, Index i)
/* Mengirimkan elemen m(i,i) */
{
    /* KAMUS */

    /* ALGORITMA */
    return (ELMT(m, i, i));
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes)
/* Melakukan assignment MRes = MIn */
{
    /* KAMUS */
    Index i, j;

    /* ALGORITMA */
    CreateMatrix(ROWS(mIn), COLS(mIn), mRes);

    for (i = 0; i <= getLastIdxRow(mIn); i++) {
        for (j = 0; j <= getLastIdxCol(mIn); j++){
            ELMT(*mRes, i, j) = ELMT(mIn, i, j); 
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    /* KAMUS */
    Index i, j;

    /* ALGORITMA */
    CreateMatrix(nRow, nCol, m);

    for (i = 0; i <= getLastIdxRow(*m); i++) {
        for (j = 0; j <= getLastIdxCol(*m); j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}
void displayMatrix(Matrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    /* KAMUS */
    Index i, j;

    /* ALGORITMA */
    for (i = 0; i <= getLastIdxRow(m); i++) {
        for (j = 0; j <= getLastIdxCol(m); j++) {
            if (j < getLastIdxCol(m)) {
                printf("%d ", ELMT(m, i, j));
            } else {
                printf("%d", ELMT(m, i, j));
            }
        }
        if (i < getLastIdxRow(m)){
            printf("\n");
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
{
    /* KAMUS */
    Index i, j;
    Matrix m;

    /* ALGORITMA */
    CreateMatrix(ROWS(m1), COLS(m1), &m);

    for (i = 0; i <= getLastIdxRow(m); i++) {
        for (j = 0; j <= getLastIdxCol(m); j++) {
            ELMT(m, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    
    return m;
}
Matrix subtractMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
{
    /* KAMUS */
    Index i, j;
    Matrix m;

    /* ALGORITMA */
    CreateMatrix(ROWS(m1), COLS(m1), &m);

    for (i = 0; i <= getLastIdxRow(m); i++) {
        for (j = 0; j <= getLastIdxCol(m); j++) {
            ELMT(m, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    
    return m;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
{
    /* KAMUS */
    Index i, j, k;
    Matrix m;

    /* ALGORITMA */
    CreateMatrix(ROWS(m1), COLS(m2), &m);

    for (i = 0; i <= getLastIdxRow(m); i++) {
        for (j = 0; j <= getLastIdxCol(m); j++) {
            ELMT(m, i, j) = 0;
            for (k = 0; k <= getLastIdxCol(m1); k++) {
                ELMT(m, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }

    return m;
}
Matrix multiplyConst(Matrix m, ElType x)
/* Mengirim hasil perkalian setiap elemen m dengan x */
{
    /* KAMUS */
    Index i, j;
    Matrix mHasil;

    /* ALGORITMA */
    CreateMatrix(ROWS(m), COLS(m), &mHasil);

    for (i = 0; i <= getLastIdxRow(mHasil); i++) {
        for (j = 0; j <= getLastIdxCol(mHasil); j++) {
            ELMT(mHasil, i, j) = x * ELMT(m, i, j);
        }
    }

    return mHasil;
}
void pMultiplyConst(Matrix *m, ElType k)
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
{
    /* KAMUS */

    /* ALGORITMA */
    copyMatrix(multiplyConst(*m, k), m);
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
{
    /* KAMUS */
    Index i, j;
    boolean hasil;

    /* ALGORITMA */
    hasil = true;

    if (!isSizeEqual(m1, m2)) {
        hasil = false;
    } else {
        i = 0;
        while ((i <= getLastIdxRow(m1)) && hasil) {
            j = 0;
            while ((j <= getLastIdxCol(m1)) && hasil) {
                hasil = (ELMT(m1, i, j) == ELMT(m2, i, j));
                j++;
            }
            i++;
        }
    }

    return hasil;
}
boolean isNotEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 tidak sama dengan m2 */
{
    /* KAMUS */

    /* ALGORITMA */
    return (!isEqual(m1, m2));
}
boolean isSizeEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((getLastIdxRow(m1) == getLastIdxRow(m2)) && (getLastIdxCol(m1) == getLastIdxCol(m2)));
}

/* ********** Operasi lain ********** */
int count(Matrix m)
/* Mengirimkan banyaknya elemen m */
{
    /* KAMUS */

    /* ALGORITMA */
    return (ROWS(m) * COLS(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
{
    /* KAMUS */

    /* ALGORITMA */
    return (ROWS(m) == COLS(m));
}
boolean isSymmetric(Matrix m)
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
{
    /* KAMUS */
    Index i, j;
    boolean hasil;

    /* ALGORITMA */
    hasil = true;

    if (!isSquare(m)) {
        hasil = false;
    } else {
        i = 0;
        while ((i <= getLastIdxRow(m)) && hasil) {
            j = 0;
            while ((j <= getLastIdxCol(m)) && hasil) {
                hasil = (ELMT(m, i, j) == ELMT(m, j, i));
                j++;
            }
            i++;
        }
    }

    return hasil;
}
boolean isIdentity(Matrix m)
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    /* KAMUS */
    Index i, j;
    boolean hasil;

    /* ALGORITMA */
    hasil = true;

    if (!isSquare(m)) {
        hasil = false;
    } else {
        i = 0;
        while ((i <= getLastIdxRow(m)) && hasil) {
            j = 0;
            while ((j <= getLastIdxCol(m)) && hasil) {
                hasil = ((i != j || ELMT(m, i, j) == 1) && (i == j || ELMT(m, i, j) == 0));
                j++;
            }
            i++;
        }
    }

    return hasil;
}
boolean isSparse(Matrix m)
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    /* KAMUS */
    Index i, j;
    double maksMemory, curMemory;

    /* ALGORITMA */
    maksMemory = ((double) count(m)) * 0.05;
    curMemory = 0;

    i = 0;
    while ((i <= getLastIdxRow(m)) && (curMemory <= maksMemory)) {
        j = 0;
        while ((j <= getLastIdxCol(m)) && (curMemory <= maksMemory)) {
            if (ELMT(m, i, j) != 0) {
                curMemory += 1;
            }
            j++;
        }
        i++;
    }

    return (curMemory <= maksMemory);
}
Matrix inverse1(Matrix m)
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    /* KAMUS */

    /* ALGORITMA */
    return multiplyConst(m, -1);
}
void pInverse1(Matrix *m)
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    /* KAMUS */

    /* ALGORITMA */
    pMultiplyConst(m, -1);
}
float cofactor(Matrix m, Index a, Index b)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai kofaktor m pada baris i dan kolom j */
{
    /* KAMUS */
    Index i, j, iHasil, jHasil;
    Matrix mHasil;
    float hasil;

    /* ALGORITMA */
    hasil = 0;
    CreateMatrix(ROWS(m) - 1, COLS(m) - 1, &mHasil);

    iHasil = 0;
    for (i = 0; i <= getLastIdxRow(m); i++) {
        jHasil = 0;
        for (j = 0; j <= getLastIdxCol(m); j++) {
            if (i == a) {
                iHasil = i - 1;
            } else if (j == b) {
                jHasil = j - 1;
            } else {
                ELMT(mHasil, iHasil, jHasil) = ELMT(m, i, j);
            }
            jHasil++;
        }
        iHasil++;
    }

    if ((a + b) % 2 == 0) {
        hasil = determinant(mHasil);
    } else {
        hasil = -1 * determinant(mHasil);
    }

    return hasil;
}
float determinant(Matrix m)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
{
    /* KAMUS */
    Index i, j;
    float hasil;

    /* ALGORITMA */
    hasil = 0;

    if (count(m) == 1) { /* Dikarenakan matriks persegi maka tidak perlu membuat matriks baru */
        hasil = (float) ELMT(m, 0, 0);
    } else {
        i = 0;
        for (j = 0; j <= getLastIdxCol(m); j++) {
            hasil += ((float) ELMT(m, i, j)) * cofactor(m, i, j);
        }
    }

    return hasil;
}
void transpose(Matrix *m)
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    /* KAMUS */
    Index i, j;
    ElType temp;

    /* ALGORITMA */

    for (i = 0; i <= getLastIdxRow(*m); i++) { /* Dikarenakan matriks persegi maka tidak perlu membuat matriks baru */
        for (j = i; j <= getLastIdxCol(*m); j++) {
            temp = ELMT(*m, i, j);
            ELMT(*m, i, j) = ELMT(*m, j, i);
            ELMT(*m, j, i) = temp;
        }
    }
}