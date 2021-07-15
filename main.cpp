#include "mergesort.h"

/*	Nama	:	Marpaung, Deborah Talita Kum	(201511014)
				Wanda Nuriza Riyana				(201511031)
	Kelas	: 	D3-1A Teknik Informatika
	Program	:	Merge Sort dengan Dynamic Binary Tree
	Tahun	: 	2021
*/

int main()
{
	binTree sTree;
	address sNode;
	int i, opsi;
	int MAX;
	infotype arr[MAX];
	
	printf("\t|=========PROGRAM MERGE SORT=========|\n");
	printf("\t| 1. Input Number                    |\n");
	printf("\t| 2. Random Number                   |\n");
	printf("Pilih :"); scanf("%d", &opsi);
	
	switch(opsi){
		case 1:
//			system("cls");
			printf("Masukkan jumlah angka yang akan di-sort :"); scanf("%d", &MAX);
			inputNumber(arr, MAX);
			sTree.root = createNode(arr, MAX);
			printf("\nIsi array sebelum di-sort:\n");
			printArray(sTree.root, MAX);
			mergeSort(&sTree.root, MAX);
			printf("\nIsi array setelah di-sort:\n");
			printArray(sTree.root, MAX);
			break;
		case 2:
			printf("Masukkan jumlah angka yang akan di-sort :"); scanf("%d", &MAX);
			randomNumber(arr,MAX);
			sTree.root = createNode(arr, MAX);
			printf("\nIsi array sebelum di-sort:\n");
			printArray(sTree.root, MAX);
			mergeSort(&sTree.root, MAX);
			printf("\nIsi array setelah di-sort:\n");
			printArray(sTree.root, MAX);
			break;
	}
	
//	printf("MASUKKAN JUMLAH DATA : \n");
//	scanf("%d", &MAX);
//	
//	printf("Masukkan DATA SEBELUM TERURUT : \n");
//	for (i = 0; i < MAX; i++)
//	{
//	printf ("Data ke %i : ", i+1);
//	scanf ("%d", &arr[i]);
//	}
//	
//    printf("Original Array:\n");
//    for (i = 0; i < MAX; i++)
//    	printf("%d ", arr[i]);
//    printf("\n");
//    
//    mergeSort(arr, MAX);
//    for(i = 0; i < MAX; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
}
