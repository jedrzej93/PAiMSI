#ifndef KOLEJKA_LISTA_HH_INCLUDED
#define KOLEJKA_LISTA_HH_INCLUDED
/*!
 *\file
 *\brief Funkcje zdefiniowane dla klasy Kolejka za pomoca listy.
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
 * Lista_kolejka jest struktura, ktora jest wpisana 
 * do kolejki klasy Kolejka_lista. W strukturze zawarty jest
 * wskaznik na nastepny element w kolejce oraz zmienna
 * int zawierajaca wartosci danego elementu.
 *
 */
struct Lista_kolejka
{
	Lista_kolejka * nast_elem;
	int wartosci;
};
/*!
 *\brief Deklaracja klasy Kolejka_lista.
 */

/*!
 * Klasa Kolejka_lista zawiera dwie listy dynamiczne, ktore 
 * wskazuja na wartosc poczatkowa kolejki oraz wskaznik wartosci na dany element.
 *
 */
class Kolejka_lista
{
	private:
		/*!
	 	* \brief Zmienna typu Lista_kolejka *, zmienna wskazuja wskaznik na dany element.
		*/		
		Lista_kolejka * wsk_pocz;
		/*!
	 	* \brief Zmienna typu Lista_kolejka *, wskazuje poczatkowy element.
		*/		
		Lista_kolejka * poczatek;
	public:
		/*!
	 	* \brief Konstruktor klasy Kolejka_lista.
	 	* Konstruktor jest funkcja bezparametryczna, zerujaca
	 	* wszystkie skladniki zawarte w private.
		*/		
		Kolejka_lista();
		/*!
	 	* \brief Destruktor klasy Kolejka_lista.
	 	* Destruktor zwalnia pamiec za pomoca usuniecia dynamicznej listy poczatek i wsk_pocz.
		*/			
		~Kolejka_lista();
		/*!
	 	* \brief Funkcja empty.
	 	* Zwraca nam czy w stosie zawarte sa jakies elementy badz tez brak.
		*/		
		bool empty(void);
		/*!
	 	* \brief Funkcja zwracajaca element znajdujacy sie na szczycie kolejki.
		*/
		int front(void);
		/*!
	 	* \brief Funkcja push.
	 	* Deklaracja funkcji odpowiedzialnej za dodawanie elementu do kolejki.
	 	* Uzytkownik podaje wartosc elementu jaki chce dodac do kolejki.
		* \param element - parametr typu int, przechowuje wartosc elementu do dodania.
		*/				
		void push(int element);
		/*!
		* \brief Funkcja pop.
		* Deklaracja funkcji odpowiedzialna za usuwanie elementu z kolejki.
		* Funkcja usuwa ostatni element znajdujacy sie w kolejce i zmiejsza
		* jego rozmiar o jeden.
		*/			
		void pop();
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
		void Wyswietl_Element();
		/*!
	 	* \brief Funkcja wyswietlajca menu klasy Kolejka.
		*/			
		void Menu();
};

#endif