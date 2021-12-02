/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 9 September 2021
Topik Praktikum     : ADT List
Deskripsi           : Mengecek apakah suatu ADT ListPos monotonik atau tidak
*/

#include <stdio.h>
#include "listpos.h"

int main() {
    /* KAMUS */
    int i, j, N;
    boolean isNonDesc, isNonAsc;
    ListPos L;

    /* ALGORITMA */
    readList(&L);
    
    N = length(L); /* Dipastikan N > 1 */

    isNonDesc = true;
    isNonAsc = true;

    for (i = 0; i < N; i++) {
        for (j = i; j < N ; j++) {
            if (ELMT(L, i) > ELMT(L, j)) {
                isNonDesc = false;
            }
            if (ELMT(L, i) < ELMT(L, j)) {
                isNonAsc = false;
            }
        }
    }

    if (isNonDesc && !isNonAsc) {
        printf("Non-descending Monotonic List\n");
    } else if (isNonAsc && !isNonDesc) {
        printf("Non-ascending Monotonic List\n");
    } else if (isNonDesc && isNonAsc) {
        printf("Static Monotonic List\n");
    } else {
        printf("Non-monotonic List\n");
    }
}