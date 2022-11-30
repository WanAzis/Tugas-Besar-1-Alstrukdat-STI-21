#include <stdio.h>
#include <stdlib.h>
#include "ADT/stack/stack.c"

void HISTORY(Stack HistoryGame, int n){
  printf("Berikut adalah daftar Game yang telah dimainkan\n");
  if (n < )
  for (int j = 0; j < n; j++) {
    printf("%d. ", j+1); printf("%d",InfoTop(HistoryGame)); printf("\n");
    Pop(&HistoryGame, &InfoTop(HistoryGame));
  }
}

int main() {
    Stack tes;
    CreateEmptystack(&tes);
    for(int i= 0; i < 6; i++) {
        Push(&tes, i);
    }
    HISTORY(tes, 3);
}

// int main(){
//     char* A[5];
//     for(int i = 0; i < 5; i++){
//         scanf("%s", A[i]);
//     }
// }