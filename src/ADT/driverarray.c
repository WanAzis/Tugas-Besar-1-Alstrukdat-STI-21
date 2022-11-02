#include <stdio.h>
#include "Array.c"

int main(){
    array arr = Makearray();
    if (IsEmpty(arr)){
        printf("Array masih kosong\n");
    }
    InsertLast(&arr, "Dinner Dash");
    InsertLast(&arr, "Game Suka suka");
    InsertLast(&arr, "Tiga");
    Printarray(arr);
    InsertAt(&arr, "Ini antara dinner dan game suka", 1);
    Printarray(arr);
    DeleteAt(&arr, 1);
    Printarray(arr);
    Reversearray(&arr);
    Printarray(arr);
    array arr2 = Copyarray(arr);
    Printarray(arr2);
}
