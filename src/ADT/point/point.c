/* File: point.c */
/* Tanggal: 28 Agustus 2019 */
/* Implementasi ADT POINT */

#include <stdio.h>
#include <math.h>
#include "point.h"

// Nama : Muhammad Rizky Ismail Faizal
// NIM  : 13518148

POINT MakePOINT (int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
    scanf("%f %f", &(Absis(*P)), &(Ordinat(*P)));
}

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean ComparePOINT(POINT P1, POINT P2){
    return Absis(P1)==Absis(P2) && Ordinat(P1)==Ordinat(P2);
}
/* True jika kedua point berada pada absis dan ordinat yg sama */

boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    return (Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    return !EQ(P1,P2);
}

boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
    return (Absis(P) == 0) && (Ordinat(P) == 0);
}

boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
    return Ordinat(P) == 0;
}

boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
    return Absis(P) == 0;
}

int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
    if (Absis(P) > 0) {
        if (Ordinat(P) > 0) {
            return 1;
        } else {
            return 4;
        }
    } else {
        if (Ordinat(P) > 0) {
            return 2;
        } else {
            return 3;
        }
    }
}

POINT PlusDelta (POINT P, int deltaX, int deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    return MakePOINT(Absis(P)+deltaX, Ordinat(P)+deltaY);
}

void Geser (POINT *P, int deltaX, int deltaY) 
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void ReplacePOINT (POINT* P, int X, int Y){
    Absis(*P)=X; Ordinat(*P)=Y;
}
/* POINT P diganti absis dan ordinatnya menjadi X dan Y */