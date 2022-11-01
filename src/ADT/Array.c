#include <stdio.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (array *T)
// procedure MakeEmpty (output T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    (*T).Neff = 0;
}
/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (array T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return T.Neff;
}
/* *** Daya tampung container *** */
int MaxNbEl (array T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return IdxMax-IdxMin+1;
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (array T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
    return IdxMin;
}
IdxType GetLastIdx (array T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{
    return NbElmt(T);
}
/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (array T, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
    return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (array Tin, array *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
{
    // array T;
    int i;
    for (i = GetFirstIdx(Tin); i<=GetLastIdx(Tin); i++){
        (*Tout).TI[i] = GetElmt(Tin,i);
    } (*Tout).Neff = Tin.Neff;
    // *Tout = T;
}
/* Assignment THsl -> Tin */
void SetEl (array *T, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
// *T = [1,2,3,4,5,6]
{
    (*T).TI[i] = v;
    if (i == GetLastIdx(*T)+1){
        (*T).Neff++;
    }
}
void SetNeff (array *T, IdxType N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
    (*T).Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (array T, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i>=IdxMin) && (i<=IdxMax);
}
boolean IsIdxEff (array T, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return (i>=GetFirstIdx(T)) && (i<=GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (array T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return NbElmt(T)==0;
}
/* *** Test tabel penuh *** */
boolean IsFull (array T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return NbElmt(T)==MaxNbEl(T);
    // T.Neff==maxelmt;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (array T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
{
    if (IsEmpty(T)){
        printf("Tabel kosong\n");
    } else {
    int j;
    for (j=GetFirstIdx(T); j<=GetLastIdx(T); j++){
        printf("%i:%i\n", j, GetElmt(T,j));
    }
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
array PlusTab (array T1, array T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
{
    array TSum;
    MakeEmpty(&TSum);
    SetNeff(&TSum,NbElmt(T1));
    // TSum.Neff = T1.Neff;
    for (int i = GetFirstIdx(T1); i<=GetLastIdx(T1); i++){
        // TSum.TI[i] = T1.TI[i] + T2.TI[i];
        SetEl(&TSum, i, GetElmt(T1, i) + GetElmt(T2, i));
    } return TSum;
}
array MinusTab (array T1, array T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */
{
    array TMin;
    MakeEmpty(&TMin);
    SetNeff(&TMin,NbElmt(T1));
    for (int i = GetFirstIdx(T1); i<=GetLastIdx(T1); i++){
        // TMin.TI[i] = T1.TI[i] + T2.TI[i];
        SetEl(&TMin, i, GetElmt(T1, i) - GetElmt(T2, i));
    } return TMin;
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (array T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
// [4,7,8,10]
{
    int maks=GetElmt(T,GetFirstIdx(T));
    for (int i = GetFirstIdx(T)+1; i<=GetLastIdx(T); i++){
        if (maks < GetElmt(T,i)){
            maks = T.TI[i];
        }
    } return maks;
}

ElType ValMin (array T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
    int mins=GetElmt(T,GetFirstIdx(T));
    for (int i = GetFirstIdx(T)+1; i<=GetLastIdx(T); i++){
        if (mins > GetElmt(T,i)){
            mins = T.TI[i];
        }
    } return mins;
}

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (array T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
{
    int valmaks = ValMax(T);
    int i = IdxMin;
    // boolean found = false;
    while ((i<=GetLastIdx(T)) && (GetElmt(T,i) != valmaks)){
        i++;
    } return i;
    // return GetElmt(T,idxmaks);
}

IdxType IdxMinTab (array T)
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
{
    int valmins = ValMin(T);
    int i = IdxMin;
    // boolean found = false;
    while ((i<=GetLastIdx(T)) && (GetElmt(T,i) != valmins)){
        i++;
    } return i;
    // return GetElmt(T,idxmins);
}