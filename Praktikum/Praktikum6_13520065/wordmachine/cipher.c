/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 30 September 2021
Topik Praktikum     : ADT Mesin Kata
Deskripsi           : Driver ADT Mesin Kata untuk melakukan caesar cipher
*/

#include <stdio.h>
#include "wordmachine.h"

char geser(char c, int x) {
    return ((c - 'A' + x) % ('Z' - 'A' + 1)) + 'A';
}

int main() {
    /* KAMUS */
    int i, N;

    /* ALGORITMA */
    startWord();
    N = currentWord.length;

    while (!endWord) {
        for (i = 0; i < currentWord.length; i++) {
            printf("%c", geser(currentWord.contents[i], N));
        }

        if (currentChar == MARK) {
            printf("%c", MARK);
        } else {
            printf(" ");
        }
        advWord();
    }
    printf("\n");
}