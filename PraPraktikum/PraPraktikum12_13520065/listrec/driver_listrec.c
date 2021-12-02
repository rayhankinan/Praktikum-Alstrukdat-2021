#include "listrec.h"

int main() {
    /* KAMUS */
    List l1, l2, l3;

    /* ALGORITMA */
    l1 = newNode(0);
    l1 = konso(l1, 1);
    l1 = konso(l1, 2);
    l1 = konso(l1, 3);
    l1 = konso(l1, 4);
    l1 = konso(l1, 5);

    printf("l1 (%d):\n", length(l1));
    displayList(l1);
    printf("\n");

    l2 = newNode(0);
    l2 = konsb(l2, 1);
    l2 = konsb(l2, 2);
    l2 = konsb(l2, 3);
    l2 = konsb(l2, 4);
    l2 = konsb(l2, 5);

    printf("l2 (%d):\n", length(l2));
    displayList(l2);
    printf("\n");

    l3 = NULL;
    if (isOneElmt(l3)) {
        printf("l3 hanya mengandung 1 elemen!\n");
        displayList(l3);
        printf("\n");
    }
    else if (isEmpty(l3)) {
        printf("l3 tidak mengandung elemen!\n");
        displayList(l3);
        printf("\n");
    } else {
        printf("l3 mengandung lebih dari 1 elemen!\n");
        displayList(l3);
        printf("\n");
    }
}