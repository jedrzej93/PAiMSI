#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>
#include "graf.hh"
#include "benchmark.hh"
/*!
 *\file Plik glowny.
 * Plik zawierajacy menu glowne programu.
 */
using namespace std;

int main()
{
	Graf * graf = new Graf();
    int wybor;
    int element, wezel1, wezel2, waga1;
    Benchmark B;

	do
	{
	    cout << endl;
        cout << "-----------MENU-----------" << endl;
	    cout << " 1 - DODAJ WEZEL          " << endl;
	    cout << " 2 - USUN WEZEL           " << endl;
	    cout << " 3 - DODAJ KRAWEDZ        " << endl;
	    cout << " 4 - USUN KRAWEDZ         " << endl;
	    cout << " 5 - WYSWIETL GRAF        " << endl;
	    cout << " 0 - ZAKONCZ PROGRAM      " << endl;
	    cout << "--------------------------" << endl;
	    cout << " WYBOR OPCJI: ";
	    cin >> wybor;
        cout << endl;

	    switch(wybor)
	    {
            case 1:
                    cout << "Dodawanie nowego wezla do grafu. " << endl;
                    cout << "---------------------------------" << endl;
                    cout << "Podaj wartosc jaka chcesz dodac: ";
                    cin >> element; B.Start();
                    graf->Dodaj_Wezel(element);
                    B.Stop(); cout << "Czas dodania wezla: "; B.Czas_Operacji();
                    cout << endl;
                    break;
            case 2:
                    cout << "Usuwanie wezla z drzewa." << endl;
                    cout << "------------------------" << endl;
                    cout << "Podaj wartosc jaka chcesz usunac: ";
                    cin >> element;
                    graf->Usun_Wezel(element);
                    cout << endl;
                    break;
            case 3:
                    cout << "Dodawanie krawedzi do grafu. " << endl;
                    cout << "-----------------------------" << endl;
                    cout << "Podaj wartosci jakie maja utworzyc krawedz (wezel1, wezel2, waga): " << endl;
                    cin >> wezel1; 
                    cin >> wezel2;
                    cin >> waga1; B.Start();
                    graf->Dodaj_Krawedz(wezel1, wezel2, waga1);
                    B.Stop(); cout << "Czas dodania krawedzi: "; B.Czas_Operacji();
                    cout << endl;
                    cout << *graf;
                    cout << endl;
                    break;
            case 4:
                    cout << "Usuwanie krawedzi z drzewa." << endl;
                    cout << "------------------------" << endl;
                    cout << "Podaj wartosci aby usunac krawedz (wezel1, wezel2): " << endl;
                    cin >> wezel1;
                    cin >> wezel2;
                    graf->Usun_Krawedz(wezel1, wezel2);
                    cout << endl;
                    break;
            case 5:
                    cout << "Wyswietlanie grafu." << endl;
                    cout << "-------------------" << endl;
                    cout << *graf << endl;
                    break;                  
            default:
            		break;

	    }
	    if((wybor <= 1) && (wybor >= 5))
        {
            cout << "Nierozpoznana opcja menu!!!" << endl;
        }
	}
	while(wybor);

	return 0;
}
