#include"Tkrol.h"

#include "Tszachownica.h"



Tkrol::~Tkrol()
{
    UnloadSound(dzwiekSzacha);
    Tpion::~Tpion();
}

Tkrol::Tkrol(Tkoordynaty poz, int numer, bool team, int kto, const char* pathDoTexturki, const char* pathDoDzwiekuRuchu, const char* pathDoDzwiekuBicia, const char* pathDzwiekuSzacha) 
    : Tpion(poz, numer, team, kto, pathDoTexturki, pathDoDzwiekuRuchu, pathDoDzwiekuBicia)
{
    dzwiekSzacha = LoadSound(pathDzwiekuSzacha);
}

void Tkrol::rysujSie()
{
    DrawTexture(tekstura, pozycja.x, pozycja.y, WHITE);
}

void Tkrol::zaznaczanie(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, jestSzach* jestszach, bool druzyna)
{
    roszada(tablicaPionow, tablicaPol, pozycja, jestszach);


        if (pozycja == 0)               // lewy górny róg
        {
            if (!tablicaPol[pozycja + 1]->Szachowane) 
            { 
                if (!tablicaPol[pozycja + 1]->zajete) tablicaPol[pozycja + 1]->zaznaczone = true;
                else if(tablicaPionow[pozycja + 1]->druzyna != druzyna) tablicaPol[pozycja + 1]->zaznaczone = true;    
            }
            if (!tablicaPol[pozycja + 9]->Szachowane)
            {
                if (!tablicaPol[pozycja + 9]->zajete) tablicaPol[pozycja + 9]->zaznaczone = true;
                else if (tablicaPionow[pozycja + 9]->druzyna != druzyna) tablicaPol[pozycja + 9]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja + 8]->Szachowane)
            {
                if (!tablicaPol[pozycja + 8]->zajete) tablicaPol[pozycja + 8]->zaznaczone = true;
                else if (tablicaPionow[pozycja + 8]->druzyna != druzyna) tablicaPol[pozycja + 8]->zaznaczone = true;
            }
        }
        else if (pozycja == 7)          // prawy górny róg
        {
            if (!tablicaPol[pozycja - 1]->Szachowane)
            {
                if (!tablicaPol[pozycja - 1]->zajete) tablicaPol[pozycja - 1]->zaznaczone = true;
                else if (tablicaPionow[pozycja - 1]->druzyna != druzyna) tablicaPol[pozycja - 1]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja + 7]->Szachowane)
            {
                if (!tablicaPol[pozycja + 7]->zajete) tablicaPol[pozycja + 7]->zaznaczone = true;
                else if (tablicaPionow[pozycja + 7]->druzyna != druzyna) tablicaPol[pozycja + 7]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja + 8]->Szachowane)
            {
                if (!tablicaPol[pozycja + 8]->zajete) tablicaPol[pozycja + 8]->zaznaczone = true;
                else if (tablicaPionow[pozycja + 8]->druzyna != druzyna) tablicaPol[pozycja + 8]->zaznaczone = true;
            }
        }
        else if (pozycja == 56)         // lewy dolny róg
        {
            if (!tablicaPol[pozycja - 7]->Szachowane)
            {
                if (!tablicaPol[pozycja - 7]->zajete) tablicaPol[pozycja - 7]->zaznaczone = true;
                else if (tablicaPionow[pozycja - 7]->druzyna != druzyna) tablicaPol[pozycja - 7]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja - 8]->Szachowane)
            {
                if (!tablicaPol[pozycja - 8]->zajete) tablicaPol[pozycja - 8]->zaznaczone = true;
                else if (tablicaPionow[pozycja - 8]->druzyna != druzyna) tablicaPol[pozycja - 8]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja + 1]->Szachowane)
            {
                if (!tablicaPol[pozycja + 1]->zajete) tablicaPol[pozycja + 1]->zaznaczone = true;
                else if (tablicaPionow[pozycja + 1]->druzyna != druzyna) tablicaPol[pozycja + 1]->zaznaczone = true;
            }
        }
        else if (pozycja == 63)         // prawy dolny róg
        {
            if (!tablicaPol[pozycja - 8]->Szachowane)
            {
                if (!tablicaPol[pozycja - 8]->zajete) tablicaPol[pozycja - 8]->zaznaczone = true;
                else if (tablicaPionow[pozycja - 8]->druzyna != druzyna) tablicaPol[pozycja - 8]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja - 1]->Szachowane)
            {
                if (!tablicaPol[pozycja - 1]->zajete) tablicaPol[pozycja - 1]->zaznaczone = true;
                else if (tablicaPionow[pozycja - 1]->druzyna != druzyna) tablicaPol[pozycja - 1]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja - 9]->Szachowane)
            {
                if (!tablicaPol[pozycja - 9]->zajete) tablicaPol[pozycja - 9]->zaznaczone = true;
                else if (tablicaPionow[pozycja - 9]->druzyna != druzyna) tablicaPol[pozycja - 9]->zaznaczone = true;
            }
        }
        else if (!(pozycja % 8))        // lewa granica
        {
            if (!tablicaPol[pozycja + 1]->Szachowane)
            {
                if (!tablicaPol[pozycja + 1]->zajete) tablicaPol[pozycja + 1]->zaznaczone = true;
                else if (tablicaPionow[pozycja + 1]->druzyna != druzyna) tablicaPol[pozycja + 1]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja + 8]->Szachowane)
            {
                if (!tablicaPol[pozycja + 8]->zajete) tablicaPol[pozycja + 8]->zaznaczone = true;
                else if (tablicaPionow[pozycja + 8]->druzyna != druzyna) tablicaPol[pozycja + 8]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja + 9]->Szachowane)
            {
                if (!tablicaPol[pozycja + 9]->zajete) tablicaPol[pozycja + 9]->zaznaczone = true;
                else if (tablicaPionow[pozycja + 9]->druzyna != druzyna) tablicaPol[pozycja + 9]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja - 8]->Szachowane)
            {
                if (!tablicaPol[pozycja - 8]->zajete) tablicaPol[pozycja - 8]->zaznaczone = true;
                else if (tablicaPionow[pozycja - 8]->druzyna != druzyna) tablicaPol[pozycja - 8]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja - 7]->Szachowane)
            {
                if (!tablicaPol[pozycja - 7]->zajete) tablicaPol[pozycja - 7]->zaznaczone = true;
                else if (tablicaPionow[pozycja - 7]->druzyna != druzyna) tablicaPol[pozycja - 7]->zaznaczone = true;
            }
        }
        else if (!((pozycja + 1) % 8))  // prawa granica
        {
        if (!tablicaPol[pozycja - 1]->Szachowane)
        {
            if (!tablicaPol[pozycja - 1]->zajete) tablicaPol[pozycja - 1]->zaznaczone = true;
            else if (tablicaPionow[pozycja - 1]->druzyna != druzyna) tablicaPol[pozycja - 1]->zaznaczone = true;
        }
        if (!tablicaPol[pozycja + 7]->Szachowane)
        {
            if (!tablicaPol[pozycja + 7]->zajete) tablicaPol[pozycja + 7]->zaznaczone = true;
            else if (tablicaPionow[pozycja + 7]->druzyna != druzyna) tablicaPol[pozycja + 7]->zaznaczone = true;
        }
        if (!tablicaPol[pozycja + 8]->Szachowane)
        {
            if (!tablicaPol[pozycja + 8]->zajete) tablicaPol[pozycja + 8]->zaznaczone = true;
            else if (tablicaPionow[pozycja + 8]->druzyna != druzyna) tablicaPol[pozycja + 8]->zaznaczone = true;
        }
            if (!tablicaPol[pozycja - 8]->Szachowane)
            {
                if (!tablicaPol[pozycja - 8]->zajete) tablicaPol[pozycja - 8]->zaznaczone = true;
                else if (tablicaPionow[pozycja - 8]->druzyna != druzyna) tablicaPol[pozycja - 8]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja - 9]->Szachowane)
            {
                if (!tablicaPol[pozycja - 9]->zajete) tablicaPol[pozycja - 9]->zaznaczone = true;
                else if (tablicaPionow[pozycja - 9]->druzyna != druzyna) tablicaPol[pozycja - 9]->zaznaczone = true;
            }
        }
        else if (pozycja < 8)           // górna granica
        {
        if (!tablicaPol[pozycja - 1]->Szachowane)
        {
            if (!tablicaPol[pozycja - 1]->zajete) tablicaPol[pozycja - 1]->zaznaczone = true;
            else if (tablicaPionow[pozycja - 1]->druzyna != druzyna) tablicaPol[pozycja - 1]->zaznaczone = true;
        }
        if (!tablicaPol[pozycja + 7]->Szachowane)
        {
            if (!tablicaPol[pozycja + 7]->zajete) tablicaPol[pozycja + 7]->zaznaczone = true;
            else if (tablicaPionow[pozycja + 7]->druzyna != druzyna) tablicaPol[pozycja + 7]->zaznaczone = true;
        }
        if (!tablicaPol[pozycja + 8]->Szachowane)
        {
            if (!tablicaPol[pozycja + 8]->zajete) tablicaPol[pozycja + 8]->zaznaczone = true;
            else if (tablicaPionow[pozycja + 8]->druzyna != druzyna) tablicaPol[pozycja + 8]->zaznaczone = true;
        }
        if (!tablicaPol[pozycja + 1]->Szachowane)
        {
            if (!tablicaPol[pozycja + 1]->zajete) tablicaPol[pozycja + 1]->zaznaczone = true;
            else if (tablicaPionow[pozycja + 1]->druzyna != druzyna) tablicaPol[pozycja + 1]->zaznaczone = true;
        }
        if (!tablicaPol[pozycja + 9]->Szachowane)
        {
            if (!tablicaPol[pozycja + 9]->zajete) tablicaPol[pozycja + 9]->zaznaczone = true;
            else if (tablicaPionow[pozycja + 9]->druzyna != druzyna) tablicaPol[pozycja + 9]->zaznaczone = true;
        }
        }
        else if (pozycja > 55)          // dolna granica
        {
        if (!tablicaPol[pozycja - 1]->Szachowane)
        {
            if (!tablicaPol[pozycja - 1]->zajete) tablicaPol[pozycja - 1]->zaznaczone = true;
            else if (tablicaPionow[pozycja - 1]->druzyna != druzyna) tablicaPol[pozycja - 1]->zaznaczone = true;
        }
        if (!tablicaPol[pozycja - 8]->Szachowane)
        {
            if (!tablicaPol[pozycja - 8]->zajete) tablicaPol[pozycja - 8]->zaznaczone = true;
            else if (tablicaPionow[pozycja - 8]->druzyna != druzyna) tablicaPol[pozycja - 8]->zaznaczone = true;
        }
        if (!tablicaPol[pozycja - 7]->Szachowane)
        {
            if (!tablicaPol[pozycja - 7]->zajete) tablicaPol[pozycja - 7]->zaznaczone = true;
            else if (tablicaPionow[pozycja - 7]->druzyna != druzyna) tablicaPol[pozycja - 7]->zaznaczone = true;
        }
        if (!tablicaPol[pozycja + 1]->Szachowane)
        {
            if (!tablicaPol[pozycja + 1]->zajete) tablicaPol[pozycja + 1]->zaznaczone = true;
            else if (tablicaPionow[pozycja + 1]->druzyna != druzyna) tablicaPol[pozycja + 1]->zaznaczone = true;
        }
        if (!tablicaPol[pozycja - 9]->Szachowane)
        {
            if (!tablicaPol[pozycja - 9]->zajete) tablicaPol[pozycja - 9]->zaznaczone = true;
            else if (tablicaPionow[pozycja - 9]->druzyna != druzyna) tablicaPol[pozycja - 9]->zaznaczone = true;
        }
        }

        // koniec wyj¹tków

        else
        {
        if (!tablicaPol[pozycja - 9]->Szachowane)
        {
            if (!tablicaPol[pozycja - 9]->zajete) tablicaPol[pozycja - 9]->zaznaczone = true;
            else if (tablicaPionow[pozycja - 9]->druzyna != druzyna) tablicaPol[pozycja - 9]->zaznaczone = true;
        }
        if (!tablicaPol[pozycja - 8]->Szachowane)
        {
            if (!tablicaPol[pozycja - 8]->zajete) tablicaPol[pozycja - 8]->zaznaczone = true;
            else if (tablicaPionow[pozycja - 8]->druzyna != druzyna) tablicaPol[pozycja - 8]->zaznaczone = true;
        }
        if (!tablicaPol[pozycja - 7]->Szachowane)
        {
            if (!tablicaPol[pozycja - 7]->zajete) tablicaPol[pozycja - 7]->zaznaczone = true;
            else if (tablicaPionow[pozycja - 7]->druzyna != druzyna) tablicaPol[pozycja - 7]->zaznaczone = true;
        }
            if (!tablicaPol[pozycja - 1]->Szachowane)
            {
                if (!tablicaPol[pozycja - 1]->zajete) tablicaPol[pozycja - 1]->zaznaczone = true;
                else if (tablicaPionow[pozycja - 1]->druzyna != druzyna) tablicaPol[pozycja - 1]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja + 7]->Szachowane)
            {
                if (!tablicaPol[pozycja + 7]->zajete) tablicaPol[pozycja + 7]->zaznaczone = true;
                else if (tablicaPionow[pozycja + 7]->druzyna != druzyna) tablicaPol[pozycja + 7]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja + 8]->Szachowane)
            {
                if (!tablicaPol[pozycja + 8]->zajete) tablicaPol[pozycja + 8]->zaznaczone = true;
                else if (tablicaPionow[pozycja + 8]->druzyna != druzyna) tablicaPol[pozycja + 8]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja + 1]->Szachowane)
            {
                if (!tablicaPol[pozycja + 1]->zajete) tablicaPol[pozycja + 1]->zaznaczone = true;
                else if (tablicaPionow[pozycja + 1]->druzyna != druzyna) tablicaPol[pozycja + 1]->zaznaczone = true;
            }
            if (!tablicaPol[pozycja + 9]->Szachowane)
            {
                if (!tablicaPol[pozycja + 9]->zajete) tablicaPol[pozycja + 9]->zaznaczone = true;
                else if (tablicaPionow[pozycja + 9]->druzyna != druzyna) tablicaPol[pozycja + 9]->zaznaczone = true;
            }
        }
}

