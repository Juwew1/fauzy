#include <stdio.h>
#include <stdlib.h>
#include "jam.h"

/*	
	Program: mJam.c
	Author: (2350081020, Fauzy faadillah)
	Kelas: A
	Deskripsi: header file dari  prototype jam
	Tanggal: 14 / 03 / 2024
*/

int main () {
	// Kamus Data
	JAM J1,J2, J3,J4;
	int tambahanDetik;
	
	//Algoritma
	ReadJam(&J1);
	printf("Nilai J1 = ");
	printJam(J1);
	printf("\n");
	
	J2 = NextDetik(J1);
	printf("Nilai J2 = ");
	printJam(J2);
	printf("\n");
	
	printf("Masukan nilai N detik (0..59) : ");
	scanf("%d", &tambahanDetik);
	
	J3 = NextNDetik (J1, tambahanDetik);
	printf("Nilai J3 = ");
	printJam(J3);
	printf("\n");
	
	J4 = J1;
	printf("Nilai J4 = ");
	printJam(J4);
	printf("\n");
	
	printf("\n Pengecekan Operator Relasional\n");
	if(JEQ(J1, J2)){
		printf("nilai J1 sama dengan J2\n");
	}
	
	if(JLT(J1, J2)){
		printf("nilai J1 lebih kecil dari J2\n");
	}
	
	if(JGT(J1, J2)){
		printf("nilsi J1 lebih besar dari J2\n");
	}
	
	if(JEQ(J3, J1)){
		printf("nilai J3 sama dengan J1\n");
	}
	
	if(JLT(J3, J1)){
		printf("nilai J3 lebih kecil dari J1\n");
	}
	
	if(JGT(J3, J1)){
		printf("nilai J3 lebih besar J1\n");
	}
	
	if(JEQ(J1, J4)){
		printf("nilai J1 sama dengan J4\n");
	}
	
	if (JLT(J1, J4)){
		printf("nilai J1 lebih kecil dari J4\n");
	}
	
	if(JGT(J1, J4)){
		printf("nilai J1 lebih besar dari J4\n");
	}
	
	Reset(&J4);
	printf("Nilai J4 = ");
	printJam(J4);
	printf("\n");
	
	getch();
	
	return 0;
}

