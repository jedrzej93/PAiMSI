#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sys/time.h>
#include "../inc/benchmark.hh"
/*!
 *\file Benchmark
 * Plik zawierajacy deklaracje poszczegolnych funkcji
 * w klasie Benchmark.
 */
using namespace std;

void Benchmark::Start()
{
	gettimeofday(&czas1, NULL);
}

void Benchmark::Stop()
{
	gettimeofday(&czas2, NULL);
}

double Benchmark::Czas_Operacji()
{
	CzasOperacji = (czas2.tv_sec - czas1.tv_sec)*1000.0;
	CzasOperacji += (czas2.tv_usec - czas1.tv_usec) / 1000.0;
	cout << "Czas znalezienia: " << CzasOperacji << "ms." << endl;

	return CzasOperacji;
}