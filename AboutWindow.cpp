#include "headers/AboutWindow.h"
#include "headers/TextureManager.h"
#include "headers/MainFrame.h"
#include "headers/MainMenu.h"
#include "headers/fonts.h"
#include "headers/music.h"

extern Initialization* MainWindow;
extern MainMenu MenuWindow;
extern Music* ClickSound;

void AboutSection::render_about_window() {
	
	about_win_surface = IMG_Load("assets/background.png");
	TextureManager::LTexture(MainWindow->renderer, about_win_surface, about_win_texture, NULL, NULL);

}

void AboutSection::render_message() {

    FontManager::LFont(MainWindow->renderer, message_surface, message_texture, MainWindow->fontType, "Carrom King v 0.1.1", { 255, 255, 255 }, &r5);

}

void AboutSection::render_close_button() {

    if (close_button_state == true) {
        close_surface = IMG_Load("buttons/close_two.png");
        close_button_state = false;
    }
    else {
        close_surface = IMG_Load("buttons/close_one.png");
        close_button_state = true;
    }

    TextureManager::LTexture(MainWindow->renderer, close_surface, close_texture, NULL, &r6);

}

void AboutSection::handleAboutWindowEvents(SDL_Event e) {

    switch (e.type) {
        case SDL_MOUSEBUTTONDOWN:
            int x, y;
            SDL_GetMouseState(&x, &y);
            if (SDL_BUTTON_LEFT == e.button.button) {
                if (x >= 440 + offsetX && x <= 640 + offsetX && y >= 540 + offsetY && y <= 680 + BUT_HEIGHT + offsetY) {

                    render_close_button();
                    ClickSound->PlayClickMusic(1);
                    SDL_RenderClear(MainWindow->renderer);
                    currState = MAINMENU;
                    MenuWindow.reset_button_states();
                    MenuWindow.main_menu_window();
                }
            }
            break;
        default:
            break;
    }

}