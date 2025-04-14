#ifndef TSZACHOWNICA
#define TSZACHOWNICA

#include"Tpion.h"
#include"Tpole.h"

#include"Twierza.h"
#include"Thetman.h"
#include"Tgoniec.h"
#include"Tskoczek.h"
#include"TzwyklyPionek.h"
#include"Tkrol.h"

#include<string>

class Tszachownica
{
    friend class Tgoniec;
    friend class Tskoczek;
    friend class Tkrol;
    friend class Thetman;
    friend class TzwyklyPionek;
    friend class Twierza;

private:
    bool czyjRuch{ false };
    bool czyMenuGlowne{ true };
    static jestSzach jestszach;
    int pozycjaOstatniegoWcisnietegoPionka;

    static int materialBialego;
    static int materialCzarnego;
    
    static int powtorzoneRuchy;

    static int zasada50ruchow;

    float timer{ 0.0f };
    int czasBialego{ 0 };
    int czasCzarnego{ 0 };

    int dodatkowyCzasB{ 0 };
    int dodatkowyCzasC{ 0 };

    Tpole* tablicaPol[64];
    Tpion* tablicaPionow[64];
public:
    void dzialaj();
    Tszachownica();
    ~Tszachownica();
    static void wlaczSzacha()
    {
        jestszach.szach = true;
        jestszach.iloscSzachujacychPionkow++;
    }

private:
    bool jestMat;
    bool jestPat;
    int jestAwans;

    void rysujZaznaczonePola();
   
    void podmianaPionkaNaWybranaFigure(int numer, int pozycjaPionka, bool team);
    void nacisnietePole();
    void odznaczaniePol();
    void usuwaniePassanta();
    void szachowanieETCszachownica(bool czyjRuch);
    void ruch(int numerKliknietegoPola);
    int sprawdzenieMata();

    void wykonanieAwansu(int pozycja);
    void Zwyciestwo(std::string slowo, bool kto);
    void Remis(std::string slowo);
    bool sprawdzenieRemisu(bool team);

    void rysujPrzyciski();
    void rysuj();
    void rysujMenu();
    // w miare z czasem bede uzupelniac te funkcje sk³adowe
};

#endif // !TSZACHOWNICA
