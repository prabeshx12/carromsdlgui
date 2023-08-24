#include "headers/GameManager.h"
#include "headers/CarromPiece.h"
#include "headers/MainFrame.h"
#include "headers/Physics.h"
#include "headers/Board.h"

extern Initialization* MainWindow;

template <class T>
void render_copy(SDL_Renderer* renderer, T* carromPiece)
{
    if (carromPiece->displayPiece == true)
    {
        SDL_Rect destRect = { carromPiece->positionRect.x, carromPiece->positionRect.y, carromPiece->positionRect.w, carromPiece->positionRect.h };
        SDL_RenderCopy(renderer, carromPiece->imageTexture, NULL, &destRect);
    }
}

template <typename T>
void render_copy_handler(SDL_Renderer* renderer, T* carromPiece)
{
    if (carromPiece->displayPiece == true)
    {
        render_copy(renderer, carromPiece);
    }
}

void handleGameEvent(SDL_Event e) {
    Striker striker(MainWindow->renderer);
    White white[9] = {
        White(MainWindow->renderer),
        White(MainWindow->renderer),
        White(MainWindow->renderer),
        White(MainWindow->renderer),
        White(MainWindow->renderer),
        White(MainWindow->renderer),
        White(MainWindow->renderer),
        White(MainWindow->renderer),
        White(MainWindow->renderer) };
    Black black[9] = {
        Black(MainWindow->renderer),
        Black(MainWindow->renderer),
        Black(MainWindow->renderer),
        Black(MainWindow->renderer),
        Black(MainWindow->renderer),
        Black(MainWindow->renderer),
        Black(MainWindow->renderer),
        Black(MainWindow->renderer),
        Black(MainWindow->renderer) };
    Queen queen(MainWindow->renderer);
    newBoardState(&striker, white, black, &queen);
    Vector<int> mouse(0, 0);
    Vector<float> speed(10, 10);
    Vector<float>delPosition(0, 0);
    SDL_GetMouseState(&mouse.x, &mouse.y);

    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
    {            
        SDL_GetMouseState(&mouse.x, &mouse.y);
        float speedFactor = 0.1;
        delPosition.y = mouse.y - striker.positionRect.y;
        delPosition.x = mouse.x - striker.positionRect.x;
        speed.x = speedFactor * delPosition.x;
        speed.y = speedFactor * delPosition.y;
        striker.setVelocity(speed);
    }
    else if (e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_r:
            striker.displayPiece = true;
            striker.setPosition(Vector<float>(centerOffset, WIN_HEIGHT - STRIKER_PIECE_SIZE - 115));
            break;

        case SDLK_RIGHT:
            if (striker.positionRect.x <= WIN_HEIGHT - 215)
            {
                striker.updatePosition(Vector<float>(10, 0));
            }
            break;
        case SDLK_LEFT:
            if (striker.positionRect.x >= 165)
            {
                striker.updatePosition(Vector<float>(-10, 0));
            }
            break;

        default:
            break;
        }
    }

    collide_and_rebound(&striker, &queen, white, black);

    // Handle collisions between entities
    striker.HandleCollision(&queen);
    for (int i = 0; i < 9; ++i)
    {
        striker.HandleCollision(&white[i]);
        striker.HandleCollision(&black[i]);
        queen.HandleCollision(&white[i]);
        queen.HandleCollision(&black[i]);
        for (int j = 0; j < 9; ++j)
        {
            white[i].HandleCollision(&white[j]);
            black[i].HandleCollision(&black[j]);
            white[i].HandleCollision(&black[j]);
            white[i].HandleCollision(&queen);
            black[i].HandleCollision(&queen);
        }
    }

    // Handle Pocketting
    striker.HandlePocket();
    queen.HandlePocket();
    for (int i = 0; i < 9; i++)
    {
        white[i].HandlePocket();
        black[i].HandlePocket();
    }

    // Check moving
    striker.Update();
    queen.Update();
    for (int i = 0; i < 9; i++)
    {
        white[i].Update();
        black[i].Update();
    }

    // Handle Rendering
    render_copy_handler(MainWindow->renderer, &striker);
    render_copy_handler(MainWindow->renderer, &queen);
    for (int i = 0; i < 9; i++)
    {
        render_copy_handler(MainWindow->renderer, &white[i]);
    }
    for (int i = 0; i < 9; i++)
    {
        render_copy_handler(MainWindow->renderer, &black[i]);
    }

    /*-----------------------------------------------------------------------------------------------*/

    // Drawing line segment with ends (200, 200) and mouse cursor
    SDL_SetRenderDrawColor(MainWindow->renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(MainWindow->renderer, (striker.positionRect.x + striker.positionRect.w / 2), (striker.positionRect.y + striker.positionRect.h / 2), (mouse.x), (mouse.y));
    // Update the screen
    SDL_RenderPresent(MainWindow->renderer);

    // Delay to control frame rate
    SDL_Delay(16); // ~60 FPS
}