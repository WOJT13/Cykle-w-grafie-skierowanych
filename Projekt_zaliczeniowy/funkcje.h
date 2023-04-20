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
/// Funkcja tworzy mapê wierzcho³ków. Je¿eli znajdzie nowy wierzcho³ek dodaje go do listy s¹siadów.
/// </summary>
/// <param name="wejscie">Lista krawedzi podanych w pliku wejœciowym.</param>
/// <returns>Mape wierzcho³ków w grafie</returns>
map<int, wierzcholek_graf*> stworz_mape_grafu(list<Krawedz> wejscie);
/// <summary>
/// Funkcja szuka mo¿liwych s¹siadów dla danego wierzcho³ka wykluczaj¹c przeanalizowane wierzcho³ki oraz niedozwolone przejœcia.
/// </summary>
/// <param name="wierzcholek">WskaŸnik na wierzcho³ek</param>
/// <param name="wykluczone_przejscia">Kolekcja niedozwolonych przejœæ.</param>
/// <param name="przeanalizowane_wierzcholki">Kolekcja wierzcho³ków, które ju¿ zosta³y przeanalizowane.</param>
/// <returns>-1 jeœli wierzcho³ek nie nadaje przejœcia, albo n czyli s¹siedni wierzcho³ek nadaj¹cy siê do przejœcia.</returns>
int znadz_mozliwych_sasiadow(wierzcholek_graf* wierzcholek, map<int, set<int>>& wykluczone_przejscia, set<int>& przeanalizowane_wierzcholki);
/// <summary>
/// Funkcja dla danego wierzcho³ka wyszukuje jego cykl.
/// </summary>
/// <param name="kolekcja_intow">List listy przechowuj¹cej wierzcho³ki, które nale¿¹ dd cyklu</param>
/// <param name="mapa_grafow">Mapa wierzcho³ków.</param>
/// <param name="index_wierzcholka">Wierzcholek</param>
/// <param name="stos">Lista, która przetrzymuje wierzcholek</param>
/// <param name="wylaczone_przejscia">Kolekcja niedozwolonych przejœæ</param>
/// <param name="przeanalizowane_wierzcholki">Poprzednio analizowanie wierzcho³ki</param>
/// <returns>Wype³niona lista listy wierzcho³ków w cyklu</returns>
list<list<int>> znajdz_cykle_dla_wierzcholka(list<list<int>> kolekcja_intow, map<int, wierzcholek_graf*> mapa_grafow, int index_wierzcholka, list<int>& stos, map<int, set<int>>& wylaczone_przejscia, set<int>& przeanalizowane_wierzcholki);
/// <summary>
/// Funkcja odk³ada poszczególne cykle dla wierzcho³ków.
/// </summary>
/// <param name="mapa_grafow">Mapa wierzcho³ków.</param>
/// <returns>Znalezione cykle</returns>
list<list<int>> znadz_cykle(map<int, wierzcholek_graf*> mapa_grafow);