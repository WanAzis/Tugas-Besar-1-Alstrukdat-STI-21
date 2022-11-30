#include <stdio.h>
#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyset(Set *S){
    COUNT(*S)=NIL;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyset(Set S){
    return COUNT(S)==NIL;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullset(Set S){
    return COUNT(S)==26;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insertset(Set *S, TypeSet Elmt){
    if(!IsMemberset(*S, Elmt)){
        ELMT(*S,COUNT(*S))=Elmt;
        COUNT(*S)++;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Deleteset(Set *S, TypeSet Elmt){
    boolean found = false;
    int i = 0;
    while (i<COUNT(*S) && !found){
        if(ELMT(*S,i)==Elmt){
            found = true;
        } else{
            i++;
        }
    }
    if (found){
        while (i<COUNT(*S)-1){
            ELMT(*S, i)=ELMT(*S, i+1);
            i++;
        } COUNT(*S)--;
    }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberset(Set S, TypeSet Elmt){
    boolean found = false;
    int i = 0;
    while (i<COUNT(S) && !found){
        if(ELMT(S,i)==Elmt){
            found= true;
        } else{
            i++;
        }
    } return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */