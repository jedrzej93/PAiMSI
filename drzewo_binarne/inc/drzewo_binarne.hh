#ifndef DRZEWO_BINARNE_HH_INCLUDED
#define DRZEWO_BINARNE_HH_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// struktura typu wezla drzewa binarnego
struct Drzewo
{
	Drzewo * gora, * lewy, * prawy;

	int klucz;

	int dane;
};

class Tablica_Asocjacyjna
{
	public:

		Drzewo * korzen; // korzen klasy Drzewo;

		int licznik; // zmienna zlicza ilosc wezlow

		Tablica_Asocjacyjna(); // konstruktor

		~Tablica_Asocjacyjna(); // destruktor

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
};
#endif
