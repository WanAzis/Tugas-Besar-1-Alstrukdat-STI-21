/* merupakan ADT yang digunakan untuk memainkan Snake on Meteor yaitu berupa matriks of matriks
   yang menyimpan kondisi map yang sesungguhnya (represenstasi dari map permainan) */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "../../boolean.h"

#define FLAG 'W'

typedef struct {
    char arr[5];
} typeMatriks;

typedef struct {
    typeMatriks A[5];
} matriks;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk matriks kosong dengan ukuran InitialSize
 */
matriks MakeMatriks();

/**
 * Fungsi untuk mengetahui apakah suatu matriks kosong.
 * Prekondisi: matriks terdefinisi
 */
boolean IsEmptyMatriks(matriks m);

/* Mengecek apakah sebuah matriks sudah penuh atau belum */
boolean IsFullMatriks (matriks m);

/**
 * Mengembalikan elemen matriks L yang ke-I (indeks lojik).
 * Prekondisi: matriks tidak kosong, i di antara 0..Length(matriks).
 */
char GetelmtMatriks(matriks arr, int i, int j);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: matriks terdefinisi, i di antara 0..Length(matriks).
 */
void InsertAtMatriks(matriks *arr, char el, int i, int j);

/**
 * Fungsi untuk menghapus elemen di index ke-i matriks
 * Prekondisi: matriks terdefinisi, i di antara 0..Length(matriks).
 */
void DeleteAtMatriks(matriks *arr, int i, int j);

/**
 * Fungsi untuk melakukan print suatu matriks.
 * Prekondisi: matriks terdefinisi
 */
void PrintMatriks(matriks arr);


#endif