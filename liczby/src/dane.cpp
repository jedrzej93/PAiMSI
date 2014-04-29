#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "../inc/dane.hh"
/*!
*\file
*\brief Plik zawierajace zdefiniowane funkcje dla klasy Dane.
*/
using namespace std;

void Dane::Wyzeruj_Dane()
{
	delete [] tablica;
	delete [] tablica_spr;

	rozmiar = 0;
	rozmiar_spr = 0;
	temp = 0;
	temp_spr = 0;
}

Dane::Dane(string Nazwa_Pliku)
{
	tablica = 0; tablica_spr = 0; temp = 0; temp_spr = 0; rozmiar_spr = 0; rozmiar = 0;

	ifstream plik(Nazwa_Pliku.c_str());
	
	if(!plik)
	{
		cout << "Nie mozna otworzyc pliku!" << endl;
		getchar();
	}
	plik >> rozmiar;
	tablica = new int[rozmiar];
	while(!plik.eof())
		plik >> tablica[temp++];
}

void Dane::Wczytaj_Dane()
{
	string nazwa_pliku;
	cout << "Wczytaj plik o nazwie: " << endl;
	cin >> nazwa_pliku;

	ifstream plik(nazwa_pliku.c_str());

	if(!plik)
	{
		cout << "Nie mozna otworzyc pliku!" << endl;
		getchar();
	}

	plik >> rozmiar;
	tablica = new int[rozmiar];
	while(!plik.eof())
		plik >> tablica[temp++];
}

void Dane::Wczytaj_Dane_Spr()
{
	
	string nazwa_pliku;
	cout << "Wczytaj plik o nazwie: " << endl;
	cin >> nazwa_pliku;
	
	ifstream plik_spr(nazwa_pliku.c_str());
	if(!plik_spr)
	{
		cout << "Nie mozna otworzyc pliku!" << endl;
		getchar();
	}
	
	plik_spr >> rozmiar_spr;
	tablica = new int[rozmiar_spr];
	while(!plik_spr.eof())
		plik_spr >> tablica_spr[temp_spr++];
		
}

void Dane::Wykonaj_Obliczenia()
{
	//cout << "Wykonanie mnozenia tablicy x2: " << endl;
		for ( int i = 0; i < rozmiar; i++)
		{
	    	tablica[i] = tablica[i]*2;
		}
}

void Dane::Sprawdz()
{
	int blad = 0;
	cout << "Sprawdzanie..." << endl;
		for ( int i = 0; i < rozmiar; i++)

	    for ( int j = 0; j < rozmiar_spr; j++)
	      {
	       		if( tablica[i] != tablica_spr[j])
	       		{
	       			blad = 1;
	       			break;
	       		}
	       		else blad = 0;
	       	}

	       	if ( blad == 1)
	       		cout << endl <<"BLAD! TABLICE SA ROZNE!" << endl;
	       	else cout << "TABLICE SA TAKIE SAME!" << endl;
}

void Dane::Pokaz_Dane()
{
	cout << "Zawartosc pliku: " << endl;
	    for ( int i = 0; i < rozmiar; i++)
	    {
	       	cout << tablica[i] << endl;
	    }
}

void Dane::Pokaz_Dane_Spr()
{
	cout << "Zawartosc pliku: " << endl;
       	for ( int j = 0; j < rozmiar; j++)
       	{
       		cout << tablica_spr[j] << endl;
       	}
}
