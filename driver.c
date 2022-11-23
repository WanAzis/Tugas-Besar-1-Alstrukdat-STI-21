#include <stdio.h>
#include "src/implementasiadt.c"
#include "mesin_karakter.h"
#include "mesin_karakter.c"
#include "mesin_kata.h"
#include "mesin_kata.c"
array ListGame;
Queue QueueGame;
Stack HistoryGame;
arraymap ScoreBoardGame;

void LOADBNMO(char *fname){
  ListGame = Makearray(); CreateQueue(&QueueGame);
  CreateEmptystack(&HistoryGame); ScoreBoardGame = Makearraymap();
  Stack awal; CreateEmptystack(&awal);
  char file[25] = "../data/";
  ConcatString(file, fname);
  STARTWORDFILE(file);
  if (pita != NULL){
    int loop=0;
    for (int i = 0; i<currentWord.Length; i++){
      loop = (loop*10) + currentWord.TabWord[i]-'0';
    }
    ADVWORD();
    while(loop--){
      InsertLast(&ListGame, currentWord);
      ADVWORD();
    } loop=0;
    for (int i = 0; i<currentWord.Length; i++){
      loop = (loop*10) + currentWord.TabWord[i]-'0';
    }
    ADVWORD();
    while(loop--){
      Push(&awal, currentWord);
      ADVWORD();
    } HistoryGame = Reversestack(&awal);
    keytype k; valuetype v; Map m;
    for (int j = 0; j<ListGame.Neff; j++){
      loop=0; CreateEmptymap(&m);
      for (int i = 0; i<currentWord.Length; i++){
        loop = (loop*10) + currentWord.TabWord[i]-'0';
      }
      while(loop--){
        ADVWORD(); k = currentWord;  // GANTI
        PrintKata(k); //HAPUS
        // ADVWORD2(); v = 0; // PrintKata(currentWord);
        for (int i = 0; i<currentWord.Length; i++){
          v = (v*10) + currentWord.TabWord[i]-'0';
        }
        Insertmap(&m, k, 0); //GANTI
      } InsertLastarrmap(&ScoreBoardGame,m); ADVWORD();
    }
  } else {
    printf("\n"); mode = 0;
  }
}

int main(){
    // MULAI UNTUK TEST MESIN KATA
    // int loop = 5;
    // while (loop--){
    //     STARTWORD();
    //     PrintKata(currentWord);
    //     while(!IsEOP()){
    //         ADVSENTENCE(); PrintKata(currentWord);
    //     } printf("\n");
    // }

    // TAHAP PENGETESAN MESIN KALIMAT
    // STARTSENTENCE(); PrintKata(currentWord);

    // PENGETESAN PROSEDUR UNTUK MEMBACA FILE

}
