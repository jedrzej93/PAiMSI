#ifndef STOS_HH_INCLUDED
#define STOS_HH_INCLUDED
/*!
 *\file
 *\brief Funkcje zdefiniowane dla klasy Stosu, jak tablica.
 */
#include <iostream>
#include <list>
#include <stack>
#include <fstream>
#include <iomanip>
#include <sys/time.h>

using namespace std;
/*!
 *\brief Deklaracja klasy Stos.
 */

/*!
 * Klasa Stos zawiera dwie tablice dynamiczne, ktora 
 * jedna z nich zawiera dane dotyczace stosu i na ktorej
 * beda dokonywane operacje, a druga jako
 * tablica tymczasowa do przechowywania danych.
 *
 */
class Stos
{
	private:
		/*!
	 	* \brief Zmienna typu int, przechowuje rozmiar Stosu.
		*/
		int rozmiar_stosu;
		/*!
	 	* \brief Zmienna typu int, zmienna pomocnicza.
		*/
		int element;
		/*!
		 * \brief Zmienna typu int, wykorzystywana jako tablica dynamiczna.
		*/
		int * S; // tablica dynamiczna
		/*!
	 	* \brief Zmienna typu int, wykorzystywana jako pomocnicza tablica dynamiczna.
		*/
		int * S_temp;
	public:
		/*!
	 	* \brief Konstruktor klasy Stos.
	 	* Konstruktor jest funkcja bezparametryczna, zerujaca
	 	* wszystkie skladniki zawarte w private.
		*/
		Stos();
		/*!
	 	* \brief Destruktor klasy Stos.
	 	* Destruktor zwalnia pamiec za pomoca usuniecia dynamicznej tablicy S.
		*/
		~Stos(){ delete [] S; }
		/*!
	 	* \brief Funkcja empty.
	 	* Zwraca nam czy w stosie zawarte sa jakies elementy badz tez brak.
		*/
		bool empty(void) { return !rozmiar_stosu; }
		/*!
	 	* \brief Funkcja size.
	 	* Funkcja odpowiedzialna za wyswietlenie obecnego rozmiaru stosu.
		*/
		unsigned size() { cout << "Rozmiar stosu: " << endl; return rozmiar_stosu; }
		/*!
	 	* \brief Funkcja push.
	 	* Deklaracja funkcji odpowiedzialnej za dodawanie elementu do stosu.
	 	* Uzytkownik podaje wartosc elementu jaki chce dodac do stosu.
		* \param dodaj_element - parametr typu int, przechowuje wartosc zadana przez uzytkownika.
		*/
		void push(int dodaj_element);
		/*!
		* \brief Funkcja pop.
		* Deklaracja funkcji odpowiedzialna za usuwanie elementu ze stosu.
		* Funkcja usuwa ostatni element znajdujacy sie na stosie i zmiejsza
		* jego rozmiar o jeden.
		*/
		void pop();
		/*!
	 	* \brief Funkcja Wyswietl Stos
	 	* Funkcja odpowiedzalna za wyswietlenie stosu.
		*/
		void Wyswietl_Stos();
		/*!
	 	* \brief Funkcja Wczytaj dane.
	 	* Funkcja wczytuje dane z pliku o zadanej nazwie pliku.
	 	*\param nazwa_pliku - zmienna typu string zawierajaca dokladna nazwe pliku do wczytania.
		*/
		void Wczytaj_Dane(string nazwa_pliku);
		/*!
	 	* \brief Funkcja wyswietlajaca Menu klasy Stos.
	 	* Deklaracja funkcji, ktora wyswietla Menu.
	 	* Uzytkownik moze wybrac dowolna opcje zawarta w Menu, poprzez
	 	* wybranie odpowiedniego numeru. W Menu uzytkownik moze dodawac element, wczytac pliku,
	 	* usunac element, zapytac o rozmiar stosu, itp.
		*/
		void Menu();
};

#endif