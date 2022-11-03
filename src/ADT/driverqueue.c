#include <stdio.h>
#include "Queue.h"

int main(){
    Queue q;
    CreateQueue(&q);
    enqueue(&q, "satu");
    enqueue(&q, "dua");
    enqueue(&q, "tiga");
    displayQueue(q);
    char *CElement;
    dequeue(&q, &CElement);
    printf("%s\n", CElement);
    displayQueue(q);
}