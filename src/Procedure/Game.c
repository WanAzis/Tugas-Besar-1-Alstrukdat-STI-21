#include <stdio.h>
#include "Game.h"

void RNG(){
  struct tm *Time;
  time_t Tval;
  Tval = time(NULL);
  Time = localtime(&Tval);
  int X = (Time->tm_hour + Time->tm_min + Time->tm_sec)%100;
  
  printf("Game RNG dimulai. Uji keberuntungan anda dengan menebak X. X bilangan 0 s.d 100\n");
  int tebak; printf("Tebakan: "); scanf("%i", &tebak);
  while(tebak!=X){
    if (tebak<X){
      printf("X Lebih Besar\n");
    } else {
      printf("X Lebih Kecil\n");
    }
    printf("Tebakan: "); scanf("%i", &tebak);
  }
  printf("Selamat, anda benar menebak X yaitu %i\n", X);
}
/* Game random number generator */
/* Cara kerja dari game ini adalah player harus menebak
   sebuah angka acak X yang sudah disiapkan oleh sistem.
   Setiap giliran menebak, sistem akan memberitahu apakah
   tebakan lebih kecil atau lebih besar terhadap X. Game akan
   selesai jika player dapat menebak angka dengan benar. */

void Diner_Dash(){
  
}
/* Game mengantar makanan */
/* Adapun peraturan pada game ini adalah: 
    - Terdapat 2 command yang dapat dilakukan pada game, yaitu COOK dan SERVE.
      COOK merupakan command yang bertujuan untuk memasak dan SERVE adalah
      command untuk menyajikan makanan kepada pelanggan 
    - Permainan dimulai dengan 3 pelanggan dimana pelanggan akan bertambah satu pada 
      setiap putaran. Setiap pelanggan hanya dapat memesan satu makanan. Untuk setiap makanan, 
      terdapat informasi tentang ID makanan yang dihasilkan secara increment (M01, M02, M03, dst), 
      durasi memasak, harga makanan, serta ketahanan makanan. Semua informasi tersebut akan didapatkan 
      secara random dengan menggunakan random number generator. Durasi dan ketahanan 
      makanan akan berkisar diantara 1-5. Sedangkan, harga makanan akan berkisar diantara 10000 - 50000
    - Kapasitas dari pemain adalah memasak 5 makanan dalam waktu yang sama. 
      Pelanggan yang dilayani adalah pelanggan yang duluan memasuki antrian
    - Permainan selesai apabila antrian melebihi 7 pelanggan atau jumlah pelanggan yang sudah 
      dilayani mencapai 15 pelanggan
    - Pada setiap putaran, seluruh durasi dari makanan yang sedang dimasak akan berkurang 1. 
      Ketika durasi makanan mencapai 0, maka makanan sudah dapat di SERVE
    - Ketika makanan sudah di SERVE, maka makanan dapat diantar kepada pelanggan dan pelanggan 
      dapat meninggalkan antrian. Setelah pelanggan meninggalkan antrian, maka pemain akan menerima uang
    - SERVE hanya dapat digunakan untuk pesanan yang berada di paling depan. */