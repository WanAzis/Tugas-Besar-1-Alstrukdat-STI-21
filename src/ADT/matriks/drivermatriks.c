#include <stdio.h>
#include "matriks.h"
#include "matriks.c"

int main(){
    matriks m = MakeMatriks();
    if (IsEmptyMatriks(m)){
        printf("Matriks kosong\n");
    }
    PrintMatriks(m);
    InsertAtMatriks(&m,'H',2,3);
    InsertAtMatriks(&m,'1',3,3);
    InsertAtMatriks(&m,'2',4,3);
    InsertAtMatriks(&m,'3',4,4);
    PrintMatriks(m);
    DeleteAtMatriks(&m,4,4);
    printf("%c\n", GetelmtMatriks(m,4,4));
}