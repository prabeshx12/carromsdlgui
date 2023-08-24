#pragma once
#include <SDL.h>
#include <SDL_image.h>


template <class T>
void render_copy(SDL_Renderer* renderer, T* carromPiece);

template <typename T>
void render_copy_handler(SDL_Renderer* renderer, T *carromPiece);

void handleGameEvent(SDL_Event e);
