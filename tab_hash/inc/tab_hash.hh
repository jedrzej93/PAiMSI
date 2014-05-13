#ifndef TAB_HASH_HH_INCLUDED
#define TAB_HASH_HH_INCLUDED

#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

class Tablica_Haszujaca
{
	private:
		
		string * wartosc;
		
		int rozmiar;
		
		int temp;
	
	public:
		
		Tablica_Haszujaca(int elementy);
		
		~Tablica_Haszujaca();
		
		int Funkcja_Hashujaca(string element);
		
		int size();

		bool Czy_Pusta();

		void Wyswietl_Tablice();

		void Szukaj();

		void Znajdz(string szukaj);

		void Usun_Element();

		void Usun(string szukaj);

		void Dodaj_Element();

		void Dodaj_Element_Tab(int zmienna, string element);

		void Wczytaj_Dane(string plik);

};
#endif