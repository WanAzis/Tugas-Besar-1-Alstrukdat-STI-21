#include <stdio.h>
#include <stdlib.h>
#include "RNG.h"

struct tm *Time;
time_t Tval;

void RNG(){
  Tval = time(NULL);
  Time = localtime(&Tval);
  int X = (Time->tm_hour + Time->tm_min + Time->tm_sec)%100;
  
  printf("Game RNG dimulai. Uji keberuntungan anda dengan menebak X. X bilangan 0 s.d 100\n");
  printf("Tebakan: "); STARTWORD();
  int tebak = 0;
  for (int i = 0; i<currentWord.Length; i++){
    tebak = (tebak * 10) + currentWord.TabWord[i] - '0';
  }
  while(tebak!=X){
    if (tebak<X){
      printf("X Lebih Besar\n");
    } else {
      printf("X Lebih Kecil\n");
    }
    tebak = 0;
    printf("Tebakan: "); STARTWORD();
    for (int i = 0; i<currentWord.Length; i++){
      tebak = (tebak * 10) + currentWord.TabWord[i] - '0';
    }
  }
  printf("Selamat, anda benar menebak X yaitu %i\n", X);
}
/* Game random number generator */
/* Cara kerja dari game ini adalah player harus menebak
   sebuah angka acak X yang sudah disiapkan oleh sistem.
   Setiap giliran menebak, sistem akan memberitahu apakah
   tebakan lebih kecil atau lebih besar terhadap X. Game akan
   selesai jika player dapat menebak angka dengan benar. */