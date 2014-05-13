#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "drzewo_binarne.hh"

using namespace std;

Drzewo_Binarne::Drzewo_Binarne()
{
	korzen = NULL;
	licznik = 0;
}

Drzewo_Binarne::~Drzewo_Binarne() // usuwanie listy z pamieci
{
    while(korzen)
        delete(Usun(korzen));
}

void Drzewo_Binarne::Usun_Drzewo(Drzewo * p) // usuwanie drzewa
{
	if(p)
	{
		Usun_Drzewo(p->lewy);
		Usun_Drzewo(p->prawy);
		delete p;
	}
}

void Drzewo_Binarne::Ilosc_Wezlow()
{
    cout << "Liczba wezlow w Drzewie: " << licznik << endl << endl;
}

bool Drzewo_Binarne::Czy_Pusty()
{
	return !korzen;
}

int Drzewo_Binarne::Min_klucz(Drzewo * korzen)
{
	Drzewo * p = korzen;

	while(p->lewy)
		p = p->lewy;
	return p->klucz;
}

Drzewo * Drzewo_Binarne::Min_klucz_adres(Drzewo * korzen)
{
	Drzewo * p = korzen;

	while(p->lewy)
		p = p->lewy;
	return p;
}

int Drzewo_Binarne::Max_klucz(Drzewo * korzen)
{
	Drzewo * p = korzen;

	while(p->prawy)
		p = p->prawy;
	return p->klucz;
}

Drzewo * Drzewo_Binarne::Max_klucz_adres(Drzewo * korzen)
{
	Drzewo * p = korzen;

	while(p->prawy)
		p = p->prawy;
	return p;
}

Drzewo * Drzewo_Binarne::Poprzedni_wezel(Drzewo * p)
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

Drzewo * Drzewo_Binarne::Nastepny_wezel(Drzewo * p)
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

bool Drzewo_Binarne::Dodaj_Wezel(Drzewo * wezel)
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

Drzewo * Drzewo_Binarne::Szukaj(int klucz)
{
	Drzewo * p = korzen;

	while((p) && (p->klucz != klucz))
		if(klucz < p->klucz)
			p = p->lewy;
		else
			p = p->prawy;

	return p;
}

Drzewo * Drzewo_Binarne::Usun(Drzewo * p)
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

void Drzewo_Binarne::Wyswietl_Drzewo(Drzewo * p)
{
    cout << p->klucz << ": LEWA GALAZ-> ";
    if(p->lewy)
        cout << p->lewy->klucz;
    else
        cout << "BRAK";
    cout << ", PRAWA GALAZ-> ";
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

void Drzewo_Binarne::Przejdz_Przez_Drzewo(Drzewo * p)
{
    if(p)
    {
        cout << p->klucz << endl;
        Przejdz_Przez_Drzewo(p->lewy);
        Przejdz_Przez_Drzewo(p->prawy);
    }
}

void Drzewo_Binarne::Dodaj(Drzewo_Binarne * temp)
{
    int ilosc;
    Drzewo * p;

    cout << "Dodanie nowego wezla do drzewa. " << endl;
    cout << "--------------------------------" << endl;
    temp->Ilosc_Wezlow();
    
    cout << "Wprowadz ilosc wezlow do stworzenia." << endl;
    cout << "Nastepnie wprowadz odpowiednia liczbe kluczy: ";
    cin >> ilosc;
        
    for(int i = 0; i < ilosc; i++)
    {
        p = new Drzewo;
        cin >> p->klucz;
        temp->Dodaj_Wezel(p);
    }
    
    cout << endl;
    temp->Wyswietl_Drzewo(temp->korzen);
    temp->Ilosc_Wezlow();
    cout << endl;
}

void Drzewo_Binarne::Usun(Drzewo_Binarne * temp)
{
    Drzewo * p;
    int klucz;

    cout << "Usun wezel drzewa o podanym kluczu: " << endl;
    cout << "------------------------------------" << endl << endl;
    cout << "Podaj klucz do usuwanego klucza: ";
    cin >> klucz;
    p = temp->Szukaj(klucz);

    if(p)
    {
        delete temp->Usun(p);
        if(temp->korzen)
            temp->Przejdz_Przez_Drzewo(temp->korzen);
        cout << "Liczba wezlow: ";
        temp->Ilosc_Wezlow();
    }
    else
        cout << "Brak wezla do usuniecia o zadanym kluczu!!! " << endl;
}

void Drzewo_Binarne::Szukaj_Wezla(Drzewo_Binarne * temp)
{
    int klucz;

    cout << "Podaj klucz do wezla: ";
    cin >> klucz;
    cout << endl;

    if(temp->Szukaj(klucz))
        cout << "Wezel znajduje sie w Drzewie!" << endl << endl;
    else
        cout << "Brak wezla w Drzewie o zadanym kluczu!" << endl << endl;
}

void Drzewo_Binarne::Przejdz_Drzewo(Drzewo_Binarne * temp)
{
    cout << "Przechodzenie przez Drzewo: " << endl;
    temp->Przejdz_Przez_Drzewo(temp->korzen);
}
