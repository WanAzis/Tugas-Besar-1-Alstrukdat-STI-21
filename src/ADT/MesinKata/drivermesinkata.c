#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mesin_kata.h"

int main(){
    // Driver membaca sebuah kata dari inputan user (stdin)
    // STARTWORD();
    // PrintKata(currentWord); printf("\n");
    // char CKata[50];
    // WordToString(currentWord, CKata);
    // printf("%s\n", CKata);
    // printf("%i\n", strlen(CKata));

    // Driver membaca sebuah path file dari inputan pengguna
    // printf("Masukkan nama file yang ingin di akses: ");
    // STARTWORD();
    // char *FName = (char*) malloc (sizeof(char) * currentWord.Length+1);
    // WordToString(currentWord, FName);
    // printf("%s\n", FName);
    // STARTWORDFILE(FName);
    // while(!EndWord){
    //     PrintKata(currentWord); printf("\n");
    //     ADVWORD();
    // }
    // STARTWORD();
    // if(WordCompareString(currentWord, "coba")){
    //     printf("kata sama, yaitu 'coba'\n");
    // }

    char string[] = "aku adalah kapiten";
    printf("Panjang string '%s' adalah : %i\n", string, strlen(string));
}

