#ifndef DINERDASH_H
#define DINERDASH_H

#include "time.h"
#include "../../procedure/fungsi_kecil.h"
#include "../../ADT/mesinkata/mesin_kata.h"
#include "../../ADT/queueDD/queueDD.h"

extern QueueDD Order, Cook, Serve;

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
/* Prosedur untuk melakukan satu putaran pada game Diner DASH. Satu putaran yang dimaksud adalah 
   mengurangkan durasi dan ketahanan makanan pada antrian Cook dan Serve, lalu menambahkan pesanan sebanyak 1 */

void printUI(QueueDD Order, QueueDD Cook, QueueDD Serve);
/* Digunakan untuk menampilkan keadaan terkini antrian pesanan, Cook, dan Serve pada game Diner DASH */

int searchDD(QueueDD q, int ID);
/* Mencari elemen q yang id nya adalah ID, mengembalikan idx ID pada q */

#endif