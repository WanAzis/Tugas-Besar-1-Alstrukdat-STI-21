#include <stdio.h>
#include <stdlib.h>
#include "toh.h"

void Tower_of_Hanoi(int *score){
    Stacktoh A, B, C;
    STARTWORD(); /*asumsi input pastilah sebuah integer*/
    int JmlPiringan = 0, counter = 0;
    for (int i = 0; i<currentWord.Length; i++){ /*looping untuk mengetahui nilai int*/
      JmlPiringan = (JmlPiringan * 10) + currentWord.TabWord[i] - '0';
    }
    CreateEmptystacktoh(&A, JmlPiringan);
    CreateEmptystacktoh(&B, JmlPiringan);
    CreateEmptystacktoh(&C, JmlPiringan);
    for (int i = A.SCapacity-1; i>=0;i--) {
      Pushtoh(&A, 1+(2*i));
    }
    char TiangIn, TiangOut;
    while (!IsFullstacktoh(C)) {
      Input_ToH(A, B, C, JmlPiringan, &TiangIn, &TiangOut); /*minta input dan checker valid/engga*/
      while (!Constrain_ToH(A, B, C, TiangIn, TiangOut)) { /*input melanggar constrain*/
        printf("Anda melanggar aturan! Tidak bisa memindahkan piringan yang lebih besar diatas piringan yang lebih kecil!\n");
        printf("Silahkan masukkan kembali input tiang asal dan tujuan!\n"); printf("\n");
        Input_ToH(A, B, C, JmlPiringan, &TiangIn, &TiangOut);
      }
      /*tidak melanggar constrain*/
      Move_Piringan(A, B, C, TiangIn, TiangOut);
      counter++;
    }
    printf("SELAMAT ANDA TELAH MEMEANANGKAN PERMAINAN!\n");
    *score = Score_Counter(counter, JmlPiringan);
}

void Display_ToH(Stacktoh A, Stacktoh B, Stacktoh C, int JmlPiringan) {
  for (int i=JmlPiringan-1; i>=0; i++) { /*looping print per line*/
    Displaystacktoh(A, i);
    Displaystacktoh(B, i);
    Displaystacktoh(C, i);
    printf("\n"); 
  }
  /*print alas dari stack*/
  for (int i=0;i<3;i++){
    for (int i=0;i<(JmlPiringan*2)-1;i++) {
      printf("=");
    }
    printf("   ");
  }
  printf("\n");
  /*print A, B, C*/
  for (int i=0;i<JmlPiringan;i++) {printf(" ");}
  printf("A");
  for (int i=0;i<JmlPiringan;i++) {printf(" ");}
  printf("   ");
  for (int i=0;i<JmlPiringan;i++) {printf(" ");}
  printf("B");
  for (int i=0;i<JmlPiringan;i++) {printf(" ");}
  printf("   ");
  for (int i=0;i<JmlPiringan;i++) {printf(" ");}
  printf("C");
  for (int i=0;i<JmlPiringan;i++) {printf(" ");}
  printf("   ");
  printf("\n");
}

void Input_ToH(Stacktoh A, Stacktoh B, Stacktoh C, int JmlPiringan, char *TiangIn, char *TiangOut) {
  Display_ToH(A, B, C, JmlPiringan);
  printf("TIANG ASAL: \n");
  STARTWORD(); /*menerima input tiang asal*/
  while (currentWord.Length != 1 && (currentWord.TabWord[0] != "A" && currentWord.TabWord[0] != 'B' && currentWord.TabWord[0] != 'C')) /*checker input valid/tidak*/
  { /*kalau tidak valid akan looping sampai valid*/
    printf("Input tidak valid, silahkan memilih tiang A, B, atau C!\n");
    printf("TIANG ASAL: \n");
    STARTWORD();
  }
  /*kondisi input valid*/
  *TiangIn = currentWord.TabWord[0];
  printf("TIANG TUJUAN: \n");
  STARTWORD();
  while (currentWord.Length != 1 && (currentWord.TabWord[0] != "A" && currentWord.TabWord[0] != 'B' && currentWord.TabWord[0] != 'C')) /*checker input valid/tidak*/
  { /*kalau tidak valid akan looping sampai valid*/
    printf("Input tidak valid, silahkan memilih tiang A, B, atau C!\n");
    printf("TIANG TUJUAN: \n");
    STARTWORD();
  }
  /*kondisi input valid*/
  *TiangOut = currentWord.TabWord[0];
}

