#include <stdio.h>
#include <stdlib.h>
#include "hangman.h"

int mode;
array Answers;

/* Fungsi utama game */
void Hangman(int* Score){
  /* Pemilihan Mode permainan */
  PilihMode(&mode);
  while (mode!=0){
    if (mode==2){
      /* Akses file konfigurasi jawaban */
      Answers = Makearray();
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
          if((currentWord.TabWord[0]>='A' && currentWord.TabWord[0]<='Z') || (currentWord.TabWord[0]>='a' && currentWord.TabWord[0]<='z')){
            if(currentWord.TabWord[0]>='a' && currentWord.TabWord[0]<='z'){currentWord.TabWord[0]-=32;}
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
    } else if (mode==1){
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
      printf("Silahkan input nama kota baru untuk dimasukkan kedalam dictionary (PASTIKAN SEMUA HURUF ADALAH KAPITAL) : "); STARTWORD();
      if (!IsMemberarr(Answers,currentWord)){
        InsertLast(&Answers,currentWord);
        saveDictionary(Answers);
        printf("Kata berhasil dimasukkan kedalam dictionary!\n");
      } else {printf("Kota sudah terdapat dalam dictionary, silahkan masukkan kota lain!\n");}
    } else {printf("Masukkan mode yang benar!\n");}
    PilihMode(&mode);
  }
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

/* Prosedure memilih mode */
void PilihMode(int* mode){
  // system("cls");
  printf("\nMode game yang tersedia: \n0.Exit\n1.In-game dictionary\n2.Play Hangman\n"); 
  printf("Silahkan masukkan mode : "); STARTWORD();
  if(WordCompareString(currentWord, "1") && currentWord.Length==1){
    *mode=1;
  } else if (WordCompareString(currentWord, "2") && currentWord.Length==1){
    *mode=2;
  } else if (WordCompareString(currentWord, "0") && currentWord.Length==1){
    *mode=0;
  } else {
    printf("Masukkan mode yang benar!\n\n");
  }
}

/* Menyimpan dictionary kedalam file */
void saveDictionary(array arr){
  FILE *fp = fopen("../data/answerhm.txt", "w");
  fprintf(fp, "%d\n", arr.Neff);
  char *ftulis = (char*) malloc (sizeof(char) * currentWord.Length+1);
  for(int i=0; i<arr.Neff; i++){
    WordToString(arr.A[i], ftulis);
    fprintf(fp, "%s\n", ftulis);
  }
  fprintf(fp, ";");
  fclose(fp);
}