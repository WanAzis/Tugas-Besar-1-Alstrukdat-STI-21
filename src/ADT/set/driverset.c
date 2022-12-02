#include <stdio.h>
#include "set.h"
#include "set.c"

int main(){
    Set S; CreateEmptyset(&S);
    if (IsEmptyset(S) && !IsFullset(S)) {
        Insertset(&S, 'a');
        Insertset(&S, 'b');
        Insertset(&S, 'c');
        if (IsMemberset(S, 'a')) {
            Deleteset(&S, 'a');
        }
        PrintSet(S);
    }
    return 0;
    
}