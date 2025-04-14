#include"Tszachownica.h"

bool koniecGry = false;
std::string zdanie;

struct 
{
	bool czyPierwszeKlikniecie{ true };
	int czas{ 5 };

	void odliczanie()
	{
		czas -= 1;
		if (czas <= 0)
		{
			czyPierwszeKlikniecie = true;
			czas = 5;
		}
	}
}kliknieciePrzyciskuRemisu;

Tszachownica::~Tszachownica()
{
	for (int i = 0; i < 64; i++)
	{
		if(tablicaPol[i]->zajete) delete tablicaPionow[i];	
		delete tablicaPol[i];
	}
}

jestSzach Tszachownica::jestszach{ false , 0 };

int Tszachownica::materialBialego{ 39 };
int Tszachownica::materialCzarnego{ 39 };

int Tszachownica::zasada50ruchow{ 50 };

int Tszachownica::powtorzoneRuchy{ 0 };

Tszachownica::Tszachownica() : pozycjaOstatniegoWcisnietegoPionka{ 99 }, jestAwans{ 99 }, jestMat{ false }, jestPat{ false }
{
	
	
	for (int i = 0; i < 64; i++)
	{
		tablicaPol[i] = new Tpole{ Tkoordynaty{ (i%8) * 64 , (i / 8) * 64 }, i , 
			((i / 8) % 2) ? 
			  ((i % 2) ? "Textures/Pola/szarePola.png" : "Textures/Pola/pomaranczowePola.png") :
			  ((i % 2) ? "Textures/Pola/pomaranczowePola.png" : "Textures/Pola/szarePola.png") };

		tablicaPionow[i] = nullptr;

		//tablicaPol[i]->zaznaczone = true;
	}
	for (int i = 8; i < 16; i++)
	{
		tablicaPionow[i] = new TzwyklyPionek{ Tkoordynaty{ (i % 8) * 64 + 14 , (i / 8) * 64 + 5 },	i, true, 3,	"Textures/Pionki/czarnyPionek.png", "", "" }; tablicaPol[i]->zajete = true;
	}
	for (int i = 48; i < 56; i++)
	{
		tablicaPionow[i] = new TzwyklyPionek{ Tkoordynaty{ (i % 8) * 64 + 14 , (i / 8) * 64 + 5 },	i, false, 3,	"Textures/Pionki/bialyPionek.png", "", "" }; tablicaPol[i]->zajete = true;
	}

	tablicaPionow[0]  = new Twierza{ Tkoordynaty{ (0 % 8) *	 64 + 11 , (0 / 8) * 64 + 5 },	0, true, 2,		"Textures/Pionki/czarnaWierza.png", "", "" }; tablicaPol[0]->zajete = true;
	tablicaPionow[7]  = new Twierza{ Tkoordynaty{ (7 % 8) *  64 + 11 , (7 / 8) * 64 + 5 },	7, true, 2,		"Textures/Pionki/czarnaWierza.png", "", "" }; tablicaPol[7]->zajete = true;
	tablicaPionow[56] = new Twierza{ Tkoordynaty{ (56 % 8) * 64 + 11 , (56 / 8) * 64 + 5 }, 56, false, 2,		"Textures/Pionki/bialaWierza.png", "", "" }; tablicaPol[56]->zajete = true;
	tablicaPionow[63] = new Twierza{ Tkoordynaty{ (63 % 8) * 64 + 11 , (63 / 8) * 64 + 5 }, 63, false, 2,		"Textures/Pionki/bialaWierza.png", "", "" }; tablicaPol[63]->zajete = true;

	tablicaPionow[1]  = new Tskoczek{ Tkoordynaty{ (1 % 8) * 64 + 5 , (1 / 8) * 64 + 7 },	1, true, 4,		"Textures/Pionki/czarnySkoczek1.png", "", "" }; tablicaPol[1]->zajete = true;
	tablicaPionow[6]  = new Tskoczek{ Tkoordynaty{ (6 % 8) * 64 + 5 , (6 / 8) * 64 + 7 },	6, true, 4,		"Textures/Pionki/czarnySkoczek2.png", "", "" }; tablicaPol[6]->zajete = true;
	tablicaPionow[57] = new Tskoczek{ Tkoordynaty{ (57 % 8) * 64 + 5 , (57 / 8) * 64 + 7 }, 57, false, 4,		"Textures/Pionki/bialySkoczek1.png", "", "" }; tablicaPol[57]->zajete = true;
	tablicaPionow[62] = new Tskoczek{ Tkoordynaty{ (62 % 8) * 64 + 5 , (62 / 8) * 64 + 7 }, 62, false, 4,		"Textures/Pionki/bialySkoczek2.png", "", "" }; tablicaPol[62]->zajete = true;

	tablicaPionow[2]  = new Tgoniec{ Tkoordynaty{ (2 % 8) * 64 + 6 , (2 / 8) * 64 + 7 },	2, true, 5,		"Textures/Pionki/czarnyGoniec.png", "", "" }; tablicaPol[2]->zajete = true;
	tablicaPionow[5]  = new Tgoniec{ Tkoordynaty{ (5 % 8) * 64 + 6 , (5 / 8) * 64 + 7 },	5, true, 6,		"Textures/Pionki/czarnyGoniec.png", "", "" }; tablicaPol[5]->zajete = true;
	tablicaPionow[58] = new Tgoniec{ Tkoordynaty{ (58 % 8) * 64 + 6 , (58 / 8) * 64 + 7 }, 58, false, 6,		"Textures/Pionki/bialyGoniec.png", "", "" }; tablicaPol[58]->zajete = true;
	tablicaPionow[61] = new Tgoniec{ Tkoordynaty{ (61 % 8) * 64 + 6 , (61 / 8) * 64 + 7 }, 61, false, 5,		"Textures/Pionki/bialyGoniec.png", "", "" }; tablicaPol[61]->zajete = true;

	tablicaPionow[3]  = new Thetman{ Tkoordynaty{ (3 % 8) * 64 + 4 , (3 / 8) * 64 + 7 },	3, true, 99,		"Textures/Pionki/czarnyHetman.png", "", "" }; tablicaPol[3]->zajete = true;
	tablicaPionow[59] = new Thetman{ Tkoordynaty{ (59 % 8) * 64 + 4 , (59 / 8) * 64 + 7 },	59, false, 99,		"Textures/Pionki/bialyHetman.png", "", "" }; tablicaPol[59]->zajete = true;

	tablicaPionow[4]  = new Tkrol{ Tkoordynaty{ (4 % 8) * 64 + 5 , (4 / 8) * 64 + 7 }, 4, true, 1,				"Textures/Pionki/czarnyKrol.png", "", "", ""}; tablicaPol[4]->zajete = true;
	tablicaPionow[60] = new Tkrol{ Tkoordynaty{ (60 % 8) * 64 + 5 , (60 / 8) * 64 + 7 }, 60, false, 1,			"Textures/Pionki/bialyKrol.png", "", "", ""}; tablicaPol[60]->zajete = true;

	

}

