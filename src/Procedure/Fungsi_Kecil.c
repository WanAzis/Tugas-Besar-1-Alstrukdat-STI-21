#include <stdio.h>
#include "fungsi_kecil.h"

void UIAwal(){
  printf("\t     _____________________________ \n");   
  printf("\t    /        _____________        \\ \n");  
  printf("\t    | == .  |             |     o | \n");  
  printf("\t    |   _   | WELCOME     |    B  | \n");  
  printf("\t    |  / \\  |             | A   O | \n");  
  printf("\t    | | O | |     TO      |  O    | \n");  
  printf("\t    |  \\_/  |             |       | \n");  
  printf("\t    |       |        BNMO | . . . | \n");  
  printf("\t    |  :::  |             | . . . | \n");  
  printf("\t    |  :::  |_____________| . . . | \n");  
  printf("\t    |           S N K             | \n");  
  printf("\t    \\_____________________________/ \n\n");

  printf("\t /$$$$$$$  /$$   /$$ /$$      /$$  /$$$$$$ \n");                                  
  printf("\t| $$__  $$| $$$ | $$| $$$    /$$$ /$$__  $$ \n");                                 
  printf("\t| $$  \\ $$| $$$$| $$| $$$$  /$$$$| $$  \\ $$ \n");                                
  printf("\t| $$$$$$$ | $$ $$ $$| $$ $$/$$ $$| $$  | $$ \n");                                
  printf("\t| $$__  $$| $$  $$$$| $$  $$$| $$| $$  | $$ \n");                                
  printf("\t| $$  \\ $$| $$\\  $$$| $$\\  $ | $$| $$  | $$ \n");                                
  printf("\t| $$$$$$$/| $$ \\  $$| $$ \\/  | $$|  $$$$$$/ \n");                                
  printf("\t|_______/ |__/  \\__/|__/     |__/ \\_____/ \n\n");    
                                                       
}
/* Tampilan awal BNMO berupa gambar dan tulisan untuk mempercantik tampilan */

void ConcatString(char *input1, char *input2){
  int i = 0;
  while (input1[i]!='\0'){
    i++;
  }
  int j = 0;
  while (input2[j]!='\0'){
    input1[i]=input2[j];
    i++; j++;
  }
}
/* Menggabungkan dua buah string input1 dan input2 ke dalam string input1 */

int searchDD(QueueDD q, int x){
  int found = false; 
  int i = IDX_HEAD(q);
  while (i<=IDX_TAIL(q) && !found){
    if (q.buffer[i].id == x){
      found = true;
    } else {
      i++;
    }
  }
  if (found){
    return i;
  } else {
    return -999;
  }
}
/* Mencari elemen q yang id nya adalah ID, mengembalikan idx ID pada q */