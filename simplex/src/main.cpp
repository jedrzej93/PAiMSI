#include <iostream>
#include <iomanip>
#include "simplex.hh"
/*!
 *\file Plik glowny programu.
 */
using namespace std;

int main()
{
	Simplex S;
	bool petla = 1;
	// petla rozpoczynajaca dzialanie programu
	while(petla == 1)
	{
		S.Stworz(); // tworzymy macierz

		S.Wypelnij(); // wypelniamy zmiennymi
		S.Wyswietl(); // wyswietlamy zmienne celu

		while(S.Zakoncz_Test() == true)
		{
			S.Pivot();
			S.Wyswietl();
		}

		cout << endl;
		S.Rozwiazanie();
		cout << "Wpisz: 1 - wykonanie programu jeszcze raz; 0 - zakoncz program. ";
		cin >> petla;
	}
	return 0;
}