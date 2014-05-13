/*!
 *\file
 *\brief
 *Plik zawiera funkcje z klasy Kolejka_lista.
 *
 */
#include <iostream>
#include <list>
#include <stack>
#include <iomanip>
#include <fstream>
#include "kolejka_lista.hh" 

using namespace std;

Kolejka_lista::Kolejka_lista()
{
	poczatek = wsk_pocz = NULL;
}

Kolejka_lista::~Kolejka_lista()
{
	Lista_kolejka * lista;
	while(poczatek)
	{
		lista = poczatek->nast_elem;
		delete poczatek;
		poczatek = lista;
	}
}

bool Kolejka_lista::empty()
{
	return !poczatek;
}

int Kolejka_lista::front(void)
{
	if(poczatek)
		return poczatek->wartosci;
	else
		return 0;
}

void Kolejka_lista::push(int element)
{
	Lista_kolejka * temp = new Lista_kolejka;
	temp->nast_elem = NULL;
	temp->wartosci = element;

	if(wsk_pocz)
		wsk_pocz->nast_elem = temp;
	else poczatek = temp;

	wsk_pocz = temp;
}

void Kolejka_lista::pop()
{
	if(poczatek)
	{
		Lista_kolejka * temp = poczatek;
		poczatek = poczatek->nast_elem;
		if(!poczatek)	
			wsk_pocz = NULL;
		delete temp;
	}
}

void Kolejka_lista::Wyswietl_Element()
{
	Lista_kolejka * wsk_pocz;
	if(!poczatek)
		cout << "Brak elementow! " << endl;
	else
	{
		wsk_pocz = poczatek;
		
		cout << "Zawartosc listy: " << endl;
		while(wsk_pocz)
		{
			cout << wsk_pocz->wartosci << endl;
			wsk_pocz = wsk_pocz->nast_elem;
		}
	}
}

void Kolejka_lista::Wczytaj_Dane(string nazwa_pliku)
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
		while( plik>>temp);
			push(temp);
	}
}

void Kolejka_lista::Menu()
{
	Kolejka_lista K;

	K.Wczytaj_Dane("stos.txt");
	K.Wyswietl_Element();
}