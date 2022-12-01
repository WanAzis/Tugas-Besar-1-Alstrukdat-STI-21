#ifndef SNAKEONMETEOR_H
#define SNAKEONMETEOR_H

#include "../../boolean.h"
#include "../../ADT/matriks/matriks.h"
#include "../../ADT/point/point.h"
#include "../../ADT/list/listdp.h"

#define MAKANAN 'o'
#define OBS '#'
#define MET 'm'
#define KEPALA 'H'

extern matriks Maps;
extern List Badan;
extern POINT Mkn, Met, Obs;
extern boolean GameOver;

/* Merupakan program utama dari game */
void SnakeonMeteor(int* Score);

/* Menampilkan kondisi terkini permainan kedalam peta */
void PrintPetaSOM(matriks Maps);

/* Meng-update matriks Maps sesuai dengan kondisi terkini permainan */
void UpdateMapsSOM(matriks* Maps, List Badan, POINT Mkn, POINT Met, POINT Obs);

/* Memvalidasi langkah ular dalam permainan */
boolean isLangkahValid(matriks Maps, Word kata);

/* Prosedur satu TURN, TURN ditandakan dengan perubahan posisi tubuh snake dan penambahan ekor snake */
void ONETURNSOM(Word kata, List* Badan, POINT* Met, POINT* Mkn, int* type);

/* Prosedur untuk penambahan ekor pada ular */
void TambahEkor(List *Badan);

/* Menghitung score pemain yang telah GameOver */
int HitungScore(List Badan);

#endif