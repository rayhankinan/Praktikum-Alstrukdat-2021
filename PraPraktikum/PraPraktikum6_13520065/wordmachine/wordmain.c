#include "wordmachine.h"
#include <stdio.h>

int main() {
    /* KAMUS */
    int i;

    /* ALGORITMA */
    startWord();

    while (!endWord) {
        printf("\"");
        for (i = 0; i < currentWord.length; i++) {
            printf("%c", currentWord.contents[i]);
        }
        printf("\"");
        printf("\n");
        advWord();
    }
}