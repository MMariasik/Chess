#include"TzwyklyPionek.h"

#include"Tszachownica.h"


TzwyklyPionek::~TzwyklyPionek()
{
    Tpion::~Tpion();
}

TzwyklyPionek::TzwyklyPionek(Tkoordynaty poz, int numer, bool team, int kto, const char* pathDoTexturki, const char* pathDoDzwiekuRuchu, const char* pathDoDzwiekuBicia) 
    : Tpion(poz, numer, team, kto, pathDoTexturki, pathDoDzwiekuRuchu, pathDoDzwiekuBicia)
{}

void TzwyklyPionek::rysujSie()
{
    DrawTexture(tekstura, pozycja.x, pozycja.y, WHITE);
}

void TzwyklyPionek::zaznaczanie(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, jestSzach* jestszach, bool druzyna)
{
    if (pozycja > 7 && pozycja < 56)
    {

        if (!tablicaPionow[pozycja]->jestemZwiazany)
        {
            if (druzyna) // true -> czarni
            {
                if (!jestszach->szach)
                {
                    if (!(pozycja % 8))
                    {
                        if (tablicaPol[pozycja + 9]->zajete)
                            if (tablicaPionow[pozycja + 9]->druzyna != druzyna)
                                tablicaPol[pozycja + 9]->zaznaczone = true;
                        if (tablicaPol[pozycja + 9]->czyEnPassant)
                            tablicaPol[pozycja + 9]->zaznaczone = true;
                    }
                    else if (!((pozycja + 1) % 8))
                    {
                        if (tablicaPol[pozycja + 7]->zajete)
                            if (tablicaPionow[pozycja + 7]->druzyna != druzyna)
                                tablicaPol[pozycja + 7]->zaznaczone = true;
                        if (tablicaPol[pozycja + 7]->czyEnPassant)
                            tablicaPol[pozycja + 7]->zaznaczone = true;
                    }
                    else
                    {
                        if (tablicaPol[pozycja + 7]->zajete)
                            if (tablicaPionow[pozycja + 7]->druzyna != druzyna)
                                tablicaPol[pozycja + 7]->zaznaczone = true;
                        if (tablicaPol[pozycja + 7]->czyEnPassant)
                            tablicaPol[pozycja + 7]->zaznaczone = true;

                        if (tablicaPol[pozycja + 9]->zajete)
                            if (tablicaPionow[pozycja + 9]->druzyna != druzyna)
                                tablicaPol[pozycja + 9]->zaznaczone = true;
                        if (tablicaPol[pozycja + 9]->czyEnPassant)
                            tablicaPol[pozycja + 9]->zaznaczone = true;
                    }

                    if (!tablicaPol[pozycja + 8]->zajete) tablicaPol[pozycja + 8]->zaznaczone = true;

                    if (pozycja > 7 && pozycja < 16)
                    {
                        if ((!tablicaPol[pozycja + 16]->zajete) && (!tablicaPol[pozycja + 8]->zajete))
                            tablicaPol[pozycja + 16]->zaznaczone = true;
                    }
                }
                else if(jestszach->iloscSzachujacychPionkow < 2)// mamy szacha
                {
                    if (!(pozycja % 8))
                    {
                        if (tablicaPol[pozycja + 9]->naLiniiSzacha && tablicaPol[pozycja + 9]->zajete)
                            if (tablicaPionow[pozycja + 9]->druzyna != druzyna)
                                tablicaPol[pozycja + 9]->zaznaczone = true;
                    }
                    else if (!((pozycja + 1) % 8))
                    {
                        if (tablicaPol[pozycja + 7]->naLiniiSzacha && tablicaPol[pozycja + 7]->zajete)
                            if (tablicaPionow[pozycja + 7]->druzyna != druzyna)
                                tablicaPol[pozycja + 7]->zaznaczone = true;
                    }
                    else
                    {
                        if (tablicaPol[pozycja + 7]->naLiniiSzacha && tablicaPol[pozycja + 7]->zajete)
                            if (tablicaPionow[pozycja + 7]->druzyna != druzyna)
                                tablicaPol[pozycja + 7]->zaznaczone = true;

                        if (tablicaPol[pozycja + 9]->naLiniiSzacha && tablicaPol[pozycja + 9]->zajete)
                            if (tablicaPionow[pozycja + 9]->druzyna != druzyna)
                                tablicaPol[pozycja + 9]->zaznaczone = true;
                    }

                    if (tablicaPol[pozycja + 8]->naLiniiSzacha && !tablicaPol[pozycja + 8]->zajete) tablicaPol[pozycja + 8]->zaznaczone = true;

                    if (pozycja > 7 && pozycja < 16)
                    {
                        if ((tablicaPol[pozycja + 16]->naLiniiSzacha) && (!tablicaPol[pozycja + 8]->zajete) && (!tablicaPol[pozycja + 16]->zajete))
                            tablicaPol[pozycja + 16]->zaznaczone = true;
                    }
                }

            }
            else // false -> biali
            {
                if (!jestszach->szach)
                {
                    if (!(pozycja % 8))
                    {
                        if (tablicaPol[pozycja - 7]->zajete)
                            if (tablicaPionow[pozycja - 7]->druzyna != druzyna)
                                tablicaPol[pozycja - 7]->zaznaczone = true;
                        if (tablicaPol[pozycja - 7]->czyEnPassant)
                            tablicaPol[pozycja - 7]->zaznaczone = true;
                    }
                    else if (!((pozycja + 1) % 8))
                    {
                        if (tablicaPol[pozycja - 9]->zajete)
                            if (tablicaPionow[pozycja - 9]->druzyna != druzyna)
                                tablicaPol[pozycja - 9]->zaznaczone = true;
                        if (tablicaPol[pozycja - 9]->czyEnPassant)
                            tablicaPol[pozycja - 9]->zaznaczone = true;
                    }
                    else
                    {
                        if (tablicaPol[pozycja - 7]->zajete)
                            if (tablicaPionow[pozycja - 7]->druzyna != druzyna)
                                tablicaPol[pozycja - 7]->zaznaczone = true;
                        if (tablicaPol[pozycja - 7]->czyEnPassant)
                            tablicaPol[pozycja - 7]->zaznaczone = true;

                        if (tablicaPol[pozycja - 9]->zajete)
                            if (tablicaPionow[pozycja - 9]->druzyna != druzyna)
                                tablicaPol[pozycja - 9]->zaznaczone = true;
                        if (tablicaPol[pozycja - 9]->czyEnPassant)
                            tablicaPol[pozycja - 9]->zaznaczone = true;
                    }

                    if (!tablicaPol[pozycja - 8]->zajete) tablicaPol[pozycja - 8]->zaznaczone = true;

                    if (pozycja > 47 && pozycja < 56)
                    {
                        if ((!tablicaPol[pozycja - 8]->zajete) && (!tablicaPol[pozycja - 16]->zajete))
                            tablicaPol[pozycja - 16]->zaznaczone = true;
                    }
                }
                else if (jestszach->iloscSzachujacychPionkow < 2)// mamy szacha
                {
                    if (!(pozycja % 8))
                    {
                        if (tablicaPol[pozycja - 7]->naLiniiSzacha && tablicaPol[pozycja - 7]->zajete)
                            if (tablicaPionow[pozycja - 7]->druzyna != druzyna)
                                tablicaPol[pozycja - 7]->zaznaczone = true;
                    }
                    else if (!((pozycja + 1) % 8))
                    {
                        if (tablicaPol[pozycja - 9]->naLiniiSzacha && tablicaPol[pozycja + 9]->zajete)
                            if (tablicaPionow[pozycja - 9]->druzyna != druzyna)
                                tablicaPol[pozycja - 9]->zaznaczone = true;
                    }
                    else
                    {
                        if (tablicaPol[pozycja - 7]->naLiniiSzacha && tablicaPol[pozycja - 7]->zajete)
                            if (tablicaPionow[pozycja - 7]->druzyna != druzyna)
                                tablicaPol[pozycja - 7]->zaznaczone = true;

                        if (tablicaPol[pozycja - 9]->naLiniiSzacha && tablicaPol[pozycja - 9]->zajete)
                            if (tablicaPionow[pozycja - 9]->druzyna != druzyna)
                                tablicaPol[pozycja - 9]->zaznaczone = true;
                    }

                    if (tablicaPol[pozycja - 8]->naLiniiSzacha && !tablicaPol[pozycja - 8]->zajete) tablicaPol[pozycja - 8]->zaznaczone = true;

                    if (pozycja > 47 && pozycja < 56)
                    {
                        if ((tablicaPol[pozycja - 16]->naLiniiSzacha) && (!tablicaPol[pozycja - 8]->zajete) && (!tablicaPol[pozycja - 16]->zajete))
                            tablicaPol[pozycja - 16]->zaznaczone = true;
                    }
                }
            }
        }
        else  // zwiazany pionek  
        {
            if (druzyna)
            {
                if (!jestszach->szach)
                {
                    if (!(pozycja % 8))
                    {
                        if (tablicaPol[pozycja + 9]->naLiniiZwiazania.poleNaLiniiZwiazania && 
                            tablicaPol[pozycja + 9]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje
                            && tablicaPol[pozycja + 9]->czyEnPassant)
                                tablicaPol[pozycja + 9]->zaznaczone = true; 

                        if (tablicaPol[pozycja + 9]->zajete && (tablicaPol[pozycja + 9]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                                tablicaPol[pozycja + 9]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje)) tablicaPol[pozycja + 9]->zaznaczone = true;
                    }
                    else if (!((pozycja + 1) % 8))
                    {
                        if (tablicaPol[pozycja + 7]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                            tablicaPol[pozycja + 7]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje
                            && tablicaPol[pozycja + 7]->czyEnPassant)
                                tablicaPol[pozycja + 7]->zaznaczone = true;

                        if (tablicaPol[pozycja + 7]->zajete && (tablicaPol[pozycja + 7]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                                tablicaPol[pozycja + 7]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje)) tablicaPol[pozycja + 7]->zaznaczone = true;
                    }
                    else
                    {
                        if (tablicaPol[pozycja + 9]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                            tablicaPol[pozycja + 9]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje
                            && tablicaPol[pozycja + 9]->czyEnPassant)
                                tablicaPol[pozycja + 9]->zaznaczone = true;

                        if (tablicaPol[pozycja + 9]->zajete && (tablicaPol[pozycja + 9]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                                tablicaPol[pozycja + 9]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje)) tablicaPol[pozycja + 9]->zaznaczone = true;

                        if (tablicaPol[pozycja + 7]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                            tablicaPol[pozycja + 7]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje
                            && tablicaPol[pozycja + 7]->czyEnPassant)
                                tablicaPol[pozycja + 7]->zaznaczone = true;
                    
                        if (tablicaPol[pozycja + 7]->zajete && (tablicaPol[pozycja + 7]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                                tablicaPol[pozycja + 7]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje)) tablicaPol[pozycja + 7]->zaznaczone = true;
                    }


                    if (tablicaPol[pozycja + 8]->naLiniiZwiazania.poleNaLiniiZwiazania && tablicaPol[pozycja + 8]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje && !tablicaPol[pozycja + 8]->zajete)
                        tablicaPol[pozycja + 8]->zaznaczone = true;

                    if (pozycja > 7 && pozycja < 16)
                    {
                        if (tablicaPol[pozycja + 16]->naLiniiZwiazania.poleNaLiniiZwiazania && tablicaPol[pozycja + 16]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje
                            && !tablicaPol[pozycja + 8]->zajete && !tablicaPol[pozycja + 16]->zajete)
                            tablicaPol[pozycja + 16]->zaznaczone = true;
                    }
                }
            }

            else
            {
                if (!jestszach->szach)
                {
                    if (!(pozycja % 8))
                    {
                        if (tablicaPol[pozycja - 9]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                            tablicaPol[pozycja - 9]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje
                            && tablicaPol[pozycja - 9]->czyEnPassant)
                            tablicaPol[pozycja - 9]->zaznaczone = true;

                        if (tablicaPol[pozycja - 9]->zajete && (tablicaPol[pozycja - 9]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                            tablicaPol[pozycja - 9]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje)) tablicaPol[pozycja - 9]->zaznaczone = true;
                    }
                    else if (!((pozycja + 1) % 8))
                    {
                        if (tablicaPol[pozycja - 7]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                            tablicaPol[pozycja - 7]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje
                            && tablicaPol[pozycja - 7]->czyEnPassant)
                            tablicaPol[pozycja - 7]->zaznaczone = true;

                        if (tablicaPol[pozycja - 7]->zajete && (tablicaPol[pozycja - 7]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                            tablicaPol[pozycja - 7]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje)) tablicaPol[pozycja - 7]->zaznaczone = true;
                    }
                    else
                    {
                        if (tablicaPol[pozycja - 9]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                            tablicaPol[pozycja - 9]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje
                            && tablicaPol[pozycja - 9]->czyEnPassant)
                            tablicaPol[pozycja - 9]->zaznaczone = true;

                        if (tablicaPol[pozycja - 9]->zajete && (tablicaPol[pozycja - 9]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                            tablicaPol[pozycja - 9]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje)) tablicaPol[pozycja - 9]->zaznaczone = true;

                        if (tablicaPol[pozycja - 7]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                            tablicaPol[pozycja - 7]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje
                            && tablicaPol[pozycja - 7]->czyEnPassant)
                            tablicaPol[pozycja - 7]->zaznaczone = true;

                        if (tablicaPol[pozycja - 7]->zajete && (tablicaPol[pozycja - 7]->naLiniiZwiazania.poleNaLiniiZwiazania &&
                            tablicaPol[pozycja - 7]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje)) tablicaPol[pozycja - 7]->zaznaczone = true;
                    }

                    if (tablicaPol[pozycja - 8]->naLiniiZwiazania.poleNaLiniiZwiazania && tablicaPol[pozycja - 8]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje && !tablicaPol[pozycja - 8]->zajete)
                        tablicaPol[pozycja - 8]->zaznaczone = true;

                    if (pozycja > 47 && pozycja < 56)
                    {
                        if (tablicaPol[pozycja - 16]->naLiniiZwiazania.poleNaLiniiZwiazania && tablicaPol[pozycja - 16]->naLiniiZwiazania.numerZwiazanegoPionka == tablicaPionow[pozycja]->naKtorymPoluStoje
                            && !tablicaPol[pozycja - 8]->zajete && !tablicaPol[pozycja - 16]->zajete)
                            tablicaPol[pozycja - 16]->zaznaczone = true;
                    }
                }          
            }
        }
    }
}

