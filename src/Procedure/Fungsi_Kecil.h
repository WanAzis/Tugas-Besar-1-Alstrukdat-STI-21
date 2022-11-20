#ifndef FUNGSI_KECIL_H
#define FUNGSI_KECIL_H

#include "../boolean.h"
#include "../ADT/queueDD/queueDD.h"

void UIAwal();
/* Tampilan awal BNMO berupa gambar dan tulisan untuk mempercantik tampilan */

void ConcatString(char *input1, char *input2);
/* Menggabungkan dua buah string input1 dan input2 ke dalam string input1 */

int searchDD(QueueDD q, int ID);
/* Mencari elemen q yang id nya adalah ID, mengembalikan idx ID pada q */
#endif