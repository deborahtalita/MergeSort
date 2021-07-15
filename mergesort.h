
#ifndef mergesort_H
#include <stdio.h>
#include <stdlib.h>


typedef int infotype;
typedef struct btree *address;
typedef struct btree {
	infotype info[100];
	address left;
	address right;
} binTreeNode;

struct binTree {
	address root;
}; 

/*	Menggabungkan dua sub array */
void mergeTwoArray(address *node, int nL, int nR);
/*	Membagi array menjadi 2 sub-array	*/
void mergeSort(address *node, int rightIdx);
/*	Input angka	*/
void inputNumber(infotype arr[], int arrayMAX);
/*	Print Isi Array	*/
void printArray(address node, int rightIdx);

address createNode (infotype arr[], int max);

void randomNumber(infotype arr[], int max);
#endif
