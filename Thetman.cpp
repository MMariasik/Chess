#include"Thetman.h"

#include"Tszachownica.h"

#include<vector>

// jezeli napotka sojuszniczego pionka to zwróci fa³sz i zakoñczy pêtlê
bool Thetman::wsparcieSzachowania(Tpole** pola, Tpion** piony, int pozycja, bool ruch)
{
    if (pola[pozycja]->zajete)
    {
        if (piony[pozycja]->druzyna == ruch)
            return false;
        else return true;
    }
    else return true;
}


Thetman::~Thetman()
{
    Tpion::~Tpion();
}

Thetman::Thetman(Tkoordynaty poz, int numer, bool team, int kto, const char* pathDoTexturki, const char* pathDoDzwiekuRuchu, const char* pathDoDzwiekuBicia) 
    : Tpion(poz, numer, team, kto, pathDoTexturki, pathDoDzwiekuRuchu, pathDoDzwiekuBicia)
{}

void Thetman::rysujSie()
{
    DrawTexture(tekstura, pozycja.x, pozycja.y, WHITE);
}

void Thetman::zaznaczanie(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, jestSzach* jestszach, bool druzyna)
{
    if (pozycja == 0)               // lewy górny róg
    {
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, +8, false, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, +1, true, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, +9, jestszach);
    }
    else if (pozycja == 7)          // prawy górny róg
    {
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, +8, false, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, -1, true, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, +7, jestszach);
    }
    else if (pozycja == 56)         // lewy dolny róg
    {
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, -8, false, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, +1, true, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, -7, jestszach);
    }
    else if (pozycja == 63)         // prawy dolny róg
    {
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, -8, false, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, -1, true, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, -9, jestszach);
    }
    else if (!(pozycja % 8))        // lewa granica
    {
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, +8, false, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, -8, false, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, +1, true, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, -7, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, +9, jestszach);
    }
    else if (!((pozycja + 1) % 8))  // prawa granica
    {
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, +8, false, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, -8, false, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, -1, true, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, -9, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, +7, jestszach);
    }
    else if (pozycja < 8)           // górna granica
    {
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, +8, false, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, +1, true, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, -1, true, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, +7, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, +9, jestszach);
    }
    else if (pozycja > 55)          // dolna granica
    {
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, +1, true, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, -8, false, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, -1, true, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, -9, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, -7, jestszach);
    }

    // koniec wyj¹tków

    else
    {
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, -8, false, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, -1, true, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, +1, true, jestszach);
        doZaznaczaniaW(tablicaPol, tablicaPionow, pozycja, druzyna, +8, false, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, -9, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, -7, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, +7, jestszach);
        doZaznaczaniaG(tablicaPol, tablicaPionow, pozycja, druzyna, +9, jestszach);
    }
}

void Thetman::zbicie(bool kto)
{
    Tszachownica::zasada50ruchow = 50;
    if (kto)
    {
        Tszachownica::materialBialego -= 9;
    }
    else
    {
        Tszachownica::materialCzarnego -= 9;
    }
}


