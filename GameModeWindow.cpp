#include "headers/GameModeWindow.h"
#include "headers/MainFrame.h"
#include "headers/TextureManager.h"
#include "headers/MainMenu.h"

extern Initialization* MainWindow;
extern MainMenu MenuWindow;

void NewGameModes::render_singleplayer_button() {

    if (single_player_button_state == true) {
        single_player_surface = IMG_Load("buttons/single_player_two.png");
        single_player_button_state = false;
    }

    else {
        single_player_surface = IMG_Load("buttons/single_player_one.png");
        single_player_button_state = true;
    }

	TextureManager::LTexture(MainWindow->renderer, single_player_surface, single_player_texture, NULL, &r1);
    SDL_Delay(100);
}

void NewGameModes::render_multiplayer_button() {

    if (multiplayer_button_state == true) {
        multiplayer_surface = IMG_Load("buttons/multiplayer_two.png");
        multiplayer_button_state = false;
    }
    else {
        multiplayer_surface = IMG_Load("buttons/multiplayer_one.png");
        multiplayer_button_state = true;
    }

    TextureManager::LTexture(MainWindow->renderer, multiplayer_surface, multiplayer_texture, NULL, &r2);
    SDL_Delay(100);

}

void NewGameModes::render_overlan_button() {

    if (over_LAN_button_state == true) {
        over_LAN_surface = IMG_Load("buttons/over_LAN_two.png");
        over_LAN_button_state = false;
    }
    else {
        over_LAN_surface = IMG_Load("buttons/over_LAN_one.png");
        over_LAN_button_state = true;
    }

    TextureManager::LTexture(MainWindow->renderer, over_LAN_surface, over_LAN_texture, NULL, &r7);
    SDL_Delay(100);

}

void NewGameModes::render_back_button() {

    if (back_button_state == true) {
        back_surface = IMG_Load("buttons/back_two.png");
        back_button_state = false;
    }
    else {
        back_surface = IMG_Load("buttons/back_one.png");
        back_button_state = true;
    }

    TextureManager::LTexture(MainWindow->renderer, back_surface, back_texture, NULL, &r4);

}

void NewGameModes::render_mode_buttons() {

    render_singleplayer_button();
    render_multiplayer_button();
    render_overlan_button();
    render_back_button();

}

void NewGameModes::reset_mode_buttons_states() {

    single_player_button_state = true;
    multiplayer_button_state = true;
    over_LAN_button_state = true;
    back_button_state = true;

}

void NewGameModes::handleNewGameModeEvents(SDL_Event e) {

    switch (e.type) {
        case SDL_MOUSEBUTTONDOWN:
            int x, y;
            SDL_GetMouseState(&x, &y);
            if (SDL_BUTTON_LEFT == e.button.button) {

                if (x >= 720 && x <= (720 + BUT_WIDTH) && y >= 200 && y <= (200 + BUT_HEIGHT)) {
                    render_singleplayer_button();
                }

                else if (x >= 720 && x <= (720 + BUT_WIDTH) && y >= 325 && y <= (325 + BUT_HEIGHT)) {
                    render_multiplayer_button();
                }

                else if (x >= 745 && x <= (995) && y >= 450 && y <= (450 + BUT_HEIGHT)) {
                    render_overlan_button();
                }

                else if (x >= 770 && x <= 970 && y >= 575 && 575 + BUT_HEIGHT) {
                    render_back_button();
                    currState = MAINMENU;
                    SDL_RenderClear(MainWindow->renderer);
                    MenuWindow.reset_button_states();
                    MenuWindow.main_menu_window();
                    
                }
            }
            break;

        default:
            break;
    }

}