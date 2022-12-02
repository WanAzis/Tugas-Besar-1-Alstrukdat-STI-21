#include <stdio.h>
#include "queue.h"
#include "queue.c"
#include "../mesinkata/mesin_karakter.c"
#include "../mesinkata/mesin_kata.c"

int main(){
    Queue q; CreateQueue(&q);
    if (isEmpty(q) & !isFull(q)) {
        for (int i=0; i<5; i++) {
            STARTWORD(); enqueue(&q, currentWord);
        }
        printf("Panjang queue: %i", length(q));
        Word dq; dequeue(&q, &dq);
        displayQueue(q);
    }
    return 0;
}