void Tkrol::zbicie(bool kto)
{ // XD ten kto zbije króla to jest jakis szef totalny
    Tszachownica::zasada50ruchow = 50;
    if (kto)
    {
        Tszachownica::materialBialego -= 9999;
    }
    else
    {
        Tszachownica::materialCzarnego -= 9999;
    }
}

void Tkrol::szachowanieETC(Tpole** tablicaPol, Tpion** tablicaPionow, int pozycja, bool czyjRuch)
{
    if (czyjRuch == druzyna)
    {
        if (pozycja == 0)               // lewy górny róg
        {
            tablicaPol[pozycja + 1]->Szachowane = true;
            tablicaPol[pozycja + 8]->Szachowane = true;
            tablicaPol[pozycja + 9]->Szachowane = true;
        }
        else if (pozycja == 7)          // prawy górny róg
        {
            tablicaPol[pozycja - 1]->Szachowane = true;
            tablicaPol[pozycja + 7]->Szachowane = true;
            tablicaPol[pozycja + 8]->Szachowane = true;
        }
        else if (pozycja == 56)         // lewy dolny róg
        {
            tablicaPol[pozycja - 8]->Szachowane = true;
            tablicaPol[pozycja - 7]->Szachowane = true;
            tablicaPol[pozycja + 1]->Szachowane = true;
        }
        else if (pozycja == 63)         // prawy dolny róg
        {
            tablicaPol[pozycja - 8]->Szachowane = true;
            tablicaPol[pozycja - 9]->Szachowane = true;
            tablicaPol[pozycja - 1]->Szachowane = true;
        }
        else if (!(pozycja % 8))        // lewa granica
        {
            tablicaPol[pozycja + 1]->Szachowane = true;
            tablicaPol[pozycja + 8]->Szachowane = true;
            tablicaPol[pozycja + 9]->Szachowane = true;
            tablicaPol[pozycja - 8]->Szachowane = true;
            tablicaPol[pozycja - 7]->Szachowane = true;
        }
        else if (!((pozycja + 1) % 8))  // prawa granica
        {
            tablicaPol[pozycja - 1]->Szachowane = true;
            tablicaPol[pozycja + 7]->Szachowane = true;
            tablicaPol[pozycja + 8]->Szachowane = true;
            tablicaPol[pozycja - 8]->Szachowane = true;
            tablicaPol[pozycja - 9]->Szachowane = true;
        }
        else if (pozycja < 8)           // górna granica
        {
            tablicaPol[pozycja - 1]->Szachowane = true;
            tablicaPol[pozycja + 7]->Szachowane = true;
            tablicaPol[pozycja + 8]->Szachowane = true;
            tablicaPol[pozycja + 1]->Szachowane = true;
            tablicaPol[pozycja + 9]->Szachowane = true;
        }
        else if (pozycja > 55)          // dolna granica
        {
            tablicaPol[pozycja - 1]->Szachowane = true;
            tablicaPol[pozycja - 7]->Szachowane = true;
            tablicaPol[pozycja - 8]->Szachowane = true;
            tablicaPol[pozycja + 1]->Szachowane = true;
            tablicaPol[pozycja - 9]->Szachowane = true;
        }

        // koniec wyj¹tków

        else
        {
            tablicaPol[pozycja - 9]->Szachowane = true;
            tablicaPol[pozycja - 8]->Szachowane = true;
            tablicaPol[pozycja - 7]->Szachowane = true;
            tablicaPol[pozycja - 1]->Szachowane = true;
            tablicaPol[pozycja + 1]->Szachowane = true;
            tablicaPol[pozycja + 7]->Szachowane = true;
            tablicaPol[pozycja + 8]->Szachowane = true;
            tablicaPol[pozycja + 9]->Szachowane = true;
        }
    }
}

