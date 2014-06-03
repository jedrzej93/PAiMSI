#include <iostream>
#include <iomanip>
#include "gra.hh"
/*!
 *\file Plik glowny programu stworzonej gry.
 */
using namespace std;

int main()
{
	Gra KolkoIKrzyzyk;
	int wybor;

	do
	{
	cout << "XOXOXOXOXOXOXOXOXOXOXOXOXOXOX" << endl;
	cout << "Witaj w grze Kolko i Krzyzyk!" << endl;
	cout << "XOXOXOXOXOXOXOXOXOXOXOXOXOXOX" << endl;
	cout << endl;
    cout << " Wybierz opcje:              " << endl;
	cout << " 1 - ROZPOCZNIJ GRE          " << endl;
	cout << " 2 - INFORMACJE O GRZE       " << endl;
	cout << " 0 - ZAKONCZ GRE             " << endl;
	cout << " Wybor opcji: ";
	cin >> wybor;
    cout << endl;

	    switch(wybor)
	    {
            case 1:
                    cout << endl;
                    cout << "   GRA ROZPOCZETA! POWODZENIA!   " << endl;
                    cout << "---------------------------------" << endl;
                    KolkoIKrzyzyk.Graj();
                    break;
            case 2:
                    cout << "   GRA KOLKO I KRZYZYK  " << endl;
                    cout << "------------------------" << endl;
                    cout << " Informacje dla gracza: " << endl;
                    cout << " - gracz oznaczony jest symbolem X, zas komputer symbolem O, " << endl;
                    cout << " - aby gracz mogl postawic swoj symbol na danym polu musi wpisac wspolrzedne, np. (2,2)," << endl;
                    cout << " - gracz zaczyna jako pierwszy, po ruchu gracza nastepuje kolej komputera." << endl;
                    cout << "------------------------" << endl;
                    cout << "    Powodzenia w grze!  " << endl << endl;
                    break;
            default:
            		cout << "Dziekujemy za gre!" << endl << endl;
            		break;

	    }
	    if((wybor <= 1) && (wybor >= 2))
        {
            cerr << "Nie ma takiej opcji!" << endl;
        }
	}
	while(wybor);

	return 0;
}