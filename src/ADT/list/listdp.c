// ADT List Berkait dengan pointer double

#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptylist (List L){
    return First(L) == NULL && Last(L) == NULL;
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptylist (List *L){
    First(*L)=NULL; Last(*L)=NULL;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    ElmtList *P = (ElmtList*) malloc (sizeof(ElmtList));
    if (P!=NULL){
        Info(P)=X; Next(P)=NULL; Prev(P)=NULL;
    } return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Searchlist (List L, infotype X){
    address hasil=NULL;
    if (!IsEmptylist(L)){
        address P = First(L);
        boolean found = false;
        while (P!=NULL && !found){
            if(Absis(Info(P))==Absis(X) && Ordinat(Info(P))==Ordinat(X)){
                found = true; hasil = P;
            } else {
                P = Next(P);
            }
        }
    } return hasil;
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);
    if (P!=NULL){
        InsertFirstlist(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
    if (P!=NULL){
        InsertLastlist(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    address P;
    DelFirstlist(L, &P);
    *X = Info(P); Dealokasi(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
    address P; DelLastlist(L, &P);
    *X = Info(P); Dealokasi(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstlist (List *L, address P){
    if (IsEmptylist(*L)){
        First(*L)=P; Last(*L)=P;
    } else {
        Next(P)=First(*L);
        Prev(First(*L))=P;
        First(*L)=Prev(First(*L));
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLastlist (List *L, address P){
    if (IsEmptylist(*L)){
        First(*L)=P; Last(*L)=P;
    } else {
        Next(Last(*L))=P;
        Prev(P)=Last(*L);
        Last(*L)=Next(Last(*L));
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
    Next(P)=Next(Prec); Prev(P)=Prec;
    Next(Prec)=P; Prev(Next(P))=P;
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ){
    Next(P)=Succ; Prev(P)=Prev(Succ);
    Prev(Succ)=P; Next(Prev(P))=P;
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstlist (List *L, address *P){
    *P = First(*L);
    if (First(*L)==Last(*L)){
        CreateEmptylist(L);
    } else {
        First(*L)=Next(First(*L));
        Next(*P)=NULL; Prev(First(*L))=NULL;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastlist (List *L, address *P){
    *P = Last(*L);
    if (First(*L)==Last(*L)){
        CreateEmptylist(L);
    } else {
        Last(*L)=Prev(Last(*L));
        Prev(*P)=NULL; Next(Last(*L))=NULL;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X){
    address P = Searchlist(*L, X);
    if (P!=NULL){
        if (P==First(*L)){
            DelFirstlist(L, &P);
        } else if (P==Last(*L)){
            DelLastlist(L, &P);
        } else {
            Next(Prev(P))=Next(P);
            Prev(Next(P))=Prev(P);
        }
    } Dealokasi(P);
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec){
    if (Next(Prec)==Last(*L)){
        DelLastlist(L, Pdel);
    } else {
        *Pdel=Next(Prec);
        Next(Prec)=Next(*Pdel); Prev(Next(*Pdel))=Prec;
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ){
    if (Prev(Succ)==First(*L)){
        DelFirstlist(L, Pdel);
    } else {
        *Pdel=Prev(Succ);
        Prev(Succ)=Prev(*Pdel); Next(Prev(*Pdel))=Succ;
    }
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
    if (IsEmptylist(L)){
        printf("[]");
    } else {
        address P=First(L);
        printf("[");
        while (P!=Last(L)){
            TulisPOINT(Info(P));printf(",");
            P = Next(P);
        } TulisPOINT(Info(Last(L)));
        printf("]");
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L){
    if (IsEmptylist(L)){
        printf("[]");
    } else {
        address P=Last(L);
        printf("[");
        while (P!=First(L)){
            TulisPOINT(Info(P));printf(",");
            P = Prev(P);
        } TulisPOINT(Info(First(L)));
        printf("]");
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kiri: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */