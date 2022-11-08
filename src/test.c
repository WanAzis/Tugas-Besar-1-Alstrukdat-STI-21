#include <stdio.h>
#include "console.h"

int main(){
    // FITURE();
    STARTBNMO();
    LISTGAME(ListGame);
    CREATEGAME(&ListGame);
    LISTGAME(ListGame);
    DELETEGAME(&ListGame);
    LISTGAME(ListGame);

}