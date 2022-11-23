#include <stdio.h>
#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptystack(Stack *S){
    Top(*S)=-1;
}
/* I.S. sembarang*/
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptystack(Stack S){
    return Top(S)==-1;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullstack(Stack S){
    return Top(S)==100-1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, TypeStack X){
    if (IsEmptystack(*S)){
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
void Pop(Stack * S, TypeStack* X){
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

Stack Reversestack(Stack *S){
    Stack hasil; CreateEmptystack(&hasil);
    TypeStack x;
    while (!IsEmptystack(*S)){
        Pop(S,&x); Push(&hasil,x);
    } return hasil;
}
/* Menghasilkan stack yang merupakan kebalikan dari stack input S */

void CetakStack(Stack S){
    if (IsEmptystack(S)){
        printf("[]\n");
    } else{
        TypeStack Kata;
        printf("[");
        while (Top(S)!=0){
            Pop(&S,&Kata); PrintKata(Kata); printf(",");
        } Pop(&S,&Kata); PrintKata(Kata);
        printf("]\n");
    }
}
/* Mencetak stack S ke layar */