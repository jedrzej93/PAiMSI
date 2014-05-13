/*!
 *\file
 *\brief
 *
 *Plik zawiera funkcje z klasy Stos.
 *
 */
#include <iostream>
#include <list>
#include <stack>
#include <fstream>
#include <iomanip>
#include <sys/time.h>
#include "stos_tablica.hh"

using namespace std;

Stos::Stos()
{
	S = 0; S_temp = 0; rozmiar_stosu = 0;
}

void Stos::Wyswietl_Stos()
{	
	if(rozmiar_stosu != 0)
	{
		cout << "Stos: " << endl;
		for(int i = (rozmiar_stosu - 1); i >= 0 ; i--)
			cout << S[i] << endl;
	}
}

void Stos::push(int dodaj_element)
{
	if( rozmiar_stosu != 0)
	{
		S_temp = new int[rozmiar_stosu];
		for(int i = 0; i < rozmiar_stosu; i++)
		{
			S_temp[i] = S[i];
		}
		delete [] S;

		++rozmiar_stosu;
		S = new int[rozmiar_stosu];
		for(int i = 0; i < (rozmiar_stosu - 1); i++)
		{
			S[i] = S_temp[i];
		}
		S[rozmiar_stosu - 1] = dodaj_element;
		delete [] S_temp;
	} else
	{
		++rozmiar_stosu;
		S = new int[rozmiar_stosu];
		S[rozmiar_stosu - 1] = dodaj_element;
	}
}

void Stos::pop()
{
	if(rozmiar_stosu != 0)
	{
		S_temp = new int[rozmiar_stosu];
		for(int i = 0; i < rozmiar_stosu; i++)
		{
			S_temp[i] = S[i];
		}
		delete [] S;

		--rozmiar_stosu;
		S = new int[rozmiar_stosu];
		for(int i = 0; i < rozmiar_stosu; i++)
		{
			S[i] = S_temp[i];
		}
		delete [] S_temp;
	}
}

void Stos::Wczytaj_Dane(string nazwa_pliku)
{
	int temp;

	ifstream plik(nazwa_pliku.c_str());

	if(!plik)
	{
		cerr << "Nie mozna otworzyc pliku!" << endl;
		getchar();
	}
	else
	{
		while( plik >> temp)
			push(temp);
	}
}

void Stos::Menu()
{
	Stos S;
	int wybor;
	int _element = 0;

	cout << "MENU:" << endl;

	do
	{
		cout << "1 - Dodaj element do stosu " << endl;
		cout << "2 - Usun element ze stosu " << endl;
		cout << "3 - Wyswietl stos " << endl;
		cout << "4 - Sprawdz rozmiar stosu " << endl;
		cout << "5 - Sprawdz czy stos jest pusty " << endl;
		cout << "6 - Wczytaj dane " << endl << endl;
		cout << "7 - Zakoncz program " << endl << endl;
		cout << "Wybor: ";

		cin >> wybor;
		cout << endl;
		if((wybor > 0) && (wybor < 7))
		{
			switch(wybor)
			{
				case 1: 
					{
						cout << "Wartosc elementu do dodania: " << endl;
						cin >> _element;
						cout << endl;  	
						S.push(_element);
						break;
					}
				case 2: S.pop();
						break;
				case 3: S.Wyswietl_Stos();
						break;
				case 4: S.size();
						break;
				case 5: S.empty();
						break;
				case 6: S.Wczytaj_Dane("stos.txt");
						S.Wyswietl_Stos();
						break;
				case 7: cout << "Zakonczono program..." << endl;
						break;

				default: cerr << "Nieznana opcja!" << endl;
						break;
			}
		} else
			cout << "Wprowadz numer opcji jeszcze raz! " << endl;

	} while (wybor != 6);
}

// zadanie domowe:
// sprawdzić czas wykonywania operacji wypełniania stosu/kolejki dla n = 100, 1000, 10000 elementów
// zrobić tylko tablice, wersje która powiększa dwa razy rozmiar tablicy przy przekraczaniu
// na 5 implementacja listy i tablicy + to co wyżej (dla dwóch różnych typów danych)
// wykresy w formacie eps lub pdf, dane z operacji benchmarku do tablicy -> plik csv