#include"Tskoczek.h"

#include"Tszachownica.h"

Tskoczek::~Tskoczek()
{
    Tpion::~Tpion();
}

Tskoczek::Tskoczek(Tkoordynaty poz, int numer, bool team, int kto, const char* pathDoTexturki, const char* pathDoDzwiekuRuchu, const char* pathDoDzwiekuBicia) 
    : Tpion(poz, numer, team, kto, pathDoTexturki, pathDoDzwiekuRuchu, pathDoDzwiekuBicia)
{}

void Tskoczek::rysujSie()
{   
    DrawTexture(tekstura, pozycja.x, pozycja.y, WHITE);
}

void Tskoczek::zaznaczanie(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, jestSzach* jestszach, bool druzyna)
{
    if (!tablicaPionow[pozycja]->jestemZwiazany)
    {
        if (!jestszach->szach)
        {
            if (pozycja % 8 < 1)
            {
                if (pozycja < 8)
                {
                    if (!tablicaPol[pozycja + 10]->zajete)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 10]->druzyna != druzyna)
                        tablicaPol[pozycja + 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 17]->zajete)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 17]->druzyna != druzyna)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                }
                else if (pozycja < 16)
                {
                    if (!tablicaPol[pozycja + 10]->zajete)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 10]->druzyna != druzyna)
                        tablicaPol[pozycja + 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 17]->zajete)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 17]->druzyna != druzyna)
                        tablicaPol[pozycja + 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 6]->zajete)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 6]->druzyna != druzyna)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                }
                else if (pozycja > 55)
                {
                    if (!tablicaPol[pozycja - 6]->zajete)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 6]->druzyna != druzyna)
                        tablicaPol[pozycja - 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 15]->zajete)
                        tablicaPol[pozycja - 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 15]->druzyna != druzyna)
                        tablicaPol[pozycja - 15]->zaznaczone = true;
                }
                else if (pozycja > 47)
                {
                    if (!tablicaPol[pozycja - 6]->zajete)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 6]->druzyna != druzyna)
                        tablicaPol[pozycja - 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 15]->zajete)
                        tablicaPol[pozycja - 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 15]->druzyna != druzyna)
                        tablicaPol[pozycja - 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 10]->zajete)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 10]->druzyna != druzyna)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                }
                else
                {
                    if (!tablicaPol[pozycja - 6]->zajete)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 6]->druzyna != druzyna)
                        tablicaPol[pozycja - 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 15]->zajete)
                        tablicaPol[pozycja - 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 15]->druzyna != druzyna)
                        tablicaPol[pozycja - 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 10]->zajete)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 10]->druzyna != druzyna)
                        tablicaPol[pozycja + 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 17]->zajete)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 17]->druzyna != druzyna)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                }
            }
            else if (pozycja % 8 < 2)
            {
                if (pozycja < 8)
                {
                    if (!tablicaPol[pozycja + 15]->zajete)
                        tablicaPol[pozycja + 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 15]->druzyna != druzyna)
                        tablicaPol[pozycja + 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 10]->zajete)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 10]->druzyna != druzyna)
                        tablicaPol[pozycja + 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 17]->zajete)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 17]->druzyna != druzyna)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                }
                else if (pozycja < 16)
                {
                    if (!tablicaPol[pozycja + 15]->zajete)
                        tablicaPol[pozycja + 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 15]->druzyna != druzyna)
                        tablicaPol[pozycja + 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 10]->zajete)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 10]->druzyna != druzyna)
                        tablicaPol[pozycja + 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 17]->zajete)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 17]->druzyna != druzyna)
                        tablicaPol[pozycja + 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 6]->zajete)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 6]->druzyna != druzyna)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                }
                else if (pozycja > 55)
                {
                    if (!tablicaPol[pozycja - 6]->zajete)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 6]->druzyna != druzyna)
                        tablicaPol[pozycja - 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 15]->zajete)
                        tablicaPol[pozycja - 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 15]->druzyna != druzyna)
                        tablicaPol[pozycja - 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 17]->zajete)
                        tablicaPol[pozycja - 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 17]->druzyna != druzyna)
                        tablicaPol[pozycja - 17]->zaznaczone = true;

                }
                else if (pozycja > 47)
                {
                    if (!tablicaPol[pozycja - 6]->zajete)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 6]->druzyna != druzyna)
                        tablicaPol[pozycja - 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 15]->zajete)
                        tablicaPol[pozycja - 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 15]->druzyna != druzyna)
                        tablicaPol[pozycja - 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 17]->zajete)
                        tablicaPol[pozycja - 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 17]->druzyna != druzyna)
                        tablicaPol[pozycja - 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 10]->zajete)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 10]->druzyna != druzyna)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                }
                else
                {
                    if (!tablicaPol[pozycja + 15]->zajete)
                        tablicaPol[pozycja + 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 15]->druzyna != druzyna)
                        tablicaPol[pozycja + 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 17]->zajete)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 17]->druzyna != druzyna)
                        tablicaPol[pozycja + 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 6]->zajete)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 6]->druzyna != druzyna)
                        tablicaPol[pozycja - 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 15]->zajete)
                        tablicaPol[pozycja - 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 15]->druzyna != druzyna)
                        tablicaPol[pozycja - 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 17]->zajete)
                        tablicaPol[pozycja - 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 17]->druzyna != druzyna)
                        tablicaPol[pozycja - 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 10]->zajete)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 10]->druzyna != druzyna)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                }
            }

            else if (pozycja % 8 > 6)
            {
                if (pozycja < 8)
                {
                    if (!tablicaPol[pozycja + 6]->zajete)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 6]->druzyna != druzyna)
                        tablicaPol[pozycja + 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 15]->zajete)
                        tablicaPol[pozycja + 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 15]->druzyna != druzyna)
                        tablicaPol[pozycja + 15]->zaznaczone = true;
                }
                else if (pozycja < 16)
                {
                    if (!tablicaPol[pozycja + 6]->zajete)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 6]->druzyna != druzyna)
                        tablicaPol[pozycja + 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 15]->zajete)
                        tablicaPol[pozycja + 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 15]->druzyna != druzyna)
                        tablicaPol[pozycja + 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 10]->zajete)
                        tablicaPol[pozycja - 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 10]->druzyna != druzyna)
                        tablicaPol[pozycja - 10]->zaznaczone = true;
                }
                else if (pozycja > 55)
                {
                    if (!tablicaPol[pozycja - 10]->zajete)
                        tablicaPol[pozycja - 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 10]->druzyna != druzyna)
                        tablicaPol[pozycja - 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 17]->zajete)
                        tablicaPol[pozycja - 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 17]->druzyna != druzyna)
                        tablicaPol[pozycja - 17]->zaznaczone = true;
                }
                else if (pozycja > 47)
                {
                    if (!tablicaPol[pozycja - 10]->zajete)
                        tablicaPol[pozycja - 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 10]->druzyna != druzyna)
                        tablicaPol[pozycja - 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 17]->zajete)
                        tablicaPol[pozycja - 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 17]->druzyna != druzyna)
                        tablicaPol[pozycja - 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 6]->zajete)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 6]->druzyna != druzyna)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                }
                else
                {
                    if (!tablicaPol[pozycja - 10]->zajete)
                        tablicaPol[pozycja - 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 10]->druzyna != druzyna)
                        tablicaPol[pozycja - 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 17]->zajete)
                        tablicaPol[pozycja - 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 17]->druzyna != druzyna)
                        tablicaPol[pozycja - 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 6]->zajete)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 6]->druzyna != druzyna)
                        tablicaPol[pozycja + 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 15]->zajete)
                        tablicaPol[pozycja + 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 15]->druzyna != druzyna)
                        tablicaPol[pozycja + 15]->zaznaczone = true;
                }
            }
            else if (pozycja % 8 > 5)
            {
                if (pozycja < 8)
                {
                    if (!tablicaPol[pozycja + 6]->zajete)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 6]->druzyna != druzyna)
                        tablicaPol[pozycja + 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 15]->zajete)
                        tablicaPol[pozycja + 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 15]->druzyna != druzyna)
                        tablicaPol[pozycja + 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 17]->zajete)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 17]->druzyna != druzyna)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                }
                else if (pozycja < 16)
                {
                    if (!tablicaPol[pozycja + 6]->zajete)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 6]->druzyna != druzyna)
                        tablicaPol[pozycja + 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 15]->zajete)
                        tablicaPol[pozycja + 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 15]->druzyna != druzyna)
                        tablicaPol[pozycja + 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 17]->zajete)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 17]->druzyna != druzyna)
                        tablicaPol[pozycja + 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 10]->zajete)
                        tablicaPol[pozycja - 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 10]->druzyna != druzyna)
                        tablicaPol[pozycja - 10]->zaznaczone = true;
                }
                else if (pozycja > 55)
                {
                    if (!tablicaPol[pozycja - 10]->zajete)
                        tablicaPol[pozycja - 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 10]->druzyna != druzyna)
                        tablicaPol[pozycja - 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 15]->zajete)
                        tablicaPol[pozycja - 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 15]->druzyna != druzyna)
                        tablicaPol[pozycja - 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 17]->zajete)
                        tablicaPol[pozycja - 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 17]->druzyna != druzyna)
                        tablicaPol[pozycja - 17]->zaznaczone = true;
                }
                else if (pozycja > 47)
                {
                    if (!tablicaPol[pozycja - 10]->zajete)
                        tablicaPol[pozycja - 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 10]->druzyna != druzyna)
                        tablicaPol[pozycja - 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 15]->zajete)
                        tablicaPol[pozycja - 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 15]->druzyna != druzyna)
                        tablicaPol[pozycja - 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 17]->zajete)
                        tablicaPol[pozycja - 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 17]->druzyna != druzyna)
                        tablicaPol[pozycja - 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 6]->zajete)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 6]->druzyna != druzyna)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                }
                else
                {
                    if (!tablicaPol[pozycja - 10]->zajete)
                        tablicaPol[pozycja - 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 10]->druzyna != druzyna)
                        tablicaPol[pozycja - 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 15]->zajete)
                        tablicaPol[pozycja - 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 15]->druzyna != druzyna)
                        tablicaPol[pozycja - 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 17]->zajete)
                        tablicaPol[pozycja - 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 17]->druzyna != druzyna)
                        tablicaPol[pozycja - 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 6]->zajete)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 6]->druzyna != druzyna)
                        tablicaPol[pozycja + 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 15]->zajete)
                        tablicaPol[pozycja + 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 15]->druzyna != druzyna)
                        tablicaPol[pozycja + 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 17]->zajete)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 17]->druzyna != druzyna)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                }
            }

            else // srodkowe pola X
            {
                if (pozycja < 8)
                {
                    if (!tablicaPol[pozycja + 15]->zajete)
                        tablicaPol[pozycja + 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 15]->druzyna != druzyna)
                        tablicaPol[pozycja + 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 10]->zajete)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 10]->druzyna != druzyna)
                        tablicaPol[pozycja + 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 17]->zajete)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 17]->druzyna != druzyna)
                        tablicaPol[pozycja + 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 6]->zajete)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 6]->druzyna != druzyna)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                }
                else if (pozycja < 16)
                {
                    if (!tablicaPol[pozycja + 15]->zajete)
                        tablicaPol[pozycja + 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 15]->druzyna != druzyna)
                        tablicaPol[pozycja + 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 10]->zajete)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 10]->druzyna != druzyna)
                        tablicaPol[pozycja + 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 17]->zajete)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 17]->druzyna != druzyna)
                        tablicaPol[pozycja + 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 6]->zajete)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 6]->druzyna != druzyna)
                        tablicaPol[pozycja + 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 10]->zajete)
                        tablicaPol[pozycja - 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 10]->druzyna != druzyna)
                        tablicaPol[pozycja - 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 6]->zajete)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 6]->druzyna != druzyna)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                }
                else if (pozycja > 55)
                {
                    if (!tablicaPol[pozycja - 15]->zajete)
                        tablicaPol[pozycja - 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 15]->druzyna != druzyna)
                        tablicaPol[pozycja - 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 17]->zajete)
                        tablicaPol[pozycja - 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 17]->druzyna != druzyna)
                        tablicaPol[pozycja - 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 10]->zajete)
                        tablicaPol[pozycja - 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 10]->druzyna != druzyna)
                        tablicaPol[pozycja - 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 6]->zajete)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 6]->druzyna != druzyna)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                }
                else if (pozycja > 47)
                {
                    if (!tablicaPol[pozycja - 15]->zajete)
                        tablicaPol[pozycja - 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 15]->druzyna != druzyna)
                        tablicaPol[pozycja - 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 17]->zajete)
                        tablicaPol[pozycja - 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 17]->druzyna != druzyna)
                        tablicaPol[pozycja - 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 10]->zajete)
                        tablicaPol[pozycja - 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 10]->druzyna != druzyna)
                        tablicaPol[pozycja - 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 6]->zajete)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 6]->druzyna != druzyna)
                        tablicaPol[pozycja - 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 10]->zajete)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 10]->druzyna != druzyna)
                        tablicaPol[pozycja + 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 6]->zajete)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 6]->druzyna != druzyna)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                }
                else
                {
                    if (!tablicaPol[pozycja - 15]->zajete)
                        tablicaPol[pozycja - 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 15]->druzyna != druzyna)
                        tablicaPol[pozycja - 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 17]->zajete)
                        tablicaPol[pozycja - 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 17]->druzyna != druzyna)
                        tablicaPol[pozycja - 17]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 10]->zajete)
                        tablicaPol[pozycja - 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 10]->druzyna != druzyna)
                        tablicaPol[pozycja - 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja - 6]->zajete)
                        tablicaPol[pozycja - 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja - 6]->druzyna != druzyna)
                        tablicaPol[pozycja - 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 10]->zajete)
                        tablicaPol[pozycja + 10]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 10]->druzyna != druzyna)
                        tablicaPol[pozycja + 10]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 6]->zajete)
                        tablicaPol[pozycja + 6]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 6]->druzyna != druzyna)
                        tablicaPol[pozycja + 6]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 15]->zajete)
                        tablicaPol[pozycja + 15]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 15]->druzyna != druzyna)
                        tablicaPol[pozycja + 15]->zaznaczone = true;

                    if (!tablicaPol[pozycja + 17]->zajete)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                    else if (tablicaPionow[pozycja + 17]->druzyna != druzyna)
                        tablicaPol[pozycja + 17]->zaznaczone = true;
                }
            }
        }
        else if (jestszach->iloscSzachujacychPionkow < 2)
        {
        if (pozycja % 8 < 1)
        {
            if (pozycja < 8)
            {
                if (tablicaPol[pozycja + 10]->naLiniiSzacha)
                    tablicaPol[pozycja + 10]->zaznaczone = true;

                if (tablicaPol[pozycja + 17]->naLiniiSzacha)
                    tablicaPol[pozycja + 17]->zaznaczone = true;
            }
            else if (pozycja < 16)
            {
                if (tablicaPol[pozycja + 10]->naLiniiSzacha)
                    tablicaPol[pozycja + 10]->zaznaczone = true;

                if (tablicaPol[pozycja + 17]->naLiniiSzacha)
                    tablicaPol[pozycja + 17]->zaznaczone = true;

                if (tablicaPol[pozycja - 6]->naLiniiSzacha)
                    tablicaPol[pozycja - 6]->zaznaczone = true;
            }
            else if (pozycja > 55)
            {
                if (tablicaPol[pozycja - 6]->naLiniiSzacha)
                    tablicaPol[pozycja - 6]->zaznaczone = true;

                if (tablicaPol[pozycja - 15]->naLiniiSzacha)
                    tablicaPol[pozycja - 15]->zaznaczone = true;
            }
            else if (pozycja > 47)
            {
                if (tablicaPol[pozycja - 6]->naLiniiSzacha)
                    tablicaPol[pozycja - 6]->zaznaczone = true;

                if (tablicaPol[pozycja - 15]->naLiniiSzacha)
                    tablicaPol[pozycja - 15]->zaznaczone = true;

                if (tablicaPol[pozycja + 10]->naLiniiSzacha)
                    tablicaPol[pozycja + 10]->zaznaczone = true;
            }
            else
            {
                if (tablicaPol[pozycja - 6]->naLiniiSzacha)
                    tablicaPol[pozycja - 6]->zaznaczone = true;

                if (tablicaPol[pozycja - 15]->naLiniiSzacha)
                    tablicaPol[pozycja - 15]->zaznaczone = true;

                if (tablicaPol[pozycja + 10]->naLiniiSzacha)
                    tablicaPol[pozycja + 10]->zaznaczone = true;

                if (tablicaPol[pozycja + 17]->naLiniiSzacha)
                    tablicaPol[pozycja + 17]->zaznaczone = true;
            }
        }
        else if (pozycja % 8 < 2)
        {
            if (pozycja < 8)
            {
                if (tablicaPol[pozycja + 15]->naLiniiSzacha)
                    tablicaPol[pozycja + 15]->zaznaczone = true;

                if (tablicaPol[pozycja + 10]->naLiniiSzacha)
                    tablicaPol[pozycja + 10]->zaznaczone = true;

                if (tablicaPol[pozycja + 17]->naLiniiSzacha)
                    tablicaPol[pozycja + 17]->zaznaczone = true;
            }
            else if (pozycja < 16)
            {
                if (tablicaPol[pozycja + 15]->naLiniiSzacha)
                    tablicaPol[pozycja + 15]->zaznaczone = true;

                if (tablicaPol[pozycja + 10]->naLiniiSzacha)
                    tablicaPol[pozycja + 10]->zaznaczone = true;

                if (tablicaPol[pozycja + 17]->naLiniiSzacha)
                    tablicaPol[pozycja + 17]->zaznaczone = true;

                if (tablicaPol[pozycja - 6]->naLiniiSzacha)
                    tablicaPol[pozycja - 6]->zaznaczone = true;
            }
            else if (pozycja > 55)
            {
                if (tablicaPol[pozycja - 6]->naLiniiSzacha)
                    tablicaPol[pozycja - 6]->zaznaczone = true;

                if (tablicaPol[pozycja - 15]->naLiniiSzacha)
                    tablicaPol[pozycja - 15]->zaznaczone = true;

                if (tablicaPol[pozycja - 17]->naLiniiSzacha)
                    tablicaPol[pozycja - 17]->zaznaczone = true;

            }
            else if (pozycja > 47)
            {
                if (tablicaPol[pozycja - 6]->naLiniiSzacha)
                    tablicaPol[pozycja - 6]->zaznaczone = true;

                if (tablicaPol[pozycja - 15]->naLiniiSzacha)
                    tablicaPol[pozycja - 15]->zaznaczone = true;

                if (tablicaPol[pozycja - 17]->naLiniiSzacha)
                    tablicaPol[pozycja - 17]->zaznaczone = true;

                if (tablicaPol[pozycja + 10]->naLiniiSzacha)
                    tablicaPol[pozycja + 10]->zaznaczone = true;
            }
            else
            {
                if (tablicaPol[pozycja + 15]->naLiniiSzacha)
                    tablicaPol[pozycja + 15]->zaznaczone = true;

                if (tablicaPol[pozycja + 17]->naLiniiSzacha)
                    tablicaPol[pozycja + 17]->zaznaczone = true;

                if (tablicaPol[pozycja - 6]->naLiniiSzacha)
                    tablicaPol[pozycja - 6]->zaznaczone = true;

                if (tablicaPol[pozycja - 15]->naLiniiSzacha)
                    tablicaPol[pozycja - 15]->zaznaczone = true;

                if (tablicaPol[pozycja - 17]->naLiniiSzacha)
                    tablicaPol[pozycja - 17]->zaznaczone = true;

                if (tablicaPol[pozycja + 10]->naLiniiSzacha)
                    tablicaPol[pozycja + 10]->zaznaczone = true;
            }
        }

        else if (pozycja % 8 > 6)
        {
            if (pozycja < 8)
            {
                if (tablicaPol[pozycja + 6]->naLiniiSzacha)
                    tablicaPol[pozycja + 6]->zaznaczone = true;

                if (tablicaPol[pozycja + 15]->naLiniiSzacha)
                    tablicaPol[pozycja + 15]->zaznaczone = true;
            }
            else if (pozycja < 16)
            {
                if (tablicaPol[pozycja + 6]->naLiniiSzacha)
                    tablicaPol[pozycja + 6]->zaznaczone = true;

                if (tablicaPol[pozycja + 15]->naLiniiSzacha)
                    tablicaPol[pozycja + 15]->zaznaczone = true;

                if (tablicaPol[pozycja - 10]->naLiniiSzacha)
                    tablicaPol[pozycja - 10]->zaznaczone = true;
            }
            else if (pozycja > 55)
            {
                if (tablicaPol[pozycja - 10]->naLiniiSzacha)
                    tablicaPol[pozycja - 10]->zaznaczone = true;

                if (tablicaPol[pozycja - 17]->naLiniiSzacha)
                    tablicaPol[pozycja - 17]->zaznaczone = true;
            }
            else if (pozycja > 47)
            {
                if (tablicaPol[pozycja - 10]->naLiniiSzacha)
                    tablicaPol[pozycja - 10]->zaznaczone = true;

                if (tablicaPol[pozycja - 17]->naLiniiSzacha)
                    tablicaPol[pozycja - 17]->zaznaczone = true;

                if (tablicaPol[pozycja + 6]->naLiniiSzacha)
                    tablicaPol[pozycja + 6]->zaznaczone = true;
            }
            else
            {
                if (tablicaPol[pozycja - 10]->naLiniiSzacha)
                    tablicaPol[pozycja - 10]->zaznaczone = true;

                if (tablicaPol[pozycja - 17]->naLiniiSzacha)
                    tablicaPol[pozycja - 17]->zaznaczone = true;

                if (tablicaPol[pozycja + 6]->naLiniiSzacha)
                    tablicaPol[pozycja + 6]->zaznaczone = true;

                if (tablicaPol[pozycja + 15]->naLiniiSzacha)
                    tablicaPol[pozycja + 15]->zaznaczone = true;
            }
        }
        else if (pozycja % 8 > 5)
        {
            if (pozycja < 8)
            {
                if (tablicaPol[pozycja + 6]->naLiniiSzacha)
                    tablicaPol[pozycja + 6]->zaznaczone = true;

                if (tablicaPol[pozycja + 15]->naLiniiSzacha)
                    tablicaPol[pozycja + 15]->zaznaczone = true;

                if (tablicaPol[pozycja + 17]->naLiniiSzacha)
                    tablicaPol[pozycja + 17]->zaznaczone = true;
            }
            else if (pozycja < 16)
            {
                if (tablicaPol[pozycja + 6]->naLiniiSzacha)
                    tablicaPol[pozycja + 6]->zaznaczone = true;

                if (tablicaPol[pozycja + 15]->naLiniiSzacha)
                    tablicaPol[pozycja + 15]->zaznaczone = true;

                if (tablicaPol[pozycja + 17]->naLiniiSzacha)
                    tablicaPol[pozycja + 17]->zaznaczone = true;

                if (tablicaPol[pozycja - 10]->naLiniiSzacha)
                    tablicaPol[pozycja - 10]->zaznaczone = true;
            }
            else if (pozycja > 55)
            {
                if (tablicaPol[pozycja - 10]->naLiniiSzacha)
                    tablicaPol[pozycja - 10]->zaznaczone = true;

                if (tablicaPol[pozycja - 15]->naLiniiSzacha)
                    tablicaPol[pozycja - 15]->zaznaczone = true;

                if (tablicaPol[pozycja - 17]->naLiniiSzacha)
                    tablicaPol[pozycja - 17]->zaznaczone = true;
            }
            else if (pozycja > 47)
            {
                if (tablicaPol[pozycja - 10]->naLiniiSzacha)
                    tablicaPol[pozycja - 10]->zaznaczone = true;

                if (tablicaPol[pozycja - 15]->naLiniiSzacha)
                    tablicaPol[pozycja - 15]->zaznaczone = true;

                if (tablicaPol[pozycja - 17]->naLiniiSzacha)
                    tablicaPol[pozycja - 17]->zaznaczone = true;

                if (tablicaPol[pozycja + 6]->naLiniiSzacha)
                    tablicaPol[pozycja + 6]->zaznaczone = true;
            }
            else
            {
                if (tablicaPol[pozycja - 10]->naLiniiSzacha)
                    tablicaPol[pozycja - 10]->zaznaczone = true;

                if (tablicaPol[pozycja - 15]->naLiniiSzacha)
                    tablicaPol[pozycja - 15]->zaznaczone = true;

                if (tablicaPol[pozycja - 17]->naLiniiSzacha)
                    tablicaPol[pozycja - 17]->zaznaczone = true;

                if (tablicaPol[pozycja + 6]->naLiniiSzacha)
                    tablicaPol[pozycja + 6]->zaznaczone = true;

                if (tablicaPol[pozycja + 15]->naLiniiSzacha)
                    tablicaPol[pozycja + 15]->zaznaczone = true;

                if (tablicaPol[pozycja + 17]->naLiniiSzacha)
                    tablicaPol[pozycja + 17]->zaznaczone = true;
            }
        }

        else // srodkowe pola X
        {
            if (pozycja < 8)
            {
                if (tablicaPol[pozycja + 15]->naLiniiSzacha)
                    tablicaPol[pozycja + 15]->zaznaczone = true;

                if (tablicaPol[pozycja + 10]->naLiniiSzacha)
                    tablicaPol[pozycja + 10]->zaznaczone = true;

                if (tablicaPol[pozycja + 17]->naLiniiSzacha)
                    tablicaPol[pozycja + 17]->zaznaczone = true;

                if (tablicaPol[pozycja + 6]->naLiniiSzacha)
                    tablicaPol[pozycja + 6]->zaznaczone = true;
            }
            else if (pozycja < 16)
            {
                if (tablicaPol[pozycja + 15]->naLiniiSzacha)
                    tablicaPol[pozycja + 15]->zaznaczone = true;

                if (tablicaPol[pozycja + 10]->naLiniiSzacha)
                    tablicaPol[pozycja + 10]->zaznaczone = true;

                if (tablicaPol[pozycja + 17]->naLiniiSzacha)
                    tablicaPol[pozycja + 17]->zaznaczone = true;

                if (tablicaPol[pozycja + 6]->naLiniiSzacha)
                    tablicaPol[pozycja + 6]->zaznaczone = true;

                if (tablicaPol[pozycja - 10]->naLiniiSzacha)
                    tablicaPol[pozycja - 10]->zaznaczone = true;

                if (tablicaPol[pozycja - 6]->naLiniiSzacha)
                    tablicaPol[pozycja - 6]->zaznaczone = true;
            }
            else if (pozycja > 55)
            {
                if (tablicaPol[pozycja - 15]->naLiniiSzacha)
                    tablicaPol[pozycja - 15]->zaznaczone = true;

                if (tablicaPol[pozycja - 17]->naLiniiSzacha)
                    tablicaPol[pozycja - 17]->zaznaczone = true;

                if (tablicaPol[pozycja - 10]->naLiniiSzacha)
                    tablicaPol[pozycja - 10]->zaznaczone = true;

                if (tablicaPol[pozycja - 6]->naLiniiSzacha)
                    tablicaPol[pozycja - 6]->zaznaczone = true;
            }
            else if (pozycja > 47)
            {
                if (tablicaPol[pozycja - 15]->naLiniiSzacha)
                    tablicaPol[pozycja - 15]->zaznaczone = true;

                if (tablicaPol[pozycja - 17]->naLiniiSzacha)
                    tablicaPol[pozycja - 17]->zaznaczone = true;

                if (tablicaPol[pozycja - 10]->naLiniiSzacha)
                    tablicaPol[pozycja - 10]->zaznaczone = true;

                if (tablicaPol[pozycja - 6]->naLiniiSzacha)
                    tablicaPol[pozycja - 6]->zaznaczone = true;

                if (tablicaPol[pozycja + 10]->naLiniiSzacha)
                    tablicaPol[pozycja + 10]->zaznaczone = true;

                if (tablicaPol[pozycja + 6]->naLiniiSzacha)
                    tablicaPol[pozycja + 6]->zaznaczone = true;
            }
            else
            {
                if (tablicaPol[pozycja - 15]->naLiniiSzacha)
                    tablicaPol[pozycja - 15]->zaznaczone = true;

                if (tablicaPol[pozycja - 17]->naLiniiSzacha)
                    tablicaPol[pozycja - 17]->zaznaczone = true;

                if (tablicaPol[pozycja - 10]->naLiniiSzacha)
                    tablicaPol[pozycja - 10]->zaznaczone = true;

                if (tablicaPol[pozycja - 6]->naLiniiSzacha)
                    tablicaPol[pozycja - 6]->zaznaczone = true;

                if (tablicaPol[pozycja + 10]->naLiniiSzacha)
                    tablicaPol[pozycja + 10]->zaznaczone = true;

                if (tablicaPol[pozycja + 6]->naLiniiSzacha)
                    tablicaPol[pozycja + 6]->zaznaczone = true;

                if (tablicaPol[pozycja + 15]->naLiniiSzacha)
                    tablicaPol[pozycja + 15]->zaznaczone = true;

                if (tablicaPol[pozycja + 17]->naLiniiSzacha)
                    tablicaPol[pozycja + 17]->zaznaczone = true;
            }
        }
        }
    }
}

