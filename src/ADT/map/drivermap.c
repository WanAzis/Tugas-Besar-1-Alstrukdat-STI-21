#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "map.c"

int main() {
    STARTWORD();
    Map m; CreateEmptymap(&m);
    if (IsEmptymap(m) && !IsFullmap(m)) {
        Insertmap(&m, currentWord, 100);
        int value = Value(m, currentWord);
        if (IsMembermap(m, currentWord)) {
            CetakMap(m);
            Deletemap(&m, currentWord);
        }
    }
}
