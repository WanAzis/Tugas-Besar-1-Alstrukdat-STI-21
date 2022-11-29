#ifndef TOWEROFHANOI_H
#define TOWEROFHANOI_H

#include "../../ADT/mesinkata/mesin_kata.h"
#include "../../ADT/stack/stacktoh.h"

void Tower_of_Hanoi(int *score);
/*
Terdapat 3 tiang, tiang A, tiang B, dan tiang C dan posisinya terurut dari kiri ke kanan. 
Pada tiang A, terdapat 5 piringan, dengan piringan paling bawah merupakan piringan yang paling besar 
dan piringan paling atas merupakan piringan yang paling kecil. Cara bermainnya ialah kelima 
piringan tersebut harus dipindahkan ke tiang C dengan posisi yang sama (piringan paling bawah 
merupakan piringan yang paling besar dan piringan paling atas merupakan piringan yang paling kecil), 
dengan peraturannya adalah piringan yang di bawah tidak boleh lebih besar kecil daripada piringan 
yang ada di atasnya. Beberapa modifikasi untuk permainan ini:
    - Jumlah piringan hanya 5 saja untuk permainan ini.
    - Piringan direpresentasikan sebagai gambar piringan dengan *, dengan piringan paling besar adalah 9 
      dan balok silinder paling kecil adalah 1.
    - Skor untuk permainan ini tergantung dengan seberapa optimal langkah dari pemain (dengan langkah 
      paling optimalnya adalah 31) dan skor maksimalnya adalah 10 (Cara perhitungan skornya dibebaskan, 
      yang terpenting adalah jika langkahnya 31, skornya adalah 10).
*/

void Display_ToH(Stacktoh A, Stacktoh B, Stacktoh C, int JmlPiringan);
/*
Menampilkan kondisi terkini dari masing-masing tiang pada Tower of Hanoi
*/

void Input_ToH(Stacktoh A, Stacktoh B, Stacktoh C, int JmlPiringan, char *TiangIn, char *TiangOut);
/*
Meminta input untuk memindahkan piringan dari tiang satu ke yang lainya
*/
boolean Constrain_ToH(Stacktoh A, Stacktoh B, Stacktoh C, char TiangIn, char TiangOut);
/*
Mengecek apakah permintaan pemindahan piring sudah benar/belum 
*/
void Move_Piringan(Stacktoh A, Stacktoh B, Stacktoh C, char TiangIn, char TiangOut);
/*
Memindahkan piringan dari satu tiang ke tiang lainnya.
*/
int Score_Counter(int counter, int JumlahPiringan);
/*
Menghitung score akhir dari game
*/
#endif