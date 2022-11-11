#include <stdio.h>
#include "Fungsi_Kecil.h"
#include "../ADT/Queue/QueueDD.h"

/*prosedur validChecker*/
void validChecker(boolean valid, int noGame) {
  scanf("Nomor Game yang mau ditambahkan ke antrian: %d", &noGame);
  valid = (noGame>0 && noGame<100); /*ini gue asumsi maks game yang ada di list 100 (masi nunggu atira)*/
  /*ini checker valid, looping sampe bener*/
  while (!valid) {
    printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list."); /*ngikutin kakanya ini gw*/
    scanf("Nomor Game yang mau ditambahkan ke antrian: %d", &noGame);
  }
}
/*ini check valid/engga input doang, simpel kok*/

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
/* Mencari elemen q yang id nya adalah ID, asumsi ID pasti terdapat pada q */