void Tszachownica::rysuj()
{
	for (int i = 0; i < 64; i++)
	{
		tablicaPol[i]->rysujSie();
		if (tablicaPol[i]->zajete) tablicaPionow[i]->rysujSie();
	}
	this->rysujMenu();
}

void Tszachownica::rysujMenu()
{
	DrawRectangle(512, 0, 300, 512, Color{ 112, 54, 0, 255 });
	DrawRectangleLinesEx(Rectangle{ 512, 0, 300, 512 }, 5, Color{ 0, 0, 0, 200 });

	const char* kogoRuch;
	czyjRuch ? kogoRuch = "CZARNY" : kogoRuch = "BIALY";

	std::string doBialego;
	std::string doCzarnego;
	std::string czasBialy;
	std::string czasCzarny;

	if (czasBialego / 60 < 10)
		czasBialy += "0";
	czasBialy += std::to_string(czasBialego / 60);

	czasBialy += ":";

	if (czasBialego % 60 < 10)
		czasBialy += "0";
	czasBialy += std::to_string(czasBialego % 60);

	if (czasCzarnego / 60 < 10)
		czasCzarny += "0";
	czasCzarny += std::to_string(czasCzarnego / 60);

	czasCzarny += ":";

	if (czasCzarnego % 60 < 10)
		czasCzarny += "0";
	czasCzarny += std::to_string(czasCzarnego % 60);

	int roznicaMaterialu{materialBialego - materialCzarnego};
	if (roznicaMaterialu > 0)
	{
		doBialego = "+" + std::to_string(roznicaMaterialu);
		doCzarnego = "-" + std::to_string(roznicaMaterialu);
	}
	else if (roznicaMaterialu < 0)
	{
		doBialego = "-" + std::to_string(roznicaMaterialu * -1);
		doCzarnego = "+" + std::to_string(roznicaMaterialu * -1);
	}
	else
	{
		doBialego = " 0";
		doCzarnego = " 0";
	}

	const char* przewagaBialego{doBialego.c_str()}, *przewagaCzarnego{doCzarnego.c_str()};

	DrawText("Ruch: ", 530, 18, 40, BLACK); 
	DrawRectangleLinesEx(Rectangle{ 645, 13, 149, 50 }, 3, BLACK); DrawText(kogoRuch, 651, 22, 34, BLACK);

	DrawRectangleLinesEx(Rectangle{ 517, 70, 290, 3 }, 8, BLACK);

	DrawText("Zdobyty material", 530, 80, 30, BLACK);

	DrawRectangleLinesEx(Rectangle{ 515, 115, 292, 3 }, 8, BLACK);

	DrawText("Bialy", 555, 120, 30, BLACK); DrawText("Czarny", 680, 120, 30, BLACK);
	DrawRectangleLinesEx(Rectangle{ 660, 115, 3, 80 }, 8, BLACK);

	DrawText(przewagaBialego, 555, 150, 50, BLACK); DrawText(przewagaCzarnego, 700, 150, 50, BLACK);

	DrawRectangleLinesEx(Rectangle{ 517, 217, 85, 3 }, 8, BLACK); DrawText("TIMER", 595, 200, 40, BLACK); DrawRectangleLinesEx(Rectangle{ 730, 217, 77, 3 }, 8, BLACK);

	DrawText(czasBialy.c_str(), 525, 237, 50, BLACK); DrawText(czasCzarny.c_str(), 673, 237, 50, BLACK);

	DrawRectangleLinesEx(Rectangle{ 515, 300, 292, 3 }, 8, BLACK);


	DrawText("Created by MM", 580, 485, 20, BLACK);

}

