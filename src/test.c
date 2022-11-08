#include <stdio.h>
#include "console.h"
#include <stdlib.h>

int main(){
    // FITURE();
    STARTBNMO();
    CREATEGAME(&ListGame);
    DELETEGAME(&ListGame);
    LISTGAME(ListGame);
    
}