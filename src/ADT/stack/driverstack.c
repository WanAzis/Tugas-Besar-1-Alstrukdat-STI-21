#include <stdio.h>
#include "stack.h"
#include "stack.c"
#include "../mesinkata/mesin_karakter.c"
#include "../mesinkata/mesin_kata.c"

int main(){
    Stack S; Word simpenan;
    CreateEmptystack(&S);
    if (IsEmptyStack(S) && !IsFullstack(S)) {
        for (int i = 0; i<5; i++) {
            STARTWORD(); Push(&S, currentWord);
        } 
    }
    Pop(&S, &simpenan);
    Reversestack(&S);
    CetakStack(S);
    return 0;
}  