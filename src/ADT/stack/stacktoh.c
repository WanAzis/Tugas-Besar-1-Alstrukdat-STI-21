#include <stdio.h>
#include "stacktoh.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptystacktoh(Stacktoh *S, int n){
    S->T = (int *) malloc (n * sizeof(int));
    S->SCapacity = n;
    Top(*S)=-1;
}
/* I.S. sembarang*/
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptystacktoh(Stacktoh S){
    return Top(S)==-1;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullstacktoh(Stacktoh S){
    return Top(S)==S.SCapacity-1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Pushtoh(Stacktoh * S, int X){
    if (IsEmptystacktoh(*S)){
        Top(*S)=0;
    } else {
        Top(*S)++;
    }
    InfoTop(*S)=X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Poptoh(Stacktoh * S, int* X){
    *X = InfoTop(*S);
    if (Top(*S)==0){
        Top(*S)=-1;
    } else {
        Top(*S)--;
    }
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void Displaystacktoh(Stacktoh *S, int i) {
    if (Top(*S) == i) { /*kondisi kalau ada piringan di tingkat tersbeut*/
        for (int j=S->SCapacity-1;j>InfoTop(*S)/2;j--) {printf(" ");}
        for (int j=0;j<InfoTop(*S);j++) {printf("*");}
        for (int j=S->SCapacity-1;j>InfoTop(*S)/2;j--) {printf(" ");}
        printf("\t");
        Top(*S)--;
    }
    else { /*kondisi kalau misal gaada piringan di tingkat tersebut*/
        for (int j=S->SCapacity-1;j>0;j--) {printf(" ");}
        printf("|");
        for (int j=S->SCapacity-1;j>0;j--) {printf(" ");}
        printf("\t");
    }
}