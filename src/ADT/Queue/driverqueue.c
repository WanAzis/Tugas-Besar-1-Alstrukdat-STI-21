#include <stdio.h>
#include "Queue.h"

int main(){
    Queue q;
    CreateQueue(&q);
    for (int i = 0; i<3; i++){
        STARTWORD();
        enqueue(&q, currentWord);
    }
    displayQueue(q);
    Word CElement;
    dequeue(&q, &CElement);
    PrintKata(CElement);printf("\n");
    displayQueue(q);
}