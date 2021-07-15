#include "mergesort.h"

address createNode (infotype arr[], int max){
	int i;
	address node;
	
	node = (address)malloc(sizeof(binTreeNode));
//	node->info = arr[];
	for (i = 0; i < max; i++){
		node->info[i] = arr[i];
	}
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

void inputNumber(infotype arr[], int arrayMAX){
	int i;
//	printf("Masukkan jumlah angka yang akan di-sort :"); scanf("%d", arrayMAX);
	for(i = 0; i < arrayMAX; i++){
		printf("\nInput data ke-%d :",i+1); scanf("%d", &arr[i]);
	}
	printf("\nData berhasil diinputkan!");
}

void randomNumber(infotype arr[], int arrayMAX){
	int i, x;
	
	for(i = 0; i < arrayMAX; i++){
		x = rand() % 4;
		arr[i] = x;
	}
}

void printArray(address node, int rightIdx){
	int i;
	
	for(i = 0; i < rightIdx; i++){
	printf("%d ",node->info[i]);
	}
}

void mergeTwoArray(address *node, int nL, int nR)
{
    // int nL = sizeof(l)/sizeof(int);
    // int nR = sizeof(r)/sizeof(int);
    int i=0,j=0,k=0;
    while(i < nL && j < nR)
    {
        if((*node)->left->info[i] < (*node)->right->info[j])
            (*node)->info[k++] = (*node)->left->info[i++];
        else
            (*node)->info[k++] = (*node)->right->info[j++];
    }
    while(i < nL)
    {
        (*node)->info[k++] = (*node)->left->info[i++];
    }
    while(j < nR)
    {
        (*node)->info[k++] = (*node)->right->info[j++];
    }
}

void mergeSort(address *node, int rightIdx)
{
	int i;

    int midIdx = (rightIdx-1)/2;
	for(i = 0; i < midIdx; i++){
		(*node)->left->info[i] = (*node)->info[i]; 
	}
	for(i = midIdx; i < rightIdx; i++){
		(*node)->right->info[i-midIdx] = (*node)->info[i];
	}
	mergeSort(&(*node)->left, midIdx);
	mergeSort(&(*node)->right, rightIdx-midIdx);
	mergeTwoArray(&(*node), midIdx, rightIdx-midIdx);
}
