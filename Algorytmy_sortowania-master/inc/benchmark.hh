#ifndef BENCHMARK_HH_INCLUDED
#define BENCHMARK_HH_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "kolejka_tablica.hh" 
/*!
 *\file Benchmark
 * Plik naglowkowy klasy Benchmark
 * zawiera elementy private oraz public tej klasy.
 */
using namespace std;
/*!
 *\class Benchmark
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
	public:
		/*!
		* \brief Konstruktor klasy Benchmark.
		* Konstruktor jest funkcja bezparametryczna.
		*/	
		Benchmark(){}
		/*!
		* \brief Funkcja wykonujaca algorytmy sortowania.
		* Funkcja wykonuje wczytanie danych z plikow stos.txt, stos100.txt, stos1000.txt, stos10000.txt.
		* ktore zawieraja wylosowane liczby z przedzialu odpowiedniego do liczby elementow
		* Uzytkownik poprzez menu moze wybrac dla jakiego zbioru elementow ma byc
		* wykonane sortowanie i dla jakiego algorytmu, tj. sortowanie szybkie - QuickSort,
		* sortowanie przez kopcowanie - HeapSort oraz sortowanie przez scalanie - SortMerge.
		* Po wyborze przez uzytkownika opcji, zostaje wlaczany zegar, jest wykonywany algorytm sortowania,
		* a na koncu zegar zostaje zatrzymany i wyswietlony calkowity czas operacji wykonania sortowania.
		*/	
		void Wykonaj_Sortowanie();
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