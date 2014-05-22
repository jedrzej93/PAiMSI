#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>
#include "graf.hh"
#include "benchmark.hh"
/*!
 *\file Plik glowny.
 * Plik zawierajacy menu glowne programu.
 */
using namespace std;

int main()
{
	cout << "Algorytmy przeszukiwania BFS oraz DFS" << endl;
	cout << "-------------------------------------" << endl;
	
	Benchmark B;
	Graf graf("test.txt");
	
	B.Start(); graf.BFS("2"); B.Stop(); B.Czas_Operacji();
	
	B.Start(); graf.DFS("2"); B.Stop(); B.Czas_Operacji();

	return 0;
}
