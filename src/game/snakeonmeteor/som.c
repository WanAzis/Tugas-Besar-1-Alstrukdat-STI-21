#include <stdio.h>
#include "time.h"
#include "som.h"

matriks Maps;
List Badan;
POINT Mkn, Met, Obs;

/* Merupakan program utama dari game */
void SnakeonMeteor(int* Score){
    /* PERSIAPAN AWAL KONDISI TUBUH SNAKE DAN POSISI Mkn */
    srand(time(NULL));
    int abs = rand() % 5, ord = rand() % 5;
    POINT koordinat = MakePOINT(abs, ord);
    address P = Alokasi(koordinat);
    InsertLastlist(&Badan, P); // Pembuatan badan snake
    
    // for(int i = 0; i<2; i++){
    //     TambahEkor(&Badan);
    // }
    srand(time(NULL));
    abs = rand() % 5 + 3; ord = rand() % 5 + 3; // Pembuatan posisi makanan
    Mkn = MakePOINT(abs, ord);
    while (ComparePOINT(Mkn, Info(First(Badan))) || ComparePOINT(Mkn, Info(Next(First(Badan)))) || ComparePOINT(Mkn, Info(Next(Next(First(Badan)))))){
        abs = rand() % 5; ord = rand() % 5;
        Mkn = MakePOINT(abs, ord);
    }
    srand(time(NULL));
    abs = rand() % 5 + 1; ord = rand() % 5 + 1; // Pembuatan posisi obs
    Obs = MakePOINT(abs, ord);
    while (ComparePOINT(Mkn, Info(First(Badan))) || ComparePOINT(Mkn, Info(Next(First(Badan)))) || ComparePOINT(Mkn, Info(Next(Next(First(Badan))))) || ComparePOINT(Mkn, Obs)){
        abs = rand() % 5; ord = rand() % 5;
        Obs = MakePOINT(abs, ord);
    } InsertAtMatriks(&Maps,OBS,Absis(Obs),Ordinat(Obs));
    // UpdateMapsSOM(&Maps, Badan, Mkn, Met);
    PrintMatriks(Maps);

    /* TAHAP PERMAINAN */
    boolean GameOver = false; // Penanda game masih terus berlanjut


}

/* Menampilkan kondisi terkini permainan kedalam peta */
void PrintPetaSOM(matriks Maps){}

/* Meng-update matriks Maps sesuai dengan kondisi terkini permainan */
void UpdateMapsSOM(matriks* Maps, List Badan, POINT Mkn, POINT Met){
    (*Maps)=MakeMatriks();
    address P = First(Badan);
    InsertAtMatriks(Maps,KEPALA,Absis(Info(P)),Ordinat(Info(P))); P = Next(P);
    // while(P!=NIL){
    //     int j = 0;
    //     InsertAtMatriks(Maps,j+'1',Absis(Info(P)),Ordinat(Info(P)));
    //     P = Next(P);
    // } Dealokasi(P);
    InsertAtMatriks(Maps,MAKANAN,Absis(Mkn),Ordinat(Mkn));
    InsertAtMatriks(Maps,MET,Absis(Met),Ordinat(Met));
}

/* Memvalidasi langkah ular dalam permainan */
boolean isLangkahValid(matriks Maps){}

/* Prosedur satu TURN, TURN ditandakan dengan perubahan posisi tubuh snake dan penambahan ekor snake */
void ONETURNSOM(List* Badan, POINT* Obs, POINT* Met, POINT* Mkn){}

/* Prosedur untuk penambahan ekor pada ular */
void TambahEkor(List *Badan){}

/* Menghitung score pemain yang telah GameOver */
int HitungScore(List Badan){}