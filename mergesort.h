/*	Nama	:	Marpaung, Deborah Talita Kum	(201511014)
				Wanda Nuriza Riyana				(201511031)
	Kelas	: 	D3-1A Teknik Informatika
	Program	:	Merge Sort dengan Dynamic Binary Tree
	Tahun	: 	2021
*/
#ifndef mergesort_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

/* Author : Marpaung, Deborah Talita Kum */
/*****************************************/
/* * * MERGE SORT MIN TO MAX * * */
/*	Membagi array menjadi 2 sub-array	*/
void mergeSortMin(int arr[], int rightIdx);
/*	Menggabungkan dua sub array */
void mergeTwoArrayMin(int arr[], int *left, int *right, int nL, int nR);

/* * * MODUL LAINNYA * * */
/*	Print Isi Array	*/
void printArray(int arr[], int max);
/* Membuat array dengan angka yang diinput secara manual */
int *createArrayManual(int max);
/* Membuat array dengan angka dari fungsi random */
int *createArrayRand(int max);
/* Membuat array dengan angka dari file */
int *createArrayFile(int max);
/* Menghitung jumlah angka dalam file */
int getArrayLength();
/* Fungsi untuk menampilkan angka random */
int randomNumber();
/* Mengecek isi file apakah kosong atau tidak */
bool isFileEmpty();
/* Menu 1 : sorting dari array yang diinput secara manual */
void sortRandom();
/* Menu 2 : sorting dari array yang angkanya dari fungsi random */
void sortManual();
/* Menu 3 : sorting dari array yang diinput melalui file */
void sortFile();


/* Author : Wanda Nuriza Riyana */
/*****************************************/
/* * * MERGE SORT MAX TO MIN * * */
/*	Membagi array menjadi 2 sub-array	*/
void mergeSortMax(int arr[], int rightIdx);
/*	Menggabungkan dua sub array */
void mergeTwoArrayMax(int arr[], int *left, int *right, int nL, int nR);

/* * * MODUL LAINNYA * * */
/* Menu 4 : menampilkan panduan pengguna program */
void panduan();
/* Menu 5 : menampilkan identitas pembuat program */
void aboutUs();

#endif
