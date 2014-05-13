/*!
 *\file
 *\brief
 *
 *Plik zawiera funkcje z klasy Kolejka.
 */
#include <iostream>
#include <list>
#include <stack>
#include <iomanip>
#include <fstream>
#include "kolejka_tablica.hh"

using namespace std;

Kolejka::Kolejka()
{
	wsk_pocz = licz_elem = rozmiar_tab = 0;
	Tab = 0;
	Tab_temp = 0;
}

bool Kolejka::isEmpty()
{
	if(rozmiar_tab == 0)
		return 1;
	else
		return 0;
}

void Kolejka::pop()
{
	if(rozmiar_tab != 0)
	{
		Tab_temp = new int[rozmiar_tab];
		for(int i = 0; i < rozmiar_tab; i++)
			Tab_temp[i] = Tab[i];
		delete Tab;
		--rozmiar_tab;

		Tab = new int[rozmiar_tab];
		for(int i = 0; i < rozmiar_tab; i++)
			Tab[i] = Tab_temp[i];
		delete [] Tab_temp;
	}
	else 
		cout << endl;
}

void Kolejka::push(int dodaj_elem)
{
	if( rozmiar_tab != 0)
	{
		Tab_temp = new int[rozmiar_tab];
		for(int i = 0; i < rozmiar_tab; i++)
		{
			Tab_temp[i] = Tab[i];
		}
		delete [] Tab;

		++rozmiar_tab;
		Tab = new int[rozmiar_tab];
		Tab[0] = dodaj_elem;
		
		int x = 1;
		for(int i = 0; i < (rozmiar_tab - 1); i++)
		{
			Tab[x] = Tab_temp[i];
			x++;
		}
		x = 0;
		delete [] Tab_temp;
	} 
	else
	{
		++rozmiar_tab;
		Tab = new int[1];
		Tab[0] = dodaj_elem;
	}

}

void Kolejka::Wyswietl_Dane()
{	
	if(rozmiar_tab != 0)
	{
		cout << "Zawartosc kolejki:  " << endl;
		for(int i = (rozmiar_tab - 1); i >= 0 ; i--)
			cout << Tab[i] << endl;
	}
}

void Kolejka::Wczytaj_Dane(string nazwa_pliku)
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
		while(plik >> temp)
			push(temp);
	}
}

void Kolejka::Menu()
{
	Kolejka K;
	K.Wczytaj_Dane("stos.txt");
	K.Wyswietl_Dane();
}