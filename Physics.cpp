#include "headers/Physics.h"
#include "headers/MainFrame.h"


void border_collision_checker(CarromPiece* carromPiece)
{
    // Check for collision with screen edges
    if (carromPiece->positionRect.x <= GAME_BORDER || carromPiece->positionRect.x >= WIN_HEIGHT - carromPiece->positionRect.w - GAME_BORDER)
    {
        if (carromPiece->positionRect.x < GAME_BORDER)
        {
            carromPiece->positionRect.x = GAME_BORDER;
        }
        else if (carromPiece->positionRect.x > WIN_HEIGHT - carromPiece->positionRect.w - GAME_BORDER)
        {
            carromPiece->positionRect.x = WIN_HEIGHT - carromPiece->positionRect.w - GAME_BORDER;
        }
        carromPiece->pieceVelocity.x = -carromPiece->pieceVelocity.x; // Reverse X-axis movement direction and apply momentum loss
    }
    if (carromPiece->positionRect.y <= GAME_BORDER || carromPiece->positionRect.y >= WIN_HEIGHT - carromPiece->positionRect.h - GAME_BORDER)
    {
        if (carromPiece->positionRect.y < GAME_BORDER)
        {
            carromPiece->positionRect.y = GAME_BORDER;
        }
        else if (carromPiece->positionRect.y > WIN_HEIGHT - carromPiece->positionRect.h - GAME_BORDER)
        {
            carromPiece->positionRect.y = WIN_HEIGHT - carromPiece->positionRect.h - GAME_BORDER;
        }
        carromPiece->pieceVelocity.y = -carromPiece->pieceVelocity.y; // Reverse Y-axis movement direction and apply momentum loss
    }
}

template <class T>
void movement(T* carromPiece)
{
    double deceleration = 0.00001;
    // Update image position
    carromPiece->positionRect.x += carromPiece->pieceVelocity.x;
    carromPiece->positionRect.y += carromPiece->pieceVelocity.y;

    // Deceleration
    if (carromPiece->pieceVelocity.x > 0)
        carromPiece->pieceVelocity.x -= deceleration;
    else if (carromPiece->pieceVelocity.x < 0)
        carromPiece->pieceVelocity.x += deceleration;
    if (carromPiece->pieceVelocity.y > 0)
        carromPiece->pieceVelocity.y -= deceleration;
    else if (carromPiece->pieceVelocity.y < 0)
        carromPiece->pieceVelocity.y += deceleration;
}

void collide_and_rebound(Striker* striker, Queen* queen, White* white, Black* black)
{
    double deceleration = 0.0001;

    movement(striker);
    movement(queen);
    for (int i = 0; i < 9; i++)
    {
        movement(white);
        movement(black);
    }
}