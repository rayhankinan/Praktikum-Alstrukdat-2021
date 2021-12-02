#include <stdio.h>
#include "list_circular.h"

int main() {
    /* KAMUS */
    List l;
    ElType val;

    /* ALGORITMA */
    CreateList(&l);
    displayList(l);
    printf("\n");

    if (addrSearch(l, search(l, 0))) {
        printf("FOUND: %d\n", INFO(search(l, 0)));
    }

    insertLast(&l, 3);
    displayList(l);
    printf("\n");

    insertLast(&l, 2);
    displayList(l);
    printf("\n");

    insertLast(&l, 1);
    displayList(l);
    printf("\n");

    insertFirst(&l, 4);
    displayList(l);
    printf("\n");

    insertFirst(&l, 5);
    displayList(l);
    printf("\n");

    if (addrSearch(l, search(l, 0))) {
        printf("FOUND: %d\n", INFO(search(l, 0)));
    }

    if (addrSearch(l, search(l, 1))) {
        printf("FOUND: %d\n", INFO(search(l, 1)));
    }

    if (addrSearch(l, search(l, 2))) {
        printf("FOUND: %d\n", INFO(search(l, 2)));
    }

    if (addrSearch(l, search(l, 3))) {
        printf("FOUND: %d\n", INFO(search(l, 3)));
    }

    if (addrSearch(l, search(l, 4))) {
        printf("FOUND: %d\n", INFO(search(l, 4)));
    }

    if (addrSearch(l, search(l, 5))) {
        printf("FOUND: %d\n", INFO(search(l, 5)));
    }

    deleteLast(&l, &val);
    displayList(l);
    printf("\n");

    deleteLast(&l, &val);
    displayList(l);
    printf("\n");

    deleteLast(&l, &val);
    displayList(l);
    printf("\n");

    deleteFirst(&l, &val);
    displayList(l);
    printf("\n");

    deleteFirst(&l, &val);
    displayList(l);
    printf("\n");
}