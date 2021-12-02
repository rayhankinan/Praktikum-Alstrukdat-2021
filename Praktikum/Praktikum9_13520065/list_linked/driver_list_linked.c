#include <stdio.h>
#include "list_linked.h"

int main() {
    /* KAMUS */
    ElType X;
    List L, LReversed, LCopy, L1, L2;

    /* ALGORITMA */
    CreateList(&L);

    do {
        scanf("%d", &X);
        if (X > 0) {
            insertLast(&L, X);
        }
    } while (X > 0);

    displayList(L);
    printf("\n");

    CreateList(&LReversed);
    LReversed = fInverseList(L);

    CreateList(&LCopy);
    LCopy = fCopyList(L);

    CreateList(&L1);
    CreateList(&L2);
    splitList(&L1, &L2, L);

    printf("\n");
    displayList(L);
    printf(" <-> ");
    displayList(LReversed);
    printf("\n");
    displayList(L);
    printf(" <-> ");
    displayList(L1);
    printf(" and ");
    displayList(L2);
    printf("\n");
}