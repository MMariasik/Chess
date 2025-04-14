#ifndef THETMAN
#define THETMAN

#include"Tpion.h"

class Thetman : public Tpion
{
public:
    Thetman(Tkoordynaty poz, int numer, bool team, int kto, const char* pathDoTexturki, const char* pathDoDzwiekuRuchu, const char* pathDoDzwiekuBicia);
    ~Thetman();

    void rysujSie() override;
    void zaznaczanie(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, jestSzach* jestszach, bool druzyna) override;
    void zbicie(bool kto) override;
    void szachowanieETC(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch) override;

private:
    // L - w Lewo, P - w Prawo, G - w Górê, D - w Dó³
    void szachowanieG(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch, int wKtoraStrone);
    void szachowanieW(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch, int wKtoraStrone, bool czyNaBoki);

    void doZaznaczaniaG(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch, int wKtoraStrone, jestSzach* jestszach);
    void doZaznaczaniaW(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch, int wKtoraStrone, bool czyNaBoki, jestSzach* jestszach);

    bool wsparcieSzachowania(Tpole** pola, Tpion** piony, int pozycja, bool ruch);
};


#endif // !THETMAN
