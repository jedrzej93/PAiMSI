#ifndef BENCHMARK_HH_INCLUDED
#define BENCHMARK_HH_INCLUDED
/*!
*\file
*\brief Funkcje zdefiniowane dla klasy Benchmark.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;
/*!
*\brief Deklaracja klasy Benchmark.
* Klasa zawiera definicje zmiennych systemowych odpowiedzialnych za
* obliczenia czasu jaki minal podczas wykonania algorytmu. 
* Zdefiniowe sa zmienne odpowiedzialne za przechowywanie czasu
* oraz zmienna przechowywujaca ilosc powtorzenia algorytmu.
* W klasie tej mamy rowniez zdefiniowane funkcje, ktore wykonuja algorytm
* oraz funkcja, ktora powtorza ten algorytm i konstruktor klasy.
*/
class Benchmark
{
	private:
		/*!
		* \brief Zmienne typu timeval.
		* Zmienna czas1 do wlaczenia zegara, zas czas2 do zatrzymania zegaru.
		*/
		timeval czas1, czas2;
		/*!
		* \brief Zmienne typu double.
		* Zmienna CzasOperacji sluzy do wyznaczenia calkowitego czasu wykonania
		* algorytmu. Zmienne t1, t2, t3 sluza do wywolania algorytmu dla innych 
		* danych wejsciowych. 
		*/
		double CzasOperacji, t1, t2, t3;
		/*!
		* \brief Zmienna typu int przechowujaca liczbe powtorzen wykonania algorytmu.
		*/
		int Il_Powtorz_Algorytm;
	public:
		/*!
		* \brief Konstruktor klasy Benchmark.
		*/
		Benchmark(){}
		/*!
		* \brief Funkcja wykonujaca algorytm.
		* W funkcji tej wczytywane sa poszczegolne dane - licz10.txt, licz100.txt oraz licz1000.txt
		* zawierajace liczbe z zakresu 1-10, 1-100 oraz 1-1000, gdzie pierwsza liczba to rozmiar pliku.
		* Nastepnie po wczytaniu funkcja wykonuje obliczenie - mnozenie danych x2.
		*/
		void Wykonaj_Algorytm();
		/*!
		* \brief Funkcja powtarzajaca algorytm.
		* Funkcja powtarzajaca algorytm Wykonaj_Algorytm().
		*/
		void Powtorz_Algorytm();
};

#endif