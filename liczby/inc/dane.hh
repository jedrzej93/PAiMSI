#ifndef DANE_HH_INCLUDED
#define DANE_HH_INCLUDED
/*!
*\file
*\brief Funkcje zdefiniowane dla klasy Dane.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;
/*!
*\brief Deklaracja klasy Kolejka.
* Klasa ta zawiera dwie tablice dynamiczne, tablica w ktorej przechowujemy
* dane wczytane z pliku oraz tablica_spr, w ktorej zawarte sa dane sprawdzajace
* czy po wykonaniu obliczenia dane z tablicy sa takie same. Klasa ta rowniez 
* ma zdefiniowane zmienne pomocnicze odpowiadajace za tworzenie tablic oraz
* zmienne zawierajace rozmiary tych tablic.
*/
class Dane
{
	private:
		/*!
		* \brief Zmienna typu int, odpowiada za tworzenie tablicy dynamicznej, ktora
		* zawiera dane wczytywane z pliku, ktore nastepnie sa wykorzystywane do wykonania na nich obliczenia - mnozenia x2.
		*/
		int *tablica;
		/*!
		* \brief Zmienna typu int, odpowiada za tworzenie tablicy sprawdzajacej dynamicznej, ktora
		* zawiera dane wczytane z pliku, ktore sa po operacji mnożenia x2, ktore nastepnie sa
		* wykorzystane do porownania z danymi z tablicy.
		*/
		int *tablica_spr;
		/*!
		* \brief Zmienne pomocnicze typu int.
		*/
		int temp, temp_spr; 
		/*!
		* \brief Zmienne typu int, zawierajace rozmiar tablicy oraz rozmiar tablicy sprawdzajacej.
		*/
		int rozmiar, rozmiar_spr;
	public:
		/*!
		* \brief Konstruktor klasy Dane.
		* W funkcji tej zerujemy wszystkie zmienne jak rowniez zmienne dynamiczne w celu
		* zwolnienia pamieci.
		*/
		Dane(){ tablica = 0; tablica_spr = 0; temp = 0; temp_spr = 0; rozmiar_spr = 0; rozmiar = 0;}
		/*!
		* \brief Konstruktor klasy Dane.
		* Funkcja wczytuje plik o zadanej nazwie oraz zeruje wszystkie zmienne w celu zwolnienia pamieci.
		*/
		Dane(string Nazwa_Pliku);
		/*!
		* \brief Funkcja wczytywania danych sprawdzajacych
		* Funkcja ta wczytuje dane z pliku sprawdzajacego - test.txt.
		*/
		void Wczytaj_Dane_Spr();
		/*!
		* \brief Funkcja wczytywania danych.
		* Funkcja ta wczytuje dane z pliku, uzytkownik jest pytany jaki plik
		* chce wczytac.
		*/
		void Wczytaj_Dane();
		/*!
		* \brief Funkcja wykonujaca obliczenia.
		* Funkcja sluzy do wykonania operacji mnozenia x2 danych
		* wczytanych z tablicy.
		*/
		void Wykonaj_Obliczenia();
		/*!
		* \brief Funkcja sprawdzajaca.
		* Funkcja ta porownuje czy dane z tablicy po operacji mnozenia
		* sa takie same jak dane zawarte w tablicy sprawdzajacej.
		* Sprawdza kazdy element po kolei i jezeli napotka rozne dane
		* to przypisuje wartosc 1 do zmiennej blad, jezeli wszystkie 
		* dane beda takie same blad = 0. I jezeli otrzymane 1 to funkcja wyswietla blad,
		* w przeciwnym razie funkcja zwraca, ze dane sa takie same.
		*/
		void Sprawdz();
		/*!
		* \brief Funkcja wyswietlajaca dane z tablicy.
		* Funkcja wyswietla dane wczytane z tablicy, badz te po wykonaniu
		* obliczen.
		*/
		void Pokaz_Dane();
		/*!
		* \brief Funkcja wyswietlajaca dane z tablicy sprawdzajacej.
		* Funkcja wyswietla dane wczytane z tablicy sprawdzajacej.
		*/
		void Pokaz_Dane_Spr();
		/*!
		* \brief Funkcja zerujaca dane.
		* Funkcja ta zeruje wszystkie zmienne pomocnicze oraz zmienne dynamiczne oraz
		* usuwa utworzone tablice dynamiczne w celu zwolnienia pamieci i ochrony
		* przed jej zapelnieniu.
		*/
		void Wyzeruj_Dane();
		/*!
		* \brief Destruktor klasy Dane.
		* Usuwa tablice dynamiczne w celu zwolnienia pamieci.
		*/
		~Dane()
		{
			delete [] tablica;
			delete [] tablica_spr;
		}
};

#endif