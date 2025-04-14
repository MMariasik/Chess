#ifndef TKOORDYNATY
#define TKOORDYNATY

#include<raylib.h>


struct Tkoordynaty
{
    int x;
    int y;
};

struct jestSzach
{
    bool szach;
    int iloscSzachujacychPionkow;
};

struct jestPodwieszenie
{
    int numerZwiazanegoPionka;
    bool poleNaLiniiZwiazania;
};

#endif // !TKOORDYNATY
