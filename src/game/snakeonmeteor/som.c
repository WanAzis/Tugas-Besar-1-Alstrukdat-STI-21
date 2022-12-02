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
    //ComparePOINT(Mkn, Info(First(Badan))) || ComparePOINT(Mkn, Info(Next(First(Badan)))) || ComparePOINT(Mkn, Info(Last(Badan)))
    while (checkBadanUlar(Badan,Mkn)){
        abs = rand() % 5; ord = rand() % 5;
        Mkn = MakePOINT(abs, ord);
    } //Memastikan posisi makanan tidak sama dengan posisi tubuh snake
    abs = rand() % 5; ord = rand() % 5; // Pembuatan posisi obs
    Obs = MakePOINT(abs, ord);
    //ComparePOINT(Obs, Info(First(Badan))) || ComparePOINT(Obs, Info(Next(First(Badan)))) || ComparePOINT(Obs, Info(Last(Badan)))
    while (checkBadanUlar(Badan,Obs) || ComparePOINT(Obs, Mkn)){
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
    printf("Maps awal\n");
    PrintMatriks(Maps);

    /* TAHAP PERMAINAN */
    GameOver = false; // Penanda game masih terus berlanjut
    int Turn = 1; int TypeGO;
    while (!GameOver){
        printf("TURN %i:\n", Turn);
        printf("Silahkan masukkan command anda: "); STARTWORD(); printf("\n");
        if (isLangkahValid(Maps,currentWord,Badan,&TypeGO)){
            printf("\nBerhasil bergerak!\n");
            ONETURNSOM(currentWord,&Badan,&Met,&Mkn, &TypeGO); 
            // UpdateMapsSOM(&Maps,Badan,Mkn,Met,Obs);
            // printf("Kondisi Map\n");
            // PrintMatriks(Maps);
            Turn++;
        }
    } //GameOver, Permainan berakhir
    //tuliskan gameover karena apa
    if (TypeGO==1){
        printf("GameOver. Kepala ular terkena meteor!\n");
    } else if (TypeGO==2){
        printf("GameOver. Ular tidak dapat bergerak kemanapun!\n");
    } else if (TypeGO==3){
        printf("GameOver. Kepala ular menambrak obstacle!\n");
    }
    int score = HitungScore(Badan,TypeGO);
    printf("Skor Anda: %i\n", score); (*Score)=score;
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
    InsertAtMatriks(Maps,MET,Absis(Met),Ordinat(Met));
}

/* Memvalidasi langkah ular dalam permainan */
boolean isLangkahValid(matriks Maps, Word kata, List Badan, int* type){
    boolean valid = true;
    if(kata.Length!=1){
        printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        return false;
    } else {
        if (kata.TabWord[0]!='w' && kata.TabWord[0]!='a' && kata.TabWord[0]!='s' && kata.TabWord[0]!='d'){
            printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
            return false;
        } else {
            if (kata.TabWord[0]!='w' && GetelmtMatriks(Maps,(Absis(Info(First(Badan)))-1) % 5,Ordinat(Info(First(Badan)))) == FLAG){
                return true;
            } else if (kata.TabWord[0]!='a' && GetelmtMatriks(Maps,Absis(Info(First(Badan))),(Ordinat(Info(First(Badan)))-1) % 5) == FLAG){
                return true;
            } else if (kata.TabWord[0]!='s' && GetelmtMatriks(Maps,(Absis(Info(First(Badan)))+1) % 5,Ordinat(Info(First(Badan)))) == FLAG){
                return true;
            } else if (kata.TabWord[0]!='d' && GetelmtMatriks(Maps,Absis(Info(First(Badan))),(Ordinat(Info(First(Badan)))+1) % 5) == FLAG){
                return true;
            } else if (GetelmtMatriks(Maps,(Absis(Info(First(Badan)))-1) % 5,Ordinat(Info(First(Badan)))) == FLAG ||
                       GetelmtMatriks(Maps,Absis(Info(First(Badan))),(Ordinat(Info(First(Badan)))-1) % 5) == FLAG ||
                       GetelmtMatriks(Maps,(Absis(Info(First(Badan)))+1) % 5,Ordinat(Info(First(Badan)))) == FLAG ||
                       GetelmtMatriks(Maps,Absis(Info(First(Badan))),(Ordinat(Info(First(Badan)))+1) % 5) == FLAG){
                printf("Ular gagal bergerak, silahkan input ulang command\n");
                return false;
            } else if (GetelmtMatriks(Maps,(Absis(Info(First(Badan)))-1) % 5,Ordinat(Info(First(Badan)))) == MAKANAN ||
                       GetelmtMatriks(Maps,Absis(Info(First(Badan))),(Ordinat(Info(First(Badan)))-1) % 5) == MAKANAN ||
                       GetelmtMatriks(Maps,(Absis(Info(First(Badan)))+1) % 5,Ordinat(Info(First(Badan)))) == MAKANAN ||
                       GetelmtMatriks(Maps,Absis(Info(First(Badan))),(Ordinat(Info(First(Badan)))+1) % 5) == MAKANAN){
                printf("Ular gagal bergerak, silahkan input ulang command\n");
                return false;
            } else {
                GameOver = true; *type=2; return false;
            }
        }
    }
}

