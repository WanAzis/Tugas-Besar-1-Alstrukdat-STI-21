#include <stdio.h>
#include "QueueDD.h"

int main(){
    Queue q;
    CreateQueue(&q);
    ElType input;
    for (int i = 0; i<3; i++){
        scanf("%i %i %i %i", &input.id, &input.durasi, &input.ketahanan, &input.harga);
        enqueue(&q, input);
    }
    displayQueue(q);
    // Word CElement;
    // dequeue(&q, &CElement);
    // PrintKata(CElement);printf("\n");
    // displayQueue(q);
}