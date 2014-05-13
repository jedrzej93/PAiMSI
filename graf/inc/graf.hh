#ifndef GRAF_HH_INCLUDED
#define GRAF_HH_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstdlib>
/*!
 *\file Plk naglowkowy klasy Graf.
 * Klasa Graf zawierajaca definicje poszczegolnych funkcji.
 */
using namespace std;
/*!
*\brief Deklaracja klasy Graf.
*/
class Graf
{
	private:

		int wierzcholek, krawedz;

		int **macierz;

		bool *temp;

	public:
		
		Graf(int wezel);
		
		~Graf();
		
		int Czy_Sasiad(int v1, int v2);
		
		int Sasiedztwo(int v);
		
		void Dodaj_Wierzcholek(int v);

		void Usun_Wierzcholek(int v);
		
		void Dodaj_Krawedz(int v1, int v2);
		
		void Usun_Krawedz(int v1, int v2);

		void Wyswietl_Graf();
		
		void DFS(int v); // dept first search
};
#endif