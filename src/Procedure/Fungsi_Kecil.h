#ifndef FUNGSI_KECIL_H
#define FUNGSI_KECIL_H

#include "../boolean.h"
#include "../ADT/Queue/QueueDD.h"

/*prosedur validChecker*/
void validChecker(boolean valid, int noGame);
/*ini check valid/engga input doang, simpel kok*/

void ConcatString(char *input1, char *input2, char *output);

int searchDD(QueueDD q, int ID);
/* Mencari elemen q yang id nya adalah ID, asumsi ID pasti terdapat pada q */
#endif