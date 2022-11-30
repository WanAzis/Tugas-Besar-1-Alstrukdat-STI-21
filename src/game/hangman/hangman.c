#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "hangman.h"
#include "time.h"

void Hangman(){
  array Answers = Makearray();
  STARTWORDFILE("answer.txt");
  if (pita != NULL){
    int loop=0;
    for (int i = 0; i<currentWord.Length; i++){
        loop = (loop*10) + currentWord.TabWord[i]-'0';
    } ADVSENTENCE ();
    while(loop--){
        InsertLast(&Answers, currentWord);
        ADVSENTENCE();
    }
  } 
  srand(time(NULL));
  int idx = rand() % 10;
  Word Jawaban = Answers.A[idx];
  Word Tebakan ;
  MakeTebakan(Jawaban, &Tebakan);
  Set SudahDitebak;
  CreateEmptyset(&SudahDitebak);

  int kesempatan = 10;
  while (kesempatan>0){
    printf("Tebakan sebelumnya : ");
    if(IsEmptyset(SudahDitebak)){
      printf("-\n");
    }
    else{
      PrintSet(SudahDitebak);
    }
    printf("Kata : "); PrintKata(Tebakan);
    printf("Kesempatan : %d\n", kesempatan);
    printf("Masukkan tebakan : "); STARTWORD();
    if(currentWord.Length!=1){
      printf("Input tidak valid \n");
    }
    else {
      if((currentWord.TabWord[0]>='a' && currentWord.TabWord[0]<='z') || (currentWord.TabWord[0]>='A' && currentWord.TabWord[0]<='Z')){
        CheckJawab(Jawaban, &Tebakan);
      }
      else{
        printf("Input tidak valid \n");
      }
    }
  }
}

void MakeTebakan(Word Jawaban, Word *Tebakan){
  (*Tebakan).Length = Jawaban.Length;
  for(int i=0; i<Jawaban.Length; i++){
    (*Tebakan).TabWord[i] = "_";
  }
}
