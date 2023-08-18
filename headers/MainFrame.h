#pragma once
#include <SDL.h>
#include<SDL_image.h>

enum windowStates {
	MAINMENU,
	NEWGAME,
	LEADERBOARD,
	ABOUT,
	SINGLEPLAYER,
	MULTIPLAYER,
	OVERLAN
};

extern windowStates currState;

class Initialization {

	private:

		int flags = 0;

	public:

		SDL_Window* window;
		SDL_Renderer* renderer;
		bool is_running = true;

		Initialization() {}
		~Initialization() {}

		void windowInit(const char* title, int x_pos, int y_pos, int p_w, int p_h, bool fullscreen);

		bool runningState() { return is_running; }

		void handleMainEvent(SDL_Event e);
		
		void clean();
};	
