#include "listrec.h"

List splitOddIndex(List l)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
ganjil pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l)) {
        return NULL;
    } else if (isOneElmt(l)) {
        return l;
    } else {
        return konso(splitOddIndex(tail(tail(l))), head(l));
    }
}

List splitEvenIndex(List l)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
genap pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l) || isOneElmt(l)) {
        return NULL;
    } else {
        return konso(splitEvenIndex(tail(tail(l))), head(tail(l)));
    }
}

List splitBeforeX(List l, ElType x)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen di depan elemen
dengan nilai x pada list l, sesuai dengan urutannya. Jika x tidak ada pada list, maka
kembalikan list l.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l) || (head(l) == x)) {
        return NULL;
    } else {
        return konso(splitBeforeX(tail(l), x), head(l));
    }
}

List reverseList(List l)
/* Mengembalikan sebuah list baru yang urutannya merupakan kebalikan dari list l.
Jika l kosong, kembalikan list kosong. */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l)) {
        return NULL;
    } else {
        return konsb(reverseList(tail(l)), head(l));
    }
}

int main() {
    /* KAMUS */
    char CC;
    List l;
    ElType k, x;

    /* ALGORITMA */
    l = NULL;
    do {
        scanf(" %c", &CC);

        switch (CC) {
            case 'F':
                scanf("%d", &k);
                l = konso(l, k);
                break;
            case 'B':
                scanf("%d", &k);
                l = konsb(l, k);
                break;
            case 'O':
                l = splitOddIndex(l);
                break;
            case 'E':
                l = splitEvenIndex(l);
                break;
            case 'R':
                l = reverseList(l);
                break;
            case 'P':
                scanf("%d", &x);
                l = splitBeforeX(l, x);
                break;
        }

    } while (CC != 'X');

    if (isEmpty(l)) {
        printf("Semua gugur\n");
    } else {
        displayList(l);
    }
}