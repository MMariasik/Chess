#ifndef TSKOCZEK
#define TSKOCZEK

#include "Tpion.h"


class Tskoczek : public Tpion
{
public:
    Tskoczek(Tkoordynaty poz, int numer, bool team,int kto, const char* pathDoTexturki, const char* pathDoDzwiekuRuchu, const char* pathDoDzwiekuBicia);
    ~Tskoczek();

    void rysujSie() override;
    void zaznaczanie(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, jestSzach* jestszach, bool druzyna) override;
    void zbicie(bool kto) override;
    void szachowanieETC(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch) override;
};

#endif // !TSKOCZEK
