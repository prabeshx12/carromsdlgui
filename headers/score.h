#pragma once
#include "MainFrame.h"
#include "PlayerIntro.h"
#include "fonts.h"
#include "TextureManager.h"
#include <iostream>

struct PlayerInfo {

	SDL_Texture* score_texture, * playername_texture;
	SDL_Surface* score_surface, * playername_surface;

	SDL_Rect r15{ 950 + 10, 550, 200, 50 };

	SDL_Rect r16{ 950 + 50, 450, 100, 50 };

	std::string PlayerName;
	int score;

	void displayPlayerName(std::string playername);

	void displayPlayerScore(int playerscore);

};

