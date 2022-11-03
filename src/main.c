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
    int mode, fitur;
    do 
    {
        MENU();
        CHOOSEMODE(&mode);
    } while(mode!=1 && mode!=2);
    if (mode==1){
        STARTBNMO();
    } else {LOADBNMO();}
    while (fitur!=0)
    {
        // System("cls");
        FITURE();
    }
    QUIT();
    
}