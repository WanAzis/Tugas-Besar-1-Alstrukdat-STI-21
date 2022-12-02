#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "dinerdash.h"

QueueDD Order, Cook, Serve;

void Diner_Dash(int* score){
  srand(time(NULL));
  MakeQueue(&Order);
  MakeQueue(&Cook);
  MakeQueue(&Serve);
  Food fd, val; int saldo = 0, idx, ID, serv=0;
  for (int i = 0; i < 3; i++){
    fd.id = i;
    fd.durasi = rand() % (5 - 1 +1) + 1;
    fd.ketahanan = rand() % (5 - 2 +1) + 2;
    fd.harga = rand() % (50000 - 10000 +1) + 10000;
    Enqueue(&Order, fd);
  }

  printf("Selamat Datang di Diner Dash!\n");
  while (Len(Order)<=7 && serv<=5){ 
    printf("\nSaldo : %i\n\n", saldo);
    printUI(Order, Cook, Serve);

    printf("MASUKKAN COMMAND: "); STARTSENTENCE();
    Word perintah;
    for (int i = 0; i<5; i++){
      perintah.TabWord[i]=currentWord.TabWord[i];
    } perintah.Length=5;

    if (WordCompareString(perintah, "COOK ") && currentWord.Length>6){
      ID=0;
      for (int i = 6; i<currentWord.Length; i++){
        ID = (ID * 10) + currentWord.TabWord[i] - '0';
      }

      idx = searchDD(Order, ID);
      if (idx>=IDX_HEAD(Order) && idx<=IDX_TAIL(Order) && Len(Cook)<=5){
        printf("Berhasil memasak M%i\n", ID);
        ONETURN(&Order, &Cook, &Serve);
        Enqueue(&Cook, Order.buffer[idx]);
      }
      else if (Len(Cook)>5){
        printf("Tidak bisa memasak makanan karena makanan yang sedang dimasak sudah mencapai 5\n");
      }
      else {
        printf("Makanan tidak terdapat dalam antrian\n");
      }
    }
    else if (WordCompareString(perintah, "SERVE") && currentWord.Length>7){
      ID=0;
      for (int i = 7; i<currentWord.Length; i++){
        ID = (ID * 10) + currentWord.TabWord[i] - '0';
      }

      idx = searchDD(Serve, ID);
      if (idx>=IDX_HEAD(Serve) && idx<=IDX_TAIL(Serve)){
        if (ID==Order.buffer[IDX_HEAD(Order)].id){
          printf("Berhasil mengantar M%i\n", ID); serv++;
          DequeueAt(&Serve, &fd, idx); DequeueAt(&Order, &fd, 0);
          saldo += fd.harga;
          ONETURN(&Order, &Cook, &Serve);
        }
        else {
          printf("M%i belum dapat disajikan karena M%i belum selesai\n", ID, Order.buffer[Order.idxHead].id);
        }
      }
      else {
        printf("Makanan belum dapat disajikan\n");
      }
    }
    else if(WordCompareString(currentWord, "SKIP")){ 
      printf("Tidak ada makanan yang dimasak maupun disajikan\n");
      ONETURN(&Order, &Cook, &Serve);
    }
    else {
      printf("Perintah tidak valid, silahkan masukkan kembali perintah");
    }
  }
  if (serv>5){
    printf("Selamat, Anda memenangkan game Diner Dash!\n\n");
  } else {
    printf("Game over, antrian sudah melebihi 7\n\n");
  } *score = saldo;
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
  Food fd; int loop;
  loop = Len(*Cook);
  int i = 0;
  for (int i = IDX_HEAD(*Cook); i<=IDX_TAIL(*Cook); i++){
    (*Cook).buffer[i].durasi--;
    if ((*Cook).buffer[i].durasi==0){
      printf("Makanan M%i telah selesai dimasak\n", (*Cook).buffer[i].id);
      DequeueAt(Cook, &fd, i);
      Enqueue(Serve, fd);
      i--;
    }
  }

  for (int i = IDX_HEAD(*Serve); i<=IDX_TAIL(*Serve); i++){
    (*Serve).buffer[i].ketahanan--;
    if ((*Serve).buffer[i].ketahanan==0){
      printf("Makanan M%i hangus, silahkan masak kembali\n", (*Serve).buffer[i].id);
      DequeueAt(Serve, &fd, i);
    }
  }
  fd.id=(*Order).buffer[IDX_TAIL(*Order)].id + 1;
  fd.durasi = rand() % (5 - 1 +1) + 1;
  fd.ketahanan = rand() % (6 - 2 +1) + 2;
  fd.harga = rand() % (50000 - 10000 +1) + 10000;  
  Enqueue(Order, fd);
}
/* Prosedur untuk melakukan satu putaran pada game Diner DASH. Satu putaran yang dimaksud adalah 
   mengurangkan durasi dan ketahanan makanan pada antrian Cook dan Serve, lalu menambahkan pesanan sebanyak 1 */

void printUI(QueueDD Order, QueueDD Cook, QueueDD Serve){ 
  printf("Daftar Pesanan\n");
  printf("Makanan\t| Durasi memasak | Ketahanan\t| Harga\n");
  printf("----------------------------------------------\n");
  for (int i = IDX_HEAD(Order); i <= IDX_TAIL(Order) ; i++){
    printf("M%d\t| %d\t\t | %d\t\t| %d\n", Order.buffer[i].id, Order.buffer[i].durasi, Order.buffer[i].ketahanan, Order.buffer[i].harga);
  } printf("\n");
    
  printf("Daftar Makanan yang sedang dimasak\n");
  printf("Makanan\t| Sisa durasi memasak\n");
  printf("------------------------------\n");
  if (ISEmpty(Cook)){
    printf("\t|\n");
  } else{
    for (int i = IDX_HEAD(Cook); i <= IDX_TAIL(Cook) ; i++){
      printf("M%d\t| %d\n", Cook.buffer[i].id, Cook.buffer[i].durasi);
    } 
  } printf("\n");

  printf("Daftar Makanan yang dapat disajikan\n");
  printf("Makanan\t| Sisa ketahanan makanan\n");
  printf("------------------------------\n");
  if (ISEmpty(Serve)){
    printf("\t|\n");
  } else{
    for (int i = IDX_HEAD(Serve); i <= IDX_TAIL(Serve) ; i++){
      printf("M%d\t| %d\n", Serve.buffer[i].id, Serve.buffer[i].ketahanan);
    }
  } printf("\n");
}
/* Digunakan untuk menampilkan keadaan terkini antrian pesanan, Cook, dan Serve pada game Diner DASH */

int searchDD(QueueDD q, int x){
  int found = false; 
  int i = IDX_HEAD(q);
  while (i<=IDX_TAIL(q) && !found){
    if (q.buffer[i].id == x){
      found = true;
    } else {
      i++;
    }
  }
  if (found){
    return i;
  } else {
    return -999;
  }
}
/* Mencari elemen q yang id nya adalah ID, mengembalikan idx ID pada q */