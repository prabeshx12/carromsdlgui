#include "headers/SinglePlayerGame.h"
#include "headers/music.h"
#include "headers/MainFrame.h"
#include "headers/TextureManager.h"
#include "headers/fonts.h"
#include "headers/GameModeWindow.h"
#include "headers/PlayerIntro.h"

extern Initialization* MainWindow;
extern Music* BackMusic;
extern Music* ClickSound;
extern NewGameModes ModeWindow;
extern MainMenu MenuWindow;
extern PlayerIntro IntroWindow;


void SinglePlayerGame::carrom_background() {

	carrom_background_surface = IMG_Load("assets/background.png");

	TextureManager::LTexture(MainWindow->renderer, carrom_background_surface, carrom_background_texture, NULL, NULL);

}


void SinglePlayerGame::render_carrom_board() {

	carrom_surface = IMG_Load("assets/carrom_board.png");

	TextureManager::LTexture(MainWindow->renderer, carrom_surface, carrom_texture, NULL, &r14);

}

void SinglePlayerGame::render_back_button() {

	if (back_button_state == true) {
		back_surface = IMG_Load("buttons/back_two.png");
		back_button_state = false;
	}
	else {
		back_surface = IMG_Load("buttons/back_one.png");
		back_button_state = true;
	}

	TextureManager::LTexture(MainWindow->renderer, back_surface, back_texture, NULL, &r17);

}

void SinglePlayerGame::reset_button_states() {

	back_button_state = true;

}

void SinglePlayerGame::render_singleplayer_window() {

	carrom_background();
	render_carrom_board();
	render_back_button();

}

void SinglePlayerGame::handleSinglePlayerGameEvents(SDL_Event e) {

	switch (e.type) {
		case SDL_MOUSEBUTTONDOWN:
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (e.button.button == SDL_BUTTON_LEFT) {

				// back button events
				if (x >= 960 && x <= 960 + 200 && y >= 750 && y <= 750 + BUT_HEIGHT) {
					render_back_button();
					ClickSound->PlayClickMusic();
					SDL_RenderClear(MainWindow->renderer);
					IntroWindow.textInput = "";

					currState = NEWGAMEMODES;
					BackMusic->PlayBackgroundMusic(-1);
					MenuWindow.carrom_menu_background();
					ModeWindow.reset_mode_buttons_states();
					ModeWindow.render_mode_buttons();

				}

				break;
			}
			break;

		default:
			break;
	}

}
