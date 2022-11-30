#include <stdio.h>
#include "time.h"
#include "som.h"

matriks Maps;
List Badan;
POINT Mkn, Met, Obs;
boolean GameOver;

/* Merupakan program utama dari game */
void SnakeonMeteor(int* Score){
    Maps = MakeMatriks();
    /* PERSIAPAN AWAL KONDISI TUBUH SNAKE DAN POSISI Mkn */
    srand(time(NULL));
    int abs = rand() % 5, ord = rand() % 5;
    POINT koordinat = MakePOINT(abs, ord);
    address P = Alokasi(koordinat);
    InsertLastlist(&Badan, P); // Pembuatan badan snake
    for(int i = 0; i<2; i++){
        TambahEkor(&Badan);
    }
    abs = rand() % 5; ord = rand() % 5; // Pembuatan posisi makanan
    Mkn = MakePOINT(abs, ord);
    // ComparePOINT(Mkn, Info(Next(First(Badan)))) || ComparePOINT(Mkn, Info(Next(Next(First(Badan)))))
    while (ComparePOINT(Mkn, Info(First(Badan))) || ComparePOINT(Mkn, Info(Next(First(Badan)))) || ComparePOINT(Mkn, Info(Last(Badan)))){
        abs = rand() % 5; ord = rand() % 5;
        Mkn = MakePOINT(abs, ord);
    }
    abs = rand() % 5; ord = rand() % 5; // Pembuatan posisi obs
    Obs = MakePOINT(abs, ord);
    while (ComparePOINT(Obs, Info(First(Badan))) || ComparePOINT(Obs, Info(Next(First(Badan)))) || ComparePOINT(Obs, Info(Last(Badan))) || ComparePOINT(Mkn, Obs)){
        abs = rand() % 5; ord = rand() % 5;
        Obs = MakePOINT(abs, ord);
    }
    UpdateMapsSOM(&Maps, Badan, Mkn, Met, Obs);
    PrintMatriks(Maps);

    /* TAHAP PERMAINAN */
    GameOver = false; // Penanda game masih terus berlanjut


}

/* Menampilkan kondisi terkini permainan kedalam peta */
void PrintPetaSOM(matriks Maps){}

/* Meng-update matriks Maps sesuai dengan kondisi terkini permainan */
void UpdateMapsSOM(matriks* Maps, List Badan, POINT Mkn, POINT Met, POINT Obs){
    (*Maps)=MakeMatriks();
    address P = First(Badan);
    InsertAtMatriks(Maps,KEPALA,Absis(Info(P)),Ordinat(Info(P))); P = Next(P);
    int j = 0;
    while(P!=NIL){
        InsertAtMatriks(Maps,j+'1',Absis(Info(P)),Ordinat(Info(P)));
        P = Next(P); j++;
    } Dealokasi(P);
    InsertAtMatriks(Maps,OBS,Absis(Obs),Ordinat(Obs));
    InsertAtMatriks(Maps,MAKANAN,Absis(Mkn),Ordinat(Mkn));
    // InsertAtMatriks(Maps,MET,Absis(Met),Ordinat(Met));
}

/* Memvalidasi langkah ular dalam permainan */
boolean isLangkahValid(matriks Maps){}

/* Prosedur satu TURN, TURN ditandakan dengan perubahan posisi tubuh snake dan penambahan ekor snake */
void ONETURNSOM(List* Badan, POINT* Obs, POINT* Met, POINT* Mkn){}

/* Prosedur untuk penambahan ekor pada ular */
void TambahEkor(List *Badan){
    address P = Last(*Badan); POINT ekor;
    if (GetelmtMatriks(Maps, Absis(Info(P)), Ordinat(Info(P))-1)==FLAG && Ordinat(Info(P))-1 >= 0){
        ekor = PlusDelta(Info(P),0,-1);
    } else if (GetelmtMatriks(Maps, Absis(Info(P))-1, Ordinat(Info(P)))==FLAG && Absis(Info(P))-1 >= 0){
        ekor = PlusDelta(Info(P),-1,0);
    } else if (GetelmtMatriks(Maps, Absis(Info(P))+1, Ordinat(Info(P)))==FLAG && Absis(Info(P))+1 <= 4){
        ekor = PlusDelta(Info(P),1,0);
    } else if (GetelmtMatriks(Maps, Absis(Info(P)), Ordinat(Info(P))+1)==FLAG && Ordinat(Info(P))+1 <= 4){
        ekor = PlusDelta(Info(P),0,1);
    } else {GameOver=true; return;}
    address add = Alokasi(ekor);
    InsertLastlist(Badan,add);
}

/* Menghitung score pemain yang telah GameOver */
int HitungScore(List Badan){}