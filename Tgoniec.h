#ifndef TGONIEC
#define TGONIEC

#include "Tpion.h"


class Tgoniec : public Tpion
{
public:
    Tgoniec(Tkoordynaty poz, int numer, bool team, int kto, const char* pathDoTexturki, const char* pathDoDzwiekuRuchu, const char* pathDoDzwiekuBicia);
    ~Tgoniec();

    void rysujSie() override;
    void zaznaczanie(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, jestSzach* jestszach, bool druzyna) override;
    void zbicie(bool kto) override;
    void szachowanieETC(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch) override;

private:
    // L - w Lewo, P - w Prawo, G - w Górê, D - w Dó³
    void szachowanie(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch, int wKtoraStrone);

    void doZaznaczania(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch, int wKtoraStrone, jestSzach* jestszach);

    bool wsparcieSzachowania(Tpole** pola, Tpion** piony, int pozycja, bool ruch);
};

#endif // !TGONIEC
