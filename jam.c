/*	
	Program: Jam.h
	Author: (2350081020, Fauzy faadillah)
	Kelas: A
	Deskripsi: header file dari  prototype jam
	Tanggal: 14 / 03 / 2024
*/

#include "jam.h"
#include <stdio.h>
#include <conio.h>


/*	Prototype ADT Jam */
void CreateJam (JAM *J, int HH, int MM, int SS){
	(*J) .Hour = HH;
	(*J) .Minute = MM;
	(*J) .Second = SS;
}

/* Nilai Jam */
int GetHour (JAM J){
	return (J.Hour);
}
int GetMinute (JAM J){
	return (J.Minute);
}
int GetSecond (JAM J){
	return (J.Second);
}

/* Nilai komponen */
void SetHour (JAM *J, int newHour){
	(*J) .Hour = newHour;
}
void SetMinute (JAM *J, int newMinute){
	(*J) .Minute = newMinute;
}

void SetSecond (JAM *J, int newSecond){
	(*J) .Second = newSecond;
}

/* Kelompok Baca/tulis */
void ReadJam (JAM *J){
	int HH, MM, SS;
	
	do{
		scanf ("%d", &HH);
		scanf ("%d", &MM);
		scanf ("%d", &SS);
	} while (HH < 0 || HH > 23 || MM < 0 || MM > 59 || SS < 0 || SS > 59);
	
	CreateJam (&(*J), HH, MM, SS);
}

void PrintJam (JAM J){
printf ("%d:%d:%d", J.Hour, J.Minute, J.Second);
}

/* Kelompok Validasi Type */
boolean IsJValid (int H, int M, int S){
	
	if (H>=0 && H<=23 && M>=0 && M<59 && S>=0 && S<=59)
		return (true);
	else
		return (false);
}

/* operator relasional */
boolean JEQ (JAM J1, JAM J2){
	
	if (J1.Hour == J2.Hour && J1.Minute == J2.Minute && J1.Second == J2.Second)
		return (true);
	else
		return (false);
}

boolean JLT (JAM J1, JAM J2){
	
	if (J1.Hour < J2.Hour || J1.Minute < J2.Minute || J1.Second < J2.Second)
		return (true);
	else
		return (false);
}

boolean JGT (JAM J1, JAM J2){
	
	if (J1.Hour > J2.Hour || J1.Minute > J2.Minute || J1.Second > J2.Second)
		return (true);
	else
		return (false);
}

/* operator aritmatika */
void Reset (JAM *J){
	(*J) .Hour = 0;
	(*J) .Minute = 0;
	(*J) .Second = 0;
	
}

JAM NextDetik (JAM J){
	JAM jamBaru;
	
	jamBaru.Hour = J.Hour;
	jamBaru.Minute = J.Minute;
	jamBaru.Second = J.Second + 1;
	
	jamBaru = J;
	jamBaru.Second = jamBaru.Second + 1;
	
	if(jamBaru.Second > 59){
		jamBaru.Second = 0;
		jamBaru.Minute = jamBaru.Hour + 1;
		if(jamBaru.Minute > 59){
			jamBaru.Minute = 0;
			jamBaru.Hour = jamBaru.Hour +1;
			if(jamBaru.Hour > 23){
				jamBaru.Hour = 0;
			}
		}
		
	}
	
	return (jamBaru);
}

JAM NextNDetik(JAM J, int N){
	int i;
	JAM jamBaru;
	
	jamBaru = J;
	if (N > 0 && N <= 86400){
		for (i=1; i<N; i++){
			jamBaru = NextDetik (jamBaru);
		}
	}
	return (jamBaru);
}

long int Durasi (JAM JAw, JAM JAkh){
	long int detikAwl, detikAkh, result;
	
	detikAwl = JamToDetik(JAw);
	detikAkh = JamToDetik(JAkh);
	if (result < 0){
		result = result * (-1);
	}
	return (result);
}

/* kelompok konversi terhadap type */
long int JamToDetik (JAM J){
	long int detik;
	
	detik = (J.Hour * 3600) + (J.Minute * 60);
	return (detik);
}
