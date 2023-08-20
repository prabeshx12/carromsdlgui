#include "headers/SinglePlayerGame.h"
#include "headers/music.h"
#include "headers/MainFrame.h"
#include "headers/TextureManager.h"
#include "headers/fonts.h"

extern Initialization* MainWindow;
extern Music* ClickSound;


void SinglePlayerGame::carrom_background() {

	carrom_background_surface = IMG_Load("assets/background.png");

	TextureManager::LTexture(MainWindow->renderer, carrom_background_surface, carrom_background_texture, NULL, NULL);

}


void SinglePlayerGame::render_carrom_board() {

	carrom_surface = IMG_Load("assets/carrom_board.png");

	TextureManager::LTexture(MainWindow->renderer, carrom_surface, carrom_texture, NULL, &r14);

}

void SinglePlayerGame::render_singleplayer_window() {

	carrom_background();
	render_carrom_board();

}

void SinglePlayerGame::handleSinglePlayerGameEvents(SDL_Event e) {

	switch (e.type) {
		case SDL_MOUSEBUTTONDOWN:
			if (e.type == SDL_BUTTON_LEFT) {

				break;
			}
			break;

		default:
			break;
	}

}
