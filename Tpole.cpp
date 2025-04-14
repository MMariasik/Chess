#include"Tpole.h"

Tpole::Tpole(Tkoordynaty poz, int numer, const char* pathDoTeksturki) 
    : pozycja{ poz }, zajete{ false }, Szachowane{ false }, zaznaczone{ false }, numerPola{ numer }, naLiniiSzacha{ false }, naLiniiZwiazania{ jestPodwieszenie{ 99, false } }, czyEnPassant{ false }
{
    tekstura = LoadTexture(pathDoTeksturki);
}

void Tpole::rysujSie()
{
    DrawTexture(tekstura, pozycja.x, pozycja.y, WHITE);
}