void Tszachownica::rysujPrzyciski()
{

	if (!czyMenuGlowne)
	{
		if ((540 < GetMouseX()) && (784 > GetMouseX()) &&
			(315 < GetMouseY()) && (360 > GetMouseY()))
		{
			if (kliknieciePrzyciskuRemisu.czyPierwszeKlikniecie)
			{
				DrawRectangleRec(Rectangle{ 540, 315, 244, 45 }, BLACK); DrawText("Zaproponuj Remis", 545, 325, 28, Color{ 112, 54, 0, 255 });
			}
			else
			{
				DrawRectangleRec(Rectangle{ 540, 315, 244, 45 }, BLACK); DrawText(" Akceptuj Remis", 545, 325, 28, Color{ 112, 54, 0, 255 });
			}

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				if (kliknieciePrzyciskuRemisu.czyPierwszeKlikniecie)
				{
					kliknieciePrzyciskuRemisu.czyPierwszeKlikniecie = false;
				}
				else
				{
					Remis("zgode");
				}
			}
		}
		else
		{
			if (kliknieciePrzyciskuRemisu.czyPierwszeKlikniecie)
			{
				DrawRectangleLinesEx(Rectangle{ 540, 315, 244, 45 }, 2, BLACK); DrawText("Zaproponuj Remis", 545, 325, 28, BLACK);
			}
			else
			{
				DrawRectangleLinesEx(Rectangle{ 540, 315, 244, 45 }, 2, BLACK); DrawText(" Akceptuj Remis", 545, 325, 28, BLACK);
			}
		}

		if ((574 < GetMouseX()) && (753 > GetMouseX()) &&
			(374 < GetMouseY()) && (418 > GetMouseY()))
		{
			DrawRectangleRec(Rectangle{ 574, 374, 179, 44 }, BLACK); DrawText("Poddaj sie", 580, 380, 33, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				Zwyciestwo("poddanie sie", !czyjRuch);
			}
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 574, 374, 179, 44 }, 2, BLACK); DrawText("Poddaj sie", 580, 380, 33, BLACK);
		}
	}
	else
	{
		static int WybranyCzasBialy{ 3 };
		static int WybranyCzasCzarny{ 3 };

		static int WybranyDodatkowyB{ 1 };
		static int WybranyDodatkowyC{ 1 };

		DrawText("Wybierz czas", 610, 305, 17, BLACK);

		if (((528 < GetMouseX()) && (578 > GetMouseX()) &&
			(328 < GetMouseY()) && (348 > GetMouseY())) || WybranyCzasBialy == 1)
		{
			DrawRectangleRec(Rectangle{ 528, 328, 50, 20 }, BLACK); DrawText("03:00", 533, 330, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyCzasBialy = 1;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 528, 328, 50, 20 }, 1, BLACK); DrawText("03:00", 533, 330, 18, BLACK);
		}

		if (((528 < GetMouseX()) && (578 > GetMouseX()) &&
			(348 < GetMouseY()) && (368 > GetMouseY())) || WybranyCzasBialy == 2)
		{
			DrawRectangleRec(Rectangle{ 528, 348, 50, 20 }, BLACK); DrawText("05:00", 533, 350, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyCzasBialy = 2;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 528, 348, 50, 20 }, 1, BLACK); DrawText("05:00", 533, 350, 18, BLACK);
		}
		if (((528 < GetMouseX()) && (578 > GetMouseX()) &&
			(368 < GetMouseY()) && (388 > GetMouseY())) || WybranyCzasBialy == 3)
		{
			DrawRectangleRec(Rectangle{ 528, 368, 50, 20 }, BLACK); DrawText("10:00", 533, 370, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyCzasBialy = 3;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 528, 368, 50, 20 }, 1, BLACK); DrawText("10:00", 533, 370, 18, BLACK);
		}
		if (((528 < GetMouseX()) && (578 > GetMouseX()) &&
			(388 < GetMouseY()) && (408 > GetMouseY())) || WybranyCzasBialy == 4)
		{
			DrawRectangleRec(Rectangle{ 528, 388, 50, 20 }, BLACK); DrawText("15:00", 533, 390, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyCzasBialy = 4;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 528, 388, 50, 20 }, 1, BLACK); DrawText("15:00", 533, 390, 18, BLACK);
		}
		if (((528 < GetMouseX()) && (578 > GetMouseX()) &&
			(408 < GetMouseY()) && (428 > GetMouseY())) || WybranyCzasBialy == 5)
		{
			DrawRectangleRec(Rectangle{ 528, 408, 50, 20 }, BLACK); DrawText("30:00", 533, 410, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyCzasBialy = 5;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 528, 408, 50, 20 }, 1, BLACK); DrawText("30:00", 533, 410, 18, BLACK);
		}

		if (((588 < GetMouseX()) && (638 > GetMouseX()) &&
			(328 < GetMouseY()) && (348 > GetMouseY())) || WybranyDodatkowyB == 1)
		{
			DrawRectangleRec(Rectangle{ 588, 328, 50, 20 }, BLACK); DrawText("+0s", 593, 330, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyDodatkowyB = 1;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 588, 328, 50, 20 }, 1, BLACK); DrawText("+0s", 593, 330, 18, BLACK);
		}

		if (((588 < GetMouseX()) && (638 > GetMouseX()) &&
			(348 < GetMouseY()) && (368 > GetMouseY())) || WybranyDodatkowyB == 2)
		{
			DrawRectangleRec(Rectangle{ 588, 348, 50, 20 }, BLACK); DrawText("+3s", 593, 350, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyDodatkowyB = 2;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 588, 348, 50, 20 }, 1, BLACK); DrawText("+3s", 593, 350, 18, BLACK);
		}
		if (((588 < GetMouseX()) && (638 > GetMouseX()) &&
			(368 < GetMouseY()) && (388 > GetMouseY())) || WybranyDodatkowyB == 3)
		{
			DrawRectangleRec(Rectangle{ 588, 368, 50, 20 }, BLACK); DrawText("+5s", 593, 370, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyDodatkowyB = 3;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 588, 368, 50, 20 }, 1, BLACK); DrawText("+5s", 593, 370, 18, BLACK);
		}
		if (((588 < GetMouseX()) && (638 > GetMouseX()) &&
			(388 < GetMouseY()) && (408 > GetMouseY())) || WybranyDodatkowyB == 4)
		{
			DrawRectangleRec(Rectangle{ 588, 388, 50, 20 }, BLACK); DrawText("+10s", 593, 390, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyDodatkowyB = 4;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 588, 388, 50, 20 }, 1, BLACK); DrawText("+10s", 593, 390, 18, BLACK);
		}
		if (((588 < GetMouseX()) && (638 > GetMouseX()) &&
			(408 < GetMouseY()) && (428 > GetMouseY())) || WybranyDodatkowyB == 5)
		{
			DrawRectangleRec(Rectangle{ 588, 408, 50, 20 }, BLACK); DrawText("+20s", 593, 410, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyDodatkowyB = 5;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 588, 408, 50, 20 }, 1, BLACK); DrawText("+20s", 593, 410, 18, BLACK);
		}

		DrawRectangleLinesEx(Rectangle{ 660, 330, 3, 80 }, 8, BLACK);

		if (((685 < GetMouseX()) && (735 > GetMouseX()) &&
			(328 < GetMouseY()) && (348 > GetMouseY())) || WybranyCzasCzarny == 1)
		{
			DrawRectangleRec(Rectangle{ 685, 328, 50, 20 }, BLACK); DrawText("03:00", 690, 330, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyCzasCzarny = 1;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 685, 328, 50, 20 }, 1, BLACK); DrawText("03:00", 690, 330, 18, BLACK);
		}

		if (((685 < GetMouseX()) && (735 > GetMouseX()) &&
			(348 < GetMouseY()) && (368 > GetMouseY())) || WybranyCzasCzarny == 2)
		{
			DrawRectangleRec(Rectangle{ 685, 348, 50, 20 }, BLACK); DrawText("05:00", 690, 350, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyCzasCzarny = 2;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 685, 348, 50, 20 }, 1, BLACK); DrawText("05:00", 690, 350, 18, BLACK);
		}
		if (((685 < GetMouseX()) && (735 > GetMouseX()) &&
			(368 < GetMouseY()) && (388 > GetMouseY())) || WybranyCzasCzarny == 3)
		{
			DrawRectangleRec(Rectangle{ 685, 368, 50, 20 }, BLACK); DrawText("10:00", 690, 370, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyCzasCzarny = 3;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 685, 368, 50, 20 }, 1, BLACK); DrawText("10:00", 690, 370, 18, BLACK);
		}
		if (((685 < GetMouseX()) && (735 > GetMouseX()) &&
			(388 < GetMouseY()) && (408 > GetMouseY())) || WybranyCzasCzarny == 4)
		{
			DrawRectangleRec(Rectangle{ 685, 388, 50, 20 }, BLACK); DrawText("15:00", 690, 390, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyCzasCzarny = 4;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 685, 388, 50, 20 }, 1, BLACK); DrawText("15:00", 690, 390, 18, BLACK);
		}
		if (((685 < GetMouseX()) && (735 > GetMouseX()) &&
			(408 < GetMouseY()) && (428 > GetMouseY())) || WybranyCzasCzarny == 5)
		{
			DrawRectangleRec(Rectangle{ 685, 408, 50, 20 }, BLACK); DrawText("30:00", 690, 410, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyCzasCzarny = 5;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 685, 408, 50, 20 }, 1, BLACK); DrawText("30:00", 690, 410, 18, BLACK);
		}

		if (((745 < GetMouseX()) && (795 > GetMouseX()) &&
			(328 < GetMouseY()) && (348 > GetMouseY())) || WybranyDodatkowyC == 1)
		{
			DrawRectangleRec(Rectangle{ 745, 328, 50, 20 }, BLACK); DrawText("+0s", 750, 330, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyDodatkowyC = 1;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 745, 328, 50, 20 }, 1, BLACK); DrawText("+0s", 750, 330, 18, BLACK);
		}

		if (((745 < GetMouseX()) && (795 > GetMouseX()) &&
			(348 < GetMouseY()) && (368 > GetMouseY())) || WybranyDodatkowyC == 2)
		{
			DrawRectangleRec(Rectangle{ 745, 348, 50, 20 }, BLACK); DrawText("+3s", 750, 350, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyDodatkowyC = 2;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 745, 348, 50, 20 }, 1, BLACK); DrawText("+3s", 750, 350, 18, BLACK);
		}
		if (((745 < GetMouseX()) && (795 > GetMouseX()) &&
			(368 < GetMouseY()) && (388 > GetMouseY())) || WybranyDodatkowyC == 3)
		{
			DrawRectangleRec(Rectangle{ 745, 368, 50, 20 }, BLACK); DrawText("+5s", 750, 370, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyDodatkowyC = 3;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 745, 368, 50, 20 }, 1, BLACK); DrawText("+5s", 750, 370, 18, BLACK);
		}
		if (((745 < GetMouseX()) && (795 > GetMouseX()) &&
			(388 < GetMouseY()) && (408 > GetMouseY())) || WybranyDodatkowyC == 4)
		{
			DrawRectangleRec(Rectangle{ 745, 388, 50, 20 }, BLACK); DrawText("+10s", 750, 390, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyDodatkowyC = 4;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 745, 388, 50, 20 }, 1, BLACK); DrawText("+10s", 750, 390, 18, BLACK);
		}
		if (((745 < GetMouseX()) && (795 > GetMouseX()) &&
			(408 < GetMouseY()) && (428 > GetMouseY())) || WybranyDodatkowyC == 5)
		{
			DrawRectangleRec(Rectangle{ 745, 408, 50, 20 }, BLACK); DrawText("+20s", 750, 410, 18, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) WybranyDodatkowyC = 5;
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 745, 408, 50, 20 }, 1, BLACK); DrawText("+20s", 750, 410, 18, BLACK);
		}



		if ((540 < GetMouseX()) && (784 > GetMouseX()) &&
			(434 < GetMouseY()) && (479 > GetMouseY()))
		{
			DrawRectangleRec(Rectangle{ 540, 434, 244, 45 }, BLACK); DrawText("Rozpocznij Gre!", 558, 445, 28, Color{ 112, 54, 0, 255 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				czyMenuGlowne = false;
				koniecGry = false;
				jestMat = false;
				jestPat = false;
				czyjRuch = false;
				materialBialego = 39;
				materialCzarnego = 39;

				zdanie.clear();

				switch (WybranyCzasBialy)
				{
				case 1: czasBialego = 180; break;
				case 2:	czasBialego = 300; break;
				case 3:	czasBialego = 600; break;
				case 4:	czasBialego = 900; break;
				case 5:	czasBialego = 1800; break;
				}

				switch (WybranyCzasCzarny)
				{
				case 1: czasCzarnego = 180; break;
				case 2:	czasCzarnego = 300; break;
				case 3:	czasCzarnego = 600; break;
				case 4:	czasCzarnego = 900; break;
				case 5:	czasCzarnego = 1800; break;
				}

				switch (WybranyDodatkowyB)
				{
				case 1: dodatkowyCzasB = 0;  break;
				case 2: dodatkowyCzasB = 3;	 break;
				case 3: dodatkowyCzasB = 5;	 break;
				case 4: dodatkowyCzasB = 10; break;
				case 5: dodatkowyCzasB = 20; break;
				}

				switch (WybranyDodatkowyC)
				{
				case 1: dodatkowyCzasC = 0;  break;
				case 2: dodatkowyCzasC = 3;	 break;
				case 3: dodatkowyCzasC = 5;	 break;
				case 4: dodatkowyCzasC = 10; break;
				case 5: dodatkowyCzasC = 20; break;
				}

				jestszach.szach = false;
				jestszach.iloscSzachujacychPionkow = 0;

				for (int i = 0; i < 64; i++)  // reset danych
				{
					tablicaPol[i]->Szachowane = false;
					tablicaPol[i]->naLiniiSzacha = false;
					tablicaPol[i]->naLiniiZwiazania.poleNaLiniiZwiazania = false;
					tablicaPol[i]->zaznaczone = false;
					if (tablicaPol[i]->zajete) delete tablicaPionow[i];
					tablicaPionow[i] = nullptr;
					tablicaPol[i]->zajete = false;
				}
					
				
				
				for (int i = 8; i < 16; i++)
				{
					tablicaPionow[i] = new TzwyklyPionek{ Tkoordynaty{ (i % 8) * 64 + 14 , (i / 8) * 64 + 5 },	i, true, 3,	"Textures/Pionki/czarnyPionek.png", "", "" }; tablicaPol[i]->zajete = true;
				}
				for (int i = 48; i < 56; i++)
				{
					tablicaPionow[i] = new TzwyklyPionek{ Tkoordynaty{ (i % 8) * 64 + 14 , (i / 8) * 64 + 5 },	i, false, 3,	"Textures/Pionki/bialyPionek.png", "", "" }; tablicaPol[i]->zajete = true;
				}

				tablicaPionow[0] = new Twierza{ Tkoordynaty{ (0 % 8) * 64 + 11 , (0 / 8) * 64 + 5 },	0, true, 2,		"Textures/Pionki/czarnaWierza.png", "", "" }; tablicaPol[0]->zajete = true;
				tablicaPionow[7] = new Twierza{ Tkoordynaty{ (7 % 8) * 64 + 11 , (7 / 8) * 64 + 5 },	7, true, 2,		"Textures/Pionki/czarnaWierza.png", "", "" }; tablicaPol[7]->zajete = true;
				tablicaPionow[56] = new Twierza{ Tkoordynaty{ (56 % 8) * 64 + 11 , (56 / 8) * 64 + 5 }, 56, false, 2,		"Textures/Pionki/bialaWierza.png", "", "" }; tablicaPol[56]->zajete = true;
				tablicaPionow[63] = new Twierza{ Tkoordynaty{ (63 % 8) * 64 + 11 , (63 / 8) * 64 + 5 }, 63, false, 2,		"Textures/Pionki/bialaWierza.png", "", "" }; tablicaPol[63]->zajete = true;

				tablicaPionow[1] = new Tskoczek{ Tkoordynaty{ (1 % 8) * 64 + 5 , (1 / 8) * 64 + 7 },	1, true, 4,		"Textures/Pionki/czarnySkoczek1.png", "", "" }; tablicaPol[1]->zajete = true;
				tablicaPionow[6] = new Tskoczek{ Tkoordynaty{ (6 % 8) * 64 + 5 , (6 / 8) * 64 + 7 },	6, true, 4,		"Textures/Pionki/czarnySkoczek2.png", "", "" }; tablicaPol[6]->zajete = true;
				tablicaPionow[57] = new Tskoczek{ Tkoordynaty{ (57 % 8) * 64 + 5 , (57 / 8) * 64 + 7 }, 57, false, 4,		"Textures/Pionki/bialySkoczek1.png", "", "" }; tablicaPol[57]->zajete = true;
				tablicaPionow[62] = new Tskoczek{ Tkoordynaty{ (62 % 8) * 64 + 5 , (62 / 8) * 64 + 7 }, 62, false, 4,		"Textures/Pionki/bialySkoczek2.png", "", "" }; tablicaPol[62]->zajete = true;

				tablicaPionow[2] = new Tgoniec{ Tkoordynaty{ (2 % 8) * 64 + 6 , (2 / 8) * 64 + 7 },	2, true, 5,		"Textures/Pionki/czarnyGoniec.png", "", "" }; tablicaPol[2]->zajete = true;
				tablicaPionow[5] = new Tgoniec{ Tkoordynaty{ (5 % 8) * 64 + 6 , (5 / 8) * 64 + 7 },	5, true, 6,		"Textures/Pionki/czarnyGoniec.png", "", "" }; tablicaPol[5]->zajete = true;
				tablicaPionow[58] = new Tgoniec{ Tkoordynaty{ (58 % 8) * 64 + 6 , (58 / 8) * 64 + 7 }, 58, false, 6,		"Textures/Pionki/bialyGoniec.png", "", "" }; tablicaPol[58]->zajete = true;
				tablicaPionow[61] = new Tgoniec{ Tkoordynaty{ (61 % 8) * 64 + 6 , (61 / 8) * 64 + 7 }, 61, false, 5,		"Textures/Pionki/bialyGoniec.png", "", "" }; tablicaPol[61]->zajete = true;

				tablicaPionow[3] = new Thetman{ Tkoordynaty{ (3 % 8) * 64 + 4 , (3 / 8) * 64 + 7 },	3, true, 99,		"Textures/Pionki/czarnyHetman.png", "", "" }; tablicaPol[3]->zajete = true;
				tablicaPionow[59] = new Thetman{ Tkoordynaty{ (59 % 8) * 64 + 4 , (59 / 8) * 64 + 7 },	59, false, 99,		"Textures/Pionki/bialyHetman.png", "", "" }; tablicaPol[59]->zajete = true;

				tablicaPionow[4] = new Tkrol{ Tkoordynaty{ (4 % 8) * 64 + 5 , (4 / 8) * 64 + 7 }, 4, true, 1,				"Textures/Pionki/czarnyKrol.png", "", "", "" }; tablicaPol[4]->zajete = true;
				tablicaPionow[60] = new Tkrol{ Tkoordynaty{ (60 % 8) * 64 + 5 , (60 / 8) * 64 + 7 }, 60, false, 1,			"Textures/Pionki/bialyKrol.png", "", "", "" }; tablicaPol[60]->zajete = true;
			}
		}
		else
		{
			DrawRectangleLinesEx(Rectangle{ 540, 434, 244, 45 }, 2, BLACK); DrawText("Rozpocznij Gre!", 558, 445, 28, BLACK);
		}

	}
}

