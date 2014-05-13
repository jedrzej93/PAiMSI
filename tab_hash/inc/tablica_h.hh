#ifndef TABLICA_H_HH_INCLUDED
#define TABLICA_H_HH_INCLUDED

#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int ROZMIAR_TAB = 100;

class Wezel
{
	public:
		int klucz;
		int wartosc;
		Wezel(int key, int wartosc)
		{
			this->klucz = klucz;
			this->wartosc = wartosc;
		}
};

class Usuniety_Wezel:public Wezel
{
	private:
		
		static Usuniety_Wezel * wejscie;
		
		Usuniety_Wezel():Wezel(-1, -1) {}
	
	public:
		
		static Usuniety_Wezel *Wez_Wezel()
		{
			if(wejscie == NULL)
				wejscie = new Usuniety_Wezel();
			return wejscie;
		}
};

class Tab_Hash
{
	private:
		
		Wezel **tab_hash;
	
	public:
		
		Tab_Hash()
		{
			tab_hash = new Wezel* [ROZMIAR_TAB];
			for(int i = 0; i < ROZMIAR_TAB; i++)
			{
				tab_hash[i] = NULL;
			}
		}
		~Tab_Hash()
		{
			for(int i = 0; i < ROZMIAR_TAB; i++)
			{
				if(tab_hash[i] != NULL && tab_hash[i] != Usuniety_Wezel::Wez_Wezel())
					delete tab_hash[i];
			}
			delete[] tab_hash;
		}

		int Hashuj(int klucz)
		{
			return klucz % ROZMIAR_TAB;
		}

		void Dodaj(int klucz, int wartosc)
		{
			int wartosc_hash = Hashuj(klucz);
			int zmienna = -1;
			int usun_indeks = -1;

			while(wartosc_hash != zmienna && (tab_hash[wartosc_hash]) == Usuniety_Wezel::Wez_Wezel() || tab_hash[wartosc_hash] != NULL)
		}
};
#endif;
http://www.sanfoundry.com/cpp-program-implement-hash-tables-linear-probing/