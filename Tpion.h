#ifndef TPION
#define TPION

#include "Tkoordynaty.h"

class Tpole;

class Tpion  // moja klasa abstrakcyjna
{
    friend class Tszachownica;

    friend class TzwyklyPionek;
    friend class Twierza;
    friend class Thetman;
    friend class Tskoczek;
    friend class Tgoniec;
    friend class Tkrol;

protected:
    Tkoordynaty pozycja;
    Texture2D tekstura;
    Sound dzwiekRuchu;
    Sound dzwiekBicia;
    bool ruszony{ false };
    int naKtorymPoluStoje;
    int powtarzaniePozycji[2];
    bool druzyna; // true - czarni
    bool jestemZwiazany;
    const int kimJestem;  // 1 - krol, 2 - wierza, 3 - zwyklyPionek, 4 - skoczek, 5 - bialo polowyGoniec, 6 - czarno Polowy Goniec

public:
    Tpion(Tkoordynaty poz, int numer, bool team, int kto, const char* pathDoTexturki, const char* pathDoDzwiekuRuchu, const char* pathDoDzwiekuBicia);
    virtual ~Tpion();

    virtual void rysujSie() = 0;
    virtual void zaznaczanie(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, jestSzach * jestszach, bool druzyna) = 0;
    virtual void zbicie(bool kto) = 0; // ta funkcja bedzie liczyc roznice materialu i jakies inne graficzne przedstawienia co zostalo zbite
    virtual void szachowanieETC(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch) = 0; // ta funkcja robi zalatwi wszystkie moje problemy
};

#endif // !TPION
