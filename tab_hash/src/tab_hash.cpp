#include <iostream>
#include <fstream>
#include "tab_hash.hh"

using namespace std;

Tablica_Haszujaca::Tablica_Haszujaca(int elementy)
{
	rozmiar = elementy;
	temp = 0;
	wartosc = new string[rozmiar];
}

Tablica_Haszujaca::~Tablica_Haszujaca()
{
	delete[] wartosc;
}

int Tablica_Haszujaca::size()
{
	cout << "Rozmiar to: " << rozmiar << endl;
	cout << "Ilosc elementow w tablicy hashujacej: " << temp << endl;
	return rozmiar;
}

int Tablica_Haszujaca::Funkcja_Hashujaca(string element)
{
	int hash = 0;
	int temp = 0;
	
	for(unsigned int i = 0; i < element.size(); i++)
		hash += element[i];
	
	temp = hash%rozmiar;
	
	return temp;
}

bool Tablica_Haszujaca::Czy_Pusta()
{
	if(temp == 0)
	{
		cout << "Brak elementow w tablicy!" << endl;
		return false;
	}
	else
	{
		cout << "W tablicy znajduja sie elementy!" << endl;
		return true;
	}
}

void Tablica_Haszujaca::Wyswietl_Tablice()
{
	cout << "Tablica Hashujaca: " << endl;
	for(int i = 0; i < rozmiar; i++)
		cout << "T[ " << i + 1 << " ] = " << wartosc[i] << endl;
}

void Tablica_Haszujaca::Szukaj()
{
	string szukaj;

	cout << "Znajdz podany element: ";
	cin >> szukaj;
	Znajdz(szukaj);
}

void Tablica_Haszujaca::Znajdz(string szukaj)
{
	int zmienna = Funkcja_Hashujaca(szukaj);
	int i = zmienna;
	bool czy_jest = 0;

	do
	{
		if(wartosc[i] == szukaj)
		{
			cout << "Element: " << szukaj << " znajduje sie w tablicy: " << i + 1 << endl;
			czy_jest = 1; 
			break;
		}
		else
			i = (i + 1) % rozmiar;
	}
	while(i != zmienna);

	if(czy_jest == 0)
		cout << "Brak elementu: " << szukaj << " - w tablicy! " << endl;	
}

void Tablica_Haszujaca::Usun_Element()
{
	string element;
	cout << "Jaki element usunac?" << endl;
	cout << "Element: ";
	cin >> element;
	Usun(element);
}

void Tablica_Haszujaca::Usun(string szukaj)
{
	int zmienna = Funkcja_Hashujaca(szukaj);
	int i = zmienna;
	bool czy_jest = 0;

	do
	{
		if(wartosc[i] == szukaj)
		{
			cout << "Element zostal usuniety: " << szukaj << " ktory znajdowal sie na pozycji: " << i + 1 << endl;
			czy_jest = 1;
			temp--; 
			break;
		}
		else
			i = (i + 1) % rozmiar;
	}
	while(i != zmienna);

	if(czy_jest == 0)
		cout << "Brak elementu: " << szukaj << " - w tablicy! " << endl;
}

void Tablica_Haszujaca::Dodaj_Element()
{
	string element;
	cout << "Podaj element jaki chcesz dodac do tablicy haszujacej: ";
	cin >> element;
	Dodaj_Element_Tab(Funkcja_Hashujaca(element), element);
}

void Tablica_Haszujaca::Dodaj_Element_Tab(int zmienna, string element)
{
	if(temp == rozmiar)
		cout << "Brak miejsca!" << endl;
	else
	{
		int i = zmienna;
		do
		{
			if(wartosc[i] == "")
			{
				wartosc[i] = element;
				temp++;
				break;
			}
		else
			i = (i + 1) % rozmiar;
		}
		while(i != zmienna);
	}
}

void Tablica_Haszujaca::Wczytaj_Dane(string nazwa_pliku)
{
	string temp;

	ifstream plik(nazwa_pliku.c_str());
	if(!plik)
		cerr << "Blad wczytania pliku!!!" << endl;
	else
		while(plik >> temp)
			Dodaj_Element_Tab(Funkcja_Hashujaca(temp), temp);
}