void Thetman::doZaznaczaniaW(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch, int wKtoraStrone, bool czyNaBoki, jestSzach* jestszach)
{
    if (!tablicaPionow[pozycja]->jestemZwiazany)
    {
        do
        {
            pozycja += wKtoraStrone;

            if (!jestszach->szach)
            {
                if (!tablicaPol[pozycja]->zajete)
                {
                    tablicaPol[pozycja]->zaznaczone = true;
                }
                else if (tablicaPionow[pozycja]->druzyna != czyjRuch)
                {
                    tablicaPol[pozycja]->zaznaczone = true;
                    return;
                }
                else
                {
                    return;
                }
            }
            else if (jestszach->iloscSzachujacychPionkow < 2)
            {
                if (!tablicaPol[pozycja]->zajete)
                {
                    if (tablicaPol[pozycja]->naLiniiSzacha)
                        tablicaPol[pozycja]->zaznaczone = true;
                }
                else if (tablicaPionow[pozycja]->druzyna != czyjRuch && tablicaPol[pozycja]->naLiniiSzacha)
                {
                    tablicaPol[pozycja]->zaznaczone = true;
                }
                else return;

            }

        } while ((czyNaBoki ? ((pozycja % 8 > 0) && (pozycja % 8 < 7)) : ((pozycja > 7) && (pozycja < 56))));
    }
    else
    {
        int pozS{ pozycja };

        do
        {
            pozycja += wKtoraStrone;
            if (!jestszach->szach)
            {
                if (tablicaPol[pozycja]->naLiniiZwiazania.poleNaLiniiZwiazania && tablicaPol[pozycja]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozS]->naKtorymPoluStoje)
                {
                    tablicaPol[pozycja]->zaznaczone = true;
                }
            }

        } while ((czyNaBoki ? ((pozycja % 8 > 0) && (pozycja % 8 < 7)) : ((pozycja > 7) && (pozycja < 56))));
    }

}
void Thetman::doZaznaczaniaG(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch, int wKtoraStrone, jestSzach* jestszach)
{
    if (!tablicaPionow[pozycja]->jestemZwiazany)
    {
        do
        {
            pozycja += wKtoraStrone;
            if (!jestszach->szach)
            {
                if (!tablicaPol[pozycja]->zajete)
                {
                    tablicaPol[pozycja]->zaznaczone = true;
                }
                else if (tablicaPionow[pozycja]->druzyna != czyjRuch)
                {
                    tablicaPol[pozycja]->zaznaczone = true;
                    return;
                }
                else return;
            }
            else if (jestszach->iloscSzachujacychPionkow < 2)
            {
                if (!tablicaPol[pozycja]->zajete)
                {
                    if (tablicaPol[pozycja]->naLiniiSzacha)
                        tablicaPol[pozycja]->zaznaczone = true;
                }
                else if (tablicaPionow[pozycja]->druzyna != czyjRuch && tablicaPol[pozycja]->naLiniiSzacha)
                {
                    tablicaPol[pozycja]->zaznaczone = true;
                }
                else return;
            }


        } while ((pozycja % 8 > 0) && (pozycja > 7) && (pozycja % 8 < 7) && (pozycja < 56));
    }
    else
    {
        int pozS{ pozycja };
        do
        {
            pozycja += wKtoraStrone;
            if (!jestszach->szach)
            {
                if (tablicaPol[pozycja]->naLiniiZwiazania.poleNaLiniiZwiazania && tablicaPol[pozycja]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozS]->naKtorymPoluStoje)
                {
                    tablicaPol[pozycja]->zaznaczone = true;
                }
            }


        } while ((pozycja % 8 > 0) && (pozycja > 7) && (pozycja % 8 < 7) && (pozycja < 56));
    }
}

void Thetman::szachowanieETC(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch)
{
    if (czyjRuch == druzyna)
    {
        if (pozycja == 0)               // lewy górny róg
        {
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, +8, false);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, +1, true);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, +9);
        }
        else if (pozycja == 7)          // prawy górny róg
        {
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, +8, false);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, -1, true);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, +7);
        }
        else if (pozycja == 56)         // lewy dolny róg
        {
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, -8, false);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, +1, true);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, -7);
        }
        else if (pozycja == 63)         // prawy dolny róg
        {
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, -8, false);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, -1, true);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, -9);
        }
        else if (!(pozycja % 8))        // lewa granica
        {
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, +8, false);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, -8, false);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, +1, true);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, -7);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, +9);
        }
        else if (!((pozycja + 1) % 8))  // prawa granica
        {
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, +8, false);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, -8, false);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, -1, true);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, -9);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, +7);
        }
        else if (pozycja < 8)           // górna granica
        {
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, +8, false);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, +1, true);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, -1, true);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, +7);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, +9);
        }
        else if (pozycja > 55)          // dolna granica
        {
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, +1, true);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, -8, false);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, -1, true);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, -9);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, -7);
        }

        // koniec wyj¹tków

        else
        {
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, -8, false);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, -1, true);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, +1, true);
            szachowanieW(tablicaPol, tablicaPionow, pozycja, czyjRuch, +8, false);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, -9);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, -7);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, +7);
            szachowanieG(tablicaPol, tablicaPionow, pozycja, czyjRuch, +9);
        }
    }
}

