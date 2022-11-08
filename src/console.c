#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADT/Array/Array.h"
#include "ADT/Queue/Queue.h"
#include "ADT/MesinKata/mesin_karakter.h"
#include "ADT/MesinKata/mesin_kata.h"
#include "Procedure/Fungsi_Kecil.h"
#include "Procedure/Game.h"
#include "boolean.h"
#include "console.h"

array ListGame;
Queue QueueGame;
int fitur=1,mode;

/* Fitur-fitur pada BNMO */

void MENU(){
  printf("---------------|  MAIN MENU |---------------\n");
  printf("[1] START\n[2] LOAD\n");
}
/* Tampilan awal mesin BNMO yang akan menampilkan pilihan START atau LOAD untuk playar */

void FITURE(){
  printf("Fitur pada BNMO yang bisa anda pilih :\n");
  printf("CREATEGAME\n");
  printf("LISTGAME\n");
  printf("DELETEGAME\n");
  printf("QUEUEGAME\n");
  printf("PLAYGAME\n");
  printf("SKIPGAME\n");
  printf("SAVE\n");
  printf("HELP\n");
  printf("QUIT\n");
}
/* Perintah untuk menampilkan seluruh fitur BNMO yang dapat dipilih oleh user */

void CHOOSEMODE(int *mode){
  STARTWORD();
  if(WordCompareString(currentWord, "START")){
    *mode=1;
  } else if (WordCompareString(currentWord, "LOAD")){
    *mode=2;
  }
}
/* Memilih mode awal apakah player memilih START atau LOAD */

void STARTBNMO(){
  ListGame = Makearray();
  char *fname = "..\\data\\config.txt";
  STARTWORDFILE(fname);
  int loop = currentWord.TabWord[0] - '0';
  ADVWORD();
  while(loop--){
    InsertLast(&ListGame, currentWord);
    ADVWORD();
  }
}
/* Memulai mesin BNMO dengan mengakses file konfigurasi default */

void LOADBNMO(){
  ListGame = Makearray();
  printf("Masukkan file save yang ingin diakses: ");
  STARTWORD();
  char *fname = (char*) malloc (sizeof(char) * currentWord.Length+1);
  WordToString(currentWord, fname);
  STARTWORDFILE(fname);
  int loop = currentWord.TabWord[0] - '0';
  ADVWORD();
  while(loop--){
    InsertLast(&ListGame, currentWord);
    ADVWORD();
  }
}
/* Memulai mesin BNMO dengan mengakses file save player sebelumnya */

void CHOOSEFITURE(int *fitur){
  STARTWORD();
  if (WordCompareString(currentWord,"CREATEGAME")){
    CREATEGAME(&ListGame);
  } else if (WordCompareString(currentWord,"LISTGAME")){
    LISTGAME(ListGame);
  } else if (WordCompareString(currentWord,"DELETEGAME")){
    DELETEGAME(&ListGame);
  } else if (WordCompareString(currentWord,"QUEUEGAME")){
    QUEUEGAME(&QueueGame);
  } else if (WordCompareString(currentWord,"PLAYGAME")){
    PLAYGAME(&QueueGame);
  } else if (WordCompareString(currentWord,"SKIPGAME")){
    SKIPGAME(&QueueGame);
  } else if (WordCompareString(currentWord,"SAVE")){
    SAVE();
  } else if (WordCompareString(currentWord,"HELP")){
    HELP();
  } else if (WordCompareString(currentWord,"QUIT")){
    *fitur = 0;
  } else {
    COMMANDLAIN();
  }
}
/* Menerima perintah dari pengguna untuk menjalankan fitur yang diinginkan */

void SAVE(){
  printf("Masukkan nama file save: ");
  STARTWORD();
  char *fname = (char*) malloc (sizeof(char) * currentWord.Length+1);
  WordToString(currentWord, fname);
  FILE *fp = fopen(fname, "w");
  fprintf(fp, "%d\n", ListGame.Neff);
  char *ftambah = (char*) malloc (sizeof(char) * currentWord.Length+1);
  for(int i=0; i<ListGame.Neff-1; i++){
    WordToString(ListGame.A[i], ftambah);
    fprintf(fp, "%s\n", ftambah);
  }
  WordToString(ListGame.A[ListGame.Neff-1], ftambah);
  fprintf(fp, "%s;", ftambah);
  fclose(fp); 
}
/* Menyimpan state terkini mesin BNMO kedalam file inputan player */

