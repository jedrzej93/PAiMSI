#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sys/time.h>
#include "../inc/benchmark.hh"
/*!
 *\file Benchmark
 *\brief 
 * Plik zawierajacy deklaracje poszczegolnych funkcji
 * w klasie Benchmark.
 */
using namespace std;

void Benchmark::Wykonaj_Algorytm()
{
	Lista L;
	Stos S;
	Kolejka_lista K_l;
	Kolejka K;

	string nazwa[4];
	nazwa[0]="stos.txt";
	nazwa[1]="stos100.txt";
	nazwa[2]="stos1000.txt";
	nazwa[3]="stos10000.txt";

	double czasL[4], czasS[4], czasK_l[4], czasK[4];
	
	for (int i = 0; i < 4; i++)
	{
		Start();
		L.Wczytaj_Dane(nazwa[i]);
		Stop();
		czasL[i] = Czas_Operacji();
		czas = czas + Czas_Operacji();
	}

	for (int i = 0; i < 4; i++)
	{
		Start();
		S.Wczytaj_Dane(nazwa[i]);
		Stop();
		czasS[i] = Czas_Operacji();
		czas = czas + Czas_Operacji();
	}
	
	for (int i = 0; i < 4; i++)
	{
		Start();
		K_l.Wczytaj_Dane(nazwa[i]);
		Stop();
		czasK_l[i] = Czas_Operacji();
		czas = czas + Czas_Operacji();
	}
	
	for (int i = 0; i < 4; i++)
	{
		Start();
		K.Wczytaj_Dane(nazwa[i]);
		Stop();
		czasK[i] = Czas_Operacji();
		czas = czas + Czas_Operacji();
	}

	cout<<"Czasy zapelniania listy:\n";
	for (int i = 0; i < 4; i++)
	{
		cout<<" ("<<10*pow( 10, i )<<" elementow) ->> "<<czasL[i]<<" ms "<<endl;
	}
	cout<<"\nCzasy zapelniania stosu:\n";
	for (int i = 0; i < 4; i++)
	{
		cout<<" ("<<10*pow( 10, i )<<" elementow) ->> "<<czasS[i]<<" ms"<<endl;
	}
	cout<<"\nCzasy zapelniania kolejki za pomoca listy:\n";
	for (int i = 0; i < 4; i++)
	{
		cout<<" ("<<10*pow( 10, i )<<" elementow) ->> "<<czasK_l[i]<<" ms"<<endl;
	}
	cout<<"\nCzasy zapelniania kolejki za pomoca tablicy:\n";
	for (int i = 0; i < 4; i++)
	{
		cout<<" ("<<10*pow( 10, i )<<" elementow) ->> "<<czasK[i]<<" ms"<<endl;
	}
}

void Benchmark::Start()
{
	//cout << "Zegar wlaczony!" << endl;
	gettimeofday(&czas1, NULL);
}

void Benchmark::Stop()
{
	//cout << "Zegar wylaczony!" << endl;
	gettimeofday(&czas2, NULL);
}

double Benchmark::Czas_Operacji()
{
	CzasOperacji = (czas2.tv_sec - czas1.tv_sec)*1000.0;
	CzasOperacji += (czas2.tv_usec - czas1.tv_usec) / 1000.0;
	cout << CzasOperacji << "ms." << endl;

	return CzasOperacji;
}