#ifndef GRAF_HH_INCLUDED
#define GRAF_HH_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <map>
#include <stack>
/*!
 *\file Plk naglowkowy klasy Graf.
 * Klasa Graf zawierajaca definicje poszczegolnych funkcji.
 */
using namespace std;
/*!
*\brief Deklaracja klasy Graf - szukanie DFS, BFS.
*/
class Graf
{
		/*!
		* \brief Kontener asocjacyjny zawierajacy dane dotyczace grafu
		* na liscie sasiedztwa, w ktorym zawarte sa wartosci klucza i danej.
		*/
		map< string, vector<string> > Graf_lista;		
		/*!
		* \brief Kontener asocjacyjny zawierajacy dane dotyczacych
		* wezlow grafu, w ktorym zawarte sa wartosci klucz oraz informacji czy dany wezel istnieje.
		*/
		map< string, bool> Wezly;

	public:
		/*!
		* \brief Konstruktor klasy Graf.
		* Konstruktor, ktory tworzy graf na podstawie
		* wczytywanego pliku, w ktorym znajduje sie 
		*/
		Graf(string nazwa_pliku);
		/*!
		* \brief Funkcja wyswietlajaca wczytany graf.
		* Funkcja wczytuje z pliku "test.txt" strukture danego grafu,
		* a nastepnie wyswietla go.
		*/
		void Wyswietl_Graf();
		/*!
		* \brief Algorytm szukania BFS (Breadth-first search).
		* Jest to algorytm przeszukiwania wszerz. BFS przeszukuje graf
		* od zadanego wierzcholka i nastepnie odwiedza wszystkie wierzcholki
		* ktore sa osiagalne dla tego wierzcholka. Algorytm ten zostal napisany
		* z wykorzystaniem standardowych bibliotek.
		*/
		void BFS(string start);
		/*!
		* \brief Algorytm szukania DFS (Depth-firstsearch).
		* Jest to algorytm przeszukiwania w glab grafu. DFS przeszukuje graf
		* odwiedzajac wszystkie krawedzie zaczynajac od zadanego wierzcholka.
		* Po przejsciu wszystkich krawedzi wraca do danego wierzcholka z ktorego
		* dany wierzcholek byl odwiedzony. 
		*/
		void DFS(string start);
		/*!
		* \brief Funkcja czyszczaca odwiedzone wezly w grafie.
		*/
		void Czysc_Odwiedzone();

};
#endif