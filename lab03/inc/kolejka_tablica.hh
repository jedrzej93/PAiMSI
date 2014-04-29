#ifndef KOLEJKA_TABLICA_HH_INCLUDED
#define KOLEJKA_TABLICA_HH_INCLUDED
/*!
 *\file
 *\brief Funkcje zdefiniowane dla klasy Kolejka za pomoca tablicy.
 */
#include <iostream>
#include <list>
#include <stack>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;
/*!
 *\brief Deklaracja klasy Kolejka.
 */

/*!
 * Klasa Kolejka zawiera dwie tablice dynamiczne, ktora 
 * jedna z nich zawiera dane dotyczace kolejki i na ktorej
 * beda dokonywane operacje, a druga jako
 * tablica tymczasowa do przechowywania danych.
 *
 */
class Kolejka
{
	private:
		/*!
	 	* \brief Zmienna typu int, przechowuje rozmiar kolejki.
		*/
		int rozmiar_tab;
		/*!
	 	* \brief Zmienna typu int, wskazuje wartosc poczatkowa kolejki.
		*/
		int wsk_pocz;
		/*!
	 	* \brief Zmienna typu int, zmienna pomocnicza przy liczeniu ilosci elementow.
		*/
		int licz_elem;
		/*!
	 	* \brief Zmienna typu int, tablica dynamiczna kolejki.
		*/
		int * Tab; // tablica dynamiczna
		/*!
	 	* \brief Zmienna typu int, tablica dynamiczna pomocnicza kolejki.
		*/
		int * Tab_temp; // tablica dynamiczna pomocnicza
	public:
		/*!
	 	* \brief Konstruktor klasy Kolejka.
	 	* Konstruktor jest funkcja bezparametryczna, zerujaca
	 	* wszystkie skladniki zawarte w private.
		*/
		Kolejka();
		/*!
	 	* \brief Destruktor klasy Kolejka.
	 	* Destruktor zwalnia pamiec za pomoca usuniecia dynamicznej tablicy Tab i Tab_temp.
		*/		
		~Kolejka(){ delete [] Tab; delete [] Tab_temp; }
		/*!
	 	* \brief Funkcja isEmpty
	 	* Zwraca nam czy w stosie zawarte sa jakies elementy badz tez brak.
		*/		
		bool isEmpty();
		/*!
	 	* \brief Funkcja push.
	 	* Deklaracja funkcji odpowiedzialnej za dodawanie elementu do kolejki.
	 	* Uzytkownik podaje wartosc elementu jaki chce dodac do kolejki.
		* \param dodaj_elem - parametr typu int, przechowuje wartosc zadana przez uzytkownika.
		*/		
		void push(int dodaj_elem);
		/*!
		* \brief Funkcja pop.
		* Deklaracja funkcji odpowiedzialna za usuwanie elementu z kolejki.
		* Funkcja usuwa ostatni element znajdujacy sie w kolejce i zmiejsza
		* jego rozmiar o jeden.
		*/		
		void pop(void);
		/*!
	 	* \brief Funkcja Wczytaj dane.
	 	* Funkcja wczytuje dane z pliku o zadanej nazwie pliku.
	 	*\param nazwa_pliku - zmienna typu string zawierajaca dokladna nazwe pliku do wczytania.
		*/
		void Wczytaj_Dane(string nazwa_pliku);
		/*!
	 	* \brief Funkcja wyswietlajaca dane.
	 	* Funkcja odpowiedzalna za wyswietlenie kolejki.
		*/
		void Wyswietl_Dane();
		/*!
	 	* \brief Funkcja wyswietlajca menu klasy Kolejka.
		*/		
		void Menu();
};

#endif