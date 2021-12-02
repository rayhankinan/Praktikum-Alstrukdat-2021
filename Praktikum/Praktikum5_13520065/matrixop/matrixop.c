/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 23 September 2021
Topik Praktikum     : ADT Matrix
Deskripsi           : Definisi fungsi dan prosedur ADT Matrix
*/

#include "matrix.h"

float rowMean(Matrix m, Index i) {
    /* KAMUS */
    float sum;
    Index j;

    /* ALGORITMA */
    sum = 0;

    for (j = 0; j < (Index) COLS(m); j++) {
        sum += (float) ELMT(m, i, j);
    }

    return sum / ((float) COLS(m));
}

float colMean(Matrix m, Index j) {
    /* KAMUS */
    float sum;
    Index i;

    /* ALGORITMA */
    sum = 0;

    for (i = 0; i < (Index) ROWS(m); i++) {
        sum += (float) ELMT(m, i, j);
    }

    return sum / ((float) ROWS(m));
}

void rowExtremes(Matrix m, Index i, ElType *max, ElType *min) {
    /* KAMUS */
    Index j;

    /* ALGORITMA */
    *max = ELMT(m, i, 0);
    *min = ELMT(m, i, 0);

    for (j = 1; j < (Index) COLS(m); j++) {
        if (ELMT(m, i, j) > *max) {
            *max = ELMT(m, i, j);
        }
        if (ELMT(m, i, j) < *min) {
            *min = ELMT(m, i, j);
        }
    }
}

void colExtremes(Matrix m, Index j, ElType *max, ElType *min) {
    /* KAMUS */
    Index i;

    /* ALGORITMA */
    *max = ELMT(m, 0, j);
    *min = ELMT(m, 0, j);

    for (i = 1; i < (Index) ROWS(m); i++) {
        if (ELMT(m, i, j) > *max) {
            *max = ELMT(m, i, j);
        }
        if (ELMT(m, i, j) < *min) {
            *min = ELMT(m, i, j);
        }
    }
}

int countValOnRow(Matrix m, Index i, ElType val) {
    /* KAMUS */
    Index j;
    int N;

    /* ALGORITMA */
    N = 0;

    for (j = 0; j < (Index) COLS(m); j++) {
        if (ELMT(m, i, j) == val) {
            N++;
        }
    }

    return N;
}

int countValOnCol(Matrix m, Index j, ElType val) {
    /* KAMUS */
    Index i;
    int N;

    /* ALGORITMA */
    N = 0;

    for (i = 0; i < (Index) ROWS(m); i++) {
        if (ELMT(m, i, j) == val) {
            N++;
        }
    }

    return N;
}