void Tskoczek::zbicie(bool kto)
{
    Tszachownica::zasada50ruchow = 50;
    if (kto)
    {
        Tszachownica::materialBialego -= 3;
    }
    else
    {
        Tszachownica::materialCzarnego -= 3;
    }
}


void Tskoczek::szachowanieETC(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch)
{
    if (czyjRuch == druzyna)
    {
        if (pozycja % 8 < 1)
        {
            if (pozycja < 8)
            {
                tablicaPol[pozycja + 10]->Szachowane = true;
                tablicaPol[pozycja + 17]->Szachowane = true;


                if (tablicaPol[pozycja + 10]->zajete)
                {
                    if (tablicaPionow[pozycja + 10]->druzyna != druzyna && tablicaPionow[pozycja + 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 17]->zajete)
                {
                    if (tablicaPionow[pozycja + 17]->druzyna != druzyna && tablicaPionow[pozycja + 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (pozycja < 16)
            {
                tablicaPol[pozycja + 10]->Szachowane = true;
                tablicaPol[pozycja + 17]->Szachowane = true;
                tablicaPol[pozycja - 6]->Szachowane = true;

                if (tablicaPol[pozycja + 10]->zajete)
                {
                    if (tablicaPionow[pozycja + 10]->druzyna != druzyna && tablicaPionow[pozycja + 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 17]->zajete)
                {
                    if (tablicaPionow[pozycja + 17]->druzyna != druzyna && tablicaPionow[pozycja + 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 6]->zajete)
                {
                    if (tablicaPionow[pozycja - 6]->druzyna != druzyna && tablicaPionow[pozycja - 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (pozycja > 55)
            {
                tablicaPol[pozycja - 6]->Szachowane = true;
                tablicaPol[pozycja - 15]->Szachowane = true;

                if (tablicaPol[pozycja - 15]->zajete)
                {
                    if (tablicaPionow[pozycja - 15]->druzyna != druzyna && tablicaPionow[pozycja - 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 6]->zajete)
                {
                    if (tablicaPionow[pozycja - 6]->druzyna != druzyna && tablicaPionow[pozycja - 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (pozycja > 47)
            {
                tablicaPol[pozycja - 6]->Szachowane = true;
                tablicaPol[pozycja - 15]->Szachowane = true;
                tablicaPol[pozycja + 10]->Szachowane = true;

                if (tablicaPol[pozycja - 15]->zajete)
                {
                    if (tablicaPionow[pozycja - 15]->druzyna != druzyna && tablicaPionow[pozycja - 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 6]->zajete)
                {
                    if (tablicaPionow[pozycja - 6]->druzyna != druzyna && tablicaPionow[pozycja - 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 10]->zajete)
                {
                    if (tablicaPionow[pozycja + 10]->druzyna != druzyna && tablicaPionow[pozycja + 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else
            {
                tablicaPol[pozycja + 10]->Szachowane = true;
                tablicaPol[pozycja + 17]->Szachowane = true;
                tablicaPol[pozycja - 6]->Szachowane = true;
                tablicaPol[pozycja - 15]->Szachowane = true;

                if (tablicaPol[pozycja - 15]->zajete)
                {
                    if (tablicaPionow[pozycja - 15]->druzyna != druzyna && tablicaPionow[pozycja - 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 10]->zajete)
                {
                    if (tablicaPionow[pozycja + 10]->druzyna != druzyna && tablicaPionow[pozycja + 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 17]->zajete)
                {
                    if (tablicaPionow[pozycja + 17]->druzyna != druzyna && tablicaPionow[pozycja + 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 6]->zajete)
                {
                    if (tablicaPionow[pozycja - 6]->druzyna != druzyna && tablicaPionow[pozycja - 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
        }
        else if (pozycja % 8 < 2)
        {
            if (pozycja < 8)
            {
                tablicaPol[pozycja + 10]->Szachowane = true;
                tablicaPol[pozycja + 15]->Szachowane = true;
                tablicaPol[pozycja + 17]->Szachowane = true;


                if (tablicaPol[pozycja + 10]->zajete)
                {
                    if (tablicaPionow[pozycja + 10]->druzyna != druzyna && tablicaPionow[pozycja + 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 17]->zajete)
                {
                    if (tablicaPionow[pozycja + 17]->druzyna != druzyna && tablicaPionow[pozycja + 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 15]->zajete)
                {
                    if (tablicaPionow[pozycja + 15]->druzyna != druzyna && tablicaPionow[pozycja + 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (pozycja < 16)
            {
                tablicaPol[pozycja + 10]->Szachowane = true;
                tablicaPol[pozycja + 17]->Szachowane = true;
                tablicaPol[pozycja + 15]->Szachowane = true;
                tablicaPol[pozycja - 6]->Szachowane = true;

                if (tablicaPol[pozycja + 10]->zajete)
                {
                    if (tablicaPionow[pozycja + 10]->druzyna != druzyna && tablicaPionow[pozycja + 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 17]->zajete)
                {
                    if (tablicaPionow[pozycja + 17]->druzyna != druzyna && tablicaPionow[pozycja + 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 15]->zajete)
                {
                    if (tablicaPionow[pozycja + 15]->druzyna != druzyna && tablicaPionow[pozycja + 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 6]->zajete)
                {
                    if (tablicaPionow[pozycja - 6]->druzyna != druzyna && tablicaPionow[pozycja - 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (pozycja > 55)
            {
                tablicaPol[pozycja - 6]->Szachowane = true;
                tablicaPol[pozycja - 15]->Szachowane = true;
                tablicaPol[pozycja - 17]->Szachowane = true;

                if (tablicaPol[pozycja - 15]->zajete)
                {
                    if (tablicaPionow[pozycja - 15]->druzyna != druzyna && tablicaPionow[pozycja - 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 17]->zajete)
                {
                    if (tablicaPionow[pozycja - 17]->druzyna != druzyna && tablicaPionow[pozycja - 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 6]->zajete)
                {
                    if (tablicaPionow[pozycja - 6]->druzyna != druzyna && tablicaPionow[pozycja - 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (pozycja > 47)
            {
                tablicaPol[pozycja - 6]->Szachowane = true;
                tablicaPol[pozycja - 15]->Szachowane = true;
                tablicaPol[pozycja + 10]->Szachowane = true;
                tablicaPol[pozycja - 17]->Szachowane = true;

                if (tablicaPol[pozycja - 15]->zajete)
                {
                    if (tablicaPionow[pozycja - 15]->druzyna != druzyna && tablicaPionow[pozycja - 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 17]->zajete)
                {
                    if (tablicaPionow[pozycja - 17]->druzyna != druzyna && tablicaPionow[pozycja - 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 6]->zajete)
                {
                    if (tablicaPionow[pozycja - 6]->druzyna != druzyna && tablicaPionow[pozycja - 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 10]->zajete)
                {
                    if (tablicaPionow[pozycja + 10]->druzyna != druzyna && tablicaPionow[pozycja + 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else
            {
                tablicaPol[pozycja + 10]->Szachowane = true;
                tablicaPol[pozycja + 17]->Szachowane = true;
                tablicaPol[pozycja + 15]->Szachowane = true;
                tablicaPol[pozycja - 17]->Szachowane = true;
                tablicaPol[pozycja - 6]->Szachowane = true;
                tablicaPol[pozycja - 15]->Szachowane = true;

                if (tablicaPol[pozycja - 15]->zajete)
                {
                    if (tablicaPionow[pozycja - 15]->druzyna != druzyna && tablicaPionow[pozycja - 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 15]->zajete)
                {
                    if (tablicaPionow[pozycja + 15]->druzyna != druzyna && tablicaPionow[pozycja + 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 17]->zajete)
                {
                    if (tablicaPionow[pozycja - 17]->druzyna != druzyna && tablicaPionow[pozycja - 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 10]->zajete)
                {
                    if (tablicaPionow[pozycja + 10]->druzyna != druzyna && tablicaPionow[pozycja + 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 17]->zajete)
                {
                    if (tablicaPionow[pozycja + 17]->druzyna != druzyna && tablicaPionow[pozycja + 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 6]->zajete)
                {
                    if (tablicaPionow[pozycja - 6]->druzyna != druzyna && tablicaPionow[pozycja - 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
        }

        else if (pozycja % 8 > 6)
        {
            if (pozycja < 8)
            {
                tablicaPol[pozycja + 6]->Szachowane = true;
                tablicaPol[pozycja + 15]->Szachowane = true;

                if (tablicaPol[pozycja + 6]->zajete)
                {
                    if (tablicaPionow[pozycja + 6]->druzyna != druzyna && tablicaPionow[pozycja + 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 15]->zajete)
                {
                    if (tablicaPionow[pozycja + 15]->druzyna != druzyna && tablicaPionow[pozycja + 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (pozycja < 16)
            {
                tablicaPol[pozycja + 6]->Szachowane = true;
                tablicaPol[pozycja + 15]->Szachowane = true;
                tablicaPol[pozycja - 10]->Szachowane = true;

                if (tablicaPol[pozycja + 6]->zajete)
                {
                    if (tablicaPionow[pozycja + 6]->druzyna != druzyna && tablicaPionow[pozycja + 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 15]->zajete)
                {
                    if (tablicaPionow[pozycja + 15]->druzyna != druzyna && tablicaPionow[pozycja + 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 10]->zajete)
                {
                    if (tablicaPionow[pozycja - 10]->druzyna != druzyna && tablicaPionow[pozycja - 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (pozycja > 55)
            {
                tablicaPol[pozycja - 10]->Szachowane = true;
                tablicaPol[pozycja - 17]->Szachowane = true;

                if (tablicaPol[pozycja - 17]->zajete)
                {
                    if (tablicaPionow[pozycja - 17]->druzyna != druzyna && tablicaPionow[pozycja - 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 10]->zajete)
                {
                    if (tablicaPionow[pozycja - 10]->druzyna != druzyna && tablicaPionow[pozycja - 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (pozycja > 47)
            {
                tablicaPol[pozycja - 10]->Szachowane = true;
                tablicaPol[pozycja - 17]->Szachowane = true;
                tablicaPol[pozycja + 6]->Szachowane = true;

                if (tablicaPol[pozycja - 17]->zajete)
                {
                    if (tablicaPionow[pozycja - 17]->druzyna != druzyna && tablicaPionow[pozycja - 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 10]->zajete)
                {
                    if (tablicaPionow[pozycja - 10]->druzyna != druzyna && tablicaPionow[pozycja - 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 6]->zajete)
                {
                    if (tablicaPionow[pozycja + 6]->druzyna != druzyna && tablicaPionow[pozycja + 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else
            {
                tablicaPol[pozycja - 10]->Szachowane = true;
                tablicaPol[pozycja - 17]->Szachowane = true;
                tablicaPol[pozycja + 6]->Szachowane = true;
                tablicaPol[pozycja + 15]->Szachowane = true;

                if (tablicaPol[pozycja - 17]->zajete)
                {
                    if (tablicaPionow[pozycja - 17]->druzyna != druzyna && tablicaPionow[pozycja - 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 10]->zajete)
                {
                    if (tablicaPionow[pozycja - 10]->druzyna != druzyna && tablicaPionow[pozycja - 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 6]->zajete)
                {
                    if (tablicaPionow[pozycja + 6]->druzyna != druzyna && tablicaPionow[pozycja + 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 15]->zajete)
                {
                    if (tablicaPionow[pozycja + 15]->druzyna != druzyna && tablicaPionow[pozycja + 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
        }
        else if (pozycja % 8 > 5)
        {
            if (pozycja < 8)
            {
                tablicaPol[pozycja + 6]->Szachowane = true;
                tablicaPol[pozycja + 15]->Szachowane = true;
                tablicaPol[pozycja + 17]->Szachowane = true;

                if (tablicaPol[pozycja + 6]->zajete)
                {
                    if (tablicaPionow[pozycja + 6]->druzyna != druzyna && tablicaPionow[pozycja + 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 15]->zajete)
                {
                    if (tablicaPionow[pozycja + 15]->druzyna != druzyna && tablicaPionow[pozycja + 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 17]->zajete)
                {
                    if (tablicaPionow[pozycja + 17]->druzyna != druzyna && tablicaPionow[pozycja + 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (pozycja < 16)
            {
                tablicaPol[pozycja + 6]->Szachowane = true;
                tablicaPol[pozycja + 15]->Szachowane = true;
                tablicaPol[pozycja + 17]->Szachowane = true;
                tablicaPol[pozycja - 10]->Szachowane = true;

                if (tablicaPol[pozycja + 6]->zajete)
                {
                    if (tablicaPionow[pozycja + 6]->druzyna != druzyna && tablicaPionow[pozycja + 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 15]->zajete)
                {
                    if (tablicaPionow[pozycja + 15]->druzyna != druzyna && tablicaPionow[pozycja + 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 17]->zajete)
                {
                    if (tablicaPionow[pozycja + 17]->druzyna != druzyna && tablicaPionow[pozycja + 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 10]->zajete)
                {
                    if (tablicaPionow[pozycja - 10]->druzyna != druzyna && tablicaPionow[pozycja - 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (pozycja > 55)
            {
                tablicaPol[pozycja - 10]->Szachowane = true;
                tablicaPol[pozycja - 17]->Szachowane = true;
                tablicaPol[pozycja - 15]->Szachowane = true;

                if (tablicaPol[pozycja - 17]->zajete)
                {
                    if (tablicaPionow[pozycja - 17]->druzyna != druzyna && tablicaPionow[pozycja - 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 10]->zajete)
                {
                    if (tablicaPionow[pozycja - 10]->druzyna != druzyna && tablicaPionow[pozycja - 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 15]->zajete)
                {
                    if (tablicaPionow[pozycja - 15]->druzyna != druzyna && tablicaPionow[pozycja - 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (pozycja > 47)
            {
                tablicaPol[pozycja - 10]->Szachowane = true;
                tablicaPol[pozycja - 17]->Szachowane = true;
                tablicaPol[pozycja - 15]->Szachowane = true;
                tablicaPol[pozycja + 6]->Szachowane = true;

                if (tablicaPol[pozycja - 17]->zajete)
                {
                    if (tablicaPionow[pozycja - 17]->druzyna != druzyna && tablicaPionow[pozycja - 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 10]->zajete)
                {
                    if (tablicaPionow[pozycja - 10]->druzyna != druzyna && tablicaPionow[pozycja - 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 15]->zajete)
                {
                    if (tablicaPionow[pozycja - 15]->druzyna != druzyna && tablicaPionow[pozycja - 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 6]->zajete)
                {
                    if (tablicaPionow[pozycja + 6]->druzyna != druzyna && tablicaPionow[pozycja + 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else
            {
                tablicaPol[pozycja - 10]->Szachowane = true;
                tablicaPol[pozycja - 17]->Szachowane = true;
                tablicaPol[pozycja - 15]->Szachowane = true;
                tablicaPol[pozycja + 6]->Szachowane = true;
                tablicaPol[pozycja + 15]->Szachowane = true;
                tablicaPol[pozycja + 17]->Szachowane = true;

                if (tablicaPol[pozycja - 17]->zajete)
                {
                    if (tablicaPionow[pozycja - 17]->druzyna != druzyna && tablicaPionow[pozycja - 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 17]->zajete)
                {
                    if (tablicaPionow[pozycja + 17]->druzyna != druzyna && tablicaPionow[pozycja + 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 10]->zajete)
                {
                    if (tablicaPionow[pozycja - 10]->druzyna != druzyna && tablicaPionow[pozycja - 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 15]->zajete)
                {
                    if (tablicaPionow[pozycja - 15]->druzyna != druzyna && tablicaPionow[pozycja - 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 15]->zajete)
                {
                    if (tablicaPionow[pozycja + 15]->druzyna != druzyna && tablicaPionow[pozycja + 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 6]->zajete)
                {
                    if (tablicaPionow[pozycja + 6]->druzyna != druzyna && tablicaPionow[pozycja + 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
        }

        else // srodkowe pola X
        {
            if (pozycja < 8)
            {
                tablicaPol[pozycja + 17]->Szachowane = true;
                tablicaPol[pozycja + 15]->Szachowane = true;
                tablicaPol[pozycja + 10]->Szachowane = true;
                tablicaPol[pozycja + 6]->Szachowane = true;

                if (tablicaPol[pozycja + 10]->zajete)
                {
                    if (tablicaPionow[pozycja + 10]->druzyna != druzyna && tablicaPionow[pozycja + 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 6]->zajete)
                {
                    if (tablicaPionow[pozycja + 6]->druzyna != druzyna && tablicaPionow[pozycja + 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 15]->zajete)
                {
                    if (tablicaPionow[pozycja + 15]->druzyna != druzyna && tablicaPionow[pozycja + 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 17]->zajete)
                {
                    if (tablicaPionow[pozycja + 17]->druzyna != druzyna && tablicaPionow[pozycja + 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (pozycja < 16)
            {
                tablicaPol[pozycja + 17]->Szachowane = true;
                tablicaPol[pozycja + 15]->Szachowane = true;
                tablicaPol[pozycja + 10]->Szachowane = true;
                tablicaPol[pozycja + 6]->Szachowane = true;
                tablicaPol[pozycja - 10]->Szachowane = true;
                tablicaPol[pozycja - 6]->Szachowane = true;

                if (tablicaPol[pozycja + 10]->zajete)
                {
                    if (tablicaPionow[pozycja + 10]->druzyna != druzyna && tablicaPionow[pozycja + 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 6]->zajete)
                {
                    if (tablicaPionow[pozycja + 6]->druzyna != druzyna && tablicaPionow[pozycja + 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 15]->zajete)
                {
                    if (tablicaPionow[pozycja + 15]->druzyna != druzyna && tablicaPionow[pozycja + 15]->kimJestem == 1)
                        
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 17]->zajete)
                {
                    if (tablicaPionow[pozycja + 17]->druzyna != druzyna && tablicaPionow[pozycja + 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 10]->zajete)
                {
                    if (tablicaPionow[pozycja - 10]->druzyna != druzyna && tablicaPionow[pozycja - 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 6]->zajete)
                {
                    if (tablicaPionow[pozycja - 6]->druzyna != druzyna && tablicaPionow[pozycja - 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }

            }
            else if (pozycja > 55)
            {
                tablicaPol[pozycja - 17]->Szachowane = true;
                tablicaPol[pozycja - 15]->Szachowane = true;
                tablicaPol[pozycja - 10]->Szachowane = true;
                tablicaPol[pozycja - 6]->Szachowane = true;

                if (tablicaPol[pozycja - 10]->zajete)
                {
                    if (tablicaPionow[pozycja - 10]->druzyna != druzyna && tablicaPionow[pozycja - 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 6]->zajete)
                {
                    if (tablicaPionow[pozycja - 6]->druzyna != druzyna && tablicaPionow[pozycja - 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 15]->zajete)
                {
                    if (tablicaPionow[pozycja - 15]->druzyna != druzyna && tablicaPionow[pozycja - 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 17]->zajete)
                {
                    if (tablicaPionow[pozycja - 17]->druzyna != druzyna && tablicaPionow[pozycja - 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (pozycja > 47)
            {
                tablicaPol[pozycja - 17]->Szachowane = true;
                tablicaPol[pozycja - 15]->Szachowane = true;
                tablicaPol[pozycja - 10]->Szachowane = true;
                tablicaPol[pozycja - 6]->Szachowane = true;
                tablicaPol[pozycja + 10]->Szachowane = true;
                tablicaPol[pozycja + 6]->Szachowane = true;

                if (tablicaPol[pozycja - 10]->zajete)
                {
                    if (tablicaPionow[pozycja - 10]->druzyna != druzyna && tablicaPionow[pozycja - 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 6]->zajete)
                {
                    if (tablicaPionow[pozycja - 6]->druzyna != druzyna && tablicaPionow[pozycja - 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 15]->zajete)
                {
                    if (tablicaPionow[pozycja - 15]->druzyna != druzyna && tablicaPionow[pozycja - 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 17]->zajete)
                {
                    if (tablicaPionow[pozycja - 17]->druzyna != druzyna && tablicaPionow[pozycja - 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 10]->zajete)
                {
                    if (tablicaPionow[pozycja + 10]->druzyna != druzyna && tablicaPionow[pozycja + 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 6]->zajete)
                {
                    if (tablicaPionow[pozycja + 6]->druzyna != druzyna && tablicaPionow[pozycja + 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else
            {
                tablicaPol[pozycja - 10]->Szachowane = true;
                tablicaPol[pozycja - 6]->Szachowane = true;
                tablicaPol[pozycja + 10]->Szachowane = true;
                tablicaPol[pozycja + 6]->Szachowane = true;
                tablicaPol[pozycja - 17]->Szachowane = true;
                tablicaPol[pozycja + 17]->Szachowane = true;
                tablicaPol[pozycja - 15]->Szachowane = true;
                tablicaPol[pozycja + 15]->Szachowane = true;

                if (tablicaPol[pozycja + 10]->zajete)
                {
                    if (tablicaPionow[pozycja + 10]->druzyna != druzyna && tablicaPionow[pozycja + 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 6]->zajete)
                {
                    if (tablicaPionow[pozycja + 6]->druzyna != druzyna && tablicaPionow[pozycja + 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 10]->zajete)
                {
                    if (tablicaPionow[pozycja - 10]->druzyna != druzyna && tablicaPionow[pozycja - 10]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 6]->zajete)
                {
                    if (tablicaPionow[pozycja - 6]->druzyna != druzyna && tablicaPionow[pozycja - 6]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 17]->zajete)
                {
                    if (tablicaPionow[pozycja - 17]->druzyna != druzyna && tablicaPionow[pozycja - 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja - 15]->zajete)
                {
                    if (tablicaPionow[pozycja - 15]->druzyna != druzyna && tablicaPionow[pozycja - 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 15]->zajete)
                {
                    if (tablicaPionow[pozycja + 15]->druzyna != druzyna && tablicaPionow[pozycja + 15]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
                if (tablicaPol[pozycja + 17]->zajete)
                {
                    if (tablicaPionow[pozycja + 17]->druzyna != druzyna && tablicaPionow[pozycja + 17]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
        }
    }
}