boolean Constrain_ToH (Stacktoh A, Stacktoh B, Stacktoh C, char TiangIn, char TiangOut) {
  if (TiangIn == 'A' && TiangOut == 'B') {
    if (!IsEmptystacktoh(A) && IsEmptystacktoh(B)) {return true;}
    else if (IsEmptystacktoh(A)) {return false;}
    else { /*tiang asal tidak kosong, tiang akhir tidak kosong*/
      if (InfoTop(A)>InfoTop(B)) {return false;}
      else {return true;}}
  }
  else if (TiangIn == 'A' && TiangOut == 'C') {
    if (!IsEmptystacktoh(A) && IsEmptystacktoh(C)) {return true;}
    else if (IsEmptystacktoh(A)) {return false;}
    else { /*tiang asal tidak kosong, tiang akhir tidak kosong*/
      if (InfoTop(A)>InfoTop(C)) {return false;}
      else {return true;}}
  }
  else if (TiangIn == 'B' && TiangOut == 'A') {
    if (!IsEmptystacktoh(B) && IsEmptystacktoh(A)) {return true;}
    else if (IsEmptystacktoh(B)) {return false;}
    else { /*tiang asal tidak kosong, tiang akhir tidak kosong*/
      if (InfoTop(B)>InfoTop(A)) {return false;}
      else {return true;}}
  }
  else if (TiangIn == 'B' && TiangOut == 'C') {
    if (!IsEmptystacktoh(B) && IsEmptystacktoh(C)) {return true;}
    else if (IsEmptystacktoh(B)) {return false;}
    else { /*tiang asal tidak kosong, tiang akhir tidak kosong*/
      if (InfoTop(B)>InfoTop(C)) {return false;}
      else {return true;}}
  }
  else if (TiangIn == 'C' && TiangOut == 'A') {
    if (!IsEmptystacktoh(C) && IsEmptystacktoh(A)) {return true;}
    else if (IsEmptystacktoh(C)) {return false;}
    else { /*tiang asal tidak kosong, tiang akhir tidak kosong*/
      if (InfoTop(C)>InfoTop(A)) {return false;}
      else {return true;}}
  }
  else if (TiangIn == 'C' && TiangOut == 'B') {
    if (!IsEmptystacktoh(C) && IsEmptystacktoh(B)) {return true;}
    else if (IsEmptystacktoh(C)) {return false;}
    else { /*tiang asal tidak kosong, tiang akhir tidak kosong*/
      if (InfoTop(C)>InfoTop(B)) {return false;}
      else {return true;}}
  }
  else if (TiangIn == 'A' && TiangOut == 'A') {return false;}
  else if (TiangIn == 'B' && TiangOut == 'B') {return false;}
  else if (TiangIn == 'C' && TiangOut == 'C') {return false;}
}
void Move_Piringan(Stacktoh A, Stacktoh B, Stacktoh C, char TiangIn, char TiangOut) {
  int Piringan;
  if (TiangIn == 'A' && TiangOut == 'B') {
    Poptoh(&A, &Piringan); Pushtoh(&B, Piringan);
  }
  else if (TiangIn == 'A' && TiangOut == 'C') {
    Poptoh(&A, &Piringan); Pushtoh(&C, Piringan);
  }
  else if (TiangIn == 'B' && TiangOut == 'A') {
    Poptoh(&B, &Piringan); Pushtoh(&A, Piringan);
  }
  else if (TiangIn == 'B' && TiangOut == 'C') {
    Poptoh(&B, &Piringan); Pushtoh(&C, Piringan);
  }
  else if (TiangIn == 'C' && TiangOut == 'A') {
    Poptoh(&C, &Piringan); Pushtoh(&A, Piringan);
  }
  else if (TiangIn == 'C' && TiangOut == 'B') {
    Poptoh(&C, &Piringan); Pushtoh(&B, Piringan);
  }
}

int Score_Counter(int counter, int JumlahPiringan) {
  int score, 
  minscore = 0,
  minmoves = 1, 
  maxscore = JumlahPiringan*2, /*maxscore akan bertambah dan berkurang bergantung Jumlah Piringan*/ 
  maxmoves = minmoves*((JumlahPiringan*2)+1); /*perhitungan maxmoves, jika lebih score akan nol*/

  for (int i = 0; i<JumlahPiringan;i++){
    minmoves = minmoves*2;
  } /*looping untuk pembagi counter nantinya*/

  if (counter >= maxmoves) {return 0;} /*kasus pemain movesnya melebihi maxmoves*/
  else { /*kalau movesnya masih lebih kecil dari maxmoves*/
    score = maxscore-((counter/minmoves-1)-1);
    return score;
  }
}