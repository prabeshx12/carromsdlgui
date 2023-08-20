#pragma once
#include "MainMenu.h"
#include "music.h"
#include "SinglePlayerGame.h"
#include "Vector.h"

class CarromPiece {
	public:

		SDL_Surface* imageSurface;
		SDL_Rect positionRect;
		Vector<int> pieceVelocity;
		bool displayPiece;

		virtual void initialize();

		virtual void initialize(SDL_Rect destinationRect);

		template <class T>
		void setPosition(Vector<T> v);

		void setVelocity();

		template <class T>
		void setVelocity(Vector<T> velocity);

};

class Striker :public CarromPiece {
	public:

		SDL_Texture* imageTexture;

		Striker(SDL_Renderer* renderer, bool display = true) {

			displayPiece = display;
			initialize(renderer);
			setVelocity();

		}

		Striker(SDL_Renderer* renderer, Vector<int> strikerVelocity, bool display = true) {

			displayPiece = display;
			initialize(renderer);
			setVelocity(strikerVelocity);

		}

		void initialize(SDL_Renderer* renderer);

};

class Queen :public CarromPiece {

	public:

		SDL_Texture* imageTexture;

		Queen(SDL_Renderer* renderer, bool display = true) {

			displayPiece = display;
			initialize(renderer);
			setVelocity();

		}

		Queen(SDL_Renderer* renderer, Vector<int> strikerVelocity, bool display = true) {

			displayPiece = display;
			initialize(renderer);
			setVelocity(strikerVelocity);

		}

		void initialize(SDL_Renderer* renderer);

};

class White :public CarromPiece {
	public:

		SDL_Texture* imageTexture;

		White(SDL_Renderer* renderer, bool display = true) {

			displayPiece = display;
			initialize(renderer);
			setVelocity();

		}

		White(SDL_Renderer* renderer, Vector<int> strikerVelocity, bool display = true) {

			displayPiece = display;
			initialize(renderer);
			setVelocity(strikerVelocity);

		}

		void initialize(SDL_Renderer* renderer);

};

class Black :public CarromPiece {
	public:

		SDL_Texture* imageTexture;

		Black(SDL_Renderer* renderer, bool display = true) {

			displayPiece = display;
			initialize(renderer);
			setVelocity();

		}

		Black(SDL_Renderer* renderer, Vector<int> strikerVelocity, bool display = true) {

			displayPiece = display;
			initialize(renderer);
			setVelocity(strikerVelocity);

		}

		void initialize(SDL_Renderer* renderer);

};


