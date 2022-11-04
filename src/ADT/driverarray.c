#include <stdio.h>
#include "Array.c"

int main(){
    array arr = Makearray();
    if (IsEmpty(arr)){
        printf("Array masih kosong\n");
    }
    char *c = (char*) malloc (sizeof(char) * 50);
    c = "Dinner Dash";
    InsertLast(&arr, c);
    c = "Game Suka Suka";
    InsertLast(&arr, c);
    c = "Tiga";
    InsertLast(&arr, c);
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
