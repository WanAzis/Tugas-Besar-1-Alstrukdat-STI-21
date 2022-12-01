#include <stdio.h>
#include "time.h"
#include "som.h"

matriks Maps;
List Badan;
POINT Mkn, Met, Obs;
boolean GameOver;

/* Merupakan program utama dari game */
void SnakeonMeteor(int* Score){
    Maps = MakeMatriks(); //Inisialisasi Maps Kosong

    /* PERSIAPAN AWAL KONDISI TUBUH SNAKE DAN POSISI Mkn serta Obs */
    srand(time(NULL));
    int abs = rand() % 5, ord = rand() % 5;
    POINT koordinat = MakePOINT(abs, ord);
    address P = Alokasi(koordinat);
    InsertLastlist(&Badan, P); // Pembuatan badan snake
    for(int i = 0; i<2; i++){
        TambahEkor(&Badan); //Penambahan 2 ekor awal
    }
    abs = rand() % 5; ord = rand() % 5; // Pembuatan posisi makanan
    Mkn = MakePOINT(abs, ord);
    while (ComparePOINT(Mkn, Info(First(Badan))) || ComparePOINT(Mkn, Info(Next(First(Badan)))) || ComparePOINT(Mkn, Info(Last(Badan)))){
        abs = rand() % 5; ord = rand() % 5;
        Mkn = MakePOINT(abs, ord);
    } //Memastikan posisi makanan tidak sama dengan posisi tubuh snake
    abs = rand() % 5; ord = rand() % 5; // Pembuatan posisi obs
    Obs = MakePOINT(abs, ord);
    while (ComparePOINT(Obs, Info(First(Badan))) || ComparePOINT(Obs, Info(Next(First(Badan)))) || ComparePOINT(Obs, Info(Last(Badan))) || ComparePOINT(Obs, Mkn)){
        abs = rand() % 5; ord = rand() % 5;
        Obs = MakePOINT(abs, ord);
    } //Memastikan posisi obstacle tidak sama dengan posisi tubuh snake dan Mkn

    /* Setup Maps awal */
    P = First(Badan);
    InsertAtMatriks(&Maps,KEPALA,Absis(Info(P)),Ordinat(Info(P))); P = Next(P);
    int j = 0;
    while(P!=NIL){
        InsertAtMatriks(&Maps,j+'1',Absis(Info(P)),Ordinat(Info(P)));
        P = Next(P); j++;
    } Dealokasi(P);
    InsertAtMatriks(&Maps,OBS,Absis(Obs),Ordinat(Obs));
    InsertAtMatriks(&Maps,MAKANAN,Absis(Mkn),Ordinat(Mkn));
    PrintMatriks(Maps);

    /* TAHAP PERMAINAN */
    GameOver = false; // Penanda game masih terus berlanjut
    int Turn = 1; int TypeGO;
    while (!GameOver){
        printf("TURN %i:\n");
        printf("Silahkan masukkan command anda: "); STARTWORD(); printf("\n");
        if (!isLangkahValid(Maps,currentWord)){
            if(!GameOver){
                printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
            }
        } else {
            printf("\nBerhasil bergerak!\n");
            ONETURNSOM(currentWord,&Badan,&Met,&Mkn, &TypeGO); UpdateMapsSOM(&Maps,Badan,Mkn,Met,Obs);
            PrintMatriks(Maps);
            Turn++;
        }
    } //GameOver, Permainan berakhir
    int score = HitungScore(Badan);
    printf("Game berakhir. Skor: %i\n", score); (*Score)=score;
}

/* Menampilkan kondisi terkini permainan kedalam peta */
void PrintPetaSOM(matriks Maps){}

/* Meng-update matriks Maps sesuai dengan kondisi terkini permainan mulai dari turn ke 2 */
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
boolean isLangkahValid(matriks Maps, Word kata){
    
}

/* Prosedur satu TURN, TURN ditandakan dengan perubahan posisi tubuh snake dan penambahan ekor snake */
void ONETURNSOM(Word kata, List* Badan, POINT* Met, POINT* Mkn, int* type){}

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