#include "bintree.h"
#include <stdio.h>

int main() {
    /* KAMUS */
    BinTree p;

    /* ALGORITMA */
    p = NewTree(1, NewTree(2, NewTree(3, NULL, NULL), NewTree(4, NULL, NULL)), NewTree(5, NewTree(6, NULL, NULL), NewTree(7, NULL, NULL)));

    /*printPreorder(p);
    printf("\n");

    printInorder(p);
    printf("\n");

    printPostorder(p);
    printf("\n");*/

    printTree(p, 4);
    invertBtree(&p);
    printTree(p, 4);
}