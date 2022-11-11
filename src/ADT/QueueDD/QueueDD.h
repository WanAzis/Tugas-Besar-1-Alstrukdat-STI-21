/* Queue yang digunakan khusus untuk mengimplementasi game Dinner Dash */
/* Definisi ADT Queue dengan representasi array secara eksplisit, alternatif 1, dan alokasi statik */

#ifndef QUEUE_DD_H
#define QUEUE_DD_H

#include "../../boolean.h"
#include "../MesinKata/mesin_kata.h"

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef struct {
        int id;
        int durasi;
        int ketahanan;
        int harga;
} Food;

typedef struct {
	Food buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} QueueDD;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void MakeQueue(QueueDD *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean ISEmpty(QueueDD q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean IsFull(QueueDD q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int Len(QueueDD q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void Enqueue(QueueDD *q, Food val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void DequeueAt(QueueDD *q, Food *val, int idx);
/* Proses: Menghapus val pada q dengan idx sesuai inputan */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen idx pd I.S., element setelah idx bergeser; 
        q mungkin kosong */

/* *** Display Queue *** */
void DisplayQueue(QueueDD q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

#endif