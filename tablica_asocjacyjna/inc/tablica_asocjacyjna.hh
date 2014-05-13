#ifndef KOLEJKA_TABLICA_HH_INCLUDED
#define KOLEJKA_TABLICA_HH_INCLUDED
/*!
*\file
*\brief Funkcje zdefiniowane dla klasy Kolejka za pomoca tablicy.
*/
#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <time.h>
#include <cstdlib>
/*!
*\brief Deklaracja klasy Tablicy Asocjacyjnej.
*/
using namespace std;
/*!
* Klasa Tablica_Asocjacyjna
*
*/
class Tablica_Asocjacyjna
{
	private:
		/*!
		* \brief Zmienna typu int, zawierajaca rozmiar tablicy.
		*/
		int rozmiar_tab;
		/*!
		* \brief Zmienna pomocnicza typu int, zawierajaca rozmiar tablicy pomocniczej.
		*/		
		int rozmiar_temp;
		/*!
		* \brief Zmienna typu string, przechowuje znaki zawarte w tablicy. 
		*/		
		string *tab;
		
		string *tab_temp;
		
		string *tab_pomoc;
		
		string *tab_key;
	
	public:
		/*!
		* \brief Konstruktor klasy Tablica Asocjacyjna.
		* Konstruktor jest funkcja bezparametryczna, zerujaca
		* wszystkie skladniki zawarte w private.
		*/		
		Tablica_Asocjacyjna();
		/*!
		* \brief Destruktor klasy Tablica Asocjacyjna.
		* Destruktor zwalnia pamiec za pomoca usuniecia dynamicznej tablicy tab i tab_temp oraz tab_pomoc.
		*/	
		~Tablica_Asocjacyjna();
		/*!
		* \brief Funkcja isEmpty
		* Zwraca nam czy w stosie zawarte sa jakies elementy badz tez ich brak.
		*/			
		bool isEmpty();

		int Rozmiar();

		void Dodaj_Element();

		void Usun_Element();

		void Znajdz_Element();
		/*!
		* \brief Funkcja push.
		* Deklaracja funkcji odpowiedzialnej za dodawanie elementu do tablicy asocjacyjnej.
		*/	
		void push(string key, string element);
		/*!
		* \brief Funkcja pop.
		* Deklaracja funkcji odpowiedzialna za usuwanie elementu z tablicy asocjacyjnej.
		*/	
		void pop(void);
		/*!
		* \brief Funkcja wyswietlajaca dane.
		* Funkcja odpowiedzalna za wyswietlenie elementow zawartych w tablicy asocjacyjnej.
		*/
		void Wyswietl_Dane();
};
#endif