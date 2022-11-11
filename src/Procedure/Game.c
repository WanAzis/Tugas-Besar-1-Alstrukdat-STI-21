#include <stdio.h>
#include <stdlib.h>
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

/*fungsi untuk menetima input dari player*/
int PlayerInput(){
  STARTWORD();
  if (WordCompareString(currentWord, "Kanan")) {return 0;}
  else if (WordCompareString(currentWord, "Kiri")) {return 1;}
  else {return 999;}
}

void Jari_Bocil(){
  const int MaxFinger = 5;
  const int RIGHT = 0;
  const int LEFT = 1;
  int PlayerRF = 1, PlayerLF = 1, ComputerRF = 1, ComputerLF = 1;
  int PIHand, PIAttack, CIHand, CIAttack, i = 0; 
  printf("Game Jari Bocil dimulai. Siapkan kedua tangan Anda untuk menyerang lawan!\n");
  while ((ComputerRF != 0 || ComputerLF != 0) && (PlayerRF != 0 || PlayerLF != 0)) {
    if /*giliran player, i mod 2 = 0 */((i%2) == 0) {
      /*giliran player untuk menyerang, asumsi player selalu bermain duluan*/
      printf("Kondisi-mu sekarang:\n"); 
      printf("Jumlah jari tangan kanan: %i\n", PlayerRF);
      printf("Jumlah jari tangan kiri: %i\n", PlayerLF); printf("\n");
      printf("Kondisi-Komputer sekarang:\n"); 
      printf("Jumlah jari tangan kanan: %i\n", ComputerRF);
      printf("Jumlah jari tangan kiri: %i\n", ComputerLF); printf("\n");
      printf("Silahkan pilih tangan untuk menyerang (Kanan/Kiri): \n"); /*input tangan menyerang*/
      PIHand = PlayerInput(); 
      while (PIHand !=0 && PIHand !=1) { /*checker input tangan yang menyerang valid*/
        printf("Input tidak valid! Input hanya bisa berupa Kanan/Kiri\n");
        printf("Silahkan pilih tangan untuk menyerang (Kanan/Kiri): \n");
        PIHand = PlayerInput();
      }
      /*Checker agar tidak menyerang dengan tangan yang sudah tidak ada jari-nya*/
      if (PIHand == 0 && PlayerRF == 0) {
        printf("Tangan kanan kamu sudah habis jari-nya, penyerangan akan dilakukan dengan tangan kiri!\n");
        PIHand = 1;
      }
      else if (PIHand == 1 && PlayerLF == 0) {
        printf("Tangan kiri kamu sudah habis jari-nya, penyerangan akan dilakukan dengan tangan kiri!\n");
        PIHand = 0;
      }
      printf("Silahkan pilih tangan lawan untuk diserang (Kanan/Kiri): \n"); /*input tangan diserang*/
      PIAttack = PlayerInput();
      while (PIAttack !=0 && PIAttack!=1) { /*checker input tangan yang diserang valid*/
        printf("Input tidak valid! Input hanya bisa berupa Kanan/Kiri\n");
        printf("Silahkan pilih tangan lawan untuk diserang (Kanan/Kiri): \n");
        PIAttack = PlayerInput();
      }
      /*Perhitungan hasil setelah penyerangan*/
      if (PIHand == RIGHT && PIAttack == RIGHT) {ComputerRF = (ComputerRF + PlayerRF) % MaxFinger;}
      else if (PIHand == RIGHT && PIAttack == LEFT) {ComputerLF = (ComputerLF + PlayerRF) % MaxFinger;}
      else if (PIHand == LEFT && PIAttack == RIGHT) {ComputerRF = (ComputerRF + PlayerLF) % MaxFinger;}
      else if (PIHand == LEFT && PIAttack == LEFT) {ComputerLF = (ComputerLF + PlayerLF) % MaxFinger;}
    }
    else /*giliran komputer, i mod 2 = 1*/ {
      /*giliran computer untuk menyerang*/
      srand(time(NULL));
      int CIHand = rand()%2;
      int CIAttack = rand()%2;
      /*Checker agar tidak menyerang dengan tangan yang sudah tidak ada jari-nya*/
      if (CIHand == 0 && ComputerRF == 0) {CIHand = 1;}
      else if (CIHand == 1 && ComputerLF == 0) {CIHand = 0;}
      if (CIHand == 0) {printf("Tangan yang dipilih komputer untuk menyerang: KANAN\n");}
      else if (CIHand == 1) {printf("Tangan yang dipilih komputer untuk menyerang: KIRI\n");}
      if (CIAttack == 0) {printf("Tangan yang dipilih komputer untuk diserang: KANAN\n");}
      else if (CIAttack == 1) {printf("Tangan yang dipilih komputer untuk diserang: KIRI\n");}
      printf("\n"); /*Ngasih jarak aja biar enak liatnya*/
      /*Penghitungan hasil setelah penyerangan*/
      if (CIHand == RIGHT && CIAttack == RIGHT) {PlayerRF = (PlayerRF + ComputerRF) % MaxFinger;}
      else if (CIHand == RIGHT && CIAttack == LEFT) {PlayerLF = (PlayerLF + ComputerRF) % MaxFinger;}
      else if (CIHand == LEFT && CIAttack == RIGHT) {PlayerRF = (PlayerRF + ComputerLF) % MaxFinger;}
      else if (CIHand == LEFT && CIAttack == LEFT) {PlayerLF = (PlayerLF + ComputerLF) % MaxFinger;}
    }
    i++;
  }
  if (ComputerRF == 0 && ComputerLF == 0) { /*kondisi player menang*/
    printf("Selamat Anda telah memenangkan permainan, jangan sombong yaaa!\n"); /*pesan player menang, komputer kalah*/
    /*print score*/
  }
  else { /*kondisi komputer menang*/
    printf("Yaaah masa kalah sama komputer, Ayok coba lagi!\n"); /*pesan komputer menang, player kalah*/
    /*print score*/
  }
}
/* Deskripsi Game: */
/* Aturan permainan game ini adalah:
    - Player akan bermain melawan computer. Player dan komputer bermain dengan kedua tangan mereka (asumsikan
      komputer memiliki "tangan"). Permainan dimulai dengan player dan komputer mengeluarkan satu jari dari masing-masing tangan mereka.
    - Saat mendapat giliran, player/komputer dapat memilih ingin menggunakan tangan kiri/kanan nya untuk menyerang,
      dan juga tangan lawan mana yang ingin diserang . Alhasil, jumlah jari lawan akan bertambah sesuai dengan 
      jumlah jari dari tangan yang dipilih.
    - Jika penjumlahan dari jari penyerang dan yang diserang melebihi kapasitas jari tangan pada umumnya (5), maka
      akan di mod dengan 5 sebagai hasil akhir.
    - Jika penjumlahan dari jari penyerang dan yang diserang = 5, maka hasilnya akan di mod 5 (jari lawan habis).
    - Kondisi menang nya ialah ketika kedua jari lawan habis setelah diserang.
*/