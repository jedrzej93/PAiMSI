#ifndef DRZEWO_BINARNE_HH_INCLUDED
#define DRZEWO_BINARNE_HH_INCLUDED
/*!
 *\file
 *\brief Funkcje zdefiniowane dla klasy Drzewo_Binarne.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
/*!
 *
 *\brief Deklaracja klasy Drzewo_Binarne.
 */
using namespace std;
/*!
 * Struktura wezlow drzewa binarnego.
 */
struct Drzewo
{
	/*!
	* \brief Zmienna typu Drzewo *, przodek wezla tzw. parent.
	*/
	Drzewo * gora;
	/*!
	* \brief Zmienna typu Drzewo *, lewy potomek wezla.
	*/
	Drzewo * lewy;
	/*!
	* \brief Zmienna typu Drzewo *, prawy potomek wezla.
	*/
	Drzewo * prawy;
	/*!
	* \brief Zmienna typu int, przechowujaca wartosc klucza.
	*/
	int klucz;
	/*!
	* \brief Zmienna typu int, przechowujaca wartosc elementu dla danego klucza.
	*/
	int dane;
};

class Drzewo_Binarne
{
	public:

		Drzewo * korzen; // korzen klasy Drzewo;

		int licznik; // zmienna zlicza ilosc wezlow

		Drzewo_Binarne(); // konstruktor

		~Drzewo_Binarne(); // destruktor

		int Min_klucz(Drzewo * korzen);

		Drzewo * Min_klucz_adres(Drzewo * korzen);

		int Max_klucz(Drzewo * korzen);

		Drzewo * Max_klucz_adres(Drzewo * korzen);

		Drzewo * Poprzedni_wezel(Drzewo * p);

		Drzewo * Nastepny_wezel(Drzewo * p);

		Drzewo * Usun(Drzewo * p);

		Drzewo * Szukaj(int klucz);

		bool Czy_Pusty();

        void Wyswietl_Drzewo(Drzewo * p);

        void Przejdz_Przez_Drzewo(Drzewo * p);

        void Ilosc_Wezlow();

		bool Dodaj_Wezel(Drzewo * wezel);

		void Usun_Drzewo(Drzewo * p);

		void Przejdz_Drzewo(Drzewo_Binarne * temp);

		void Szukaj_Wezla(Drzewo_Binarne * temp);

		void Usun(Drzewo_Binarne * temp);

		void Dodaj(Drzewo_Binarne * temp);
};
#endif
