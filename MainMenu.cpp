#include "headers/MainMenu.h"
#include "headers/MainFrame.h"
#include "headers/GameModeWindow.h"
#include "headers/TextureManager.h"
#include "headers/AboutWindow.h"

extern Initialization* MainWindow;
extern NewGameModes ModeWindow;
extern AboutSection AboutWindow;


void MainMenu::render_developer_window() {

    developer_surface = IMG_Load("assets/logo.png");
    TextureManager::LTexture(MainWindow->renderer, developer_surface, developer_texture, NULL, NULL);
    SDL_Delay(2000);

}

void MainMenu::render_game_logo_window() {

    game_logo_surface = IMG_Load("assets/carrom.png");
    TextureManager::LTexture(MainWindow->renderer, game_logo_surface, game_logo_texture, NULL, NULL);
    SDL_Delay(2000);

}

void MainMenu::carrom_menu_background() {

    background_surface = IMG_Load("assets/carrom_background.png");
    TextureManager::LTexture(MainWindow->renderer, background_surface, background_texture, NULL, NULL);
    SDL_Delay(400);

}

void MainMenu::render_new_game_button() {

    if (new_game_button_state == true) {
        new_game_surface = IMG_Load("buttons/new_game_two.png");
        new_game_button_state = false;
    }
    else {
        new_game_surface = IMG_Load("buttons/new_game_one.png");
        new_game_button_state = true;
    }

    TextureManager::LTexture(MainWindow->renderer, new_game_surface, new_game_texture, NULL, &r1);
    SDL_Delay(100);

}

void MainMenu::render_leaderboard_button() {

    if (leaderboard_button_state == true) {
        leaderboard_surface = IMG_Load("buttons/leaderboard_two.png");
        leaderboard_button_state = false;
    }
    else {
        leaderboard_surface = IMG_Load("buttons/leaderboard_one.png");
        leaderboard_button_state = true;
    }

    TextureManager::LTexture(MainWindow->renderer, leaderboard_surface, leaderboard_texture, NULL, &r2);
    SDL_Delay(100);

}

void MainMenu::render_about_button() {

    if (about_button_state == true) {
        about_surface = IMG_Load("buttons/about_two.png");
        about_button_state = false;
    }
    else {
        about_surface = IMG_Load("buttons/about_one.png");
        about_button_state = true;
    }

    TextureManager::LTexture(MainWindow->renderer, about_surface, about_texture, NULL, &r3);
    SDL_Delay(100);

}

void MainMenu::render_exit_button() {

    if (exit_button_state == true) {
        exit_surface = IMG_Load("buttons/exit_two.png");
        exit_button_state = false;
    }
    else {
        exit_surface = IMG_Load("buttons/exit_one.png");
        exit_button_state = true;
    }

    TextureManager::LTexture(MainWindow->renderer, exit_surface, exit_texture, NULL, &r4);

}

void MainMenu::main_menu_window() {

    carrom_menu_background();
    render_new_game_button();
    render_leaderboard_button();
    render_about_button();
    render_exit_button();

}

void MainMenu::reset_button_states() {

    new_game_button_state = true;
    leaderboard_button_state = true;
    about_button_state = true;
    exit_button_state = true;

}

void MainMenu::handleMainMenuEvents(SDL_Event e) {

    switch (e.type) {
        case SDL_MOUSEBUTTONDOWN:
            int x, y;
            SDL_GetMouseState(&x, &y);

            if (SDL_BUTTON_LEFT == e.button.button) {

                if (x >= 720 && x <= (720 + BUT_WIDTH) && y >= 200 && y <= (200 + BUT_HEIGHT)) {
                    render_new_game_button();
                    currState = NEWGAME;
                    SDL_RenderClear(MainWindow->renderer);
                    carrom_menu_background();
                    ModeWindow.reset_mode_buttons_states();
                    ModeWindow.render_mode_buttons();

                }

                else if (x >= 720 && x <= (720 + BUT_WIDTH) && y >= 325 && y <= (325 + BUT_HEIGHT)) {
                    render_leaderboard_button();
                }

                else if (x >= 770 && x <= (770 + 200) && y >= 450 && y <= (450 + BUT_HEIGHT)) {
                    render_about_button();
                    currState = ABOUT;
                    SDL_RenderClear(MainWindow->renderer);
                    AboutWindow.render_about_window();
                    AboutWindow.render_close_button();
                }

                else if (x >= 770 && x <= (770 + 200) && y >= 575 && y <= (575 + BUT_HEIGHT)) {
                    render_exit_button();
                    MainWindow->is_running = false;
                }
            }
            break;

        default:
            break;
    }

}