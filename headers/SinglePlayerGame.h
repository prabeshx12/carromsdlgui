#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <SDL_mixer.h>
#include "MainFrame.h"
#include "MainMenu.h"

const int CARROM_PIECE_SIZE = 42;
const int STRIKER_PIECE_SIZE = 50;

const int BOARD_BORDER = 53;
const int BORDER_LEFT = BOARD_BORDER;
const int BORDER_RIGHT = WIN_WIDTH - 950 - BOARD_BORDER;
const int BORDER_UP = BOARD_BORDER;
const int BORDER_DOWN = WIN_HEIGHT - BOARD_BORDER;

extern Initialization* MainWindow;


class SinglePlayerGame {

	private:
		bool back_button_state = true;
		SDL_Surface* carrom_surface, * carrom_background_surface, * back_surface;
		SDL_Texture* carrom_texture, * carrom_background_texture, * back_texture;

	public:
		SDL_Rect r14{ 0, 0, 950, 950 };
		SDL_Rect r17{ 950 + 10, 750, 200, BUT_HEIGHT };

		void carrom_background();

		void render_carrom_board();

		void render_singleplayer_window();

		void render_back_button();

		void reset_button_states();

		void handleSinglePlayerGameEvents(SDL_Event e);
        

};

