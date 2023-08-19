#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include "headers/MainMenu.h"


class AboutSection {
	private:
		bool close_button_state = true;
		SDL_Surface* about_win_surface, * close_surface, * message_surface;
		SDL_Texture* about_win_texture, * close_texture, * message_texture;
		int offsetX = 60;
		int offsetY = 100;

	public:
		SDL_Rect r5{ 330 + offsetX, 70 + offsetY, 400, 70 };
		SDL_Rect r6{ 440 + offsetX, 680 + offsetY, 200, BUT_HEIGHT };
		

		void render_about_window();

		void render_message();

		void render_close_button();

		void handleAboutWindowEvents(SDL_Event e);

};
