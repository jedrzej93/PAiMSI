#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "graf.hh"
/*!
 *\file Definicje poszczegolnych funkcji dla klasy Graf.
 */
using namespace std;

Graf::Graf(int wierzcholek)
{
	this->wierzcholek = wierzcholek;
	temp = new bool [wierzcholek];
	macierz = new int* [wierzcholek];
	for(int i = 0; i < wierzcholek; i++)
	{
		macierz[i] = new int [wierzcholek];
		for(int j = 0; j < wierzcholek; j++)
		{
			macierz[i][j] = 0;
		}
	}
}

Graf::~Graf()
{
	for(int i = 0; i < wierzcholek; ++i)
		delete[] macierz[i];
	delete[] macierz;
}

void Graf::Dodaj_Krawedz(int v1, int v2)
{
	if(v1 > wierzcholek || v2 > wierzcholek || v1 < 0 || v2 < 0)
	{
		cout << "Nie mozna dodac krawedzi! " << endl;
	}
	else
	{
		macierz[v1 - 1][v2 - 1] = 1;
	}
}

void Graf::Wyswietl_Graf()
{
	cout << "----Macierz sasiedztwa-----" << endl;
	for(int i = 0; i < wierzcholek; i++)
	{
		for(int j = 0; j < wierzcholek; j++)
			cout << setw(3) << macierz[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int Graf::Czy_Sasiad(int v1, int v2)
{
	return macierz[v1][v2];
}

void Graf::Usun_Krawedz(int v1, int v2)
{
	macierz[v1][v2] = 0;
	krawedz--;
}

int Graf::Sasiedztwo(int v)
{
	for(int i = 0; i < wierzcholek; i++)
		if(macierz[v][i] != 0 )
			return i;
		return wierzcholek;
}

void Graf::Dodaj_Wierzcholek(int v)
{
	
}

void Graf::Usun_Wierzcholek(int v)
{

}

void Graf::DFS(int v)
{
	temp[v] = true;
	cout << v << " " << endl;

	for(int i = 0; i < wierzcholek; i++)
		if((macierz[v][i] == 1) && !macierz[i]) 
			DFS(i);
}

