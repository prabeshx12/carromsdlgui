#include<SDL.h>
#include<SDL_image.h>
#include "headers/MainFrame.h"
#include "headers/MainMenu.h"
#include "headers/GameModeWindow.h"
#include "headers/AboutWindow.h"
#include "headers/music.h"

Initialization* MainWindow = nullptr;
MainMenu MenuWindow;
NewGameModes ModeWindow;
AboutSection AboutWindow;
Music* BackMusic;
Music* ClickSound;

const int WIN_WIDTH = 1180, WIN_HEIGHT = 950;
windowStates currState;

int main(int argc, char* argv[]) {

	currState = MAINMENU;

	MainWindow = new Initialization();
	BackMusic = new Music("music/background_one.mp3");
	ClickSound = new Music("music/selection_music.mp3");

	MainWindow->windowInit("CarromKing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, false);
	MenuWindow.render_developer_window();
	MenuWindow.render_game_logo_window();
	BackMusic->PlayBackgroundMusic(-1);
	MenuWindow.main_menu_window();

	SDL_Event event;

	while (MainWindow->runningState()) {

		if (SDL_PollEvent(&event)) {
			MainWindow->handleMainEvent(event);

			switch (currState) {
				case MAINMENU:
					MenuWindow.handleMainMenuEvents(event);
					break;

				case NEWGAME:
					ModeWindow.handleNewGameModeEvents(event);
					break;

				case LEADERBOARD:
					break;

				case ABOUT:
					AboutWindow.handleAboutWindowEvents(event);
					break;

				case SINGLEPLAYER:
					break;

				case MULTIPLAYER:
					break;

				case OVERLAN:
					break;

				default:
					break;

			}
		}


	}

	MainWindow->clean();

	return 0;
}