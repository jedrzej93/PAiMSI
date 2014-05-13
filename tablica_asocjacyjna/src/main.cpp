#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "tablica_asocjacyjna.hh"
/*!
 *\file Plik glowny.
 * Plik zawierajacy menu glowne programu.
 * Wykonuje algorytm zawarty w klasie Benchmark.
 */
using namespace std;

int main()
{
	Tablica_Asocjacyjna Tab_Aso;
	int opcja;

	do 
	{
		cout << endl;
		cout << "----MENU TAB ASO----" << endl;
		cout << " 1 - DODAJ ELEMENT DO TABLICY ASOCJACYJNEJ " << endl;
		cout << " 2 - USUN ELEMENT Z TABLICY ASOCJACYJNEJ" << endl;
		cout << " 3 - ZNAJDZ ELEMENT O ZADANYM KLUCZU" << endl;
		cout << " 4 - WYSWIETL TABLICE ASOCJACYJNA" << endl;
		cout << " 5 - ZAKONCZ PROGRAM " << endl;
		cout << " ---------------------" << endl;
		cout << "Wybor opcji: ";
		cin >> opcja;

		switch(opcja)
		{
			case 1:	
					Tab_Aso.Dodaj_Element();
					break;
			case 2:
					Tab_Aso.Usun_Element();
					break;
			case 3: 
					Tab_Aso.Znajdz_Element();
					break;
			case 4: 
					Tab_Aso.Wyswietl_Dane();
					break;
			case 5:
					cout << "Zakonczono program!" << endl;
					break;
			default:
					cerr << "Nieprawidlowa opcja wyboru! Sprobuj ponownie." << endl;
					break;
		}
	}
	while(opcja);
	
	return 0;
}
