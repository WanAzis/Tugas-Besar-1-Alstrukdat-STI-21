#include <stdio.h>
#include <stdlib.h>
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
int fitur=1,mode=0;

/* Fitur-fitur pada BNMO */

void MENU(){
  printf("---------------|  MAIN MENU |---------------\n");
  printf("[1] START\n[2] LOAD\n");
}
/* Tampilan awal mesin BNMO yang akan menampilkan pilihan START atau LOAD untuk playar */

void FITURE(){
  printf("-----------------------------------------------\n");
  printf("|  Ketik HELP untuk melihat penjelasan fitur  |\n");
  printf("-----------------------------------------------\n");
  printf("\nFitur pada BNMO yang bisa anda pilih :\n");
  printf(">> CREATE GAME\n");
  printf(">> LIST GAME\n");
  printf(">> DELETE GAME\n");
  printf(">> QUEUE GAME\n");
  printf(">> PLAY GAME\n");
  printf(">> SKIP GAME\n");
  printf(">> SAVE\n");
  printf(">> HELP\n");
  printf(">> QUIT\n");
}
/* Perintah untuk menampilkan seluruh fitur BNMO yang dapat dipilih oleh user */

void CHOOSEMODE(int *mode, char *file){
  printf("Silahkan memilih mode START/LOAD: "); STARTWORD2();
  PrintKata(currentWord); printf("\n"); // HAPUS
  if(WordCompareString(currentWord, "START") && currentWord.Length==5){
    *mode=1;
  } else if (WordCompareString(currentWord, "LOAD")){
    ADVWORD2(); PrintKata(currentWord); printf("\n"); //HAPUS
    WordToString(currentWord, file);
    *mode=2;
  } else {
    printf("Ketikkan mode yang benar START/LOAD\n\n");
  }
}
/* Memilih mode awal apakah player memilih START atau LOAD */

