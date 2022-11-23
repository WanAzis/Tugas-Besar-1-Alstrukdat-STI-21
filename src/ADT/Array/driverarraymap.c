#include <stdio.h>
#include "arraymap.h"
#include "arraymap.c"
// #include "../map/map.h"
#include "../map/map.c"
#include "../mesinkata/mesin_karakter.c"
#include "../mesinkata/mesin_kata.c"


int main(){
    arraymap armap = Makearraymap();
    Map m; CreateEmptymap(&m);
    TypeInfo I;
    for (int j = 0; j<3; j++){
        for (int i = 0; i<5; i++){
            STARTWORD(); I.Key=currentWord;
            I.Value=i;
            Insertmap(&m,I.Key,I.Value);
        }
        InsertLastarrmap(&armap,m); CreateEmptymap(&m);
    }
    Printarraymap(armap);
}