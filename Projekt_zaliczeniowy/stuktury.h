/**@file struktury.h
*/
#pragma once
#include <iostream>
#include <list>
#include <string>

using namespace std;

/// <summary>
/// Struktura reprezentuj¹ca krawêdŸ w grafie skierowanych
/// </summary>
struct Krawedz {
public:
    /// <summary> 
    /// Funkcja zwraca punkt startowy krawedzi
    /// </summary>
    /// <returns>Starowy punkt krawedzi</returns>
    int zwroc_start() {
        return this->startowy;
    }
    /// <summary>
    /// Funkcja zwraca punkt koncowy krawedzi
    /// </summary>
    /// <returns>Koncowy punkt krawedzi</returns>
    int zwroc_koniec() {
        return this->koncowy;
    }
    /// <summary>
    /// Konstruktor, dziêki któremu mamy dostêp do startowego i koñcowego punktu krawedzi.
    /// </summary>
    /// <param name="start">Zmienna, w której bêdzie punkt startowy.</param>
    /// <param name="koniec">Zmienna, w której bêdzie punkt koñcowy.<</param>
    Krawedz(int start, int koniec) {
        this->startowy = start;
        this->koncowy = koniec;
    }

private:
    int startowy;/*!<Startowy punkt krawedzi*/
    int koncowy;/*!<Koncowy punkt krawedzi*/
};
/// <summary>
/// Stuktura reprezentuj¹ca wierzcho³ek w grafie.
/// </summary>
struct wierzcholek_graf
{
    int wierzcholek; /*!<Wierzcholek*/
    list<int> sasiedzi; /*!<Lista sasiednich wierzcholków w grafie */
    /// <summary>
    /// Konstruktor, dziêki któremy mamy dostêp do wierzcho³ka.
    /// </summary>
    /// <param name="wierzcholek">Zmienna, której bedzie wierzcho³ek.</param>
    wierzcholek_graf(int wierzcholek)
    {
        this->wierzcholek = wierzcholek;

    }
    wierzcholek_graf() {
        wierzcholek = 0;
    }
    /// <summary>
    /// Funkcja dodaje s¹siedni wierzcholek do listy s¹siadów.
    /// </summary>
    /// <param name="sasiad">S¹siedni wierzcho³ek</param>
    void dodaj_sasiada(int sasiad)
    {
        if (find(this->sasiedzi.begin(), this->sasiedzi.end(), sasiad) == this->sasiedzi.end())
            this->sasiedzi.push_back(sasiad);
    }
};
/// <summary>
/// Struktura która zajmuje siê czytaniem argumentów z naszego pliku.
/// </summary>
struct czytanie_argumentow {
public:
    /// <summary>
    /// Funkcja zwraca plik wejœciowy.
    /// </summary>
    /// <returns>Plik wejœciowy</returns>
    const string zwroc_plik_wejsciowy() {
        return this->plik_wejsciowy;
    }
    /// <summary>
    /// Funkcja zwraca plik wyjœciowy.
    /// </summary>
    /// <returns>Plik wyjœciowy</returns>
    const string zwroc_plik_wyjsciowy() {
        return this->plik_wyjsciowy;
    }
    /// <summary>
    /// Funkcja sprawdza odpowiedni¹ liczbe argumentów oraz w zale¿noœci od podanego argumentu wykonuje odpowiedni¹ operacje.
    /// </summary>
    /// <param name="liczba_argumentow">Liczba podanych argumentó</param>
    /// <param name="argument">WkaŸnik na tablice argumentów</param>
    czytanie_argumentow(int liczba_argumentow, char* argument[]) {
        if (liczba_argumentow != 5) {

            cout << "Zle parametry" << endl;
            cout << "W wierszu polecen nalezy podac:" << endl;
            cout << "Sciezka do odpalanego programu" << " " << "-g" << " " << "sciezka do pliku wejsciowego " << " " << "-c" << " " << "sciezka pliku wyjsciowego" << endl;
        }
        int i;
        for (i = 1; i < liczba_argumentow - 1; i++) {
            if (strcmp(argument[i], "-g") == 0)
                this->plik_wejsciowy = argument[i + 1];
            else if (strcmp(argument[i], "-c") == 0)
                this->plik_wyjsciowy = argument[i + 1];
        }
        this->poprawnosc_nazwy_pliku();
    }

private:
    string plik_wejsciowy; /*!<Tekstowy plik wejœciowy*/
    string plik_wyjsciowy; /*!<Tekstowy plik wyjœciowy*/
    /// <summary>
    /// Funkcja sprawdza czy podana jest prawid³owa nazwa pliku tekstowego.
    /// </summary>
    void poprawnosc_nazwy_pliku() {
        if (this->plik_wejsciowy.empty())
            cout << "Nazwa pliku wejsciowego jest nieprawidlowa" << endl;;
        if (this->plik_wyjsciowy.empty())
            cout << "Nazwa pliku wyjsciowego jest nieprawidlowa" << endl;
    }
};
/// <summary>
/// Struktura zajmuje sie plikami wejœcia i wyjœcia.
/// </summary>
struct operator_pliku {
public:
    /// <summary>
    /// Funkcja przypisuje plik do nazwy pliku.
    /// </summary>
    /// <param name="nazwa_pliku_wejsciowego">Nazwa pliku wejœciowego</param>
    /// <param name="nazwa_pliku_wyjsciowego">Nazwa pliku wyjœciowego</param>
    operator_pliku(string nazwa_pliku_wejsciowego, string nazwa_pliku_wyjsciowego) {
        this->plik_wejsciowy = nazwa_pliku_wejsciowego;
        this->plik_wyjsciowy = nazwa_pliku_wyjsciowego;
    }
    /// <summary>
    /// Funckcja otwiera plik i czyta z niego.
    /// </summary>
    /// <returns>Ci¹g znaków bez znaku przerwy oraz nowej linii.</returns>
    string czytanie_z_pliku() {
        ifstream plik;
        plik.open(this->plik_wejsciowy);
        stringstream stringstream;
        stringstream << plik.rdbuf();
        plik.close();
        auto wartosc = stringstream.str();
        this->usun_znak_konca_linii(wartosc);
        this->bez_znakow(wartosc);
        return wartosc;
    }
    /// <summary>
    /// Funkcja zapisuje znalecione cykle do pliku wyjœciowego.
    /// </summary>
    /// <param name="cykle">Lista listy wierzcho³ków tworz¹cych cykle.</param>
    void zapisz_cykle(list<list<int>> cykle) 
    {
        ofstream plik;
        plik.open(this->plik_wyjsciowy);
        if (cykle.empty())
        {
            plik << "Nie znaleziono cyklu!";
        }
        else
        {
            for (auto cykl : cykle) {
                for (auto element_cyklu : cykl) {
                    plik << element_cyklu << " ";
                }
                plik << '\n'; 
            }
        }
        plik.close();
    }
private:
    string plik_wejsciowy; /*!<Tekstowy plik wejœciowy*/
    string plik_wyjsciowy; /*!<Tekstowy plik wejœciowy*/

private:
    /// <summary>
    /// Funkcja usuwa znak koñca linii (enter).
    /// </summary>
    /// <param name="wartosc">Ci¹g znaków z pliku wejœciowego.</param>
    void usun_znak_konca_linii(string& wartosc) {
        usun_znak(wartosc, '\n');
    }
    /// <summary>
    /// Funkcja usuwa spacje z tekstu.
    /// </summary>
    /// <param name="wartosc">Ci¹g znaków z pliku wejœciowego.</param>
    void bez_znakow(string& wartosc) {
        usun_znak(wartosc, ' ');
    }
    /// <summary>
    /// Funkcja usuwa dany znak.
    /// </summary>
    /// <param name="wartosc">Tekst w którym znajduje sie dany znak.</param>
    /// <param name="character">Podany znak</param>
    void usun_znak(string& wartosc, char character) {
        wartosc.erase(remove(wartosc.begin(), wartosc.end(), character), wartosc.end());
    }
};
/// <summary>
/// Struktura zajmuje siê wyjêciem z pliku wejœciowego elementów ju¿ podzielonych i ze zmienionym typem zmiennych.
/// </summary>
struct fabryka_krawedzi {
public:
    /// <summary>
    /// Funkcja zamienia podzielony ci¹g znaków na inty.
    /// </summary>
    /// <param name="wejscie">Tekst w pliku wejœciowym.</param>
    /// <returns>Podzielona lista krawedzi.</returns>
    static list<Krawedz> stworz(string wejscie) {
        list<Krawedz> wartosci;
        auto wartosci_podzielone_przecinkami = podziel(wejscie, ",");
        for (auto v : wartosci_podzielone_przecinkami) {
            auto para_krawedzi = podziel(v, "->");        
            auto poczatak_na_int = stoi(para_krawedzi.front());
            auto koniec_na_int = stoi(para_krawedzi.back());
            auto krawedz = Krawedz(poczatak_na_int, koniec_na_int);
            wartosci.push_back(krawedz);
        }

        return wartosci;
    }

private:
    /// <summary>
    /// Funkcja szuka ogranicznika, a potem dzieli ci¹g znaków od tego ogranicznika do nastêpnego.
    /// </summary>
    /// <param name="wartosc">Znaki do podzielenia.</param>
    /// <param name="ogranicznik">Znak lub znaki, które dziel¹ dany ci¹g znaków.</param>
    /// <returns>Podzielony ci¹g znaków.</returns>
    static list<string> podziel(string wartosc, string ogranicznik) {
        list<string> podzielone_wartosci;

        int pos = 0;
        while ((pos = wartosc.find(ogranicznik)) != string::npos) {
            auto podzielone_wartosc = wartosc.substr(0, pos);
            podzielone_wartosci.push_back(podzielone_wartosc);
            wartosc.erase(0, pos + ogranicznik.length());//wywal
        }
        podzielone_wartosci.push_back(wartosc);
        return podzielone_wartosci;
    }
};