void CREATEGAME(array *ListGame){
  printf("Masukkan game yang ingin ditambahkan : ");
  STARTWORD();
  InsertLast(ListGame, currentWord); printf("\n");
  printf("Game berhasil ditambahkan!\n");
}
/* Membuat sebuah game baru inputan player */

void LISTGAME(array ListGame){
  printf("Berikut daftar game yang anda miliki : \n");
  for (int i = 0; i<ListGame.Neff; i++){
    printf("%i. ", i+1); PrintKata(ListGame.A[i]); printf("\n");
  }
}
/* Menampilkan daftar game terkini yang dimiliki oleh player */

void DELETEGAME(array *ListGame){
  LISTGAME(*ListGame);
  printf("Masukkan game yang ingin dihapus : "); STARTWORD();
  char *gname = (char*) malloc (sizeof(char) * currentWord.Length+1);
  WordToString(currentWord, gname);
  if ((*ListGame).Neff>5){
    int idx = 5;
    boolean found = false;
    while(idx < Length(*ListGame) && !found){
      if (WordCompareString((*ListGame).A[idx], gname)){
        found = true;
      } else {
        idx++;
      }
    }
    if (found){
      DeleteAt(ListGame, idx);
      printf("Game berhasil dihapus!\n");
    } else {
      printf("Game yang dimaksud tidak ditemukan!\n");
    }
  } else {
    printf("Game default tidak bisa dihapus!\n");
  }
}
/* Menghapus sebuah game yang dimiliki oleh player */

// void QUEUEGAME(IdxType X, array ListGame, Queue *QueueGame){

// }
// /* Mendaftarkan sebuah game yang dimiliki oleh player kedalam Queue Game untuk dimainkan */

/*prosedur queuegame*/
void QUEUEGAME(Queue *q) {
  int noGame = 0;
  char *game;
  boolean valid = false;
  // validChecker(valid, noGame);
  /*game diinisialiasi sama elemen ke-noGame dari list Game*/
  enqueue(q, currentWord);
}
/*
Deskripsi: function akan dijalankan ketika menerima input dari user berupa "QUEUE GAME", 
           intinya setiap dipanggil, akan memilih game pada list game, dan akan dimasukkan
           kedalam queue. 
           Catatan: - Memungkinkan untuk ada lebih dari satu game yang sama pada queue.
                    - Disini hanya memasukkan game, masalah penanganan input valid/tidak 
                      bukan disini, di file main.
                    - Diasumsikan di file main udah dibuat queue kosong, jadi tinggal isi.
                    - Diasumsikan maksimum queue pada satu kali proses bermain adalah 10
I.S. input sudah valid, list game + queue game (jika sudah ada) di tampilkan
F.S. memasukkan game ke-n yang diminta user (jika input valid)
*/

// void PLAYGAME(IdxType X, array ListGame){

// }
// /* Memainkan sebuah game yang dimiliki oleh player */

/*prosedur playgame*/
void PLAYGAME(Queue *q /*harusnya ada list juga*/) {
  if (isEmpty(*q)) {
    int noGame = 0;
    char game;
    boolean valid = false;
    // validChecker(valid, noGame);
    /*game diinisialiasi sama elemen ke-noGame dari list Game*/
    if (true/*kalo dia game di list ke-noGame nya itu = "RNG" atau "Dinner Dash", (btw true nya biarin aja, cm biar ga error)*/) {
      printf("Loading %s...", q->buffer[IDX_HEAD(*q)]);
      /*eksekusi game, panggil fungsi game nya*/
    }
    else /*bilang gabisa dimainin*/ {
      printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", q->buffer[IDX_HEAD(*q)]);
    }
  }
  // else /*queue game ada isi nya*/ {
  //   /*panggil game pertama dari queue*/
  //   if (q->buffer[IDX_HEAD(*q)] == "RNG" || q->buffer[IDX_HEAD(*q)] == "Dinner Dash") {
  //     printf("Loading %s...", q->buffer[IDX_HEAD(*q)]);
  //     /*eksekusi game, panggil fungsi game nya*/
  //   }
  //   else /*bilang gabisa dimainin*/ {
  //     printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", q->buffer[IDX_HEAD(*q)]);
  //   }
  // }
}
/*
Deskripsi: function akan dijalankan ketika menerima input dari user berupa "PLAY GAME"
           ketika dipanggil, akan mengecek apakah queue game kosong atau tidak, jika kosong,
           maka akan menampilkan list game, lalu meminta input game yang akan dimainkan. Jika
           queue game tidak kosong, maka akan menjalankan game pertama yang ada di queue.
           Catatan - Dilakukan pengecekan valid/tidak nya input (jika queue kosong)
                   - 
I.S. list game ditampilkan (bisa berupa queue jika sudah ada, kalau queue kosong, tampilkan
list game awal). 
F.S. game dimainkan (memanggil game jika dia RNG/Dinner Dash)
*/

