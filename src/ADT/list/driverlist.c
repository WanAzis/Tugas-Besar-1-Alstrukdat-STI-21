#include <stdio.h>
#include "listdp.h"

int main(){
    List L; CreateEmptylist(&L);
    address P; POINT PT;
    for (int i = 0; i<2; i++){
        for (int j = 0; j<3; j++){
            PT = MakePOINT(i,j);
            InsVFirst(&L,PT);
        }
    } 
    PrintForward(L); printf("\n");
    if(!IsEmptylist(L)){
        printf("List tidak kosong!\n");
    } 
    printf("Hapus POINT(1,2)\n");
    PT = MakePOINT(1,2);
    P = Searchlist(L,PT);
    if(P!=NULL){
        DelP(&L,PT);
    } PrintForward(L); printf("\n");

    printf("Print dari belakang\n");
    PrintBackward(L); printf("\n");
}