void Tkrol::roszada(Tpion** tablicaPionow, Tpole** tablicaPol, int pozycja, jestSzach *jestszach)
{
    if (!tablicaPionow[pozycja]->ruszony)
    {
        if (!tablicaPol[pozycja - 1]->zajete && !tablicaPol[pozycja - 2]->zajete && !tablicaPol[pozycja - 3]->zajete && !jestszach->szach)
        {
            if (tablicaPol[pozycja - 4]->zajete && !tablicaPol[pozycja - 2]->Szachowane)
            {
                if (tablicaPionow[pozycja - 4]->kimJestem == 2 && !tablicaPionow[pozycja - 4]->ruszony)
                {
                    tablicaPol[pozycja - 2]->zaznaczone = true;
                }
            }
        }
        if (!tablicaPol[pozycja + 1]->zajete && !tablicaPol[pozycja + 2]->zajete && !jestszach->szach)
        {
            if (tablicaPol[pozycja + 3]->zajete && !tablicaPol[pozycja + 2]->Szachowane)
            {
                if (tablicaPionow[pozycja + 3]->kimJestem == 2 && !tablicaPionow[pozycja + 3]->ruszony)
                {
                    tablicaPol[pozycja + 2]->zaznaczone = true;
                }
            }
        }

    }
}
