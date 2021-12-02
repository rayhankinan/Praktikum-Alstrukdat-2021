/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 25 November 2021
Topik Praktikum     : ADT Binary Tree
Deskripsi           : Realisasi fungsi invert binary tree
*/

#include "bintree.h"

void invertBtree(BinTree *p)
/* I.S. Pohon p terdefinisi */
/* F.S. Pohop p diflip secara vertikal*/
{
    /* KAMUS */
    BinTree temp;

    /* ALGORITMA */
    if (!isTreeEmpty(*p)) {
        temp = LEFT(*p);
        LEFT(*p) = RIGHT(*p);
        RIGHT(*p) = temp;
        
        invertBtree(&LEFT(*p));
        invertBtree(&RIGHT(*p));
    }
}