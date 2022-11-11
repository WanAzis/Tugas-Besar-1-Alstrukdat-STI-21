#include <stdio.h>
#include <stdlib.h>
#include "ADT/Array/Array.h"
#include "ADT/Queue/Queue.h"
#include "ADT/MesinKata/mesin_karakter.h"
#include "ADT/MesinKata/mesin_kata.h"
#include "Procedure/Fungsi_Kecil.h"
#include "Procedure/Game.h"
#include "console.h"
#include "boolean.h"

char fname[50];

int main(){
    UIAwal(); printf("\n\n");
    label : while (mode!=1 && mode!=2){
        MENU();
        CHOOSEMODE(&mode, fname);
    }
    if (mode==1){
        STARTBNMO();
    } else {LOADBNMO(fname);}
    if (mode==0){
        goto label;
    }

    while (fitur!=0)
    {
        system("cls");
        FITURE();
        CHOOSEFITURE(&fitur, fname);
        if (fitur!=0){
            printf("Tekan <ENTER> untuk melanjutkan >>> "); STARTENTER();
        }
    }
    QUIT();
}