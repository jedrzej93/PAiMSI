#include <iostream>
#include <fstream>
#include "simplex.hh"

using namespace std;
/*!
 *\file Plik zawierajacy deklarcje poszczegolnych funkcji
 * dla klasy Simplex.
 */
void Simplex::Stworz()
{
	cout << " Podaj liczbe rownan: ";
	cin >> wiersze;
	wiersze += 1;
	cout << "Podaj liczbe zmienych decyzyjnych: ";
	cin >> kolumny;
	kolumny += 1;

	macierz = new double*[wiersze];
	for(int i = 0; i < wiersze; i++)
		macierz[i] = new double[kolumny];
	
	k_zmienne = new int[kolumny - 1];
	for(int j = 0; j < kolumny - 1; j++)
		k_zmienne[j] = -1*(j + 1);

	w_zmienne = new int[wiersze - 1];
	for(int i = 0; i < wiersze - 1; i++)
		w_zmienne[i] = i;

	powt_test[0] = 0;
	powt_test[1] = -1;
	powt_test1[0] = -2;
	powt_test1[1] = -3;
}

void Simplex::Wypelnij()
{
	cout << "Dla kolumn " << kolumny - 1 << " wprowadz wartosci funkcji celu: ";
	for(int i = 0; i < kolumny - 1; i++)
	{
		cin >> macierz[wiersze - 1][i];
	}
	macierz[wiersze - 1][kolumny - 1] = 0;
	cout << endl;

	cout << "M = ";
	for(int j; j < kolumny - 2; j++)
	{
		cout << macierz[wiersze - 1][j] << "x" << j + 1 << " + ";
	}

	if(kolumny - 2 >= 0)
		cout << macierz[wiersze - 1][kolumny - 2] << "x" << kolumny - 1 << endl;
	cout << "Forma zapisu ax1 + bx2... <= c - zestaw wejscia zamowienia." << endl;

	for(int i = 0; i < wiersze - 1; i++)
	{
		cout << "Dla kolumn " << kolumny - 1 << " wprowadz wartosci funkcji celu: ";
		for(int j = 0; j < kolumny; j++)
		{
			cin >> macierz[i][j];
		}

		cout << macierz[i][0] << "x1";

		for(int x = 1; x < kolumny - 1; x++)
		{
			cout << " + " << macierz[i][x] << "*x" << x + 1;
		}

		if(kolumny -2 >= 0)
			cout << " <= " << macierz[i][kolumny - 1] << endl;
		macierz[i][kolumny - 1] *= -1;
	}
	cout << endl;
}

bool Simplex::Zakoncz_Test()
{
	bool test = false;
	if(powt_test[0] == powt_test1[0] && powt_test[1] == powt_test1[1])
		return false;
	for(int i = 0; i < wiersze - 1; i++)
		if(macierz[i][kolumny - 1] > 0)
			return false;

	for(int j = 0; j < kolumny - 1; j++)
	{
		if(macierz[wiersze - 1][j] > 0)
			for(int x = 0; x < wiersze - 1; x++)
			{
				if(macierz[x][j] > 0)
					return true;
			}
	}
	return false;
}

int* Simplex::Obroc_Pivot()
{
	bool* cel_test = new bool[kolumny];
	int *poz_pivota = new int[2];

	poz_pivota[0] = 0;
	poz_pivota[1] = 0;

	double wsp = -1; // wspolczynnik

	for(int i = 0; i < kolumny - 1; i++)
	{
		if(macierz[wiersze - 1][i] > 0)
			cel_test[i] = 1;
	}

	for(int j = 0; j < kolumny - 1; j++)
	{
		if(cel_test[j] == 1)
		{
			for(int k = 0; k < wiersze - 1; k++)
			{
				if(macierz[k][j] != 0 && macierz[k][j] > 0 && abs(macierz[k][kolumny - 1]) / macierz[k][j] <= wsp || wsp == -1)
				{
					poz_pivota[0] = k;
					poz_pivota[1] = j;

					wsp = abs(macierz[poz_pivota[0]][kolumny - 1] / macierz[poz_pivota[0]][poz_pivota[1]]);
				}
			}
		}
	}
	cout << "Punkt obrotu znajduje sie (" << poz_pivota[0] + 1 << "," << poz_pivota[1] + 1 << ") o wartosci: " << macierz[poz_pivota[0]][poz_pivota[1]] << endl; 

	return poz_pivota;
}

void Simplex::Pivot()
{
	int* poz_pivota = Obroc_Pivot();
	int temp;

	temp = k_zmienne[poz_pivota[1]];
	k_zmienne[poz_pivota[1]] = w_zmienne[poz_pivota[0]];
	w_zmienne[poz_pivota[0]] = temp;

	powt_test[0] = powt_test1[0];
	powt_test1[1] = powt_test1[1];
	powt_test1[0] = poz_pivota[0];
	powt_test1[1] = poz_pivota[1];

	double wartosc = macierz[poz_pivota[0]][poz_pivota[1]];

	for(int x = 0; x < kolumny; x++)
	{
		macierz[poz_pivota[0]][x] /= wartosc;
	}

	for(int u1 = 0; u1 < wiersze; u1++)
	{
		if(u1 != poz_pivota[0])
		{
			for(int u2 = 0; u2 < kolumny; u2++)
			{
				if(u2 != poz_pivota[1])
					macierz[u1][u2] -= macierz[poz_pivota[0]][u2] * macierz[u1][poz_pivota[1]];
			}
		}
	}
	for(int w = 0; w < wiersze; w++)
	{
		if(w != poz_pivota[0])
			macierz[w][poz_pivota[1]] /= -wartosc;
		else
			macierz[w][poz_pivota[1]] /= wartosc;
	}
}

double** Simplex::Zwroc_Macierz()
{
	return macierz;
}

void Simplex::Wyswietl()
{
	for(int i = 0; i < wiersze; i++)
	{
		if(i == wiersze - 1)
			for(int k = 0; k < kolumny; k++)
				cout << "___";
			cout << endl;

			for(int j = 0; j < kolumny; j++)
			{
				if(j == kolumny - 1)
					cout << "|";
				cout << macierz[i][j];
			}
			cout << endl;
	}
}

void Simplex::Rozwiazanie()
{
	bool rozwiazanie = 1;

	for(int a = 0; a < kolumny - 1; a++)
	{
		if(macierz[wiersze - 1][a] > 0)
			rozwiazanie = 0;
	}

	if(rozwiazanie == 1)
	{
		double* rozwiazanie = new double[kolumny - 1];

		for(int b = 0; b < kolumny - 1; b++)
			rozwiazanie[b] = 0;

		for(int a = 0; a < kolumny - 1; a++)
			if(w_zmienne[a] < 0)
				rozwiazanie[-(w_zmienne[a] + 1)] = -macierz[a][kolumny - 1];

			cout << "Optymalne rozwiazanie " << macierz[wiersze - 1][kolumny - 1] << " gdzie";

			for(int i = 0; i < kolumny - 1; i++)
			{
				cout << ", x" << i + 1 <<" = " << rozwiazanie[i];
			}
		cout << endl;
	}
	else
		cout << "Nie ma optymalnego rozwiazania!" << endl;
}