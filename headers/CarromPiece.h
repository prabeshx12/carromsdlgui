#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Vector.h"
#include "MainFrame.h"

class CarromPiece
{
public:
    SDL_Surface* imageSurface;
    SDL_Rect positionRect;
    Vector<float> pieceVelocity;
    double radius = (CARROM_PIECE_SIZE / 2.0);
    bool displayPiece;
    bool moving = false;

    CarromPiece() {}

    virtual void initialize();

    virtual void initialize(SDL_Rect destinationRect);

    void setPosition(Vector<float> v);

    void updatePosition(Vector<float> v);

    void setVelocity();

    void setVelocity(Vector<float> velocity);

    bool CheckCollision(const CarromPiece* other) const;

    void HandleCollision(CarromPiece* other);

    bool CheckPocket() const;

    void Update();

    void HandlePocket();
};


class Striker : public CarromPiece
{
public:
    SDL_Texture* imageTexture;

    Striker(SDL_Renderer* renderer, bool display = true)
    {
        radius = STRIKER_PIECE_SIZE / 2.0;
        displayPiece = display;
        initialize(renderer);
        setVelocity();
    }

    Striker(SDL_Renderer* renderer, Vector<float> strikerVelocity, bool display = true)
    {
        radius = STRIKER_PIECE_SIZE / 2.0;
        displayPiece = display;
        initialize(renderer);
        setVelocity(strikerVelocity);
    }

    void initialize(SDL_Renderer* renderer);
};


class White : public CarromPiece
{
public:
    SDL_Texture* imageTexture;

    White(SDL_Renderer* renderer, bool display = true)
    {
        displayPiece = display;
        initialize(renderer);
        setVelocity();
    }

    White(SDL_Renderer* renderer, Vector<float> strikerVelocity, bool display = true)
    {
        displayPiece = display;
        initialize(renderer);
        setVelocity(strikerVelocity);
    }

    void initialize(SDL_Renderer* renderer);
};


class Black : public CarromPiece
{
public:
    SDL_Texture* imageTexture;

    Black(SDL_Renderer* renderer, bool display = true)
    {
        displayPiece = display;
        initialize(renderer);
        setVelocity();
    }

    Black(SDL_Renderer* renderer, Vector<float> strikerVelocity, bool display = true)
    {
        displayPiece = display;
        initialize(renderer);
        setVelocity(strikerVelocity);
    }

    void initialize(SDL_Renderer* renderer);
};


class Queen : public CarromPiece
{
public:
    SDL_Texture* imageTexture;

    Queen(SDL_Renderer* renderer, bool display = true)
    {
        displayPiece = display;
        initialize(renderer);
        setVelocity();
    }

    Queen(SDL_Renderer* renderer, Vector<float> strikerVelocity, bool display = true)
    {
        displayPiece = display;
        initialize(renderer);
        setVelocity(strikerVelocity);
    }

    void initialize(SDL_Renderer* renderer);
};