void Tszachownica::rysujZaznaczonePola()
{
	for (int i{ 0 }; i < 64; i++)
	{
		if (tablicaPol[i]->zaznaczone && !tablicaPol[i]->zajete)
			DrawCircleV(Vector2{ float((i % 8) * 64 + 32) , float((i / 8) * 64 + 32) }, 10, YELLOW);
		else if (tablicaPol[i]->zaznaczone && tablicaPol[i]->zajete)
			DrawCircleLines((i % 8) * 64 + 32, (i / 8) * 64 + 32, 20, YELLOW);
	}
}

void Tszachownica::odznaczaniePol()
{
	for (int i{ 0 }; i < 64; i++)
	{
		tablicaPol[i]->zaznaczone = false;
	}
}

void Tszachownica::nacisnietePole()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		for (int i{ 0 }; i < 64; i++)
		{
			if ((tablicaPol[i]->pozycja.x < GetMouseX()) && (tablicaPol[i]->pozycja.x + 64 > GetMouseX()) &&
				(tablicaPol[i]->pozycja.y < GetMouseY()) && (tablicaPol[i]->pozycja.y + 64 > GetMouseY()))
			{// po kliknieciu w dane pole
				
				if (!tablicaPol[i]->zaznaczone)
				{
					this->odznaczaniePol(); // reset pól
					if (tablicaPol[i]->zajete)
						if (tablicaPionow[i]->druzyna == czyjRuch)
						{
							tablicaPionow[i]->zaznaczanie(tablicaPol, tablicaPionow, i, &jestszach, czyjRuch); // zaznaczenie od nowa dla nowego pionka
							pozycjaOstatniegoWcisnietegoPionka = i; // to mi sie przyda przy ruchu pionka
						}
				}
				else
				{
					if (tablicaPol[i]->zajete)
						tablicaPionow[i]->zbicie(czyjRuch);

					zasada50ruchow -= 1;
					if (zasada50ruchow <= 0)
						Remis("zasada 50 ruchow");
					this->ruch(i);
					if (tablicaPionow[i]->kimJestem == 3)
						zasada50ruchow = 50;

					czyjRuch ? czasCzarnego += dodatkowyCzasC : czasBialego += dodatkowyCzasB;

					this->odznaczaniePol();

					this->szachowanieETCszachownica(czyjRuch);

					czyjRuch = !czyjRuch;

					switch (sprawdzenieMata())
					{
					case 0: break;
					case 1: jestMat = true; break;
					case 2: jestPat = true; break;
					case 4: Remis("nie wystarczajacy\nmaterial");
					}
					this->odznaczaniePol();
				}
			}
		}
	}
}

