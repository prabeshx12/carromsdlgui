#include "headers/score.h"

#include <iostream>

extern Initialization* MainWindow;


void PlayerInfo::displayPlayerName(std::string playername) {

	FontManager::LFont(MainWindow->renderer, playername_surface, playername_texture, MainWindow->fontType, playername, { 255, 255, 255 }, &r15);

}

void PlayerInfo::displayPlayerScore(int playerscore = 0) {

	/*std::string playersc = std::to_string(playerscore);
	FontManager::LFont(MainWindow->renderer, score_surface, score_texture, MainWindow->fontType, playerscore, { 255, 255, 255 }, &r16);*/

}
