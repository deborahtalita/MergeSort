/*	Nama	:	Marpaung, Deborah Talita Kum	(201511014)
				Wanda Nuriza Riyana				(201511031)
	Kelas	: 	D3-1A Teknik Informatika
	Program	:	Merge Sort dengan Dynamic Binary Tree
	Tahun	: 	2021
*/

#include "mergesort.h"

void mergeTwoArrayMin(int arr[], int *left, int *right, int nL, int nR)
{
    int i=0,j=0,k=0;
    
    while(i < nL && j < nR)
    {
        if(left[i] < right[j]){ // membandingkan left[i] dan right[j] lalu mengambil nilai terkecil
        	arr[k] = left[i];
        	i++;
		}
        else {
        	arr[k] = right[j];
        	j++;
		}
		k++;
    }
    while(i < nL)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    while(j < nR)
    {
        arr[k] = right[j];      
		k++;
        j++;
    }
}

void mergeTwoArrayMax(int arr[], int *left, int *right, int nL, int nR)
{
    int i=0,j=0,k=0;
    
    while(i < nL && j < nR)
    {
        if(left[i] > right[j]){ // membandingkan left[i] dan right[j] lalu mengambil nilai terbesar
        	arr[k] = left[i];
        	i++;
		}
        else {
        	arr[k] = right[j];
        	j++;
		}
		k++;
    }
    while(i < nL)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    while(j < nR)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void mergeSortMin(int arr[], int rightIdx)
{
	if (rightIdx < 2){
		return;
}
		int i;

    	int midIdx = rightIdx/2;
    	int *left = (int *)malloc(midIdx*sizeof(int)); // alokasi array secara dinamis
   		int *right = (int *)malloc(sizeof(int)*(rightIdx-midIdx));
   		for(i=0; i < midIdx; i++){
        	left[i] = arr[i]; // pengisian array left dengan nilai dari array arr
		}	
    	for(i=midIdx;i<rightIdx;i++){
    		right[i-midIdx] = arr[i]; // pengisian array right dengan nilai dari array arr	
		}
   		mergeSortMin(left, midIdx);
  		mergeSortMin(right, rightIdx-midIdx);
    	mergeTwoArrayMin(arr, left, right, midIdx, rightIdx-midIdx);
}

void mergeSortMax(int arr[], int rightIdx)
{
	if (rightIdx < 2){
		return;
}
		int i;

    	int midIdx = rightIdx/2;
    	int *left = (int *)malloc(midIdx*sizeof(int));	// alokasi array secara dinamis
   		int *right = (int *)malloc(sizeof(int)*(rightIdx-midIdx));
   		for(i=0; i < midIdx; i++){ 
        	left[i] = arr[i]; // pengisian array left dengan nilai dari array arr
		}	
    	for(i=midIdx;i<rightIdx;i++){
    		right[i-midIdx] = arr[i]; // pengisian array right dengan nilai dari array arr	
		}
   		mergeSortMax(left, midIdx);
  		mergeSortMax(right, rightIdx-midIdx);
    	mergeTwoArrayMax(arr, left, right, midIdx, rightIdx-midIdx);
}

void printArray(int arr[], int max){
	int i;
	
	for(i = 0; i < max; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int *createArrayRand(int max){
	int i;
	
	int *a = (int*)malloc(max*sizeof(int)); // alokasi array secara dinamis
	for(i = 0; i < max; i++){
		a[i] = randomNumber();
		printf("Data ke %d : %d\n", i+1, a[i]);
	}
	return a;
}

int *createArrayManual(int max){
	int i;
	
	int *a = (int*)malloc(max*sizeof(int)); // alokasi array secara dinamis
	for(i = 0; i < max; i++){
		printf("Data ke %d :", i+1);
		scanf("%d", &a[i]);
	}
	return a;
}

int randomNumber(){
	int x, num;
	
	x = rand() % 3; // pemanggilan fungsi random dengan batasnya angka 1-3
	if (x == 1){
		num = rand();
	} else if (x == 2){
		num = rand();
		num = num*(-1);
	} else {
		num = 0;
	}
	return num;
}

int *createArrayFile(int max){
	FILE *fp;
	fp = fopen("DataAngka.txt","r");
	
	if (fp == NULL){
		printf("Error reading file\n");
		exit(1);
	}
	
	int i;
	int *a = (int*)malloc(max*sizeof(int)); // alokasi array secara dinamis
	for (i = 0; i < max; i++){
		fscanf(fp,"%d", &a[i]);
		printf("Data ke %d : %d\n", i+1, a[i]);
	}
	fclose(fp);
	return a;
}

int getArrayLength(){
	FILE *fp;
	fp = fopen("DataAngka.txt","r");
	
	if (fp == NULL){
		printf("Error reading file\n");
		exit(1);
	}
	
	int max = 0;
	int temp;
	
	while(!feof(fp)){
		fscanf(fp,"%d",&temp);
		max++; //menambahkan nilai maks untuk setiap nial integer yang di scan
	}
	fclose(fp);
	return max;
}

bool isFileEmpty()
{
	FILE *fp;
	fp = fopen ("DataAngka.txt", "r");
		
	if (fp == NULL)
	{
		printf("Error opening file!");
		exit (1);
	}
	
	fseek(fp, 0, SEEK_END);
	if (ftell(fp) == 0)
	{
		fclose(fp);
		return true;
	}
	
	fclose(fp);
	return false;
}