int Tszachownica::sprawdzenieMata()
{
	bool potencjalnyRemis{ false };
	bool potencjalnyRemisGoncowy{ false };
	int polowoscGonca{ 9999 }; // numer rozny od 5 i 6 oznacza ze nie natrafiono jescze na gonca ale to nic nei zmienia bo nie bede z tego korzystac

	if (materialBialego == 0 && materialCzarnego == 0) // 2 krole
		return 4;

	if (materialBialego == 3 && materialCzarnego == 3) potencjalnyRemisGoncowy = true; // sytuacje z goncami oddzielam od innych
	else if ((materialBialego == 0 || materialBialego == 3) && (materialCzarnego == 0 || materialCzarnego == 3)) // jezeli bialy ma samego krola lub tez potencjalnie gonca, i czarny to samo
		potencjalnyRemis = true;

	for (int i = 0; i < 64; i++)
	{
		if (tablicaPol[i]->zajete)
		{
			if (potencjalnyRemis)
			{
				if (tablicaPionow[i]->kimJestem == 4 || tablicaPionow[i]->kimJestem == 5 || tablicaPionow[i]->kimJestem == 6)
					return 4;
				else if (tablicaPionow[i]->kimJestem != 1)
					potencjalnyRemis = false;
			}
			else if (potencjalnyRemisGoncowy)
			{
				if (tablicaPionow[i]->kimJestem == 5 || tablicaPionow[i]->kimJestem == 6)
				{
					if (tablicaPionow[i]->kimJestem == polowoscGonca)
						return 4;
					else polowoscGonca = tablicaPionow[i]->kimJestem;
				}
				else if(tablicaPionow[i]->kimJestem != 1)
					potencjalnyRemisGoncowy = false;
			}
			//czy jest krol + goniec vs krol + goniec(tego samego koloru)


			if (tablicaPionow[i]->druzyna == czyjRuch)
			{
				tablicaPionow[i]->zaznaczanie(tablicaPol, tablicaPionow, i, &jestszach, czyjRuch);
			}
		}
	}
	for (int i = 0; i < 64; i++)
	{
		if (tablicaPol[i]->zaznaczone)
			return 0;
	}

	if (jestszach.szach) return 1;
	else return 2;
}

