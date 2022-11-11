#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

QueueDD Order, Cook, Serve;
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

void Diner_Dash(){
  CreateQueue(&Order);
  CreateQueue(&Cook);
  CreateQueue(&Serve);
  ElType Food, val; int saldo = 0, idx, ID;
  for (int i = 0; i < 3; i++){
    Food.id = i;
    Food.durasi = rand() % (5 - 1 +1) + 1;
    Food.ketahanan = rand() % (5 - 1 +1) + 1;
    Food.harga = rand() % (50000 - 10000 +1) + 10000;
    enqueue(&Order, Food);
  }
  displayQueue(Order); //HAPUS
  printf("idx head: %i \nidx tail: %i\n", Order.idxHead, Order.idxTail);

  printf("Selamat Datang di Diner Dash!\n");
  while (length(Order)<=7 && length(Serve)<=15){
    printf("\nSaldo : %i\n\n", saldo);
    printUI(Order, Cook, Serve);

    printf("MASUKKAN COMMAND: "); STARTWORD();
    Word perintah;
    for (int i = 0; i<5; i++){
      perintah.TabWord[i]=currentWord.TabWord[i];
    } perintah.Length=5;

    if (WordCompareString(perintah, "COOK ")){
      ID=0;
      for (int i = 6; i<currentWord.Length; i++){
        ID = (ID * 10) + currentWord.TabWord[i] - '0';
      } printf("ID yang di akses: %i\n", ID); // HAPUS

      idx = searchDD(Order, ID); printf("idx yang di akses: %i\n", idx); //HAPUS
      if (idx>=IDX_HEAD(Order) && idx<=IDX_TAIL(Order)){
        printf("Berhasil memasak M%i\n", ID);
        ONETURN(&Order, &Cook, &Serve);
        enqueue(&Cook, Order.buffer[idx]);
      }
      else {
        printf("Makanan tidak terdapat dalam antrian\n");
      }
    }
    else if (WordCompareString(perintah, "SERVE")){
      ID=0;
      for (int i = 7; i<currentWord.Length; i++){
        ID = (ID * 10) + currentWord.TabWord[i] - '0';
      } printf("ID yang di akses: %i\n", ID); // HAPUS

      idx = searchDD(Serve, ID); printf("idx yang di akses: %i\n", idx); //HAPUS
      if (idx>=IDX_HEAD(Serve) && idx<=IDX_TAIL(Serve)){
        if (idx==IDX_HEAD(Order)){
          printf("Berhasil mengantar M%i\n", ID);
          dequeue(&Serve, &Food, idx); dequeue(&Order, &Food, idx);
          saldo += Food.harga;
          ONETURN(&Order, &Cook, &Serve);
        }
        else {
          printf("M%i belum dapat disajikan karena M%i belum selesai\n", ID, Cook.buffer[Cook.idxHead].id);
        }
      }
      else {
        printf("Makanan belum dapat disajikan\n");
      }
    }
    else if(WordCompareString(perintah, "SKIP ")){ 
      printf("Tidak ada makanan yang dimasak maupun disajikan\n");
      ONETURN(&Order, &Cook, &Serve);
    }
    else {
      printf("Perintah tidak valid, silahkan masukkan kembali perintah");
    }
  }
  if (length(Order)>7){
    printf("Game over, antrian sudah melebihi 7\n");
  } else {
    printf("Selamat, Anda memenangkan game Diner Dash!\n");
  }
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

void ONETURN(QueueDD *Order, QueueDD *Cook, QueueDD *Serve){
  ElType Food; int loop;
  loop = length(*Cook);
  int i = 0;
  for (int i = IDX_HEAD(*Cook); i<=IDX_TAIL(*Cook); i++){
    (*Cook).buffer[i].durasi--;
    if ((*Cook).buffer[i].durasi==0){
      printf("Makanan M%i telah selesai dimasak\n", (*Cook).buffer[i].id);
      dequeue(Cook, &Food, i);
      enqueue(Serve, Food);
      i--;
    }
  }

  for (int i = IDX_HEAD(*Serve); i<=IDX_TAIL(*Serve); i++){
    (*Serve).buffer[i].ketahanan--;
    if ((*Serve).buffer[i].ketahanan==0){
      printf("Makanan M%i hangus, silahkan masak kembali\n", (*Serve).buffer[i].id);
      dequeue(Serve, &Food, i);
      enqueue(Cook, Food);
      i--;
    }
  }
  Food.id=(*Order).buffer[IDX_TAIL(*Order)].id + 1;
  Food.durasi = rand() % (5 - 1 +1) + 1;
  Food.ketahanan = rand() % (5 - 1 +1) + 1;
  Food.harga = rand() % (50000 - 10000 +1) + 10000;  
  enqueue(Order, Food);
}

void printUI(QueueDD Order, QueueDD Cook, QueueDD Serve){ 
  printf("Daftar Pesanan\n");
  printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
  printf("----------------------------------------------\n");
  for (int i = IDX_HEAD(Order); i <= IDX_TAIL(Order) ; i++){
    if (i < 10){
      printf("M%d      | %d              | %d         | %d\n", Order.buffer[i].id, Order.buffer[i].durasi, Order.buffer[i].ketahanan, Order.buffer[i].harga);
    } else {
      printf("M%d     | %d              | %d         | %d\n", Order.buffer[i].id, Order.buffer[i].durasi, Order.buffer[i].ketahanan, Order.buffer[i].harga);
    }
  } printf("\n");
    
  printf("Daftar Makanan yang sedang dimasak\n");
  printf("Makanan | Sisa durasi memasak\n");
  printf("------------------------------\n");
  if (isEmpty(Cook)){
    printf("        |\n");
  } else{
    for (int i = IDX_HEAD(Cook); i <= IDX_TAIL(Cook) ; i++){
      if (i < 10){
        printf("M%d      | %d\n", Cook.buffer[i].id, Cook.buffer[i].durasi);
      } else{
        printf("M%d     | %d\n", Cook.buffer[i].id, Cook.buffer[i].durasi);
      }
    } printf("\n");
  }

  printf("Daftar Makanan yang dapat disajikan\n");
  printf("Makanan | Sisa ketahanan makanan\n");
  printf("------------------------------\n");
  if (isEmpty(Serve)){
    printf("        |\n");
  } else{
    for (int i = IDX_HEAD(Serve); i <= IDX_TAIL(Serve) ; i++){
      if (i < 10){
        printf("M%d      | %d\n", Serve.buffer[i].id, Serve.buffer[i].ketahanan);
      } else{
        printf("M%d     | %d\n", Serve.buffer[i].id, Serve.buffer[i].ketahanan);
      }
    }
  } printf("\n");
}

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