/* Prosedur satu TURN, TURN ditandakan dengan perubahan posisi tubuh snake dan penambahan ekor snake serta peruabah posisi meteor */
void ONETURNSOM(Word kata, List* Badan, POINT* Met, POINT* Mkn, int* type){
    /* Menggerakkan kepala ular, serta badan yang mengikuti pergerakan kepala atau bagian badan sebelumnya */
    address P = Last(*Badan);
    while (P!=First(*Badan)){
        ReplacePOINT(&Info(P),Absis(Info(Prev(P))),Ordinat(Info(Prev(P))));
        P = Prev(P);
    } //P berada di kepala ular
    if (kata.TabWord[0]=='w'){
        ReplacePOINT(&Info(P),(Absis(Info(P))-1) % 5,Ordinat(Info(P)));
        // Geser(&Info(P),-1,0);
    } else if (kata.TabWord[0]=='a'){
        ReplacePOINT(&Info(P),Absis(Info(P)),(Ordinat(Info(P))-1) % 5);
        // Geser(&Info(P),0,-1);
    } else if (kata.TabWord[0]=='s'){
        ReplacePOINT(&Info(P),(Absis(Info(P))+1) % 5,Ordinat(Info(P)));
        // Geser(&Info(P),1,0);
    } else if (kata.TabWord[0]=='d'){
        ReplacePOINT(&Info(P),Absis(Info(P)),(Ordinat(Info(P))+1) % 5);
        // Geser(&Info(P),0,1);
    } //Posisi kepala dan badan ular sudah sesuai

    /* Men-generate posisi meteor dan makanan baru (jika sudah dimakan) */
    int abs,ord;
    if (ComparePOINT(Info(First(*Badan)),*Mkn)){
        TambahEkor(Badan); //Menambah ekor ular sesuai aturan
        // srand(time(NULL));
        abs = rand() % 5; ord = rand() % 5; // Pembuatan posisi makanan
        ReplacePOINT(Mkn,abs,ord);
        while (checkBadanUlar(*Badan,*Mkn) && ComparePOINT(*Mkn,Obs)){
            abs = rand() % 5; ord = rand() % 5;
            ReplacePOINT(Mkn,abs,ord);
        } //Memastikan posisi makanan tidak sama dengan posisi tubuh snake dan Obs
    }
    abs = rand() % 5; ord = rand() % 5; // Pembuatan posisi Meteor
    ReplacePOINT(Met,abs,ord);
    while (ComparePOINT(*Met, *Mkn) && ComparePOINT(*Met,Obs)){
        abs = rand() % 5; ord = rand() % 5;
        ReplacePOINT(Met,abs,ord);
    } //Memastikan posisi meteor tidak sama dengan posisi Mkn

    /* Mengecek apakah ular menabrak obs atau tidak */
    if(ComparePOINT(Info(First(*Badan)),Obs)){
        UpdateMapsSOM(&Maps,*Badan,*Mkn,*Met,Obs);
        printf("Kondisi map\n");
        PrintMatriks(Maps); printf("\n");
        GameOver = true; *type=3; return;
    }

    UpdateMapsSOM(&Maps,*Badan,*Mkn,*Met,Obs);
    printf("Kondisi map\n");
    PrintMatriks(Maps); printf("\n");

    P = Searchlist(*Badan,*Met); //Mengecek apakah ada koordinat Met pada badan ular
    if(P!=NIL){
        if(P==First(*Badan)){
            GameOver = true; *type=1; return;
        }
        printf("Anda terkena meteor!\nBerikut merupakan kondisi map terkini\n");
        DelP(Badan,*Met);
        UpdateMapsSOM(&Maps,*Badan,*Mkn,*Met,Obs);
        PrintMatriks(Maps);
    } else {Dealokasi(P);}

}

/* Prosedur untuk penambahan ekor pada ular */
void TambahEkor(List *Badan){
    address P = Last(*Badan); POINT ekor;
    if ((GetelmtMatriks(Maps, Absis(Info(P)), Ordinat(Info(P))-1)==FLAG) && ((Ordinat(Info(P))-1) >= 0)){
        ekor = PlusDelta(Info(P),0,-1);
    } else if ((GetelmtMatriks(Maps, Absis(Info(P))-1, Ordinat(Info(P)))==FLAG) && ((Absis(Info(P))-1) >= 0)){
        ekor = PlusDelta(Info(P),-1,0);
    } else if ((GetelmtMatriks(Maps, Absis(Info(P))+1, Ordinat(Info(P)))==FLAG) && ((Absis(Info(P))+1) <= 4)){
        ekor = PlusDelta(Info(P),1,0);
    } else if ((GetelmtMatriks(Maps, Absis(Info(P)), Ordinat(Info(P))+1)==FLAG) && ((Ordinat(Info(P))+1) <= 4)){
        ekor = PlusDelta(Info(P),0,1);
    }
    address add = Alokasi(ekor);
    InsertLastlist(Badan,add);
}

/* Mengecek apakah sebuah koordinat titik ada pada badan ular */
boolean checkBadanUlar(List Badan, POINT P){
    boolean found = false;
    address loc = First(Badan);
    while (loc!=NIL && !found){
        if (ComparePOINT(Info(loc),P)){
            found = true;
        } else {
            loc = Next(loc);
        }
    } return found;
}

/* Menghitung score pemain yang telah GameOver */
int HitungScore(List Badan, int type){
    int score=0; address P;
    if (type==1){
        P = Next(First(Badan));
    } else {P = First(Badan);}

    if (P!=NIL){
        while(P!=NIL){
            score++; P = Next(P);
        }
    } return score*2;
}