void Tszachownica::ruch(int numerKliknietegoPola)
{// wiem z ktorego pola przenosze pionka, wiem na ktore pole, wiec mam wszystko


	if (tablicaPol[numerKliknietegoPola]->czyEnPassant)
	{
		if (numerKliknietegoPola < 31)
		{
			if (tablicaPionow[numerKliknietegoPola + 8])
				delete tablicaPionow[numerKliknietegoPola + 8];
			tablicaPionow[numerKliknietegoPola + 8] = nullptr;

			tablicaPol[numerKliknietegoPola + 8]->zajete = false;
		}
		else
		{
			if (tablicaPionow[numerKliknietegoPola - 8])
				delete tablicaPionow[numerKliknietegoPola - 8];
			tablicaPionow[numerKliknietegoPola - 8] = nullptr;

			tablicaPol[numerKliknietegoPola - 8]->zajete = false;
		}
	}
	for (int i = 0; i < 64; i++)
		tablicaPol[i]->czyEnPassant = false;

	if (tablicaPionow[pozycjaOstatniegoWcisnietegoPionka]->kimJestem == 1 && (pozycjaOstatniegoWcisnietegoPionka + 2 == numerKliknietegoPola || pozycjaOstatniegoWcisnietegoPionka - 2 == numerKliknietegoPola))
	{
		// ruch wierzy
		if (numerKliknietegoPola > pozycjaOstatniegoWcisnietegoPionka) // wierza z prawej
		{
			tablicaPionow[pozycjaOstatniegoWcisnietegoPionka + 3]->ruszony = true;
			tablicaPionow[pozycjaOstatniegoWcisnietegoPionka + 3]->naKtorymPoluStoje = numerKliknietegoPola - 1;
			tablicaPionow[pozycjaOstatniegoWcisnietegoPionka + 3]->pozycja.x += (((numerKliknietegoPola - 1) % 8) - ((pozycjaOstatniegoWcisnietegoPionka + 3) % 8)) * 64;

			if (tablicaPionow[numerKliknietegoPola - 1])
				delete tablicaPionow[numerKliknietegoPola - 1];

			tablicaPionow[numerKliknietegoPola - 1] = tablicaPionow[pozycjaOstatniegoWcisnietegoPionka + 3];
			tablicaPionow[pozycjaOstatniegoWcisnietegoPionka + 3] = nullptr;

			tablicaPol[pozycjaOstatniegoWcisnietegoPionka + 3]->zajete = false; tablicaPol[numerKliknietegoPola - 1]->zajete = true;
		}
		else
		{
			tablicaPionow[pozycjaOstatniegoWcisnietegoPionka - 4]->ruszony = true;
			tablicaPionow[pozycjaOstatniegoWcisnietegoPionka - 4]->naKtorymPoluStoje = numerKliknietegoPola + 1;
			tablicaPionow[pozycjaOstatniegoWcisnietegoPionka - 4]->pozycja.x += (((numerKliknietegoPola + 1) % 8) - ((pozycjaOstatniegoWcisnietegoPionka - 4) % 8)) * 64;

			if (tablicaPionow[numerKliknietegoPola + 1])
				delete tablicaPionow[numerKliknietegoPola + 1];

			tablicaPionow[numerKliknietegoPola + 1] = tablicaPionow[pozycjaOstatniegoWcisnietegoPionka - 4];
			tablicaPionow[pozycjaOstatniegoWcisnietegoPionka - 4] = nullptr;

			tablicaPol[pozycjaOstatniegoWcisnietegoPionka - 4]->zajete = false; tablicaPol[numerKliknietegoPola + 1]->zajete = true;
		}
	}
	if (tablicaPionow[pozycjaOstatniegoWcisnietegoPionka]->kimJestem == 3 && (numerKliknietegoPola + 16 == pozycjaOstatniegoWcisnietegoPionka || numerKliknietegoPola - 16 == pozycjaOstatniegoWcisnietegoPionka))
	{
		if (numerKliknietegoPola + 16 == pozycjaOstatniegoWcisnietegoPionka)
		{
			tablicaPol[numerKliknietegoPola + 8]->czyEnPassant = true;
		}
		else
		{
			tablicaPol[numerKliknietegoPola - 8]->czyEnPassant = true;
		}
	}

		tablicaPionow[pozycjaOstatniegoWcisnietegoPionka]->ruszony = true;
		tablicaPionow[pozycjaOstatniegoWcisnietegoPionka]->naKtorymPoluStoje = numerKliknietegoPola;
		tablicaPionow[pozycjaOstatniegoWcisnietegoPionka]->pozycja.x += ((numerKliknietegoPola % 8) - (pozycjaOstatniegoWcisnietegoPionka % 8)) * 64;
		tablicaPionow[pozycjaOstatniegoWcisnietegoPionka]->pozycja.y += ((numerKliknietegoPola / 8) - (pozycjaOstatniegoWcisnietegoPionka / 8)) * 64;

		if (tablicaPionow[numerKliknietegoPola])
			delete tablicaPionow[numerKliknietegoPola];

		tablicaPionow[numerKliknietegoPola] =  tablicaPionow[pozycjaOstatniegoWcisnietegoPionka];
		tablicaPionow[pozycjaOstatniegoWcisnietegoPionka] = nullptr;
		tablicaPol[pozycjaOstatniegoWcisnietegoPionka]->zajete = false; tablicaPol[numerKliknietegoPola]->zajete = true;

		static int pozycjaOstaniaBialego{ 5656 };
		static int pozycjaOstatniaCzarnego{ 5656 };


		if (czyjRuch)
		{
			if (pozycjaOstatniegoWcisnietegoPionka != pozycjaOstatniaCzarnego)
				Tszachownica::powtorzoneRuchy = 0;
		}
		else
		{
			if (pozycjaOstatniegoWcisnietegoPionka != pozycjaOstaniaBialego)
				Tszachownica::powtorzoneRuchy = 0;
		}

		if (tablicaPionow[numerKliknietegoPola]->powtarzaniePozycji[1] == numerKliknietegoPola) // stara pozycja czy jest równa nowej pozycji
		{
			Tszachownica::powtorzoneRuchy++;
		}
		else
		{
			Tszachownica::powtorzoneRuchy = 0;
		}
		tablicaPionow[numerKliknietegoPola]->powtarzaniePozycji[1] = tablicaPionow[numerKliknietegoPola]->powtarzaniePozycji[0]; // aktualna pozycja to teraz bedzie stara pozycja
		tablicaPionow[numerKliknietegoPola]->powtarzaniePozycji[0] = numerKliknietegoPola; // nowa pozycja to teraz bedzie aktualna pozycja
		if (Tszachownica::powtorzoneRuchy >= 6)
			Remis("3-krotne powto-\nrzenie pozycji");

		czyjRuch ? pozycjaOstatniaCzarnego = numerKliknietegoPola : pozycjaOstaniaBialego = numerKliknietegoPola;


		if (tablicaPionow[numerKliknietegoPola]->kimJestem == 3)
		{
			if (numerKliknietegoPola < 8 && czyjRuch == false)
			{
				this->jestAwans = numerKliknietegoPola;
			}
			else if (numerKliknietegoPola > 55 && czyjRuch == true)
			{
				this->jestAwans = numerKliknietegoPola;
			}
		}
}

