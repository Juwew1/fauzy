/*	
	Program: Jam.h
	Author: (2350081020, Fauzy faadillah)
	Kelas: A
	Deskripsi: header file dari  prototype jam
	Tanggal: 14 / 03 / 2024
*/

#ifndef JAM_H
#define JAM_H
#include "boolean.h"
#define true 1
#define false 0
#define boolean unsigned char

typedef struct {
	int Hour; /* Hour [0..23] */
	int Minute; /* Minute [0..59]*/
	int Second; /* Second [0..59]*/
}	JAM;

/*	Prototype ADT Jam */
void CreateJam (JAM *J, int HH, int MM, int SS);

/* Nilai Jam */
int GetHour (JAM J);
int GetMinute (JAM J);
int GetSecond (JAM J);

/* Nilai komponen */
void SetHour (JAM *J, int newHour);
void SetMinute (JAM *J, int newMinute);
void SetSecond (JAM *J, int newMinute);

/* Kelompok Baca/tulis */
void ReadJam (JAM *J);
void PrintJAm (JAM J);

/* kelompok validasi type */
boolean IsJValid (int H, int M, int S);

/* operator relasional */
boolean JEQ (JAM J1, JAM J2);
boolean JLT (JAM J1, JAM J2);
boolean JGT (JAM J1, JAM J2);

/* operator aritmatika */
void Reset (JAM *J);
JAM NextDetik (JAM J);
JAM NextNDetik (JAM J, int N);
long int Durasi (JAM JAw, JAM JAkh);

/* kelompok konversi terhadap type */
long int JamToDetik (JAM J);

#endif


