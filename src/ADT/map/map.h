#ifndef map_H
#define map_H

#include "../../boolean.h"
#include "../mesinkata/mesin_kata.h"

/* MODUL Map
Deklarasi map yang dengan implementasi array eksplisit-statik rata kiri
*/

#define Nil 0
#define MaxEl 30
#define Undefined -999

// typedef int bool;
typedef Word keytype;
typedef int valuetype;
typedef int add;

typedef struct {
	keytype Key;
	valuetype Value;
} TypeInfo;

typedef struct {
	TypeInfo Elements[MaxEl];
	add Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptymap(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptymap(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullmap(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insertmap(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M dengan v yang berurut dari terbesar. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Deletemap(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMembermap(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

void CetakMap(Map M);
/* Mencetak Map M kelayar */

#endif