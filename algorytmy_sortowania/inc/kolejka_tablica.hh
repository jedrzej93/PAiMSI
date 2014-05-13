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
*\brief Deklaracja klasy Kolejka.
*/
using namespace std;
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
		* \brief Zmienne typu int, wykorzystywany do
		*/		
		int k, j;
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
		~Kolejka(){ delete [] Tab; rozmiar_tab = 0; }
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
		* \param nazwa_pliku - zmienna typu string zawierajaca dokladna nazwe pliku do wczytania.
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
		/*!
		* \brief Funkcja wykonujaca algorytm szybkiego sortowania.
		* Funkcja zawierajaca dwie zmienne, ktore wskazuja na poczatek oraz koniec zbioru.
		* Dzieki czemu sprawdzamy czy partycje utworzone poprzez funkcje Partition
		* zawieraja wiecej niz jeden element. Jezeli tak, to wywolujemy 
		* rekurencyjnie algorytm sortowania szybkiego z wyznaczonymi granicami partycji.
		* Po tym wywolaniu partycja jest posortowana rosnaco.
		*/	
		void Quick_Sort(int pocz_p, int koniec_p);
		void Wykonaj_Quick_Sort(){Quick_Sort(0, rozmiar_tab - 1);}
		/*!
		* \brief Funkcja tworzaca partycje do algorytmu szybkiego sortowania.
		* Funkcja wykorzystuje dwa wskazniki na poczatku zbioru i,j. Zmienna i przeszukuje
		* zbior utworzonej partycji mniejszej wartosci niz wartosc najwieksza tej partycji.
		* A nastepnie gdy natrafi na mniejsza, to jest ta wartosc zamieniana poprzez zmienna j.
		* Kolejno wskaznik j przesuwa sie na nastepna pozycje. Wskaznik j zapmamietuje pozycje
		* na ktorej znajduje sie nastepny element, zatem na koncu zbioru wskaze pozycje
		* zakonczenia partycji.
		*/	
		int Partition(int * Tab, int pocz_p, int koniec_p);
		/*!
		* \brief Funkcja wyswietlajaca posortowane dane za pomoca algorytmu QuickSort.
		*/
		void Quick_Sort2(int lewa, int prawa);	
		void Wyswietl_Dane_Quick_Sort();
		/*!
		* \brief Funkcja sortowania przez scalanie.
		* Algorytm wywolujemy z zadanymi wartosciami indeksow l_p oraz l_k
		* ktore powinny objac caly zbior tablicy. Na poczatku algorytm dzieli
		* poprzez zmienna polowa zbior na dwie polowki, a nastepnie sprawdzamy
		* czy dana polowka zawiera wiecej niz jeden element. Jezeli tak to
		* to rekurencyjnie sortujemy algorytmem przez scalanie. Po operacji
		* sortowania dla dwoch polowek uporzadkowane zbiory scalamy je i zakanczamy 
		* algorytm.
		*/		
		void Sort_Merge(int l_p, int l_k);
		void Wykonaj_Sort_Merge(){Sort_Merge(0, rozmiar_tab - 1);}
		/*!
		* \brief Funkcja wyswietlajaca posortowane dane za pomoca algorytmu SortMerge.
		*/
		void Wyswietl_Dane_Sort_Merge();
		/*!
		* \brief Funkcja algorytmu sortowania przez kopcowanie.
		* Funkcja budujaca kopiec, ktory uzywany jest to sortowanie przez kopcowanie.
		*/		
		void Buduj_Kopiec(int * Tab);
		/*!
		* \brief Funkcja algorytmu sortowania przez kopcowanie.
		* Funkcja rozbierajaca kopiec, dzieki czemu elementy, ktore
		* budowaly kopiec zostaly rozebrany i w ten sposob sa posortowane.
		*/	
		void Rozbierz_Kopiec(int * Tab);
		/*!
		* \brief Funkcja wyswietlajaca posortowane dane za pomoca algorytmu HeapSort.
		*/		
		void Wyswietl_Dane_Heap_Sort();
		/*! 
		* \brief Funkcja wykonujaca algorytm HeapSort.
		* Najpierw jest budowany kopiec, a nastepnie rozebrany. Dzieki
		* temu mamy posortowane elementy.
		*/ 
		void Wykonaj_Heap_Sort();
};
#endif