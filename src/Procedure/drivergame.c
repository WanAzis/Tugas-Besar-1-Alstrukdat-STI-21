#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Fungsi_Kecil.h"

int main(){
    char tes1[] = "saya ";
    char tes2[] = "Azis";
    char hasil[50];
    ConcatString(tes1, tes2);
    printf("hasil concat 'saya ' dan 'Azis' adalah : %s", tes1);
    for (int i = 0; i<10; i++){
        printf("%i ", rand() % (5 - 1 +1) + 1);
    }
    Diner_Dash();

    struct tm *Time;
    time_t Tval;
    Tval = time(NULL);
    Time = localtime(&Tval);
    for (int i = 0; i<5; i++){
        printf("%i\n", (Time->tm_hour + Time->tm_min + Time->tm_sec)%100);
    }
}