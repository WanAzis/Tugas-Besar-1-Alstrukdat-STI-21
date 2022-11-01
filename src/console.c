#include <stdio.h>
#include "console.h"

/* Fitur-fitur pada BNMO */

void START(){

}
/* Memulai mesin BNMO dengan mengakses file konfigurasi default */

void LOAD(FILE File_name){

}
/* Memulai mesin BNMO dengan mengakses file save player sebelumnya */

void SAVE(FILE File_name){

}
/* Menyimpan state terkini mesin BNMO kedalam file inputan player */

void CREATEGAME(char Game, array *ListGame){

}
/* Membuat sebuah game baru inputan player */

void LISTGAME(array ListGame){

}
/* Menampilkan daftar game terkini yang dimiliki oleh player */

void DELETEGAME(IdxType X, array *ListGame){

}
/* Menghapus sebuah game yang dimiliki oleh player */

// void QUEUEGAME(IdxType X, array ListGame, Queue *QueueGame){

// }
// /* Mendaftarkan sebuah game yang dimiliki oleh player kedalam Queue Game untuk dimainkan */

/*prosedur queuegame*/
void QUEUEGAME(Queue *q) {
  int noGame = 0;
  char game;
  boolean valid = false;
  validChecker(valid, noGame);
  /*game diinisialiasi sama elemen ke-noGame dari list Game*/
  enqueue(q, game);
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
    validChecker(valid, noGame);
    /*game diinisialiasi sama elemen ke-noGame dari list Game*/
    if (true/*kalo dia game di list ke-noGame nya itu = "RNG" atau "Dinner Dash", (btw true nya biarin aja, cm biar ga error)*/) {
      printf("Loading %s...", q->buffer[IDX_HEAD(*q)]);
      /*eksekusi game, panggil fungsi game nya*/
    }
    else /*bilang gabisa dimainin*/ {
      printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", q->buffer[IDX_HEAD(*q)]);
    }
  }
  else /*queue game ada isi nya*/ {
    /*panggil game pertama dari queue*/
    if (q->buffer[IDX_HEAD(*q)] == "RNG" || q->buffer[IDX_HEAD(*q)] == "Dinner Dash") {
      printf("Loading %s...", q->buffer[IDX_HEAD(*q)]);
      /*eksekusi game, panggil fungsi game nya*/
    }
    else /*bilang gabisa dimainin*/ {
      printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", q->buffer[IDX_HEAD(*q)]);
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

// void SKIPGAME(IdxType X, Queue *QueueGame){

// }
// /* Melewatkan satu atau beberapa game dari Queue Game yang dimiliki player */

/*prosedur skipGame*/
void SKIPGAME(Queue *q, int n) {
  boolean valid = false;
  valid = (n<length(*q)); /*inisialisasi valid*/
  /*checker valid/tidak input*/
  if (!valid) {
    printf("Tidak ada permainan lagi dalam daftar game-mu.");
  }
  else /*input valid*/ {
    char game;
    /*skip game sebanyak n kali*/
    for (int i = 0; i<n;i++) {
      dequeue(q, &game);
    }
    playGame(q);
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

}
/* Player keluar dari mesin BNMO */

void HELP(){

}
/* Menampilkan menu fitur-fitur yang dimiliki oleh mesin BNMO serta penjelasannya */

void COMMANDLAIN(){

}
/* Mengeluarkan pesan kesalahan serta meminta inputan ulang ketika player memberi perintah yang tidak valid */