#ifndef SIMPLEX_INCLUDED
#define SIMPLEX_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
/*!
 *\file Plik naglowkowy klasy Simplex.
 */
using namespace std;
/*!
*\brief Deklaracja klasy Simplex.
*/
class Simplex
{
	private:
		/*!
		*\brief Zmienna wskaznikowa typu double, tworzaca macierz dla algorytmu Simplex.
		*/
		double** macierz;
		/*!
		*\brief Zmienna typu int odpowiadajaca za wiersze w tworzonej macierzy dla
		* algorytmu simplex.
		*/
		int wiersze;
		/*!
		*\brief Zmienna typu int odpowiadajaca za kolumny w macierzy simplex.
		*/	
		int kolumny;
		/*!
		*\brief Tablica pomocnicza nr 1 trojelementowa typu int do wykonywania algorytmu simplex.
		*/
		int powt_test[2];
		/*!
		*\brief Tablica pomocnicza nr2 trojelementowa typu int do wykonywania algorytmu simplex.
		*/
		int powt_test1[2];
		/*!
		*\brief Zmienna wskaznikowa typu int, zawierajace zmienne wierszy w macierzy simplex.
		*/
		int* w_zmienne;
		/*!
		*\brief Zmienna wskaznikowa typu int, zawierajaca zmienne znajdujace sie w kolumnach macierzy simplex.
		*/
		int* k_zmienne;
		
	public:
		/*!
		*\brief Funkcja tworzaca macierz dla algorytmu simplex.
		* Funkcja tworzy o zadanej liczbie rownan oraz zmiennych decyzyjnych czyli np x1, x2 itp
		* tworzac tablice dynamiczna dla wierszy oraz kolumn.
		*/
		void Stworz();
		/*!
		*\brief Funkcja wypelniajaca macierz simplex.
		* Funkcja zapelnia stworzona wczesniej macierz, poprzez uzytkownika, ktory wprowadza 
		* poszczegolne zmienne - wartosci funkcji celu. A nastepnie sa wyswietlane utworzone rownania oraz rozmiar macierzy M.
		*/
		void Wypelnij();
		/*!
		*\brief Funkcja konczaca wykonanie testu dla algorytmu simplex.
		* Funkcja sprawdza czy poszczegolne wartosci w utworzonych wierszach oraz
		* kolumnach w macierzy sa wieksze niz zero, aby bylo to rownanie do obliczenia.
		*/
		bool Zakoncz_Test();
		/*!
		*\brief Funkcja obracajaca pivota.
		*/
		int* Obroc_Pivot();
		/*!
		*\brief Funkcja pivota.
		*/
		void Pivot();
		/*!
		*\brief Funkcja wskaznikowa zwracajaca zmienna macierz.
		*/
		double** Zwroc_Macierz();
		/*!
		*\brief Funkcja wyswietlajaca macierz z wartosciami
		* poszczegolnych wartosci celu.
		*/
		void Wyswietl();
		/*!
		*\brief Funkcja rozwiazujaca podane rowniania
		* w celu znalezienia optymalnego rozwiazania.
		*/
		void Rozwiazanie();

};
#endif