void Thetman::szachowanieG(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch, int wKtoraStrone)
{
    const int pozycjaPoczatkowa{ pozycja };
    std::vector<int>numeryPol;
    bool mamyPotencjalneZwiazanie{ false };
    bool mamySzacha{ false };
    int pozycjaPotencjalnieZwiazanegoPionka;

    do
    {
        pozycja += wKtoraStrone;



        if (tablicaPol[pozycja]->zajete)
        {
            if (tablicaPionow[pozycja]->druzyna != czyjRuch)
            {
                if (tablicaPionow[pozycja]->kimJestem == 1)
                {
                    if (mamyPotencjalneZwiazanie)
                    {
                        numeryPol.push_back(pozycjaPoczatkowa);
                        for (auto pole : numeryPol)
                        {
                            tablicaPol[pole]->naLiniiZwiazania.poleNaLiniiZwiazania = true;
                            tablicaPol[pole]->naLiniiZwiazania.numerZwiazanegoPionka = pozycjaPotencjalnieZwiazanegoPionka;
                        }

                        tablicaPionow[pozycjaPotencjalnieZwiazanegoPionka]->jestemZwiazany = true;

                        break;
                    }
                    else mamySzacha = true;
                }
                else // spotykam pionka przeciwnego
                {
                    if (mamySzacha)
                    {
                        tablicaPol[pozycja]->Szachowane = true;

                        break;
                    }
                    else { mamyPotencjalneZwiazanie = true; pozycjaPotencjalnieZwiazanegoPionka = pozycja; }
                }
            }
        }

        if (mamyPotencjalneZwiazanie)
        {
            //tablicaPol[pozycja]->Szachowane = true;
            numeryPol.push_back(pozycja);
        }
        else if (mamySzacha)
        {
            tablicaPol[pozycja]->Szachowane = true;
            //numeryPol.push_back(pozycja);
        }
        else
        {
            tablicaPol[pozycja]->Szachowane = true;
            numeryPol.push_back(pozycja);
        }


    } while ((pozycja % 8 > 0) && (pozycja > 7) && (pozycja % 8 < 7) && (pozycja < 56) && wsparcieSzachowania(tablicaPol, tablicaPionow, pozycja, czyjRuch));

    if (mamySzacha)
    {
        Tszachownica::wlaczSzacha();

        numeryPol.push_back(pozycjaPoczatkowa);

        for (auto pole : numeryPol)
        {
            tablicaPol[pole]->naLiniiSzacha = true;
        }
    }
}

void Thetman::szachowanieW(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch, int wKtoraStrone, bool czyNaBoki)
{
    const int pozycjaPoczatkowa{ pozycja };
    std::vector<int>numeryPol;
    bool mamyPotencjalneZwiazanie{ false };
    bool mamySzacha{ false };
    int pozycjaPotencjalnieZwiazanegoPionka;

    do
    {
        pozycja += wKtoraStrone;

        if (tablicaPol[pozycja]->zajete)
        {
            if (tablicaPionow[pozycja]->druzyna != czyjRuch)
            {
                if (tablicaPionow[pozycja]->kimJestem == 1)
                {
                    if (mamyPotencjalneZwiazanie)
                    {
                        numeryPol.push_back(pozycjaPoczatkowa);
                        for (auto pole : numeryPol)
                        {
                            tablicaPol[pole]->naLiniiZwiazania.poleNaLiniiZwiazania = true;
                            tablicaPol[pole]->naLiniiZwiazania.numerZwiazanegoPionka = pozycjaPotencjalnieZwiazanegoPionka;
                        }

                        tablicaPionow[pozycjaPotencjalnieZwiazanegoPionka]->jestemZwiazany = true;

                        break;
                    }
                    else mamySzacha = true;
                }
                else // spotykam pionka przeciwnego
                {
                    if (mamyPotencjalneZwiazanie) { break; }
                    if (mamySzacha)
                    {
                        tablicaPol[pozycja]->Szachowane = true;

                        break;
                    }
                    else { tablicaPol[pozycja]->Szachowane = true; mamyPotencjalneZwiazanie = true; pozycjaPotencjalnieZwiazanegoPionka = pozycja; }
                }
            }
        }

        if (mamyPotencjalneZwiazanie)
        {
            //tablicaPol[pozycja]->Szachowane = true;
            numeryPol.push_back(pozycja);
        }
        else if (mamySzacha)
        {
            tablicaPol[pozycja]->Szachowane = true;
            //numeryPol.push_back(pozycja);
        }
        else
        {
            tablicaPol[pozycja]->Szachowane = true;
            numeryPol.push_back(pozycja);
        }


    } while ((czyNaBoki ? ((pozycja % 8 > 0) && (pozycja % 8 < 7)) : ((pozycja > 7) && (pozycja < 56))) && wsparcieSzachowania(tablicaPol, tablicaPionow, pozycja, czyjRuch));

    if (mamySzacha)
    {
        Tszachownica::wlaczSzacha();
        numeryPol.push_back(pozycjaPoczatkowa);

        for (auto pole : numeryPol)
        {
            tablicaPol[pole]->naLiniiSzacha = true;
        }
    }
}





