#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>
#include "drzewo_binarne.hh"
/*!
 *\file Plik glowny.
 * Plik zawierajacy menu glowne programu.
 * Wykonuje algorytm zawarty w klasie Benchmark.
 */
using namespace std;

// funkcje do opcji menu

void Dodaj(Tablica_Asocjacyjna * temp)
{
    int ilosc;
    Drzewo * p;

    cout << "Dodanie nowego wezla do drzewa. " << endl;
    cout << "--------------------------------" << endl;
    cout << "Wprowadz ilosc wezlow do stworzenia: ";
    cin >> ilosc;
    cout << "Wprowadz liczbe kluczy: ";
        for(int i = 0; i < ilosc; i++)
        {
            p = new Drzewo;
            cin >> p->klucz;
            temp->Dodaj_Wezel(p);
        }
    cout << endl;
    temp->Wyswietl_Drzewo(temp->korzen);
    temp->Ilosc_Wezlow();
}

void Usun(Tablica_Asocjacyjna * temp)
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

void Szukaj_Wezla(Tablica_Asocjacyjna * temp)
{
    int klucz;

    cout << "Podaj klucz do wezla: ";
    cin >> klucz;
    cout << endl;

    if(temp->Szukaj(klucz))
        cout << "Wezel znajduje sie w Drzewie!" << endl;
    else
        cout << "Brak wezla w Drzewie o zadanym kluczu!" << endl;
}

void Przejdz_Drzewo(Tablica_Asocjacyjna * temp)
{
    cout << "Przechodzenie przez Drzewo: " << endl;
    temp->Przejdz_Przez_Drzewo(temp->korzen);
}


int main()
{
	Tablica_Asocjacyjna * Tab_Aso = new Tablica_Asocjacyjna();
	int wybor;

	do
	{
	    cout << "-----------MENU-----------" << endl;
	    cout << " 1 - DODAJ WEZEL          " << endl;
	    cout << " 2 - USUN WEZEL           " << endl;
	    cout << " 3 - CZY JEST WEZEL?      " << endl;
	    cout << " 4 - PRZEJDZ PRZEZ DRZEWO " << endl;
	    cout << "--------------------------" << endl;
	    cout << " WYBOR OPCJI: ";
	    cin >> wybor;

	    switch(wybor)
	    {
            case 1:
                    Dodaj(Tab_Aso);
                    break;
            case 2:
                    Usun(Tab_Aso);
                    break;
            case 3:
                    Szukaj_Wezla(Tab_Aso);
                    break;
            case 4:
                    Przejdz_Drzewo(Tab_Aso);
                    break;
            default:
            		break;

	    }
	    if((wybor <= 0) && (wybor >= 5))
        {
            cout << "Nierozpoznana opcja menu!!!" << endl;
        }
	}
	while(wybor);

	delete Tab_Aso;
}
