/**@file Projekt_zaliczeniowy.cpp
*/
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
#include "funkcje.h"


/// <summary>
/// 
/// </summary>
/// <param name="argc">Liczba argumnetów</param>
/// <param name="argv">Wskaźnik na tablice z argumentami</param>
/// <returns></returns>
int main(int argc, char* argv[])
{
    auto Czytanie_argumentow = new czytanie_argumentow(argc, argv);
    auto Operator_pliku = new operator_pliku(Czytanie_argumentow->zwroc_plik_wejsciowy(), Czytanie_argumentow->zwroc_plik_wyjsciowy());
    auto wartosci_stringow = Operator_pliku->czytanie_z_pliku();
    auto fabryka_grafu = new fabryka_krawedzi();
    auto krawedzie = fabryka_grafu->stworz(wartosci_stringow);
    auto mapa_grafow = stworz_mape_grafu(krawedzie);
    auto znaleziony_cykl = znadz_cykle(mapa_grafow);
    Operator_pliku->zapisz_cykle(znaleziony_cykl);
}
