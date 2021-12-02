#include "listrec.h"

int main() {
    /* KAMUS */
    int N;
    List l, l1, l2;
    ElType val, x;

    /* ALGORITMA */
    printf("Masukkan N: ");
    scanf("%d", &N);

    l = NULL;

    while (N > 0) {
        scanf("%d", &val);
        l = konsb(l, val);
        N--;
    }
    printf("\nHASIL EKSEKUSI:\n\n");

    printf("Original:\n");
    displayList(l);
    printf("\n");
    printf("Hasil inverseList:\n");
    displayList(inverseList(l));
    printf("\n");

    printf("Hasil splitPosNeg:\n");
    splitPosNeg(l, &l1, &l2);
    printf("Pos:\n");
    displayList(l1);
    printf("Neg:\n");
    displayList(l2);
    printf("\n");

    printf("Hasil splitOnX:\n");
    printf("Masukkan x: ");
    scanf("%d", &x);
    splitOnX(l, x, &l1, &l2);
    printf("Lebih kecil dari x:\n");
    displayList(l1);
    printf("Lebih besar sama dengan dari x:\n");
    displayList(l2);

    if (compareList(l1, l2) == -1) {
        printf("Compare -1 benar\n");
    }
    if (compareList(l, l) == 0) {
        printf("Compare 0 benar\n");
    }
    if (compareList(l2, l1) == 1) {
        printf("Compare 1 benar\n");
    }

    if (isAllExist(l1, l)) {
        printf("isAllExist awal benar\n");
    }
    if (isAllExist(l2, l)) {
        printf("isAllExist akhir benar\n");
    }
}