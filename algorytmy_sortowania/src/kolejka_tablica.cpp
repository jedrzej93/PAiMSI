#include "kolejka_tablica.hh"
/*!
 *\file Kolejka tablica
 * Plik zawierajacy deklaracje poszczegolnych funkcji
 * w klasie Kolejka.
 */
using namespace std;


Kolejka::Kolejka()
{
	wsk_pocz = licz_elem = rozmiar_tab = 0;
	Tab = 0;
	Tab_temp = 0;
}

bool Kolejka::isEmpty()
{
	if(rozmiar_tab == 0)
		return 1;
	else
		return 0;
}

void Kolejka::pop()
{
	if(rozmiar_tab != 0)
	{
		Tab_temp = new int[rozmiar_tab];
		for(int i = 0; i < rozmiar_tab; i++)
			Tab_temp[i] = Tab[i];
		delete Tab;
		--rozmiar_tab;

		Tab = new int[rozmiar_tab];
		for(int i = 0; i < rozmiar_tab; i++)
			Tab[i] = Tab_temp[i];
		delete [] Tab_temp;
	}
	else 
		cout << endl;
}

void Kolejka::push(int dodaj_elem)
{
	if( rozmiar_tab != 0)
	{
		Tab_temp = new int[rozmiar_tab];
		for(int i = 0; i < rozmiar_tab; i++)
		{
			Tab_temp[i] = Tab[i];
		}
		delete [] Tab;

		++rozmiar_tab;
		Tab = new int[rozmiar_tab];
		Tab[0] = dodaj_elem;
		
		int x = 1;
		for(int i = 0; i < (rozmiar_tab - 1); i++)
		{
			Tab[x] = Tab_temp[i];
			x++;
		}
		x = 0;
		delete [] Tab_temp;
	} 
	else
	{
		++rozmiar_tab;
		Tab = new int[1];
		Tab[0] = dodaj_elem;
	}

}

void Kolejka::Wyswietl_Dane()
{	
	if(rozmiar_tab != 0)
	{
		cout << "Zawartosc kolejki:  " << endl;
		for(int i = (rozmiar_tab - 1); i >= 0 ; i--)
		{
			cout << Tab[i] << endl;
		}
	} 
	else
		cout << "Brak elementow! " << endl;
}

void Kolejka::Wczytaj_Dane(string nazwa_pliku)
{
	int temp;

	ifstream plik(nazwa_pliku.c_str());

	if(!plik)
	{
		cerr << "Nie mozna otworzyc pliku!" << endl;
		getchar();
	}
	else
	{
		while(plik >> temp)
			push(temp);
	}
}

int Kolejka::Partition(int * Tab, int pocz_p, int koniec_p)
{
	int elem, temp, i, j;

	elem = Tab[pocz_p];
	i = pocz_p;
	j = koniec_p;
	do
	{
		do
		{
			i++;
		}
	while(Tab[i] < elem);
		do
		{
			j--;
		}
	while(Tab[j] > elem);
		if (i < j)
		{
			temp = Tab[i];
			Tab[i] = Tab[j];
			Tab[j] = temp;
		}
	}
	while(i < j);
	Tab[pocz_p] = Tab[j];
	Tab[j] = elem;

	return j;
}

void Kolejka::Quick_Sort(int pocz_p, int koniec_p)
{
	int wart_elem;
	if(pocz_p < koniec_p)
	{
		wart_elem = Partition(Tab, pocz_p, koniec_p + 1);
		Quick_Sort(wart_elem + 1, koniec_p);
		Quick_Sort(pocz_p, wart_elem - 1);
	}
}

void Kolejka::Quick_Sort2(int lewa, int prawa)
{
	int i,j,partycja;

	i = (lewa + prawa)/2;
	partycja = Tab[i];
	Tab[i] = Tab[prawa];
	for(j = i = lewa; i < prawa; i++)
		if(Tab[i] < partycja)
		{
			swap(Tab[i],Tab[j]);
			j++;
		}
	Tab[prawa] = Tab[j];
	Tab[j] = partycja;
	if(lewa < j - 1)
		Quick_Sort2(lewa, j-1);
	if(j + 1 < prawa)
		Quick_Sort2(j + 1, prawa);
}

void Kolejka::Wyswietl_Dane_Quick_Sort()
{	
	Quick_Sort(0,9);

	if(rozmiar_tab != 0)
	{
		cout << "Zawartosc kolejki:  " << endl;
		for(int i = 0; i < rozmiar_tab ; i++)
		{
			cout << Tab[i] << endl;
		}
	} 
	else
		cout << "Brak elementow! " << endl;
}

void Kolejka::Sort_Merge(int l_p, int l_k) // sortowanie przez scalanie
{
	int polowa, l1, l2, l;

	polowa = (l_p + l_k + 1) / 2;
	if(polowa - l_p > 1)
		Sort_Merge(l_p, polowa - 1);
	if(l_k - polowa > 0)
		Sort_Merge(polowa, l_k);
	l1 = l_p;
	l2 = polowa;
	for(l = l_p; l <= l_k; l++)
	{
		Tab_temp[l] = ((l1 == polowa) || ((l2 <= l_k) && (Tab[l1] > Tab[l2]))) ? Tab[l2++]: Tab[l1++];
	}
	for(l = l_p; l <= l_k; l++)
	{
		Tab[l] = Tab_temp[l];
	}
}

void Kolejka::Wyswietl_Dane_Sort_Merge()
{	
	Sort_Merge(0,9);

	if(rozmiar_tab != 0)
	{
		cout << "Zawartosc kolejki:  " << endl;
		for(int i = 0; i < rozmiar_tab ; i++)
		{
			cout << Tab[i] << endl;
		}
	} 
	else
		cout << "Brak elementow! " << endl;
}


void Kolejka::Buduj_Kopiec(int * Tab)
{
	int temp;

	for(int i = 2; i <= rozmiar_tab; i++)
	{
		j = i;
		k = j / 2;
		temp = Tab[i];
		while((k > 0) && (Tab[k] < temp))
		{
			Tab[j] = Tab[k];
			j = k;
			k = j / 2;
		}
		Tab[j] = temp;
	}
}

void Kolejka::Rozbierz_Kopiec(int * Tab)
{
	int m;

	for(int i = rozmiar_tab; i > 1; i--)
	{
		swap(Tab[1], Tab[i]);
		j = 1;
		k = 2;
		while( k < i)
		{
			if((k + 1 < i) && (Tab[k + 1] > Tab[k]))
				m = k + 1;
			else
				m = k;
			if(Tab[m] <= Tab[j])
				break;
			swap(Tab[j], Tab[m]);
			j = m;
			k = j + j;
		}
	}
}

void Kolejka::Wykonaj_Heap_Sort()
{
	Buduj_Kopiec(Tab);
	Rozbierz_Kopiec(Tab);
}

void Kolejka::Wyswietl_Dane_Heap_Sort()
{
	Wykonaj_Heap_Sort();

	if(rozmiar_tab != 0)
	{
		cout << "Zawartosc kolejki:  " << endl;
		for(int i = 0; i <= rozmiar_tab ; i++)
		{
			cout << Tab[i] << endl;
		}
	} 
	else
		cout << "Brak elementow! " << endl;
}

void Kolejka::Menu()
{
	Kolejka K;
	K.Wczytaj_Dane("stos.txt");
	K.Wyswietl_Dane_Quick_Sort();
	K.Wyswietl_Dane_Sort_Merge();
	K.Wyswietl_Dane_Heap_Sort();
}