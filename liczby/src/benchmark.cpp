#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sys/time.h>
#include "../inc/benchmark.hh"
#include "../inc/dane.hh"
/*!
*\file
*\brief Definicje funkcji dla klasy Benchmark.
*/
using namespace std;

void Benchmark::Wykonaj_Algorytm()
{
	Dane t1("licz10.txt");
	Dane t2("licz100.txt");
	Dane t3("licz1000.txt");

	t1.Wykonaj_Obliczenia();
	t2.Wykonaj_Obliczenia();
	t3.Wykonaj_Obliczenia();

}

void Benchmark::Powtorz_Algorytm()
{
	Il_Powtorz_Algorytm = 10;

	//cout << "Zegar wlaczony!" << endl;
	cout << "Wykonanie algorytmu dla n = 10 powtorzen: " << endl;

	gettimeofday(&czas1, NULL);
	
	for(int x = 0; x < Il_Powtorz_Algorytm; x++)
	{
		Wykonaj_Algorytm();
	}
	//cout << "Zegar wylaczony!" << endl;
	gettimeofday(&czas2, NULL);

	CzasOperacji = (czas2.tv_sec - czas1.tv_sec)*1000.0;
	CzasOperacji += (czas2.tv_usec - czas1.tv_usec) / 1000.0;
	cout << "Czas wykonania operacji: " << CzasOperacji << "ms." << endl;
}

