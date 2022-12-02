#ifndef HANGMAN_H
#define HANGMAN_H

#include "time.h"
#include "../../boolean.h"
#include "../../ADT/Array/Array.h"
#include "../../ADT/MesinKata/mesin_kata.h"

/* Fungsi utama game */
void Hangman(int* Score);

/* Menyiapkan Word Tebakan */
void MakeTebakan(Word Jawaban, Word *Tebakan);

/* Mengecek apakah input terdapat dalam Jawaban */
boolean CheckJawab(Word Jawaban, Word* Tebakan, Word input);

/* Men-generate kata baru dari array */
void generateKata(array* arr, Word* Jawaban);

#endif