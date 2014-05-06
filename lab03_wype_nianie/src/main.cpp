#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "../inc/stos_tablica.hh"
#include "../inc/stos_lista.hh"
#include "../inc/kolejka_tablica.hh"
#include "../inc/kolejka_lista.hh"
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
	B.Wykonaj_Algorytm();
}