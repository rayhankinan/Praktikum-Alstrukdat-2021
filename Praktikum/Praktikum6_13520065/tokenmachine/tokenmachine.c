/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 30 September 2021
Topik Praktikum     : ADT Mesin Kata
Deskripsi           : Definisi fungsi dan prosedur ADT Token
*/

#include "tokenmachine.h"

/* Token Machine State */
boolean endToken;
Token currentToken;

void ignoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    /* KAMUS */

    /* ALGORITMA */
    while (currentChar == BLANK && currentChar != MARK) {
        adv();
    }
}

void startToken()
/* I.S. : currentChar sembarang 
   F.S. : endToken = true, dan currentChar = MARK; 
          atau endToken = false, currentToken adalah Token yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir Token */
{
    /* KAMUS */

    /* ALGORITMA */
    start();
    ignoreBlank();

    if (currentChar == MARK) {
        endToken = true;
    } else {
        endToken = false;
        salinToken();
    }
}

void advToken()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentToken adalah Token terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, maka endToken = true		  
   Proses : Akuisisi kata menggunakan procedure salinToken */
{
    /* KAMUS */

    /* ALGORITMA */
    ignoreBlank();

    if (currentChar == MARK) {
        endToken = true;
    } else {
        salinToken();
        ignoreBlank(); // INI BERBEDA DENGAN TEMPLATE
    }
}

void salinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam currentToken
   I.S. : currentChar adalah karakter pertama dari Token
   F.S. : currentToken berisi Token yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata "dipotong" */
{
    /* KAMUS */
    int i;

    /* ALGORITMA */
    i = 0;

    currentToken.val = 0;
    while (currentChar != MARK && currentChar != BLANK) {
        if (i < CAPACITY) {
            if (currentChar >= '0' && currentChar <= '9') {
                currentToken.val = currentToken.val * 10 + (currentChar - 48);
                currentToken.tkn = 'b';
            } else {
                currentToken.val = -1;
                currentToken.tkn = currentChar;
            }
        }
        adv();
        i++;
    }
}