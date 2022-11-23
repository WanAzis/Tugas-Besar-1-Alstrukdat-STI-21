#include <stdio.h>
#include "mesin_karakter.h"
#include "mesin_karakter.c"
#include "mesin_kata.h"
#include "mesin_kata.c"
#include "src/implementasiadt.c"
array ListGame;
Queue QueueGame;
Stack HistoryGame;
arraymap ScoreBoardGame;

void LOADBNMO(char *fname){
  ListGame = Makearray(); CreateQueue(&QueueGame);
  CreateEmptystack(&HistoryGame); ScoreBoardGame = Makearraymap();
  Stack awal; CreateEmptystack(&awal);
  char file[25] = "data/";
  ConcatString(file, fname);
  STARTWORDFILE(file);
  if (pita != NULL){
    int loop=0;
    for (int i = 0; i<currentWord.Length; i++){
      loop = (loop*10) + currentWord.TabWord[i]-'0';
    } PrintKata(currentWord); printf("\n");//HAPUS 
    ADVSENTENCE(); //GANTI
    while(loop--){
      PrintKata(currentWord); printf("\n");//HAPUS
      InsertLast(&ListGame, currentWord);
      ADVSENTENCE(); //GANTI
    } loop=0;
    for (int i = 0; i<currentWord.Length; i++){
      loop = (loop*10) + currentWord.TabWord[i]-'0';
    } printf("%i\n", loop); //HAPUS
    ADVSENTENCE(); PrintKata(currentWord); printf("\n");//HAPUS
    while(loop--){
      Push(&awal, currentWord);
      ADVSENTENCE(); PrintKata(currentWord); printf("\n");//HAPUS
    } HistoryGame = Reversestack(&awal);
    keytype k; valuetype v; Map m;
    for (int j = 0; j<ListGame.Neff; j++){
      loop=0; CreateEmptymap(&m);
      for (int i = 0; i<currentWord.Length; i++){
        loop = (loop*10) + currentWord.TabWord[i]-'0';
      } printf("%i\n", loop); //HAPUS
      while(loop--){
        ADVWORD(); k = currentWord;  // GANTI
        PrintKata(currentWord); //HAPUS
        ADVWORD(); v = 0; printf(" ");
        for (int i = 0; i<currentWord.Length; i++){
          v = (v*10) + currentWord.TabWord[i]-'0';
        } printf("%i",v); printf(" ");
        Insertmap(&m, k, v); //GANTI
      } InsertLastarrmap(&ScoreBoardGame,m); ADVSENTENCE();
    }
  } else {
    printf("\n"); 
    // mode = 0;
  }
}

int main(){
    // MULAI UNTUK TEST MESIN KATA
    // int loop = 5;
    // while (loop--){
    //     STARTWORD();
    //     PrintKata(currentWord);
    //     ADVWORD(); PrintKata(currentWord);
    //     while(!IsEOP()){
    //         ADVSENTENCE(); PrintKata(currentWord);
    //     } printf("\n");
    // }

    // TAHAP PENGETESAN MESIN KALIMAT
    // STARTSENTENCE(); PrintKata(currentWord);

    // PENGETESAN PROSEDUR UNTUK MEMBACA FILE
    char fname[50];
    STARTWORD(); WordToString(currentWord, fname);
    LOADBNMO(fname); 
    Printarray(ListGame);
    CetakStack(HistoryGame);
    Printarraymap(ScoreBoardGame);

}
