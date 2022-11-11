#include <stdio.h>
#include <string.h>
#include "mesin_kata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
    while ((currentChar==BLANK || currentChar==NEWLINE) && currentChar!=MARK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(){
    START();
    if (pita != NULL){
        IgnoreBlanks();
        if (currentChar==MARK){
            EndWord=true;
        } else {
            EndWord=false;
            CopyWord();
        }
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTWORDFILE(char *FileName){
    STARTFILE(FileName);
    if (pita != NULL){
        IgnoreBlanks();
        if (currentChar==MARK){
            EndWord=true;
        } else {
            EndWord=false;
            CopyWord();
        }
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi dari file,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD(){
    IgnoreBlanks();
    if (currentChar==MARK){
        EndWord=true;
    } else{
        CopyWord();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord(){
    int i = 0;
    while (currentChar!=MARK && currentChar!=NEWLINE){
        if (i<NMax){
            currentWord.TabWord[i]=currentChar;
        }
        ADV(); i++;
    } 
    if (i<NMax) {
        currentWord.Length=i;
    } else {currentWord.Length=NMax;}
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void WordToString(Word Kata, char *s){
    for (int i = 0; i<Kata.Length; i++){
        s[i]=Kata.TabWord[i];
    } 
    for (int i = Kata.Length; i < strlen(s); i++) 
    {
        if (s[i] != '\0') {
            s[i] = '\0';
        }
    }
}
/* Proses : Menerima kata dalam bentuk Word lalu mengubahnya ke bentuk string
   I.S. : currentWord terdefinisi
   F.S. : terbentuk sebuah string s yang berisi char dari currentWord*/

boolean WordCompareString(Word Kata, char *s){
    boolean found = true;
    int i = 0;
    while (i<Kata.Length && found){
        if (Kata.TabWord[i]!=s[i]){
            found = false;
        }
        else {
            i++;
        }
    } return found;
}
/* Proses : Membandingkan kata dengan string, menghasilkan true jika sama 
   I.S. : Word terdefinisi, string juga terdefinisi
   F.S. : menghasilkan true jika kata sama dengan ripresentasinya pada string input */

void PrintKata(Word Kata){
    for (int i = 0; i<Kata.Length; i++){
        printf("%c", Kata.TabWord[i]);
    }
}
/* Proses : Menuliskan tipe bentukan kata ke layar
   I.S. : Word terdefinisi
   F.S. : kata yang disimpan dalam Word Kata tertulis di layar */