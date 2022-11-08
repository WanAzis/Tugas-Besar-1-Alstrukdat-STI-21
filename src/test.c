#include <stdio.h>
#include "console.h"
#include <stdlib.h>

int main(){
    // FITURE();
    STARTWORD();
    char *fname = (char*) malloc (sizeof(char) * currentWord.Length+1);
    WordToString(currentWord, fname);
    printf("%s", fname);
}