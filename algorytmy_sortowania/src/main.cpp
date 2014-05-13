#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "../inc/kolejka_tablica.hh"
#include "../inc/benchmark.hh"
/*!
 *\file Plik glowny.
 * Plik zawierajacy menu glowne programu.
 * Wykonuje algorytm zawarty w klasie Benchmark.
 */
using namespace std;

int main()
{
	Benchmark B;
	B.Wykonaj_Sortowanie();
}