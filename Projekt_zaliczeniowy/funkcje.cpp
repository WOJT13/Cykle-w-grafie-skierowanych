/**@file funkcje.cpp
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

using namespace std;

map<int, wierzcholek_graf*> stworz_mape_grafu(list<Krawedz> wejscie) {
    map<int, wierzcholek_graf*> wierzcholki;
    for (auto v : wejscie) {
        auto key = wierzcholki.find(v.zwroc_start());
        if (wierzcholki.end() == key) {
            auto nowy_wierzcholek = new wierzcholek_graf(v.zwroc_start());
            nowy_wierzcholek->sasiedzi.push_back(v.zwroc_koniec());
            wierzcholki[v.zwroc_start()] = nowy_wierzcholek;
        }
        else {
            wierzcholki[v.zwroc_start()]->dodaj_sasiada(v.zwroc_koniec());
        }
    }
    return wierzcholki;
}

int znadz_mozliwych_sasiadow(wierzcholek_graf* wierzcholek, map<int, set<int>>& wykluczone_przejscia, set<int>& przeanalizowane_wierzcholki) {
    if (wierzcholek == NULL) {
        return -1;
    }
    auto obecne_przejscia_wierzcholkow = wykluczone_przejscia[wierzcholek->wierzcholek]; 
    for (auto n : wierzcholek->sasiedzi) { 
        if (obecne_przejscia_wierzcholkow.find(n) == obecne_przejscia_wierzcholkow.end()
            && przeanalizowane_wierzcholki.find(n) == przeanalizowane_wierzcholki.end()) { 
            return n; 
        }
    }
    return -1;
}

list<list<int>> znajdz_cykle_dla_wierzcholka(list<list<int>> kolekcja_intow, map<int, wierzcholek_graf*> mapa_grafow, int index_wierzcholka,
    list<int>& stos, map<int, set<int>>& wylaczone_przejscia, set<int>& przeanalizowane_wierzcholki) {
    stos.push_back(index_wierzcholka);
    if (stos.size() != 1 && stos.front() == stos.back()) {
        auto c = stos;
        kolekcja_intow.push_back(c);
        stos.pop_back();
        index_wierzcholka = stos.back(); 
    }
    auto mozliwy_sasiad = znadz_mozliwych_sasiadow(mapa_grafow[index_wierzcholka], wylaczone_przejscia, przeanalizowane_wierzcholki); 
   

    while (mozliwy_sasiad == -1) {
        if (stos.size() == 1) {
            return kolekcja_intow;
        }
        stos.pop_back(); 
        index_wierzcholka = stos.back();
        mozliwy_sasiad = znadz_mozliwych_sasiadow(mapa_grafow[index_wierzcholka], wylaczone_przejscia, przeanalizowane_wierzcholki);
    }
    wylaczone_przejscia[index_wierzcholka].insert(mozliwy_sasiad);
    return znajdz_cykle_dla_wierzcholka(kolekcja_intow, mapa_grafow, mozliwy_sasiad, stos, wylaczone_przejscia, przeanalizowane_wierzcholki);
}

list<list<int>> znadz_cykle(map<int, wierzcholek_graf*> mapa_grafow) {
    map<int, set<int>> wykluczone_przejscia; 
  
    set<int> przeanalizowane_wierzcholki;
    list<list<int>> znaleziony_cykl; 
    for (auto p : mapa_grafow) {
        auto aktualny_wierzcholek = mapa_grafow[p.first];
        list<int> schowek;
        list<list<int>> kolekcja_intow;

        auto cykle = znajdz_cykle_dla_wierzcholka(kolekcja_intow, mapa_grafow, aktualny_wierzcholek->wierzcholek, schowek, wykluczone_przejscia, przeanalizowane_wierzcholki);

        for (auto c : cykle)
        {
            znaleziony_cykl.push_back(c);
        }

        wykluczone_przejscia.clear(); 
        przeanalizowane_wierzcholki.insert(aktualny_wierzcholek->wierzcholek);
    }
    return znaleziony_cykl;
}
