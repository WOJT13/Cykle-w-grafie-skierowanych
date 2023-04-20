/**@file funkcje.h
*/
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <vector>
#include "stuktury.h"

using namespace std;

/// <summary>
/// Funkcja tworzy map� wierzcho�k�w. Je�eli znajdzie nowy wierzcho�ek dodaje go do listy s�siad�w.
/// </summary>
/// <param name="wejscie">Lista krawedzi podanych w pliku wej�ciowym.</param>
/// <returns>Mape wierzcho�k�w w grafie</returns>
map<int, wierzcholek_graf*> stworz_mape_grafu(list<Krawedz> wejscie);
/// <summary>
/// Funkcja szuka mo�liwych s�siad�w dla danego wierzcho�ka wykluczaj�c przeanalizowane wierzcho�ki oraz niedozwolone przej�cia.
/// </summary>
/// <param name="wierzcholek">Wska�nik na wierzcho�ek</param>
/// <param name="wykluczone_przejscia">Kolekcja niedozwolonych przej��.</param>
/// <param name="przeanalizowane_wierzcholki">Kolekcja wierzcho�k�w, kt�re ju� zosta�y przeanalizowane.</param>
/// <returns>-1 je�li wierzcho�ek nie nadaje przej�cia, albo n czyli s�siedni wierzcho�ek nadaj�cy si� do przej�cia.</returns>
int znadz_mozliwych_sasiadow(wierzcholek_graf* wierzcholek, map<int, set<int>>& wykluczone_przejscia, set<int>& przeanalizowane_wierzcholki);
/// <summary>
/// Funkcja dla danego wierzcho�ka wyszukuje jego cykl.
/// </summary>
/// <param name="kolekcja_intow">List listy przechowuj�cej wierzcho�ki, kt�re nale�� dd cyklu</param>
/// <param name="mapa_grafow">Mapa wierzcho�k�w.</param>
/// <param name="index_wierzcholka">Wierzcholek</param>
/// <param name="stos">Lista, kt�ra przetrzymuje wierzcholek</param>
/// <param name="wylaczone_przejscia">Kolekcja niedozwolonych przej��</param>
/// <param name="przeanalizowane_wierzcholki">Poprzednio analizowanie wierzcho�ki</param>
/// <returns>Wype�niona lista listy wierzcho�k�w w cyklu</returns>
list<list<int>> znajdz_cykle_dla_wierzcholka(list<list<int>> kolekcja_intow, map<int, wierzcholek_graf*> mapa_grafow, int index_wierzcholka, list<int>& stos, map<int, set<int>>& wylaczone_przejscia, set<int>& przeanalizowane_wierzcholki);
/// <summary>
/// Funkcja odk�ada poszczeg�lne cykle dla wierzcho�k�w.
/// </summary>
/// <param name="mapa_grafow">Mapa wierzcho�k�w.</param>
/// <returns>Znalezione cykle</returns>
list<list<int>> znadz_cykle(map<int, wierzcholek_graf*> mapa_grafow);