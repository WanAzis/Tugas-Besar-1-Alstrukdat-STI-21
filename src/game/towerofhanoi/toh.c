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
      Input_ToH(A, B, C, &TiangIn, &TiangOut); /*minta input dan checker valid/engga*/
      while (!Constrain_ToH(A, B, C, TiangIn, TiangOut)) { /*input melanggar constrain*/
        printf("Anda melanggar aturan! Tidak bisa memindahkan piringan yang lebih besar diatas piringan yang lebih kecil!\n");
        printf("Silahkan masukkan kembali input tiang asal dan tujuan!\n"); printf("\n");
        Input_ToH(A, B, C, &TiangIn, &TiangOut);
      }
      /*tidak melanggar constrain*/
      Move_Piringan(A, B, C, TiangIn, TiangOut);
      counter++;
    printf("SELAMAT ANDA TELAH MEMEANANGKAN PERMAINAN!\n");
    *score = Score_Counter(counter, JmlPiringan);
  }
}

void Display_ToH(Stacktoh A, Stacktoh B, Stacktoh C) {
  /*display nya bingung mau gimana jujur, ini printstack dulu aja ya*/
  printf("TIANG A:\n");
  if (IsEmptystacktoh(A)){
      printf("[]\n");
  } 
  else {
      int Piringan;
      printf("[");
      while (Top(A)!=0){
          Poptoh(&A,&Piringan); printf("%i, ",Piringan);
      } Poptoh(&A,&Piringan); printf("%i",Piringan);
      printf("]\n");
  }
  printf("TIANG B:\n");
  if (IsEmptystacktoh(B)){
      printf("[]\n");
  } 
  else {
      int Piringan;
      printf("[");
      while (Top(B)!=0){
          Poptoh(&B,&Piringan); printf("%i, ",Piringan);
      } Poptoh(&B,&Piringan); printf("%i",Piringan);
      printf("]\n");
  }
  printf("TIANG C:\n");
  if (IsEmptystacktoh(C)){
      printf("[]\n");
  } 
  else {
      int Piringan;
      printf("[");
      while (Top(C)!=0){
          Poptoh(&C,&Piringan); printf("%i, ",Piringan);
      } Poptoh(&C,&Piringan); printf("%i",Piringan);
      printf("]\n");
  }
}

void Input_ToH(Stacktoh A, Stacktoh B, Stacktoh C, char *TiangIn, char *TiangOut) {
  Display_ToH(A, B, C);
  printf("TIANG ASAL: \n");
  STARTWORD(); /*menerima input tiang asal*/
  while (currentWord.Length != 1 && (currentWord.TabWord[0] != 'A' && currentWord.TabWord[0] != 'B' && currentWord.TabWord[0] != 'C')) /*checker input valid/tidak*/
  { /*kalau tidak valid akan looping sampai valid*/
    printf("Input tidak valid, silahkan memilih tiang A, B, atau C!\n");
    printf("TIANG ASAL: \n");
    STARTWORD();
  }
  *TiangIn = currentWord.TabWord[0];
  /*kondisi input valid*/
  printf("TIANG TUJUAN: \n");
  STARTWORD();
  while (currentWord.Length != 1 && (currentWord.TabWord[0] != 'A' && currentWord.TabWord[0] != 'B' && currentWord.TabWord[0] != 'C')) /*checker input valid/tidak*/
  { /*kalau tidak valid akan looping sampai valid*/
    printf("Input tidak valid, silahkan memilih tiang A, B, atau C!\n");
    printf("TIANG TUJUAN: \n");
    STARTWORD();
  }
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
  int score, minmoves = 1;
  for (int i = 0; i<JumlahPiringan;i++){
    minmoves = minmoves*2;
  }
  score = 10-((counter/minmoves-1)-1);
  return score;
}