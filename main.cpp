/*	Nama	:	Marpaung, Deborah Talita Kum	(201511014)
				Wanda Nuriza Riyana				(201511031)
	Kelas	: 	D3-1A Teknik Informatika
	Program	:	Merge Sort dengan Dynamic Binary Tree
	Tahun	: 	2021
*/

#include "mergesort.h"

int main(){
	int opsi;
	while(1){
		printf("\t|=========PROGRAM MERGE SORT=========|\n");
		printf("\t| 1. Input Number Manual             |\n");
		printf("\t| 2. Random Number                   |\n");
		printf("\t| 3. Input Number From File          |\n");
		printf("\t| 4. Panduan			     |\n");
		printf("\t| 5. About Us			     |\n");
		printf("\t| 6. Exit                            |\n");
		printf("\n\t  Pilih : "); scanf("%d", &opsi);
	
		switch(opsi){
			case 1:
				sortManual();
				break;
			case 2:
				sortRandom();
				break;
			case 3:
				sortFile();
				break;
			case 4:
				system("cls");
				panduan();
				system("pause");
				break;
			case 5:
				system("cls");
				aboutUs();
				break;
			case 6:
				printf("\n\t  Anda telah keluar dari program.\n");
				exit(1);
			default:
				printf("\t|  Angka yang diinputkan salah!      |\n");
				break;	
		}
		getch();
		system("cls");
	}
	return 0;
}

void sortRandom(){
	int MAX;
	system("cls");
	printf("Masukkan jumlah angka yang akan di-sort :"); scanf("%d", &MAX);

	int *arr = createArrayRand(MAX);
	printf("\nIsi array sebelum di sort:\n");
	printArray(arr, MAX);
			
	mergeSortMin(arr, MAX);
	printf("\nIsi array setelah di-sort dari angka yang terkecil:\n");
	printArray(arr, MAX);
		
	mergeSortMax(arr, MAX);
	printf("\nIsi array setelah di-sort dari angka yang terbesar:\n");
	printArray(arr, MAX);
}

void sortManual(){
	int MAX;
	system("cls");
	printf("Masukkan jumlah angka yang akan di-sort :"); scanf("%d", &MAX);

	int *arr = createArrayManual(MAX);
	printf("\nIsi array sebelum di-sort:\n");
	printArray(arr, MAX);
			
	mergeSortMin(arr, MAX);
	printf("\nIsi array setelah di-sort dari angka yang terkecil:\n");
	printArray(arr, MAX);
			
	mergeSortMax(arr, MAX);
	printf("\nIsi array setelah di-sort dari angka yang terbesar:\n");
	printArray(arr, MAX);
}

void sortFile(){
	if (isFileEmpty()){
		printf("\t  Tidak ada data dalam file!\n");
		return;
	}
	system("cls");
	
	printf("Data angka dalam file:\n");
	int MAX = getArrayLength();
	int *arr = createArrayFile(MAX);
	printf("\nIsi array sebelum di-sort:\n");
	printArray(arr, MAX);
			
	mergeSortMin(arr, MAX);
	printf("\nIsi array setelah di-sort dari angka yang terkecil:\n");
	printArray(arr, MAX);
			
	mergeSortMax(arr, MAX);
	printf("\nIsi array setelah di-sort dari angka yang terbesar:\n");
	printArray(arr, MAX);
}

void panduan(){
	FILE *ft = fopen("panduan.txt","rt"); 
	char s[1000];
	if(ft == NULL){
		printf("\n file tidak dapat dibuka \n");
		exit(1);
	}
	while (fgets(s,100,ft)){
		printf("%s",s);
	}
	fclose(ft);
}

void aboutUs(){  
	printf("\n\t-----------------------------------------------");
	printf("\n\t|NAMA\t:\tMARPAUNG, DEBORAH TALITA KUM  |\n");
	printf("\t|NIM \t:\t201511014                     |\n");
	printf("\t|KELAS\t:\tD3 1A TEKNIK INFORMATIKA      |\n");
	printf("\t----------------------------------------------|");
	printf("\n\t|NAMA\t:\tWANDA NURIZA RIYANA           |\n");
	printf("\t|NIM \t:\t201511031                     |\n");
	printf("\t|KELAS\t:\tD3 1A TEKNIK INFORMATIKA      |\n");
	printf("\t-----------------------------------------------\n");
	printf("\t| Dibuat pada 2021                            |");
}
