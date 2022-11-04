#include <stdio.h>
#include "ADT/Array.h"
#include "ADT/Queue.h"
#include "ADT/mesin_karakter.h"
#include "ADT/mesin_kata.h"
#include "Procedure/Fungsi_Kecil.h"
#include "Procedure/Game.h"
#include "console.h"
#include "boolean.h"

int main(){
    while (mode!=1 && mode!=2){
        MENU();
        CHOOSEMODE(&mode);
    }
    if (mode==1){
        STARTBNMO();
    } else {LOADBNMO();}
    while (fitur!=0)
    {
        // System("cls");
        FITURE();
        CHOOSEFITURE(&fitur);
    }
    QUIT();
}