void Tszachownica::szachowanieETCszachownica(bool czyjRuch)
{
	jestszach.szach = false;
	jestszach.iloscSzachujacychPionkow = 0;

	for (int i = 0; i < 64; i++)  // reset danych
	{
		tablicaPol[i]->Szachowane = false;
		tablicaPol[i]->naLiniiSzacha = false;
		tablicaPol[i]->naLiniiZwiazania.poleNaLiniiZwiazania = false;
		if (tablicaPol[i]->zajete)
		{
			tablicaPionow[i]->jestemZwiazany = false;
		}
	}

	for (int i = 0; i < 64; i++) // ustawianie danych od nowa
	{
		if (tablicaPol[i]->zajete)
		{ // dodanie sprawdzania druzyny, aby nie uruchamiaæ funkcji niepotrzebnie
			tablicaPionow[i]->szachowanieETC(tablicaPol, tablicaPionow, i, czyjRuch);
		}
	}
}

void Tszachownica::dzialaj()
{
	rysuj();
	rysujMenu();
	rysujPrzyciski();

	if (koniecGry)
	{

		DrawRectangleRec(Rectangle{ 10, 100, 470, 180 }, Color{ 112, 54, 0, 255 });
		DrawRectangleLinesEx(Rectangle{ 10, 100, 470, 180 }, 5, Color{ 0, 0, 0, 200 });

		DrawRectangleRec(Rectangle{ 450, 100, 30, 30 }, RED);
		DrawText("X", 453, 97, 40, BLACK);

		if (((450 < GetMouseX()) && (480 > GetMouseX()) &&
			(100 < GetMouseY()) && (130 > GetMouseY())))

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				koniecGry = false;
			

		DrawText(zdanie.c_str(), 20, 110, 40, BLACK);
	}

	if (!czyMenuGlowne)
	{
		timer += GetFrameTime();
		if (timer >= 1.0f)
		{
			if (!kliknieciePrzyciskuRemisu.czyPierwszeKlikniecie)
				kliknieciePrzyciskuRemisu.odliczanie();
			if (czyjRuch)
			{
				czasCzarnego -= 1;	
				if (czasCzarnego <= 0)
					if (sprawdzenieRemisu(!czyjRuch))
						Remis("brak czasu\ni brak materialu");
					else
						Zwyciestwo("brak czasu", !czyjRuch);
			} 
			else
			{
				czasBialego -= 1;
				if (czasBialego <= 0)
					if (sprawdzenieRemisu(!czyjRuch))
						Remis("brak czasu\ni brak materialu");
					else
						Zwyciestwo("brak czasu", !czyjRuch);
			}
			timer = 0.0f;
		}

		rysujZaznaczonePola();

		if (!jestMat && !jestPat && jestAwans > 63)
		{
			nacisnietePole();
		}
		else if (jestMat)
		{
			Zwyciestwo("Mata", !czyjRuch);
		}
		else if (jestPat)
		{
			Remis("Pata");
		}
		else // jest awans pionka
		{
			wykonanieAwansu(jestAwans);
		}
	}
}

