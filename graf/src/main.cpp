#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>
#include "graf.hh"
/*!
 *\file Plik glowny.
 * Plik zawierajacy menu glowne programu.
 */
using namespace std;

int main()
{
	int wezly, max_krawedz, element1, element2;
	
	cout << " Wprowadz liczbe wezlow: ";
	cin >> wezly;
	cout << endl;

	Graf graf(wezly);
	
	max_krawedz = wezly * (wezly - 1);
	
	for(int i = 0; i < max_krawedz; i++)
	{
		cout << " Aby zakonczyc wpisywanie wpisz - > -1 -1 " << endl;
		cout << " Wprowadz krawedz: ";
		cin >> element1 >> element2;
		if((element1 == -1) && (element2 == -1))
			break;
		graf.Dodaj_Krawedz(element1, element2);
	}
	cout << endl;
	graf.Wyswietl_Graf();

	return 0;
}
