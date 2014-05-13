#ifndef STOS_LISTA_HH_INCLUDED
#define STOS_LISTA_HH_INCLUDED
/*!
 *\file
 *\brief Funkcje zdefiniowane dla klasy Stos_Lista, jako lista.
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
 *
 *\brief Deklaracja klasy Stos_Lista.
 */

/*!
 * Stos_Lista jest struktura, ktora jest wpisana 
 * do stosu klasy Lista. W strukturze zawarty jest
 * wskaznik na nastepny element w stosie oraz zmienna
 * int zawierajaca wartosci danego elementu.
 *
 */
struct Stos_Lista
{
	/*!
	* \brief Zmienna typu Stos_Lista *, jest to wskaznik laczacy elementy w stos.
	*/
	Stos_Lista * nastepna_wartosc;
	/*!
	* \brief Zmienna typu int, przechowuje wartosci danych elementow.
	*/
	int dane_stosu;
};
/*!
 * Klasa Lista zawiera dwie listy dynamiczne, ktora 
 * jedna z nich zawiera dane dotyczace poczatku listy, a druga jako
 * dotyczaca konca listy, na ktorych beda wykonywane operacje.
 *
 */
class Lista
{
	private:
		/*!
	 	* \brief Zmienna typu Stos_Lista *, wskaznik na pierwszy element listy.
		*/
		Stos_Lista * poczatek;
		/*!
	 	* \brief Zmienna typu Stos_Lista *, wskaznik na ostatni element listy.
		*/
		Stos_Lista * koniec; 
		/*!
		* \brief Zmienna typu unsigned, bedzie pelnina funkcje jako rozmiar stosu.
		*/
		unsigned licznik;

	public:
		/*!
	 	* \brief Konstruktor klasy Lista.
	 	* Konstruktor jest funkcja bezparametryczna, zerujaca
	 	* wszystkie skladniki zawarte w private.
		*/
		Lista(); // konstruktor
		/*!
	 	* \brief Destruktor klasy Lista.
	 	* Destruktor zwalnia pamiec za pomoca usuniecia dynamicznej listy poczatek, koniec
		*/
		~Lista(); // destruktor
		
		unsigned size();
		/*!
	 	* \brief Funkcja wyswietlajaca rozmiar listy.
		*/
		void rozmiar_listy();
		/*!
	 	* \brief Funkcja empty.
	 	* Zwraca nam czy w stosie zawarte sa jakies elementy badz tez brak.
		*/
		bool empty(void);
		/*!
 		*\brief Funkcja zwracaja pierwsza wartosc stosu.
 		* 
 		* Funkcja zwraca nam wartosc znajdujaca sie na szczycie stosu.
 		*/
		Stos_Lista * top(void);
		/*!
 		*\brief Funkcja dodajaca element do stosu
 		* 
 		* Funkcja, ktora dodaje element do stosu za pomoca push.
 		* Uzytkownik podaje podana wartosc elementu, ktory ma zostac dodany.
 		*\param lista - zmienna typu Stos_Lista*, ktora przechowuje wartosci, ktore beda wpisane do stosu.
 		*/
		Stos_Lista * push(Stos_Lista * lista);
		/*!
 		*\brief Funkcja usuwajaca ostatni element na stosie.
 		* Na poczatku sprawdzamy czy stos nie jest pusty, jezeli jest to zwracamy NULL.
 		* Jesli stos zawiera elementy to przypisuje wskaznik jako pierwszy element. Poprzez zmienna poczatek
 		* przechodzimy do kolejnego elementu i odczepiamy go od listy. Jesli zmienna poczatek
		* zwroci NULL to rowniez do zmiennej koniec przypisujemy NULL, zmiejszamy licznik i 
		* zwracamy adres wskaznika elementu, ktory usunelismy.	
 		*/
		Stos_Lista * pop();
		/*!
	 	* \brief Funkcja Wyswietl Elementy
	 	* Funkcja odpowiedzalna za wyswietlenie elementow znajdujacych sie na stosie.
		*/
		void Wyswietl_Elementy();
		/*!
	 	* \brief Funkcja Wczytaj dane.
	 	* Funkcja wczytuje dane z pliku o zadanej nazwie pliku.
	 	*\param nazwa_pliku - zmienna typu string zawierajaca dokladna nazwe pliku do wczytania.
		*/
		void Wczytaj_Dane(string nazwa_pliku);
		/*!
 		*\brief Funkcja dodajaca element poprzez funkcje push
 		* 
 		* Funkcja, ktora dodaje element do stosu za pomoca push.
 		* Uzytkownik podaje podana wartosc elementu, ktory ma zostac dodany.
 		*\param wartosc - zmienna typu int, zawierajaca wartosc elementu do dodania.
 		*/
		void Dodaj_Element(int wartosc);
		/*!
	 	* \brief Funkcja wyswietlajaca Menu klasy Lista.
	 	* Deklaracja funkcji, ktora wyswietla Menu.
	 	* Uzytkownik moze wybrac dowolna opcje zawarta w Menu, poprzez
	 	* wybranie odpowiedniego numeru. W Menu uzytkownik moze dodawac element, wczytac pliku,
	 	* usunac element, zapytac o rozmiar stosu, itp.
		*/
		void Menu();
};


#endif