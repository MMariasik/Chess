#ifndef TWIERZA
#define TWIERZA

#include"Tpion.h"


class Twierza : public Tpion
{
public:
    Twierza(Tkoordynaty poz, int numer, bool team, int kto, const char* pathDoTexturki, const char* pathDoDzwiekuRuchu, const char* pathDoDzwiekuBicia);
    ~Twierza();

    void rysujSie() override;
    void zaznaczanie(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, jestSzach* jestszach, bool druzyna) override;
    void zbicie(bool kto) override;
    void szachowanieETC(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch) override;

private:
    // L - w Lewo, P - w Prawo, G - w Górê, D - w Dó³
    void szachowanie(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch, int wKtoraStrone, bool czyNaBoki);

    void doZaznaczania(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch, int wKtoraStrone, bool czyNaBoki, jestSzach* jestszach);

    bool wsparcieSzachowania(Tpole** pola, Tpion** piony, int pozycja, bool ruch);
};

#endif // !TWIERZA
