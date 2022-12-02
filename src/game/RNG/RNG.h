#ifndef RNG_H
#define RNG_H

#include "time.h"
#include "../../ADT/mesinkata/mesin_kata.h"

void RNG(int* score);
/* Game random number generator */
/* Cara kerja dari game ini adalah player harus menebak
   sebuah angka acak X yang sudah disiapkan oleh sistem.
   Setiap giliran menebak, sistem akan memberitahu apakah
   tebakan lebih kecil atau lebih besar terhadap X. Game akan
   selesai jika player dapat menebak angka dengan benar. */

#endif