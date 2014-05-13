#include <iostream>
#include <iomanip>
#include <fstream>
#include "tab_hash.hh"

using namespace std;

int main()
{
	Tablica_Haszujaca Tab_Hash(100);
	int opcja;
	string nazwa;

	do 
	{
		cout << endl;
		cout << "----MENU TABLICY HASZUJACEJ----" << endl;
		cout << " 1 - DODAJ ELEMENT DO TABLICY HASZUJACEJ " << endl;
		cout << " 2 - USUN ELEMENT Z TABLICY HASZUJACEJ" << endl;
		cout << " 3 - ZNAJDZ ELEMENT O W TABLICY HASZUJACEJ" << endl;
		cout << " 4 - WYSWIETL TABLICE HASZUJACA" << endl;
		cout << " 5 - WCZYTAJ PLIK DO TABLICY HASZUJACEJ" << endl;
		cout << " 6 - ZAKONCZ PROGRAM " << endl;
		cout << " ---------------------" << endl;
		cout << "Wybor opcji: ";
		cin >> opcja;

		switch(opcja)
		{
			case 1:	
					Tab_Hash.Dodaj_Element();
					break;
			case 2:
					Tab_Hash.Usun_Element();
					break;
			case 3: 
					cout << "Podaj nazwe szukanego elementu: ";
					cin >> nazwa;
					Tab_Hash.Znajdz(nazwa);
					break;
			case 4: 
					Tab_Hash.Wyswietl_Tablice();
					break;
			case 5: 
					Tab_Hash.Wczytaj_Dane("plik.txt");
					break;
			case 6:
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