#ifndef BENCHMARK_HH_INCLUDED
#define BENCHMARK_HH_INCLUDED

#include <fstream>
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include "kolejka_tablica.hh"
#include "kolejka_lista.hh"
#include "stos_tablica.hh"
#include "stos_lista.hh" 
/*!
 *\file Benchmark
 *\brief 
 * Plik naglowkowy klasy Benchmark
 * zawiera elementy private oraz public tej klasy.
 */
using namespace std;
/*!
 *\brief Benchmark
 * Klasa Benchmark
 * w owej klasie definiujemy funkcje odpowiedzialne
 * za wykonanie algorytmu benchmarku, ktory zwraca
 * nam czas w ms jaki uplynal podczas wykonywania operacji.
 */
class Benchmark
{
	private:
		/*!
	 	* \brief Zmienne typu timeval, zmienne przyjmujace wartosci czasu start i stop.
		*/	
		timeval czas1, czas2;
		/*!
	 	* \brief Zmienna typu double, zawiera wartosc czasu operacji.
		*/	
		double CzasOperacji;

		double czas;
	public:
		/*!
	 	* \brief Konstruktor klasy Benchmark.
	 	* Konstruktor jest funkcja bezparametryczna.
		*/			
		Benchmark(){}
		/*!
	 	* \brief Funkcja wykonujaca algorytm benchmarku.
		* Funkcja wykonuje wczytanie danych z plikow stos.txt, stos100.txt, stos1000.txt, stos10000.txt.
		* Nastepnie tworzy obiekty klas i wypelnia je wartosciami wczytanymi z tych plikow.
		* Czyli wypelnia je wartosciami: 10 elementow, 100 elementow, 1000 oraz 10000 elementow.
		* Na koniec wyswietla dla zadanej klasy poszczegolne wartosci.
		* Funkcja zawiera menu, dzieki ktoremu uzytkownik moze wybrac opcje
		* zapelnienia danej klasy obiektu.
		*/			
		void Wykonaj_Algorytm();
		/*!
	 	* \brief Funkcja startujaca zegar.
		* Funkcja odpala zegar, ktory liczy czas zapelnienia stosu czy tez kolejki
		* danymi wczytanymi z pliku.
		*/	
		void Start();
		/*!
	 	* \brief Funkcja zatrzymujaca zegar.
		* Funkcja zatrzymuje zegar, ktory liczy czas zapelnienia stosu czy tez kolejki
		* danymi wczytanymi z pliku.
		*/			
		void Stop();
		/*!
	 	* \brief Funkcja zawieracaja czas operacji zegaru.
		* Funkcja zwraca nam czas calkowity wykonanej operacji w ms.
		*/	
		double Czas_Operacji();
};

#endif