void Tszachownica::wykonanieAwansu(int pozycja)
{
	DrawRectangle(0, 0, 512, 512, Color{ 0, 0, 0, 150 });

	float pozycjaX = ((pozycja % 8) * 64.0f) - 5.0f;

	if (pozycja < 31)
	{// na gorze
		DrawRectangleV(Vector2{ pozycjaX , 5.0f }, Vector2{ 74.0f, 280.0f}, Color{ 163, 92, 0 , 255});

		DrawTexture(LoadTexture("Textures/Pionki/bialyHetman.png"), pozycjaX + 10, 10, WHITE);
		DrawTexture(LoadTexture("Textures/Pionki/bialaWierza.png"), pozycjaX + 15, 80, WHITE);
		DrawTexture(LoadTexture("Textures/Pionki/bialyGoniec.png"), pozycjaX + 10, 150, WHITE);
		DrawTexture(LoadTexture("Textures/Pionki/bialySkoczek1.png"), pozycjaX + 10, 220, WHITE);

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if ((pozycjaX < GetMouseX()) && (pozycjaX + 74 > GetMouseX()))
			{
				for (int i = 0; i < 4; i++)
				{
					if ((i * 70 + 5 < GetMouseY()) && ((i + 1) * 70 > GetMouseY()))
					{
						podmianaPionkaNaWybranaFigure(i, pozycja, false);
						jestAwans = 99;
						szachowanieETCszachownica(!czyjRuch);
					}
				}
			}
		}

	}
	else// na dole
	{
		DrawRectangleV(Vector2{ pozycjaX , 227.0f }, Vector2{ 74.0f, 280.0f }, Color{ 163, 92, 0 , 255 });

		DrawTexture(LoadTexture("Textures/Pionki/czarnyHetman.png"), pozycjaX + 10, 450, WHITE);
		DrawTexture(LoadTexture("Textures/Pionki/czarnaWierza.png"), pozycjaX + 15, 380, WHITE);
		DrawTexture(LoadTexture("Textures/Pionki/czarnyGoniec.png"), pozycjaX + 10, 310, WHITE);
		DrawTexture(LoadTexture("Textures/Pionki/czarnySkoczek1.png"), pozycjaX + 10, 240, WHITE);

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if ((pozycjaX < GetMouseX()) && (pozycjaX + 74 > GetMouseX()))
				for (int i = 0; i < 4; i++)
			{
				{
					if ((i * 70 + 227 < GetMouseY()) && ((i + 1) * 70 + 227 > GetMouseY()))
					{
						podmianaPionkaNaWybranaFigure(3 - i, pozycja, true);
						jestAwans = 99;
						szachowanieETCszachownica(!czyjRuch);
					}
				}
			}
		}

	}

	
}

void Tszachownica::podmianaPionkaNaWybranaFigure(int numer, int pozycjaPionka, bool czyCzarni)
{
	delete tablicaPionow[pozycjaPionka];
	switch (numer)
	{
	case 0: // hetman
	{
		czyCzarni ?
			tablicaPionow[pozycjaPionka] = new Thetman{ Tkoordynaty{ (pozycjaPionka % 8) * 64 + 4 , (pozycjaPionka / 8) * 64 + 7 },	pozycjaPionka, true, 99,		"Textures/Pionki/czarnyHetman.png", "", "" } :
			tablicaPionow[pozycjaPionka] = new Thetman{ Tkoordynaty{ (pozycjaPionka % 8) * 64 + 4 , (pozycjaPionka / 8) * 64 + 7 },	pozycjaPionka, false, 99,		"Textures/Pionki/bialyHetman.png", "", "" };
		break;
	}
	case 1: // wierza
	{
		czyCzarni ?
			tablicaPionow[pozycjaPionka] = new Twierza{ Tkoordynaty{ (pozycjaPionka % 8) * 64 + 11 , (pozycjaPionka / 8) * 64 + 5 },	pozycjaPionka, true, 2,		"Textures/Pionki/czarnaWierza.png", "", "" } :
			tablicaPionow[pozycjaPionka] = new Twierza{ Tkoordynaty{ (pozycjaPionka % 8) * 64 + 11 , (pozycjaPionka / 8) * 64 + 5 },	pozycjaPionka, false, 2,		"Textures/Pionki/bialaWierza.png", "", "" };
		break;
	}
	case 2: // goniec
	{
		czyCzarni ?
			tablicaPionow[pozycjaPionka] = new Tgoniec{ Tkoordynaty{ (pozycjaPionka % 8) * 64 + 6 , (pozycjaPionka / 8) * 64 + 7 },	pozycjaPionka, true, 99,		"Textures/Pionki/czarnyGoniec.png", "", "" } :
			tablicaPionow[pozycjaPionka] = new Tgoniec{ Tkoordynaty{ (pozycjaPionka % 8) * 64 + 6 , (pozycjaPionka / 8) * 64 + 7 },	pozycjaPionka, false, 99,		"Textures/Pionki/bialyGoniec.png", "", "" };
		break;
	}
	case 3: // skoczek
	{
		czyCzarni ?
			tablicaPionow[pozycjaPionka] = new Tskoczek{ Tkoordynaty{ (pozycjaPionka % 8) * 64 + 5 , (pozycjaPionka / 8) * 64 + 7 },	pozycjaPionka, true, 99,		"Textures/Pionki/czarnySkoczek1.png", "", "" } :
			tablicaPionow[pozycjaPionka] = new Tskoczek{ Tkoordynaty{ (pozycjaPionka % 8) * 64 + 5 , (pozycjaPionka / 8) * 64 + 7 },	pozycjaPionka, false, 99,		"Textures/Pionki/bialySkoczek1.png", "", "" };
		break;
	}
	}//switch
}

void Tszachownica::Zwyciestwo(std::string slowo, bool kto)
{
	czyMenuGlowne = true;
	// dzwiek mata
	koniecGry = true;
	zdanie += "Wygral ";
	kto ? zdanie += "Czarny\n" : zdanie += "Bialy \n";
	zdanie += "poprzez "; zdanie += slowo; zdanie += " !";

}

void Tszachownica::Remis(std::string slowo)
{
	czyMenuGlowne = true;
	// dzwiek remisu
	koniecGry = true;
	zdanie += "Remis poprzez\n";
	zdanie += slowo; zdanie += " !";
}

bool Tszachownica::sprawdzenieRemisu(bool team)
{
	bool potencjalnyRemis{ false };

	if (team)
	{
		if (materialCzarnego == 0)
			return true;
		else if (materialCzarnego == 3)
			potencjalnyRemis = true;
	}
	else
	{
		if (materialBialego == 0)
			return true;
		else if (materialBialego == 3)
			potencjalnyRemis = true;
	}

	if (potencjalnyRemis)
	{
		for (int i = 0; i < 64; i++)
		{
			if (tablicaPol[i]->zajete)
			{
				if (tablicaPionow[i]->druzyna == team)
				{
					if (tablicaPionow[i]->kimJestem == 4 || tablicaPionow[i]->kimJestem == 5 || tablicaPionow[i]->kimJestem == 6)
						return true;
					else if (tablicaPionow[i]->kimJestem != 1)
						return false;
				}
			}
		}
	}
	return false;
}