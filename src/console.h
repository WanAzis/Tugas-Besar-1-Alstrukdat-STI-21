#ifndef CONSOLE_H
#define CONSOLE_H

#include "implementasiadt.h"
#include "boolean.h"

extern array ListGame;
extern Queue QueueGame;
extern Stack HistoryGame;
extern arraymap ScoreBoardGame;
extern int fitur, mode;

/* Fitur-fitur pada BNMO */

void MENU();
/* Tampilan awal mesin BNMO yang akan menampilkan pilihan START atau LOAD untuk playar */

void FITURE();
/* Perintah untuk menampilkan seluruh fitur BNMO yang dapat dipilih oleh user */

void CHOOSEMODE(int *mode, char *file);
/* Memilih mode awal apakah player memilih START atau LOAD */

void STARTBNMO();
/* Memulai mesin BNMO dengan mengakses file konfigurasi default */

void LOADBNMO(char *fname);
/* Memulai mesin BNMO dengan mengakses file save player sebelumnya */

void CHOOSEFITURE(int *fitur, char *fname);
/* Menerima perintah dari pengguna untuk menjalankan fitur yang diinginkan */

void SAVE(char *file);
/* Menyimpan state terkini mesin BNMO kedalam file inputan player */

void CREATEGAME(array *ListGame);
/* Membuat sebuah game baru inputan player */

void LISTGAME(array ListGame);
/* Menampilkan daftar game terkini yang dimiliki oleh player */

void DELETEGAME(array *ListGame);
/* Menghapus sebuah game yang dimiliki oleh player */

/*prosedur queuegame*/
void QUEUEGAME(Queue *q, array ListGame);
/*
Deskripsi: function akan dijalankan ketika menerima input dari user berupa "QUEUE GAME", 
           intinya setiap dipanggil, akan memilih game pada list game, dan akan dimasukkan
           kedalam queue. 
           Catatan: - Memungkinkan untuk ada lebih dari satu game yang sama pada queue.
                    - Disini hanya memasukkan game, masalah penanganan input valid/tidak 
                      bukan disini, di file main.
                    - Diasumsikan maksimum queue pada satu kali proses bermain adalah 10
I.S. input sudah valid, list game + queue game (jika sudah ada) di tampilkan
F.S. memasukkan game ke-n yang diminta user (jika input valid)
*/

/*prosedur playgame*/
void PLAYGAME(Queue *q, arraymap *ScoreBoardGame, Stack *HistoryGame);
/*
/*penunjang playgame*/
void EndGame(arraymap *ScoreBoardGame, int Game, int score);
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
void SKIPGAME(Queue *q, int ctr);
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

void SCOREBOARD(arraymap ScoreBoardGame, array ListGame);
/* Menampilkan ScoreBoard pemain ditiap game */

void RESETSCOREBOARD(arraymap* ScoreBoardGame);
/* ScoreBoard permainan direset sesuai keinginan player */

void HISTORY(Stack HistoryGame, int n);
/* Menampilkan History permainan pemain */

void RESETHISTORY(Stack* HistoryGame);
/* Mereset history permainan pemain */

void QUIT();
/* Player keluar dari mesin BNMO */

void HELP();
/* Menampilkan menu fitur-fitur yang dimiliki oleh mesin BNMO serta penjelasannya */

void COMMANDLAIN();
/* Mengeluarkan pesan kesalahan serta meminta inputan ulang ketika player memberi perintah yang tidak valid */


#endif 