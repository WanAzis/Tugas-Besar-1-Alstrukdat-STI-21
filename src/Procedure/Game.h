#ifndef GAME_H
#define GAME_H

#include "time.h"
#include "Fungsi_Kecil.h"
#include "../ADT/MesinKata/mesin_kata.h"
#include "../ADT/QueueDD/QueueDD.h"

extern QueueDD Order, Cook, Serve;

/* Daftar Game yang Dapat Dimainkan */

void RNG();
/* Game random number generator */
/* Cara kerja dari game ini adalah player harus menebak
   sebuah angka acak X yang sudah disiapkan oleh sistem.
   Setiap giliran menebak, sistem akan memberitahu apakah
   tebakan lebih kecil atau lebih besar terhadap X. Game akan
   selesai jika player dapat menebak angka dengan benar. */

void Diner_Dash();
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


void ONETURN(QueueDD *Order, QueueDD *Cook, QueueDD *Serve);

void printUI(QueueDD Order, QueueDD Cook, QueueDD Serve);

void Jari_Bocil();
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

int playerInput(); /*function buat membantu game Jari_Bocil*/

#endif