#ifndef TZWYKLYPIONEK
#define TZWYKLYPIONEK

#include "Tpion.h"

class TzwyklyPionek : public Tpion
{
public:
    TzwyklyPionek(Tkoordynaty poz, int numer, bool team, int kto, const char* pathDoTexturki, const char* pathDoDzwiekuRuchu, const char* pathDoDzwiekuBicia);
    ~TzwyklyPionek();

    void rysujSie() override;
    void zaznaczanie(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, jestSzach* jestszac, bool druzynah) override;
    void zbicie(bool kto) override;
    void szachowanieETC(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch) override;
    void awans();
};

#endif // !TZWYKLYPIONEK
