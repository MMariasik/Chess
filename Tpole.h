#ifndef TPOLE
#define TPOLE

#include"Tkoordynaty.h"


class Tpole
{
    friend class Tszachownica;

    friend class TzwyklyPionek;
    friend class Twierza;
    friend class Thetman;
    friend class Tskoczek;
    friend class Tgoniec;
    friend class Tkrol;

private:
    Texture2D tekstura;
    Tkoordynaty pozycja;
    int numerPola;
    bool czyEnPassant;
    bool zajete;
    bool Szachowane; // w sensie tylko by ulatwic obliczenia gdzie krol moze isc
    bool zaznaczone;
    bool naLiniiSzacha;
    jestPodwieszenie naLiniiZwiazania;
    
public:
    Tpole(Tkoordynaty poz, int numer, const char* pathDoTeksturki);

    void rysujSie();
};

#endif // !TPOLE
