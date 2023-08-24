#include <iostream>
#include "headers/CarromPiece.h"
#include "headers/MainFrame.h"
#include "headers/Physics.h"


void CarromPiece::initialize()
{
    // Initial position of the image
    positionRect.x = 0;                 // Center horizontally
    positionRect.y = 0;                 // Center vertically
    positionRect.w = CARROM_PIECE_SIZE; // Width of the rendered image
    positionRect.h = CARROM_PIECE_SIZE; // Height of the rendered image
}

void CarromPiece::initialize(SDL_Rect destinationRect)
{
    // Initial position of the image
    positionRect.x = destinationRect.x; // Center horizontally
    positionRect.y = destinationRect.y; // Center vertically
    positionRect.w = destinationRect.w; // Width of the rendered image
    positionRect.h = destinationRect.h; // Height of the rendered image
}

void CarromPiece::setPosition(Vector<float> v)
{
    positionRect.x = v.x; // Center horizontally
    positionRect.y = v.y; // Center vertically
}

void CarromPiece::updatePosition(Vector<float> v)
{
    positionRect.x += v.x; // Center horizontally
    positionRect.y += v.y; // Center vertically
}

void CarromPiece::setVelocity()
{
    pieceVelocity.x = 0;
    pieceVelocity.y = 0;
}

void CarromPiece::setVelocity(Vector<float> velocity)
{
    pieceVelocity.x = int(velocity.x);
    pieceVelocity.y = int(velocity.y);
}

bool CarromPiece::CheckCollision(const CarromPiece* other) const
{
    if (displayPiece == true && other->displayPiece == true)
    {
        return (positionRect.x < other->positionRect.x + 45 &&
            positionRect.x + 45 > other->positionRect.x &&
            positionRect.y < other->positionRect.y + 45 &&
            positionRect.y + 45 > other->positionRect.y);
    }
    return false;
}

void CarromPiece::HandleCollision(CarromPiece* other)
{
    border_collision_checker(this);
    border_collision_checker(other);
    if (CheckCollision(other))
    {
        // Calculate the overlap between entities
        float overlapX = (positionRect.x + positionRect.w / 2) - (other->positionRect.x + other->positionRect.w / 2);
        float overlapY = (positionRect.y + positionRect.h / 2) - (other->positionRect.y + other->positionRect.h / 2);

        // Separate the entities based on the overlap
        if (std::abs(overlapX) > std::abs(overlapY))
        {
            positionRect.x += overlapX > 0 ? 1.0f : -1.0f;
            other->positionRect.x -= overlapX > 0 ? 1.0f : -1.0f;
        }
        else
        {
            positionRect.y += overlapY > 0 ? 1.0f : -1.0f;
            other->positionRect.y -= overlapY > 0 ? 1.0f : -1.0f;
        }

        // Swap velocities to simulate elastic collision
        std::swap(pieceVelocity.x, other->pieceVelocity.x);
        std::swap(pieceVelocity.y, other->pieceVelocity.y);
    }
}

bool CarromPiece::CheckPocket() const
{
    return (((positionRect.x < GAME_BORDER + POCKET_WIDTH - CARROM_PIECE_SIZE * 1 / 2) && (positionRect.y < GAME_BORDER + POCKET_WIDTH - CARROM_PIECE_SIZE * 1 / 2)) ||                               // Top Left
        ((positionRect.x < GAME_BORDER + POCKET_WIDTH - CARROM_PIECE_SIZE * 1 / 2) && (positionRect.y > WIN_HEIGHT - GAME_BORDER - POCKET_WIDTH - CARROM_PIECE_SIZE * 1 / 2)) ||               // Bottom Left
        ((positionRect.x > WIN_HEIGHT - GAME_BORDER - POCKET_WIDTH - CARROM_PIECE_SIZE * 1 / 2) && (positionRect.y < GAME_BORDER + POCKET_WIDTH - CARROM_PIECE_SIZE * 1 / 2)) ||                // Top Right
        ((positionRect.x > WIN_HEIGHT - GAME_BORDER - POCKET_WIDTH - CARROM_PIECE_SIZE * 1 / 2) && (positionRect.y > WIN_HEIGHT - GAME_BORDER - POCKET_WIDTH - CARROM_PIECE_SIZE * 1 / 2))); // Bottom Left
}

void CarromPiece::Update()
{
    if (pieceVelocity.x != 0 && pieceVelocity.y != 0)
    {
        moving = true;
    }
    else
    {
        moving = false;
    }
}

void CarromPiece::HandlePocket()
{
    if (CheckPocket())
    {
        displayPiece = false;
    }
}

void Striker::initialize(SDL_Renderer* renderer)
{
    imageSurface = IMG_Load("assets/striker.png");
    if (!imageSurface)
    {
        std::cout << "Image could not be loaded! SDL_Error: \n" << IMG_GetError();
        return;
    }
    imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    // Initial position of the image
    positionRect.x = WIN_HEIGHT / 2 - STRIKER_PIECE_SIZE / 2; // Center horizontally
    positionRect.y = 20;                        // Center vertically
    positionRect.w = STRIKER_PIECE_SIZE;        // Width of the rendered image
    positionRect.h = STRIKER_PIECE_SIZE;        // Height of the rendered image
}

void White::initialize(SDL_Renderer* renderer)
{
    imageSurface = IMG_Load("assets/white.png");
    if (!imageSurface)
    {
        std::cout << "Image could not be loaded! SDL_Error: \n" << IMG_GetError();
        return;
    }
    imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    // Initial position of the image
    positionRect.x = WIN_HEIGHT / 2 - 45 / 2;  // Center horizontally
    positionRect.y = WIN_HEIGHT / 2 - 45 / 2; // Center vertically
    positionRect.w = CARROM_PIECE_SIZE;          // Width of the rendered image
    positionRect.h = CARROM_PIECE_SIZE;          // Height of the rendered image
}

void Black::initialize(SDL_Renderer* renderer)
{
    imageSurface = IMG_Load("assets/black.png");
    if (!imageSurface)
    {
        std::cout << "Image could not be loaded! SDL_Error: \n" << IMG_GetError();
        return;
    }
    imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    // Initial position of the image
    positionRect.x = WIN_HEIGHT - 100;  // Center horizontally
    positionRect.y = WIN_HEIGHT - 100; // Center vertically
    positionRect.w = CARROM_PIECE_SIZE;   // Width of the rendered image
    positionRect.h = CARROM_PIECE_SIZE;   // Height of the rendered image
}

void Queen::initialize(SDL_Renderer* renderer)
{
    imageSurface = IMG_Load("assets/queen.png");
    if (!imageSurface)
    {
        std::cout << "Image could not be loaded! SDL_Error: \n" << IMG_GetError();
        return;
    }
    imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    // Initial position of the image
    positionRect.x = WIN_HEIGHT - 200;  // Center horizontally
    positionRect.y = WIN_HEIGHT - 200; // Center vertically
    positionRect.w = CARROM_PIECE_SIZE;   // Width of the rendered image
    positionRect.h = CARROM_PIECE_SIZE;   // Height of the rendered image
}
