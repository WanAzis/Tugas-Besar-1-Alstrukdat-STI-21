#include <stdio.h>
#include "Queue.h"

int main(){
    Queue q;
    displayQueue(q);
    Word CElement;
    dequeue(&q, &CElement);
    PrintKata(CElement);printf("\n");
    displayQueue(q);
}
