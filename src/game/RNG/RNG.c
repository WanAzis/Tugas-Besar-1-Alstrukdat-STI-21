#include <stdio.h>
#include <stdlib.h>
#include "RNG.h"

struct tm *Time;
time_t Tval;

void RNG(int* score){
  Tval = time(NULL);
  Time = localtime(&Tval);
  int X = (Time->tm_hour + Time->tm_min + Time->tm_sec)%100;
  int kesempatan = 20;
  
  printf("Game RNG dimulai. Uji keberuntungan anda dengan menebak X. X bilangan 0 s.d 100\n");
  printf("\nKesempatan menebak : %i\n", kesempatan);
  printf("Tebakan: "); STARTWORD();
  int tebak = 0;
  for (int i = 0; i<currentWord.Length; i++){
    tebak = (tebak * 10) + currentWord.TabWord[i] - '0';
  }
  while(tebak!=X && kesempatan>0){
    if (tebak<X){
      printf("X Lebih Besar\n");
    } else {
      printf("X Lebih Kecil\n");
    }
    tebak = 0; kesempatan--;
    printf("\nKesempatan menebak : %i\n", kesempatan);
    printf("Tebakan: "); STARTWORD();
    for (int i = 0; i<currentWord.Length; i++){
      tebak = (tebak * 10) + currentWord.TabWord[i] - '0';
    } if(tebak!=X){kesempatan--;}
  }
  if(tebak==X){
    printf("Selamat, anda benar menebak X yaitu %i\n", X);
  } else {
    printf("Yah sayang sekali, kesempatan-mu habis :(\n");
  }
  *score = kesempatan/2;
}
/* Game random number generator */
/* Cara kerja dari game ini adalah player harus menebak
   sebuah angka acak X yang sudah disiapkan oleh sistem.
   Setiap giliran menebak, sistem akan memberitahu apakah
   tebakan lebih kecil atau lebih besar terhadap X. Game akan
   selesai jika player dapat menebak angka dengan benar. */