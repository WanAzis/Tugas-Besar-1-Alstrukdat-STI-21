#ifndef set_H
#define set_H

#include "../../boolean.h"
#include "../mesinkata/mesin_kata.h"

/* MODUL Set
Deklarasi set yang dengan implementasi array eksplisit-statik rata kiri
*/

#define NIL 0

typedef Word TypeSet;
typedef int idx;

typedef struct
{
    TypeSet Elements[100];
    idx Count;
} Set;

#define COUNT(S) (S).Count
#define ELMT(S,i) (S).Elements[i]

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyset(Set *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyset(Set S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullset(Set S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insertset(Set *S, TypeSet Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Deleteset(Set *S, TypeSet Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberset(Set S, TypeSet Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

#endif