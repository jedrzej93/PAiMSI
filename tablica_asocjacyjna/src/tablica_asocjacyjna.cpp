#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "tablica_asocjacyjna.hh"
/*!
 *\file Zdefiniowane funkcje klasy Tablica Asocjacyjna.
 * Plik zawiera definicje poszczegolnych funkcji
 * z klasy tablica asocjacyjna.
 */
using namespace std;
		
Tablica_Asocjacyjna::Tablica_Asocjacyjna()
{
	tab = tab_temp = tab_pomoc = tab_key = 0;
	rozmiar_tab = rozmiar_temp = 0;

}

Tablica_Asocjacyjna::~Tablica_Asocjacyjna()
{
	delete[] tab;

	if(rozmiar_temp != 0)
		delete[] tab_temp;
}

bool Tablica_Asocjacyjna::isEmpty()
{
	if(rozmiar_tab == 0)
	{
		cout << "W tablicy asocjacyjnej nie znajduja sie elementy!" << endl;
		return false;
	}
	else
	{
		cout << "W tablicy asocjacyjnej znajduja sie elementy!" << endl;
		return true;
	}
}

int Tablica_Asocjacyjna::Rozmiar()
{
	cout << " Rozmiar tablicy: ";
	return rozmiar_tab;
}

void Tablica_Asocjacyjna::Dodaj_Element()
{
	string klucz, wartosc;
	cout << "Podaj nazwe klucza: ";
	cin >> klucz;
	cout << "Podaj wartosc klucza: ";
	cin >> wartosc;
	push(klucz, wartosc);
}

void Tablica_Asocjacyjna::Usun_Element()
{
	string key;
	bool czy_jest_klucz = 0;
	int temp = 0;

	cout << "Jaki usunac klucz: ";
	cin >> key;
	for(int i = 0; i < rozmiar_tab; i++)
	{
		if(tab_key[i] == key)
		{
			czy_jest_klucz = 1;
			temp = i;
		}
	}

	if (czy_jest_klucz == 1)
	{
		string zmienna1, zmienna2;
		zmienna1 = tab_key[temp];
		zmienna2 = tab[temp];
		tab_key[temp]=tab_key[rozmiar_tab - 1];
		tab[temp] = tab[rozmiar_tab - 1];
		tab_key[rozmiar_tab - 1] = zmienna1;
		tab[rozmiar_tab - 1] = zmienna2;
		pop();
			cout<<"Element o podanym kluczu: " << key << " zostal usuniety!" << endl;
	}
	else
		pop();
}

void Tablica_Asocjacyjna::push(string key, string element)
{
	if (rozmiar_tab != 0)
	{
		tab_temp = new string[rozmiar_tab];
		tab_pomoc = new string[rozmiar_tab];
		for (int i = 0; i < rozmiar_tab; i++)
		{
			tab_temp[i] = tab[i];
			tab_pomoc[i] = tab_key[i];
		}
	delete [] tab;
	delete [] tab_key;
	
	++rozmiar_tab;
	tab = new string[rozmiar_tab];
	tab_key = new string[rozmiar_tab];
	
	for (int i = 0; i < (rozmiar_tab - 1); i++)
	{
		tab[i] = tab_temp[i];
		tab_key[i] = tab_pomoc[i];
	}
	
	tab[rozmiar_tab - 1] = element;
	tab_key[rozmiar_tab - 1] = key;
	
	delete [] tab;
	delete [] tab_pomoc;
	}
	else
	{
		++rozmiar_tab;

		tab = new string[rozmiar_tab];
		tab[rozmiar_tab - 1] = element;
		tab_key = new string[rozmiar_tab];
		tab_key[rozmiar_tab - 1] = key;
	}
}

void Tablica_Asocjacyjna::pop()
{
	if (rozmiar_tab != 0)
	{
		tab_temp = new string[rozmiar_tab];
		tab_pomoc = new string[rozmiar_tab];
		
		for (int i = 0; i < rozmiar_tab; i++)
		{
			tab_temp[i] = tab[i];
			tab_pomoc[i] = tab_key[i];
		}
		delete [] tab;
		delete [] tab_key;
		--rozmiar_tab;
		
		tab = new string[rozmiar_tab];
		tab_key = new string[rozmiar_tab];
		
		for (int i = 0; i < rozmiar_tab; i++)
		{
			tab[i] = tab_temp[i];
			tab_key[i] = tab_pomoc[i];
		}
		delete [] tab_temp;
		delete [] tab_pomoc;
	}
	else 
		cout << "Brak elementow do usuniecia!" << endl;
}

void Tablica_Asocjacyjna::Znajdz_Element()
{
	string key;
	bool czy_jest_klucz = 0;
	int temp = 0;
	
	cout << "Znajdz element zawierajacy klucz: ";
	cin >> key;
	
	for (int i = 0; i < rozmiar_tab; i++)
	{
		if (tab_key[i] == key)
		{
		czy_jest_klucz = 1;
		temp = i;
		}
	}
	string zmienna1, zmienna2;

	if (czy_jest_klucz == 1)
	{
		cout << "Klucz elementu: " << key << " - ma wartosc : " << tab[temp] << endl;
	}
	else
		cout << "Nie ma takiego elementu o zadanym kluczu: " << key << endl;
}

void Tablica_Asocjacyjna::Wyswietl_Dane()
{
	if(rozmiar_tab != 0)
	{
		cout << "Wyswietlanie elementow: " << endl;
		for(int i = 0; i < rozmiar_tab; i++)
			cout << "Element o zadanym kluczu: " << tab_key[i] << ": o wartosci: " << tab[i] << endl;
	}
	else
		cout << "Brak elementow! " << endl;
}
