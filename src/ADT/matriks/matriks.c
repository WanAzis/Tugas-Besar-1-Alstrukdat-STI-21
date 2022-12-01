#include <stdio.h>
#include "matriks.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk matriks kosong dengan ukuran InitialSize
 */
matriks MakeMatriks(){
    matriks m;
    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++){
            InsertAtMatriks(&m, FLAG, i, j);
        }
    }
    return m;
}

/**
 * Fungsi untuk mengetahui apakah suatu matriks kosong.
 * Prekondisi: matriks terdefinisi
 */
boolean IsEmptyMatriks(matriks m){
    boolean found = true;
    int i = 0;
    while (i<5 && found){
        int j = 0;
        while (j<5 && found){
            if (GetelmtMatriks(m,i,j)!=FLAG){
                found = false;
            } else {j++;}
        } 
        if (found){
            i++;
        }
    }
    return found;
}

/* Mengecek apakah sebuah matriks sudah penuh atau belum */
boolean IsFullMatriks (matriks m){
    boolean found = false;
    int i = 0;
    while (i<5 && !found){
        int j = 0;
        while (j<5 && !found){
            if (GetelmtMatriks(m,i,j)==FLAG){
                found = true;
            } else {j++;}
        } 
        if (!found){
            i++;
        }
    }
    return found;
}

/**
 * Mengembalikan elemen matriks L yang ke-I (indeks lojik).
 * Prekondisi: matriks tidak kosong, i di antara 0..Length(matriks).
 */
char GetelmtMatriks(matriks m, int i, int j){
    return m.A[i].arr[j];
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: matriks terdefinisi, i di antara 0..Length(matriks).
 */
void InsertAtMatriks(matriks *m, char el, int i, int j){
    (*m).A[i].arr[j]=el;
}

/**
 * Fungsi untuk menghapus elemen di index ke-i matriks
 * Prekondisi: matriks terdefinisi, i di antara 0..Length(matriks).
 */
void DeleteAtMatriks(matriks *m, int i, int j){
    (*m).A[i].arr[j]=FLAG;
}

/**
 * Fungsi untuk melakukan print suatu matriks.
 * Prekondisi: matriks terdefinisi
 */
void PrintMatriks(matriks m){
    printf("[\n");
    for(int i = 0; i<5; i++){
        printf("{%c", GetelmtMatriks(m,i,0));
        for (int j = 1; j<5; j++){
            printf(",%c", GetelmtMatriks(m,i,j));
        } printf("}"); if(i<4){printf("\n");}
    } printf("\n]\n");
}