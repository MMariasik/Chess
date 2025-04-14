#ifndef TKROL
#define TKROL

#include"Tpion.h"


class Tkrol : public Tpion
{
private:
    Sound dzwiekSzacha;
public:
    Tkrol(Tkoordynaty poz, int numer, bool team, int kto, const char* pathDoTexturki, const char* pathDoDzwiekuRuchu, const char* pathDoDzwiekuBicia, const char* pathDzwiekuSzacha);
    ~Tkrol();

    void rysujSie() override;
    void zaznaczanie(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, jestSzach* jestszach, bool druzyna) override;
    void zbicie(bool kto) override; // ?
    void szachowanieETC(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch) override;

    void roszada(Tpion** tablicaPionow, Tpole** tablicaPol, int pozycja, jestSzach * jestszach );
};

#endif // !TKROL
