#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "drzewo_binarne.hh"

using namespace std;

Tablica_Asocjacyjna::Tablica_Asocjacyjna()
{
	korzen = NULL;
	licznik = 0;
}

Tablica_Asocjacyjna::~Tablica_Asocjacyjna() // usuwanie listy z pamieci
{
    while(korzen)
        delete(Usun(korzen));
}

void Tablica_Asocjacyjna::Usun_Drzewo(Drzewo * p) // usuwanie drzewa
{
	if(p)
	{
		Usun_Drzewo(p->lewy);
		Usun_Drzewo(p->prawy);
		delete p;
	}
}

void Tablica_Asocjacyjna::Ilosc_Wezlow()
{
    cout << "Liczba wezlow w Drzewie: " << licznik << endl;
}

bool Tablica_Asocjacyjna::Czy_Pusty()
{
	return !korzen;
}

int Tablica_Asocjacyjna::Min_klucz(Drzewo * korzen)
{
	Drzewo * p = korzen;

	while(p->lewy)
		p = p->lewy;
	return p->klucz;
}

Drzewo * Tablica_Asocjacyjna::Min_klucz_adres(Drzewo * korzen)
{
	Drzewo * p = korzen;

	while(p->lewy)
		p = p->lewy;
	return p;
}

int Tablica_Asocjacyjna::Max_klucz(Drzewo * korzen)
{
	Drzewo * p = korzen;

	while(p->prawy)
		p = p->prawy;
	return p->klucz;
}

Drzewo * Tablica_Asocjacyjna::Max_klucz_adres(Drzewo * korzen)
{
	Drzewo * p = korzen;

	while(p->prawy)
		p = p->prawy;
	return p;
}

Drzewo * Tablica_Asocjacyjna::Poprzedni_wezel(Drzewo * p)
{
	if(p->lewy)
		return Max_klucz_adres(p->lewy);
	Drzewo * _wezel;

	do
	{
		_wezel = p;
		p = p->gora;
	}
		while((p) && (p->prawy != _wezel));

	return p;
}

Drzewo * Tablica_Asocjacyjna::Nastepny_wezel(Drzewo * p)
{
	if(p->prawy)
		return Min_klucz_adres(p->prawy);
	Drzewo * _wezel;

	do
	{
		_wezel = p;
		p = p->gora;
	}
		while((p) && (p->lewy != _wezel));

	return p;
}

bool Tablica_Asocjacyjna::Dodaj_Wezel(Drzewo * wezel)
{
	Drzewo * r = NULL, * p = korzen;

	wezel->lewy = wezel->prawy = NULL;

	while(p)
	{
		if(wezel->klucz == p->klucz)
		{
			delete wezel;
			return false;
		}
		r = p;
		p = (wezel->klucz < p->klucz) ? p->lewy: p->prawy;
	}

	wezel->gora = r;

	if(!r)
		korzen = wezel;
	else
		if(wezel->klucz < r->klucz)
			r->lewy = wezel;
		else
			r->prawy = wezel;

	licznik++;
	return true;
}

Drzewo * Tablica_Asocjacyjna::Szukaj(int klucz)
{
	Drzewo * p = korzen;

	while((p) && (p->klucz != klucz))
		if(klucz < p->klucz)
			p = p->lewy;
		else
			p = p->prawy;

	return p;
}

Drzewo * Tablica_Asocjacyjna::Usun(Drzewo * p)
{
	Drzewo * x = p->gora, * y;

	if((p->lewy) && (p->prawy))
    {
        y =(rand() % 2) ? Usun(Poprzedni_wezel(p)) : Usun(Nastepny_wezel(p));
        y->lewy = p->lewy;
        if(y->lewy)
            y->lewy->gora = y;
            y->prawy = p->prawy;
            if(y->prawy)
                y->prawy->gora = y;
        licznik++;
    }
    else
        y = (p->lewy) ? p->lewy : p->prawy;

    if(y)
        y->gora = x;
    if(!x)
        korzen = y;
    else
        if(x->lewy == p)
        x->lewy = y;
    else
        x->prawy = y;
    licznik--;

    return p;
}

void Tablica_Asocjacyjna::Wyswietl_Drzewo(Drzewo * p)
{
    cout << p->klucz << ": LEWA GALAZ-> ";
    if(p->lewy)
        cout << p->lewy->klucz;
    else
        cout << "BRAK";
    cout << ": PRAWA GALAZ-> ";
    if(p->prawy)
        cout << p->prawy->klucz;
    else
        cout << "BRAK" << endl;
        cout << endl;
    if(p->lewy)
        Wyswietl_Drzewo(p->lewy);
    if(p->prawy)
        Wyswietl_Drzewo(p->prawy);
}

void Tablica_Asocjacyjna::Przejdz_Przez_Drzewo(Drzewo * p)
{
    if(p)
    {
        cout << p->klucz << endl;
        Przejdz_Przez_Drzewo(p->lewy);
        Przejdz_Przez_Drzewo(p->prawy);
    }
}