// void SKIPGAME(IdxType X, Queue *QueueGame){

// }
// /* Melewatkan satu atau beberapa game dari Queue Game yang dimiliki player */

/*prosedur skipGame*/
void SKIPGAME(Queue *q) {
  boolean valid = false;
  int n;
  scanf("%i", &n);
  valid = (n<length(*q)); /*inisialisasi valid*/
  /*checker valid/tidak input*/
  if (!valid) {
    printf("Tidak ada permainan lagi dalam daftar game-mu.");
  }
  else /*input valid*/ {
    Word game;
    /*skip game sebanyak n kali*/
    for (int i = 0; i<n;i++) {
      dequeue(q, &game);
    }
    PLAYGAME(q);
  }
}
/*
Deskripsi: function akan dilakukan ketika queue game sudah ada dan user memberika input
           berupa "SKIP GAME n". Jika n>length queue, maka muncul pesan error, jika n valid,
           maka akan mengeskip game sebanyak n kali(dequeue sebanyak n kali) lalu menjalankan 
           function playgame
           Catatan: -
I.S. list game ditampilkan (bisa berupa queue jika sudah ada, kalau queue kosong, tampilkan
list game awal). n sudah di dapat dari input command
F.S. game di skip, lalu dimainkan
*/

void QUIT(){
  printf("Apakah anda ingin save?\n");
  STARTWORD();
  char *s = (char*) malloc (sizeof(char) * currentWord.Length+1);
  WordToString(currentWord, s);
  if (s == "SAVE") {
    SAVE();
    printf("Data berhasil di save\n");
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...\n");
  }
  else {
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...\n");
  }
}
/* Player keluar dari mesin BNMO */

void HELP(){
  printf("FITUR-FITUR BNMO:\n");
  printf("1. START -> merupakan menu awal untuk memulai BNMO dengan pilihan game default.\n");
  printf("2. LOAD -> merupakan menu awal untuk membaca dan membuka file save yang berisikan history permainan dari player.\n");
  printf("3. SAVE -> merupakan menu untuk menyimpan data setelah adanya perubahan dari player.\n");
  printf("4. CREATEGAME -> merupakan menu untuk menambahkan game baru pada daftar game.\n");
  printf("5. LISTGAME -> merupakan menu untuk menampilkan daftar game yang tersedia untuk player.\n");
  printf("6. DELETEGAME -> merupakan menu untuk menghapus sebuah game dari daftar game, dengan syarat:\n");
  printf("game yang dihapus adalah game tambahan dan game yang terdapat pada queue saat itu tidak bisa dihapus.\n");
  printf("7. QUEUEGAME -> merupakan menu untuk mendaftarkan game kedalam list queue game yang akan dimainkan oleh player.\n");
  printf("8. PLAYGAME -> merupakan menu untuk memainkan game.\n");
  printf("9. SKIPGAME -> merupakan menu untuk melewati game yang tidak ingin dimainkan, sebanyak yang diinginkan.\n");
  printf("10. QUIT -> merupakan menu untuk keluar dari BNMO.\n");
}
/* Menampilkan menu fitur-fitur yang dimiliki oleh mesin BNMO serta penjelasannya */

void COMMANDLAIN(){
  printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
}
/* Mengeluarkan pesan kesalahan serta meminta inputan ulang ketika player memberi perintah yang tidak valid */