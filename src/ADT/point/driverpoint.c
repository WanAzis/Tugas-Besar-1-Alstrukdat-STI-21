#include <stdio.h>
#include "point.h"
#include "point.c"
#include "../mesinkata/mesin_karakter.c"
#include "../mesinkata/mesin_kata.c"

int main(){
    POINT P1, P2; int x = 2, y = 3;
    P1 = MakePOINT(x, y); int i, j; 
    STARTWORD(); i = currentWord.TabWord[0]; /*asumsi input cuma 1 huruf*/
    STARTWORD(); j = currentWord.TabWord[0]; /*asumsi input cuma 1 huruf*/    
    P2 = MakePOINT(i,j);
    if (ComparePOINT(P1, P2)) {
        printf("100\n");
    }
    else {
        if (IsOrigin) {
            printf("000!\n");
        }
        else if (IsOnSbX) {
            printf("XXX!\n");
        }
        else if (IsOnSbY) {
            printf("YYY!\n");
        }
    }
    printf("Kuadran Point mu: %d", Kuadran(P2));
    Geser(&P1, 3, 10); PlusDelta(P1, 10, 3);TulisPOINT(P1);
    ReplacePOINT(&P1, 11, 23); TulisPOINT(P1);
    return 0;
}