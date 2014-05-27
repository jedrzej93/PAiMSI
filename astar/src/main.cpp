/*!
 *\file Plk glowny programu.
 */
#include <iostream>
#include <iomanip>
#include "astar.hh"
#include "benchmark.hh"

using namespace std;

int main()
{
	Graf g;
	Benchmark B;
	
	B.Start(); g.AStar(); B.Stop(); B.Czas_Operacji();
	
	cout << endl;
	cout << "Wyswietlenie drogi jaka przebyl algorytm A*: "<< endl << g << endl;
	
	return 0;
}