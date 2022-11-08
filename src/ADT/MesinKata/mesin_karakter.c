#include <stdio.h>
#include "mesin_karakter.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;


void START(){
    pita = stdin;
    ADV();
}
/* Mesin siap dioperasikan. Pita merupakan stdin yang adalah inputan dari pengguna.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void STARTFILE(char *FileName){
    pita = fopen(FileName, "r");
    if (pita != NULL) {
        ADV();
    } else {
        printf("PATH TO FILE DOES NOT EXIST\n");
    }
}
/* Mesin siap dioperasikan. Pita merupakan file yang diakses dan disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV(){
    retval = fscanf(pita,"%c",&currentChar);
    EOP = (currentChar==MARK);
    if (EOP){
        fclose(pita);
    }
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCC(){
    return currentChar;
}
/* Mengirimkan currentChar */

boolean IsEOP(){
    return currentChar==MARK;
}
/* Mengirimkan true jika currentChar = MARK */