void TzwyklyPionek::zbicie(bool kto)
{
    Tszachownica::zasada50ruchow = 50;
    if (kto)
    {
        Tszachownica::materialBialego -= 1;
    }
    else
    {
        Tszachownica::materialCzarnego -= 1;
    }
}


void TzwyklyPionek::szachowanieETC(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch)
{
    if (druzyna == czyjRuch && pozycja > 7 && pozycja < 56)
    {
        if (czyjRuch) // true -> czarni
        {
            if (!(pozycja % 8))
            {
                tablicaPol[pozycja + 9]->Szachowane = true;

                if (tablicaPol[pozycja + 9]->zajete)
                {
                    if (tablicaPionow[pozycja + 9]->druzyna != druzyna && tablicaPionow[pozycja + 9]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        if (tablicaPol[pozycja - 8]->czyEnPassant) tablicaPol[pozycja - 8]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (!((pozycja + 1) % 8))
            {
                tablicaPol[pozycja + 7]->Szachowane = true;

                if (tablicaPol[pozycja + 7]->zajete)
                {
                    if (tablicaPionow[pozycja + 7]->druzyna != druzyna && tablicaPionow[pozycja + 7]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        if (tablicaPol[pozycja - 8]->czyEnPassant) tablicaPol[pozycja - 8]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else
            {
                tablicaPol[pozycja + 7]->Szachowane = true;

                if (tablicaPol[pozycja + 7]->zajete)
                {
                    if (tablicaPionow[pozycja + 7]->druzyna != druzyna && tablicaPionow[pozycja + 7]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        if (tablicaPol[pozycja - 8]->czyEnPassant) tablicaPol[pozycja - 8]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }

                tablicaPol[pozycja + 9]->Szachowane = true;

                if (tablicaPol[pozycja + 9]->zajete)
                {
                    if (tablicaPionow[pozycja + 9]->druzyna != druzyna && tablicaPionow[pozycja + 9]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        if (tablicaPol[pozycja - 8]->czyEnPassant) tablicaPol[pozycja - 8]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
        }
        else // false -> biali
        {
            if (!(pozycja % 8))
            {
                tablicaPol[pozycja - 7]->Szachowane = true;

                if (tablicaPol[pozycja - 7]->zajete)
                {
                    if (tablicaPionow[pozycja - 7]->druzyna != druzyna && tablicaPionow[pozycja - 7]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        if (tablicaPol[pozycja + 8]->czyEnPassant) tablicaPol[pozycja + 8]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else if (!((pozycja + 1) % 8))
            {
                tablicaPol[pozycja - 9]->Szachowane = true;

                if (tablicaPol[pozycja - 9]->zajete)
                {
                    if (tablicaPionow[pozycja - 9]->druzyna != druzyna && tablicaPionow[pozycja - 9]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        if (tablicaPol[pozycja + 8]->czyEnPassant) tablicaPol[pozycja + 8]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
            else
            {
                tablicaPol[pozycja - 9]->Szachowane = true;

                if (tablicaPol[pozycja - 9]->zajete)
                {
                    if (tablicaPionow[pozycja - 9]->druzyna != druzyna && tablicaPionow[pozycja - 9]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        if (tablicaPol[pozycja + 8]->czyEnPassant) tablicaPol[pozycja + 8]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }

                tablicaPol[pozycja - 7]->Szachowane = true;

                if (tablicaPol[pozycja - 7]->zajete)
                {
                    if (tablicaPionow[pozycja - 7]->druzyna != druzyna && tablicaPionow[pozycja - 7]->kimJestem == 1)
                    {
                        tablicaPol[pozycja]->naLiniiSzacha = true;
                        if (tablicaPol[pozycja + 8]->czyEnPassant) tablicaPol[pozycja + 8]->naLiniiSzacha = true;
                        Tszachownica::wlaczSzacha();
                    }
                }
            }
        }
    }
}