#ifndef HANGMAN_H
#define HANGMAN_H

#include "time.h"
#include "../../boolean.h"
#include "../../ADT/Array/Array.h"
#include "../../ADT/MesinKata/mesin_kata.h"

void Hangman();

void MakeTebakan(Word Jawaban, Word *Tebakan);

boolean CheckJawab(Word Jawaban, Word* Tebakan);

#endif