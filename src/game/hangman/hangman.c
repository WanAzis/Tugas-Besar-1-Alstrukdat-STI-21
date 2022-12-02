#include <stdio.h>
#include <stdlib.h>
#include "hangman.h"

/* Fungsi utama game */
void Hangman(int* Score){
  /* Akses file konfigurasi jawaban */
  array Answers = Makearray();
  STARTWORDFILE("../data/answerhm.txt");
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

  /* Persiapan permainan */
  srand(time(NULL));
  Set SudahDitebak; CreateEmptyset(&SudahDitebak); //List huruf yang sudah ditebak
  boolean found;
  int kesempatan = 10, score=0;
  Word Jawaban, Tebakan;
  generateKata(&Answers,&Jawaban); MakeTebakan(Jawaban, &Tebakan); 

  /* Memulai permainan */
  printf("\n======SELAMAT DATANG DI GAME HANGMAN======\n");
  printf("   UJI KEAHLIAN-MU DENGAN MENEBAK KATA!\n");
  printf(" SELAMAT BERMAIN DAN SEMOGA BERUNTUNG!! :)\n\n");
  printf("-------------------------------------------\n");

  while (kesempatan>0){
    if (WordCompare(Jawaban,Tebakan)){
      printf("\nSelamat kamu berhasil menebak "); PrintKata(Jawaban); printf("! Kamu mendapatkan %i point!\n", Tebakan.Length); score+=Tebakan.Length;
      CreateEmptyset(&SudahDitebak); generateKata(&Answers,&Jawaban);
      MakeTebakan(Jawaban,&Tebakan);
    }
    else {
      printf("\nHINT : KATA MERUPAKAN KOTA TERKENAL DI INDONESIA!\n");
      printf("Tebakan sebelumnya :");
      if(IsEmptyset(SudahDitebak)){
        printf("-\n");
      }
      else{PrintSet(SudahDitebak);}
 
      printf("Kata :"); PrintKata(Tebakan); printf("\n");
      printf("Kesempatan : %i\n", kesempatan);
      printf("Masukkan tebakan : "); STARTWORD();
      if(currentWord.Length!=1){
        printf("\nInput tidak valid! Silahkan input tebakan ulang!\n");
      }
      else {
        if((currentWord.TabWord[0]>='A' && currentWord.TabWord[0]<='Z')){
          if(!IsMemberset(SudahDitebak,currentWord.TabWord[0])){
            Insertset(&SudahDitebak,currentWord.TabWord[0]);
            found = CheckJawab(Jawaban, &Tebakan, currentWord);
            if(!found){
              kesempatan--;
            }
          } else {
            printf("\nHuruf sudah pernah ditebak! Silahkan input tebakan ulang!\n");
          }

        }
        else{
          printf("\nInput tidak valid! Silahkan input tebakan ulang!\n");
        }
      }
    }
  } *Score = score;
  printf("GameOver! Kesempatan-mu sudah habis!\n");
}

/* Menyiapkan Word Tebakan */
void MakeTebakan(Word Jawaban, Word *Tebakan){
  (*Tebakan).Length = Jawaban.Length;
  for(int i=0; i<Jawaban.Length; i++){
    (*Tebakan).TabWord[i] = '_';
  }
}

/* Mengecek apakah input terdapat dalam Jawaban */
boolean CheckJawab(Word Jawaban, Word* Tebakan, Word input){
  boolean found = false;
  for(int i = 0; i<Jawaban.Length; i++){
    if (input.TabWord[0]==Jawaban.TabWord[i]){
      found = true;
      (*Tebakan).TabWord[i]=Jawaban.TabWord[i];
    }
  } return found;
}

/* Men-generate kata baru dari array */
void generateKata(array* arr, Word* Jawaban){
  int idx = rand() % (*arr).Neff;
  *Jawaban = (*arr).A[idx];
  DeleteAt(arr,idx);
}