void STARTBNMO(){
  ListGame = Makearray();
  CreateQueue(&QueueGame);
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

void LOADBNMO(char *fname){
  ListGame = Makearray();
  CreateQueue(&QueueGame);
  char file[25] = "../data/";
  ConcatString(file, fname); printf("file yg diakses : %s\n", file); // HAPUS
  STARTWORDFILE(file);
  if (pita != NULL){
    int loop = currentWord.TabWord[0] - '0';
    ADVWORD();
    while(loop--){
      InsertLast(&ListGame, currentWord);
      ADVWORD();
    }
  } else {
    printf("\n"); mode = 0;
  }
}
/* Memulai mesin BNMO dengan mengakses file save player sebelumnya */

void CHOOSEFITURE(int *fitur, char *file){
  printf("Masukkan perintah: "); STARTWORD2(); printf("\n");
  if (WordCompareString(currentWord,"CREATE")){
    ADVWORD2();
    if (WordCompareString(currentWord,"GAME")){
      CREATEGAME(&ListGame);
    }
  } else if (WordCompareString(currentWord,"LIST")){
    ADVWORD2();
    if (WordCompareString(currentWord,"GAME")){
      LISTGAME(ListGame);
    }
  } else if (WordCompareString(currentWord,"DELETE")){
    ADVWORD2();
    if (WordCompareString(currentWord,"GAME")){
      DELETEGAME(&ListGame);
    }
  } else if (WordCompareString(currentWord,"QUEUE")){
    ADVWORD2();
    if (WordCompareString(currentWord,"GAME")){
      QUEUEGAME(&QueueGame);
    }
  } else if (WordCompareString(currentWord,"PLAY")){
    ADVWORD2();
    if (WordCompareString(currentWord,"GAME")){
      PLAYGAME(&QueueGame);
    }
  } else if (WordCompareString(currentWord,"SKIPGAME")){
    ADVWORD2();
    int ctr=0;
    for (int i = 0; i<currentWord.Length; i++){
      ctr = (ctr * 10) + currentWord.TabWord[i] - '0';
    }
    SKIPGAME(&QueueGame, ctr);
  } else if (WordCompareString(currentWord,"SAVE")){
    ADVWORD2(); PrintKata(currentWord); // HAPUS
    WordToString(currentWord, file);
    SAVE(file);
  } else if (WordCompareString(currentWord,"HELP")){
    HELP();
  } else if (WordCompareString(currentWord,"QUIT")){
    *fitur = 0;
  } else {
    COMMANDLAIN();
  }
}
/* Menerima perintah dari pengguna untuk menjalankan fitur yang diinginkan */

void SAVE(char *file){
  char fname[25] = "..\\data\\";
  ConcatString(fname, file);
  FILE *fp = fopen(fname, "w");
  fprintf(fp, "%d\n", ListGame.Neff);
  char *ftulis = (char*) malloc (sizeof(char) * currentWord.Length+1);
  for(int i=0; i<ListGame.Neff-1; i++){
    WordToString(ListGame.A[i], ftulis);
    fprintf(fp, "%s\n", ftulis);
  }
  WordToString(ListGame.A[ListGame.Neff-1], ftulis);
  fprintf(fp, "%s;", ftulis);
  fclose(fp);
}
/* Menyimpan state terkini mesin BNMO kedalam file inputan player */

void CREATEGAME(array *ListGame){
  int i = 0;
  boolean found = false;

  printf("Masukkan nama game yang akan ditambahkan: "); STARTWORD();
  char *g = (char*) malloc (sizeof(char) * currentWord.Length+1);
  WordToString(currentWord, g);
  while (i<(*ListGame).Neff && !found){
    if (WordCompareString((*ListGame).A[i], g)){
       found = true;
    } else {
      i++;
    }
  }
  if (!found){
    InsertLast(ListGame, currentWord);
    printf("Game berhasil ditambahkan\n");
  } else {
    printf("Game sudah terdaftar\n");
  }
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
  LISTGAME(*ListGame); printf("\n");
  printf("Masukkan nomor game yang ingin dihapus : "); STARTWORD();
  int nmr = currentWord.TabWord[0] - '0';
  if ((*ListGame).Neff>5 && nmr>5){
    if (nmr<=(*ListGame).Neff){
      DeleteAt(ListGame, nmr-1);
      printf("Game berhasil dihapus!\n");
    }
    else {
      printf("Nomor game tidak valid!\n");
    }
  } else {
    printf("Game default tidak bisa dihapus!\n");
  }
}
/* Menghapus sebuah game yang dimiliki oleh player */

/*prosedur queuegame*/
void QUEUEGAME(Queue *QueueGame) {
  /*Menampilkan List Game*/
  LISTGAME(ListGame); printf("\n");
  /*Menampilkan Queue Game yang sudah ada*/
  printf("Berikut adalah daftar antrian game-mu: \n");
  for (int i = 0; i<=IDX_TAIL(*QueueGame); i++){
    printf("%i. ", i+1); PrintKata(QueueGame->buffer[i]); printf("\n");
  } printf("\n");
  /*Masukkan input nomor game yang mau dimasukkan kedalam queue*/
  printf("Nomor Game yang mau ditambahkan ke antrian: "); STARTWORD();
  int noGame = currentWord.TabWord[0] - '0';
  char *g = (char*) malloc (sizeof(char) * ListGame.A[noGame-1].Length+1);
  WordToString(ListGame.A[noGame-1], g);
  if (noGame <= ListGame.Neff && noGame > 0) {
    enqueue(QueueGame, ListGame.A[noGame-1]);
    printf("Game %s dimasukkan kedalam antrian.\n", g);
  }
  else /*kasus kalau input salah*/ {
    printf("No Game yang di input tidak valid!\n");
  }
}
/*
/*
Deskripsi: function akan dijalankan ketika menerima input dari user berupa "QUEUE GAME", 
           intinya setiap dipanggil, akan memilih game pada list game, dan akan dimasukkan
           kedalam queue. 
           Catatan: - Memungkinkan untuk ada lebih dari satu game yang sama pada queue.
                    - Diasumsikan di file main udah dibuat queue kosong, jadi tinggal isi.
                    - Diasumsikan maksimum queue pada satu kali proses bermain adalah 10
I.S. input sudah valid, list game + queue game (jika sudah ada) di tampilkan
F.S. memasukkan game ke-n yang diminta user (jika input valid)
*/

/*prosedur playgame*/
void PLAYGAME(Queue *QueueGame /*harusnya ada list juga*/) {
  printf("Berikut adalah daftar antrian game-mu: \n");
  for (int i = 0; i<=IDX_TAIL(*QueueGame); i++){
    printf("%i. ", i+1); PrintKata(QueueGame->buffer[i]); printf("\n");
  } printf("\n");
  if (isEmpty(*QueueGame)) {
    printf("Tidak ada game di dalam antrian untuk dimainkan, silahkan masukkkan game kedalam antrian terlebih dahulu!\n");
  }
  else /*kasus queue tidak kosong*/{
    Word Game;
    dequeue(QueueGame, &Game);
    if (WordCompareString(Game, "Diner DASH")) {
      printf("Loading...\n\n");
      Diner_Dash();
    }
    else if (WordCompareString(Game, "RNG")) {
      printf("Loading...\n\n");
      RNG();
    }
    else if (WordCompareString(Game, "Jari Bocil")) {
      printf("Loading...\n\n");
      Jari_Bocil();
    }
    else /*game selain RNG dan Dinner Dash*/ {
      char *stringGame = (char*) malloc (sizeof(char) * Game.Length+1);
      WordToString(Game, stringGame);
      printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", stringGame);
    }
  }
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

/*prosedur skipGame*/
void SKIPGAME(Queue *QueueGame, int ctr) {
  printf("Berikut adalah daftar antrian game-mu: \n");
  for (int i = 0; i<=IDX_TAIL(*QueueGame); i++){
    printf("%i. ", i+1); PrintKata(QueueGame->buffer[i]); printf("\n");
  }
  if (ctr <= IDX_TAIL(*QueueGame) && ctr >= 0) {
    Word Game;
    for (int i=0; i<ctr;i++) {dequeue(QueueGame, &Game);}
    PLAYGAME(QueueGame);
  }
  else /*kasus kalau input salah*/ {
    CreateQueue(QueueGame);
    printf("Tidak ada permainan lagi dalam daftar game-mu");
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
  printf("Apakah anda ingin save? (Y/N)\n"); STARTWORD();
  if (WordCompareString(currentWord, "Y")){
    printf("Masukkan nama file yang ingin disimpan: "); STARTWORD();
    char *file = (char*) malloc (sizeof(char) * currentWord.Length+1);
    WordToString(currentWord, file);
    SAVE(file);
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
  printf("1. START \t-> merupakan menu awal untuk memulai BNMO dengan pilihan game default.\n");
  printf("2. LOAD \t-> merupakan menu awal untuk membaca dan membuka file save yang berisikan history permainan dari player.\n");
  printf("3. SAVE \t-> merupakan menu untuk menyimpan data setelah adanya perubahan dari player.\n");
  printf("4. CREATE GAME \t-> merupakan menu untuk menambahkan game baru pada daftar game.\n");
  printf("5. LIST GAME \t-> merupakan menu untuk menampilkan daftar game yang tersedia untuk player.\n");
  printf("6. DELETE GAME \t-> merupakan menu untuk menghapus sebuah game dari daftar game, dengan syarat:\n");
  printf("\t\t   game yang dihapus adalah game tambahan dan game yang terdapat pada queue saat itu tidak bisa dihapus.\n");
  printf("7. QUEUE GAME \t-> merupakan menu untuk mendaftarkan game kedalam list queue game yang akan dimainkan oleh player.\n");
  printf("8. PLAY GAME \t-> merupakan menu untuk memainkan game.\n");
  printf("9. SKIP GAME \t-> merupakan menu untuk melewati game yang tidak ingin dimainkan, sebanyak yang diinginkan.\n");
  printf("10. QUIT \t-> merupakan menu untuk keluar dari BNMO.\n");
}
/* Menampilkan menu fitur-fitur yang dimiliki oleh mesin BNMO serta penjelasannya */

void COMMANDLAIN(){
  printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
}
/* Mengeluarkan pesan kesalahan serta meminta inputan ulang ketika player memberi perintah yang tidak valid */
