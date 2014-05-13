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

int main()
{
	Drzewo_Binarne * D_Bin = new Drzewo_Binarne();
    Drzewo_Binarne D;
    int wybor;

	do
	{
	    cout << endl;
        cout << "-----------MENU-----------" << endl;
	    cout << " 1 - DODAJ WEZEL          " << endl;
	    cout << " 2 - USUN WEZEL           " << endl;
	    cout << " 3 - CZY JEST WEZEL?      " << endl;
	    cout << " 4 - PRZEJDZ PRZEZ DRZEWO " << endl;
	    cout << "--------------------------" << endl;
	    cout << " WYBOR OPCJI: ";
	    cin >> wybor;
        cout << endl;

	    switch(wybor)
	    {
            case 1:
                    cout << "Dodawanie nowego wezla do drzewa." << endl;
                    cout << "---------------------------------" << endl;
                    D.Dodaj(D_Bin);
                    break;
            case 2:
                    cout << "Usuwanie wezla z drzewa." << endl;
                    cout << "------------------------" << endl;
                    D.Usun(D_Bin);
                    break;
            case 3:
                    cout << "Szukanie wezla." << endl;
                    cout << "---------------" << endl;
                    D.Szukaj_Wezla(D_Bin);
                    break;
            case 4:
                    cout << "Wyswietlenie drzewa." << endl;
                    cout << "--------------------" << endl;
                    D.Przejdz_Drzewo(D_Bin);
                    break;
            default:
            		break;

	    }
	    if((wybor <= 1) && (wybor >= 4))
        {
            cout << "Nierozpoznana opcja menu!!!" << endl;
        }
	}
	while(wybor);

	delete D_Bin;
}
