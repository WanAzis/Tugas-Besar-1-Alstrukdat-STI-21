#ifndef HANGMAN_H
#define HANGMAN_H

#include "../../boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/Array/Array.h"
#include "../../ADT/MesinKata/mesin_kata.h"
#include "../../ADT/MesinKata/mesin_karakter.h"

void Hangman();

void MakeTebakan(Word Jawaban, Word *Tebakan);

#endif