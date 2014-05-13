/*!
 *\file
 *\brief
 *Plik zawiera funkcje z klasy Lista.
 */
#include <iostream>
#include <list>
#include <stack>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "stos_lista.hh"

using namespace std;

Lista::Lista()
{
	poczatek = koniec = NULL;
	licznik = 0;
}

Lista::~Lista()
{
	while(poczatek)
		pop();
}

unsigned Lista::size()
{
	Stos_Lista * temp = poczatek;
	while(temp)
	{
		licznik++;
		temp = temp->nastepna_wartosc;
	}

	cout << "Liczba elementow: " << endl;
	return licznik;
}

bool Lista::empty(void)
{
	if(licznik == 0)
		return 1;
	return 0;
}

Stos_Lista * Lista::top(void)
{
	return poczatek;
}

Stos_Lista * Lista::push(Stos_Lista * lista)
{
	lista->nastepna_wartosc = poczatek;
	poczatek = lista;
	
	if(!koniec) koniec  = poczatek;
	licznik++;
	
	return poczatek;
}

Stos_Lista * Lista::pop()
{
	Stos_Lista * lista;
	
	if(poczatek)
	{
		lista = poczatek;
		poczatek = poczatek->nastepna_wartosc;
		
		if(!poczatek) koniec = NULL;
		licznik--;
		return lista;
	}
	else
	{
		return NULL;	 
	}
}

void Lista::Wyswietl_Elementy()
{
	Stos_Lista * lista;
	if(!poczatek)
		cout << "Brak elementow! " << endl;
	else
	{
		lista = poczatek;
		
		cout << "Zawartosc listy: " << endl;
		while(lista)
		{
			cout << lista->dane_stosu << endl;
			lista = lista->nastepna_wartosc;
		}
	}
}

void Lista::Dodaj_Element(int wartosc)
{
	Stos_Lista * lista;
	lista = new Stos_Lista;

	lista->dane_stosu = wartosc;
	push(lista);
}

void Lista::Wczytaj_Dane(string nazwa_pliku)
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
		while( plik>>temp)
			Dodaj_Element(temp);
	}
}

void Lista::Menu()
{
	Lista L;
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
		cout << "6 - Wczytaj dane " << endl;
		cout << "7 - Zakoncz program " << endl << endl;
		cout << "Wybor: ";

		cin >> wybor;

		if((wybor > 0) && (wybor < 7))
		{
			switch(wybor)
			{
				case 1: 
					{
						cout << "Wartosc elementu do dodania: " << endl;
						cin >> _element;
						cout << endl;  	
						L.Dodaj_Element(_element);
						break;
					}
				case 2: L.pop();
						break;
				case 3: L.Wyswietl_Elementy();
						break;
				case 4: L.size();
						break;
				case 5: L.empty();
						break;
				case 6: L.Wczytaj_Dane("stos.txt");
						L.Wyswietl_Elementy();
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