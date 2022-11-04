#include <stdio.h>
#include "Array.h"

int main(){
    array arr = Makearray();
    if (IsEmpty(arr)){
        printf("Array masih kosong\n");
    }
    for (int i = 0; i<5; i++){
        STARTWORD();
        InsertLast(&arr, currentWord);
    }
    Printarray(arr);
    DeleteAt(&arr, 1);
    Printarray(arr);
    Reversearray(&arr);
    Printarray(arr);
    array arr2 = Copyarray(arr);
    Printarray(arr2);
}
