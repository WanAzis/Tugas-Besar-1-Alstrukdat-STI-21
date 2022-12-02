#include <stdio.h>
#include "stacktoh.h"
#include "stacktoh.c"
#include "../mesinkata/mesin_karakter.c"
#include "../mesinkata/mesin_kata.c"

int main(){
    Stacktoh S; int simpenan;
    CreateEmptystacktoh(&S, 5);
    if (IsEmptyStacktoh(S) && !IsFullstacktoh(S)) {
        for (int i = 0; i<5; i++) {
            STARTWORD(); Pushtoh(&S, currentWord.TabWord[0] - '0');
        } 
    }
    return 0;
}  