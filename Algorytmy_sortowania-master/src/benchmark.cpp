#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sys/time.h>
#include "../inc/benchmark.hh"
/*!
 *\file Benchmark
 * Plik zawierajacy deklaracje poszczegolnych funkcji
 * w klasie Benchmark.
 */
using namespace std;
/*!
 *\fn Funkcja wykonujaca sortowanie.
 * W owej funkcji wykonywany jest algorytm 
 * sortowania dla sortowania szybkiego, sortowania kopcem
 * oraz sortowania przez scalanie.
 */
void Benchmark::Wykonaj_Sortowanie()
{
	Kolejka K;
	
	int wybor;

	cout << "----MENU BENCHMARK----" << endl;
	cout << " 1 - SORTOWANIE PRZEZ SCALANIE 10 ELEMENTOW" << endl;
	cout << " 2 - SORTOWANIE PRZEZ SCALANIE 100 ELEMENTOW" << endl;
	cout << " 3 - SORTOWANIE PRZEZ SCALANIE 1000 ELEMENTOW " << endl;
	cout << " 4 - SORTOWANIE PRZEZ SCALANIE 10000 ELEMENTOW " << endl;
	cout << " 5 - SORTOWANIE PRZEZ SCALANIE 100000 ELEMENTOW " << endl;
	cout << " 6 - SORTOWANIE PRZEZ SCALANIE 1000000 ELEMENTOW " << endl;
	cout << " 7 - SORTOWANIE SZYBKIE 10 ELEMENTOW " << endl;
	cout << " 8 - SORTOWANIE SZYBKIE 100 ELEMENTOW " << endl;
	cout << " 9 - SORTOWANIE SZYBKIE 1000 ELEMENTOW " << endl;
	cout << "10 - SORTOWANIE SZYBKIE 10000 ELEMENTOW " << endl;
	cout << "11 - SORTOWANIE SZYBKIE 100000 ELEMENTOW " << endl;
	cout << "12 - SORTOWANIE SZYBKIE 1000000 ELEMENTOW " << endl;
	cout << "13 - SORTOWANIE KOPCEM 10 ELEMENTOW " << endl;
	cout << "14 - SORTOWANIE KOPCEM 100 ELEMENTOW " << endl;
	cout << "15 - SORTOWANIE KOPCEM 1000 ELEMENTOW " << endl;
	cout << "16 - SORTOWANIE KOPCEM 10000 ELEMENTOW " << endl;
	cout << "17 - SORTOWANIE KOPCEM 100000 ELEMENTOW " << endl;
	cout << "18 - SORTOWANIE KOPCEM 1000000 ELEMENTOW " << endl;
	cout << "19 - ZAKONCZ PROGRAM " << endl;
	cout << " WYBIERZ OPCJE: ";
	cin >> wybor;

	switch(wybor)
	{
		case 1: 
			cout << "Sortowanie przez scalanie dla 10 elementow: ";
			K.Wczytaj_Dane("pliki/stos_malejacy.txt"); Start(); K.Wykonaj_Sort_Merge(); Stop(); Czas_Operacji();
			break;
		case 2: 
			cout << "Sortowanie przez scalanie dla 100 elementow: ";
			K.Wczytaj_Dane("pliki/stos100_malejacy.txt"); Start(); K.Wykonaj_Sort_Merge(); Stop(); Czas_Operacji();			
			break;
		case 3:
			cout << "Sortowanie przez scalanie dla 1000 elementow: ";
			K.Wczytaj_Dane("pliki/stos1000_malejacy.txt"); Start(); K.Wykonaj_Sort_Merge(); Stop(); Czas_Operacji();
			break;
		case 4:
			cout << "Sortowanie przez scalanie dla 10000 elementow: ";
			K.Wczytaj_Dane("pliki/stos10000_malejacy.txt"); Start(); K.Wykonaj_Sort_Merge(); Stop(); Czas_Operacji();
			break;
		case 5:
			cout << "Sortowanie przez scalanie dla 100000 elementow: ";
			K.Wczytaj_Dane("pliki/stos100000_malejacy.txt"); Start(); K.Wykonaj_Sort_Merge(); Stop(); Czas_Operacji();
			break;
		case 6:
			cout << "Sortowanie przez scalanie dla 1000000 elementow: ";
			K.Wczytaj_Dane("pliki/stos1000000_malejacy.txt"); Start(); K.Wykonaj_Sort_Merge(); Stop(); Czas_Operacji();
			break;	
		case 7: 
			cout << "Sortowanie szybkie dla 10 elementow: ";
			K.Wczytaj_Dane("pliki/stos_malejacy.txt"); Start(); K.Wykonaj_Quick_Sort(); Stop(); Czas_Operacji();
			break;
		case 8: 
			cout << "Sortowanie szybkie dla 100 elementow: ";
			K.Wczytaj_Dane("pliki/stos100_malejacy.txt"); Start(); K.Wykonaj_Quick_Sort(); Stop(); Czas_Operacji();
			break;
		case 9: 
			cout << "Sortowanie szybkie dla 1000 elementow: ";
			K.Wczytaj_Dane("pliki/stos1000_malejacy.txt"); Start(); K.Wykonaj_Quick_Sort(); Stop(); Czas_Operacji();
			break;
		case 10: 
			cout << "Sortowanie szybkie dla 10000 elementow: ";
			K.Wczytaj_Dane("pliki/stos10000_malejacy.txt"); Start(); K.Wykonaj_Quick_Sort(); Stop(); Czas_Operacji();
			break;
		case 11: 
			cout << "Sortowanie szybkie dla 100000 elementow: ";
			K.Wczytaj_Dane("pliki/stos100000_malejacy.txt"); Start(); K.Wykonaj_Quick_Sort(); Stop(); Czas_Operacji();
			break;
		case 12: 
			cout << "Sortowanie szybkie dla 1000000 elementow: ";
			K.Wczytaj_Dane("pliki/stos1000000_malejacy.txt"); Start(); K.Wykonaj_Quick_Sort(); Stop(); Czas_Operacji();
			break;			
		case 13: 
			cout << "Sortowanie kopcem dla 10 elementow: ";
			K.Wczytaj_Dane("pliki/stos_malejacy.txt"); Start(); K.Wykonaj_Heap_Sort(); Stop(); Czas_Operacji();
			break;
		case 14: 
			cout << "Sortowanie kopcem dla 100 elementow: ";
			K.Wczytaj_Dane("pliki/stos100_malejacy.txt"); Start(); K.Wykonaj_Heap_Sort(); Stop(); Czas_Operacji();
			break;	
		case 15: 
			cout << "Sortowanie kopcem dla 1000 elementow: ";
			K.Wczytaj_Dane("pliki/stos1000_malejacy.txt"); Start(); K.Wykonaj_Heap_Sort(); Stop(); Czas_Operacji();
			break;	
		case 16: 
			cout << "Sortowanie kopcem dla 10000 elementow: ";
			K.Wczytaj_Dane("pliki/stos10000_malejacy.txt"); Start(); K.Wykonaj_Heap_Sort(); Stop(); Czas_Operacji();
			break;			
		case 17: 
			cout << "Sortowanie kopcem dla 100000 elementow: ";
			K.Wczytaj_Dane("pliki/stos100000_malejacy.txt"); Start(); K.Wykonaj_Heap_Sort(); Stop(); Czas_Operacji();
			break;
		case 18: 
			cout << "Sortowanie kopcem dla 1000000 elementow: ";
			K.Wczytaj_Dane("pliki/stos1000000_malejacy.txt"); Start(); K.Wykonaj_Heap_Sort(); Stop(); Czas_Operacji();
			break;	
		case 19:
				cout << "ZAKONCZONO PROGRAM " << endl;
				break;
		default:
				break;
	}
}

void Benchmark::Start()
{
	//cout << "Zegar wlaczony!" << endl;
	gettimeofday(&czas1, NULL);
}

void Benchmark::Stop()
{
	//cout << "Zegar wylaczony!" << endl;
	gettimeofday(&czas2, NULL);
}

double Benchmark::Czas_Operacji()
{
	CzasOperacji = (czas2.tv_sec - czas1.tv_sec)*1000.0;
	CzasOperacji += (czas2.tv_usec - czas1.tv_usec) / 1000.0;
	cout << CzasOperacji << "ms." << endl;

	return CzasOperacji;
}