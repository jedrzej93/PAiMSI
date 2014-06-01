#ifndef GRAF_HH_INCLUDED
#define GRAF_HH_INCLUDED
/*!
 *\file Plik naglowkowy klasy Graf.
 * Klasa Graf zawierajaca definicje poszczegolnych funkcji.
 */
#include <iostream>
#include <iomanip>

using namespace std;
/*!
*\brief Deklaracja klasy Graf.
*/
class Graf
{
	public:
		/*!
		*\brief Konstruktor klasy Graf.
		* Funkcja zeruje zmienna wezel.
		*/
		Graf();
		/*!
		*\brief Konstruktor klasy Graf.
		*/
		Graf(const Graf&);
		/*!
		*\brief Destruktor klasy Graf.
		* Funkcja zwalnia pamiec poprzez usuniecie utworzonych wezlow.
		*/
		~Graf();
		/*!
		*\brief Operator przesuniecia bitowego.
		* Operator sluzy do wyswietlenia stworzonego grafu.
		*/
		friend ostream& operator << (ostream&, const Graf&);
		/*!
		*\brief Deklaracja klasy Wezel w klasie Graf.
		*/
		class Wezel
		{
			public:
				/*!
				*\brief Konstruktor klasy Wezel.
				* W konstruktorze przydzielany jest klucz
				* do danego wezla oraz zerowane sa zmienne
				* nastepny oraz krawedz.
				*/
				Wezel(int);
				/*!
				*\brief Destruktor klasy Wezel.
				* Funkcja zwalnia pamiec poprzez usuniecie utworzonych wezlow.
				*/
				~Wezel();
				/*!
				*\brief Operator przesuniecia bitowego.
				* Operator sluzy do wyswietlenia stworzonych wezlow.
				*/
				friend ostream& operator << (ostream&, const Wezel&);
				/*!
				*\brief Deklaracja klasy Krawedz w klasie Wezel, w klasie Graf.
				*/
				class Krawedz
				{
					public:
						/*!
						*\brief Konstruktor klasy Krawedz.
						* W konstruktorze przydzielany jest cel
						* oraz nadawana jest waga danej krawedzi.
						* Zerowana jest zmienna nastepny.
						*/
						Krawedz(int, int);
						/*!
						*\brief Destruktor klasy Krawedz.
						* Funkcja zwalnia pamiec poprzez zerowanie zmiennej nastepny.
						*/
						~Krawedz();
						/*!
						*\brief Operator przesuniecia bitowego.
						* Operator sluzy do wyswietlenia stworzonych krawedzi.
						*/
						friend ostream& operator << (ostream&, const Krawedz&);
						/*!
						*\brief Zmienna pomocnicza typu int, odpowiedzialna za tworzenie krawedzi.
						* Dzieki tej zmiennej wiemy z jakim wezlem tworzymy krawedz.
						*/
						int cel;
						/*!
						*\brief Zmienna pomocnicza typu int, odpowiedzialna za nadawanie wagi
						* poszczegolnym krawedziom.
						*/
						int waga;
						/*!
						*\brief Zmienna typy Krawedz, jest to wskaznik na nastepny element
						* tworzacy krawedz.
						*/
						Krawedz * nastepny;
				};
				/*!
				*\brief Zmienna pomocnicza typu int, nadaje odpowiedni klucz
				* wezlom, dzieki temu mozemy wyszukiwac po kluczu dane wezly.
				*/
				int klucz;
				/*!
				*\brief Zmienna typu Wezel, wskaznik na nastepny element dodawany do wezla.
				*/
				Wezel * nastepny;
				/*!
				*\brief Zmienna typu Krawedz, wskaznik na dana krawedz.
				*/
				Krawedz * krawedz;
				/*!
				*\brief Funkcja szukajaca dana krawedz.
				* Funkcja o zadanym celu wyszukuje dana krawedz, przyrownujac
				* czy dana krawedz jest rowna zadanemu celu.
				*/
				bool Szukaj_Krawedz(int);
				/*!
				*\brief Funkcja sprawdzajaca czy istnieja krawedzie w wezle.
				*/
				bool empty();
				/*!
				*\brief Funkcja dodaja krawedz.
				* Funkcja dodaje krawedz o zadanym celu oraz nadajac wage
				* tej krawedzi.
				*/
				void Dodaj_Krawedz(int, int);
				/*!
				*\brief Funkcja usuwajaca krawedz.
				* Funkcja usuwa dana krawedz o zadanym celu.
				*/
				void Usun_Krawedz(int);
		};
		/*!
		*\brief Funkcja szukajaca wezla.
		* Funkcja wyszukuje wezla o podanym kluczu.
		*/
		bool Szukaj_Wezel(int);
		/*!
		*\brief Funkcja znajdujaca wezel.
		* Funkcja z klasy Wezel w klasie Graf, znajdujaca 
		* wezel o podanym kluczu oraz sprawdzajaca czy dany wezel
		* zostal znaleziony.
		*/
		Graf::Wezel * Znajdz_Wezel(int);
		/*!
		*\brief Funkcja sprawdzajaca czy istnieja wezly w grafie.
		*/
		bool empty();
		/*!
		*\brief Funkcja dodajaca wezel do grafu.
		* Funkcja dodaje wezel o zadanym kluczu.
		*/
		void Dodaj_Wezel(int);
		/*!
		*\brief Funkcja dodajaca krawedz do grafu.
		* Funkcja dodaje krawedz o zdanych trzech zmiennych -
		* klucz do wezla z ktorym ma byc utworzona krawedz, zmienna
		* cel oraz waga tej krawedzi.
		*/
		void Dodaj_Krawedz(int, int, int);
		/*!
		*\brief Funkcja usuwajaca wezel.
		* Funkcja usuwa dany wezel w grafie o zadanym kluczu.
		*/
		void Usun_Wezel(int);
		/*!
		*\brief Funkcja usuwajaca stworzone krawedzie.
		* Funkcja usuwajaca krawedzie, ktore zostaly stworzone i 
		* w danym momencie znajduja sie w grafie. Jest to funkcja pomocnicza
		* do usuwania wezla w grafie.
		*/
		void Usun_Istniejace_Krawedzie(int);
		/*!
		*\brief Funkcja usuwajaca krawedz.
		* Funkcja usuwa dana krawedz z grafu o zadanym kluczu wezla i celu.
		*/
		void Usun_Krawedz(int, int);

	private:
		/*!
		*\brief Zmienna typu Wezel, jest to wskaznik na dany wezel w grafie.
		*/
		Wezel * wezel;
};
#endif