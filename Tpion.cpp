#include"Tpion.h"

Tpion::Tpion(Tkoordynaty poz, int numerPola, bool team, int kto, const char* pathDoTextury, const char* pathDoDzwiekuRuchu, const char* pathDoDzwiekuBicia) 
    : pozycja{ poz }, naKtorymPoluStoje{ numerPola }, druzyna{ team }, jestemZwiazany{ false }, kimJestem{ kto }
{
    tekstura = LoadTexture(pathDoTextury);
    dzwiekBicia = LoadSound(pathDoDzwiekuBicia);
    dzwiekRuchu = LoadSound(pathDoDzwiekuRuchu);
    powtarzaniePozycji[0] = numerPola;
    powtarzaniePozycji[1] = 9999;
}

Tpion::~Tpion()
{
    UnloadTexture(tekstura);
    UnloadSound(dzwiekBicia);
    UnloadSound(dzwiekRuchu);
}