#include "headers/Piece.h"
#include "headers/MainFrame.h"

void CarromPiece::initialize() {

    positionRect.x = 0;                 
    positionRect.y = 0;                 
    positionRect.w = CARROM_PIECE_SIZE; 
    positionRect.h = CARROM_PIECE_SIZE;

}

void CarromPiece::initialize(SDL_Rect destinationRect) {

    positionRect.x = destinationRect.x; 
    positionRect.y = destinationRect.y; 
    positionRect.w = destinationRect.w; 
    positionRect.h = destinationRect.h;

}

template <class T>
void CarromPiece::setPosition(Vector<T> v) {

    positionRect.x = v.x;
    positionRect.y = v.y;

}

void CarromPiece::setVelocity() {

    pieceVelocity.x = 0;
    pieceVelocity.y = 0;

}

template<class T>
void CarromPiece::setVelocity(Vector<T> velocity) {

    pieceVelocity.x = int(velocity.x);
    pieceVelocity.y = int(velocity.y);

}

Striker::Striker(SDL_Renderer* renderer, bool display = true) {

    displayPiece = display;
    initialize(renderer);
    setVelocity();

}

Striker::Striker(SDL_Renderer* renderer, Vector<int> strikerVelocity, bool display = true) {

    displayPiece = display;
    initialize(renderer);
    setVelocity(strikerVelocity);

}

void Striker::initialize(SDL_Renderer* renderer) {

    imageSurface = IMG_Load("objects/striker.png");
    imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    positionRect.x = 950 / 2 - 45 / 2; 
    positionRect.y = 20;                        
    positionRect.w = STRIKER_PIECE_SIZE;        
    positionRect.h = STRIKER_PIECE_SIZE;

}

Queen::Queen(SDL_Renderer* renderer, bool display = true) {

    displayPiece = display;
    initialize(renderer);
    setVelocity();

}

Queen::Queen(SDL_Renderer* renderer, Vector<int> strikerVelocity, bool display = true) {

    displayPiece = display;
    initialize(renderer);
    setVelocity(strikerVelocity);

}

void Queen::initialize(SDL_Renderer* renderer) {

    imageSurface = IMG_Load("objects/queen.png");
    imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    positionRect.x = 950 - 200;
    positionRect.y = WIN_HEIGHT - 200; 
    positionRect.w = CARROM_PIECE_SIZE;   
    positionRect.h = CARROM_PIECE_SIZE;

}

White::White(SDL_Renderer* renderer, bool display = true) {

    displayPiece = display;
    initialize(renderer);
    setVelocity();

}

White::White(SDL_Renderer* renderer, Vector<int> strikerVelocity, bool display = true) {

    displayPiece = display;
    initialize(renderer);
    setVelocity(strikerVelocity);

}

void White::initialize(SDL_Renderer* renderer) {

    imageSurface = IMG_Load("objects/white.png");
    imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    positionRect.x = 950 / 2 - 45 / 2;  
    positionRect.y = WIN_HEIGHT / 2 - 45 / 2; 
    positionRect.w = CARROM_PIECE_SIZE;          
    positionRect.h = CARROM_PIECE_SIZE;

}

Black::Black(SDL_Renderer* renderer, bool display = true) {

    displayPiece = display;
    initialize(renderer);
    setVelocity();

}

Black::Black(SDL_Renderer* renderer, Vector<int> strikerVelocity, bool display = true) {

    displayPiece = display;
    initialize(renderer);
    setVelocity(strikerVelocity);

}

void Black::initialize(SDL_Renderer* renderer) {

    imageSurface = IMG_Load("objects/striker.png");
    imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    positionRect.x = 950 - 100;
    positionRect.y = WIN_HEIGHT - 100; 
    positionRect.w = CARROM_PIECE_SIZE;   
    positionRect.h = CARROM_PIECE_SIZE;

}

// Physics
template <class T>
void collide_and_rebound(T& carromPiece) {

    // Update image position
    carromPiece.positionRect.x += carromPiece.pieceVelocity.x;
    /*std::cout << "X position: " << carromPiece.positionRect.x << " === ";*/
    carromPiece.positionRect.y += carromPiece.pieceVelocity.y;

    // Check for collision with screen edges
    if (carromPiece.positionRect.x <= BORDER_LEFT || carromPiece.positionRect.x >= BORDER_RIGHT - carromPiece.positionRect.w)
    {
        if (carromPiece.positionRect.x < BORDER_LEFT)
        {
            carromPiece.positionRect.x = BORDER_LEFT;
        }
        else if (carromPiece.positionRect.x > BORDER_RIGHT - carromPiece.positionRect.w)
        {
            carromPiece.positionRect.x = BORDER_RIGHT - carromPiece.positionRect.w;
        }
        carromPiece.pieceVelocity.x = -carromPiece.pieceVelocity.x; // Reverse X-axis movement direction
    }
    /*std::cout << "X velocity: " << carromPiece.pieceVelocity.x << std::endl;*/
    if (carromPiece.positionRect.y <= BORDER_UP || carromPiece.positionRect.y >= BORDER_DOWN - carromPiece.positionRect.h)
    {
        if (carromPiece.positionRect.y < BORDER_UP) {
            carromPiece.positionRect.y = BORDER_UP;
        }
        else if (carromPiece.positionRect.y > BORDER_DOWN - carromPiece.positionRect.h) {
            carromPiece.positionRect.y = BORDER_DOWN - carromPiece.positionRect.h;
        }

        carromPiece.pieceVelocity.y = -carromPiece.pieceVelocity.y; // Reverse Y-axis movement direction
    }
    // std::cout << "Y velocity: " <<  carromPiece.pieceVelocity.y << std::endl;

}

// Easy rendering the objects
template <class T>
void render_copy(SDL_Renderer* renderer, T carromPiece) {

    if (carromPiece.displayPiece == true) {
        SDL_Rect destRect = { carromPiece.positionRect.x, carromPiece.positionRect.y, carromPiece.positionRect.w, carromPiece.positionRect.h };
        SDL_RenderCopy(renderer, carromPiece.imageTexture, NULL, &destRect);
    }

}

template <typename T, typename U, typename V, typename W>
void newBoardState(T& striker, U white, V black, W& queen) {

    const int pieceSize = CARROM_PIECE_SIZE;
    const int centerOffset = (950 - pieceSize) / 2;

    striker.setPosition(Vector<float>(centerOffset, WIN_HEIGHT - STRIKER_PIECE_SIZE - 115));
    queen.setPosition(Vector<float>(centerOffset, centerOffset));

    Vector<float> whitePositions[9] = {
        Vector<float>(centerOffset - pieceSize * 2, centerOffset - pieceSize * 1.15),
        Vector<float>(centerOffset, centerOffset - pieceSize),
        Vector<float>(centerOffset + pieceSize * 1.75, centerOffset - pieceSize * 1.75),

        Vector<float>(centerOffset - pieceSize, centerOffset),
        Vector<float>(centerOffset - pieceSize * 1.15, centerOffset - pieceSize * 2), // UP ko left ko down
        Vector<float>(centerOffset + pieceSize, centerOffset),

        Vector<float>(centerOffset - pieceSize * 1.75, centerOffset + pieceSize * 1.75),
        Vector<float>(centerOffset, centerOffset + pieceSize),
        Vector<float>(centerOffset + pieceSize * 2, centerOffset)
    };

    Vector<float> blackPositions[9] = {
        Vector<float>(centerOffset - pieceSize, centerOffset - pieceSize),
        Vector<float>(centerOffset, centerOffset - pieceSize * 2.1),
        Vector<float>(centerOffset + pieceSize, centerOffset - pieceSize),

        Vector<float>(centerOffset - pieceSize * 2, centerOffset),
        Vector<float>(centerOffset + pieceSize * 1.15, centerOffset + pieceSize * 2), // Down ko right ko down
        Vector<float>(centerOffset + pieceSize * 2, centerOffset + pieceSize * 1.15),

        Vector<float>(centerOffset - pieceSize, centerOffset + pieceSize),
        Vector<float>(centerOffset, centerOffset + pieceSize * 2.1),
        Vector<float>(centerOffset + pieceSize, centerOffset + pieceSize)
    };

    for (int i = 0; i < 9; i++) {
        white[i].setPosition(whitePositions[i]);
        black[i].setPosition(blackPositions[i]);
    }

}

template <class T, class U, class V, class W>
void cleanBoardPieces(T striker, U queen, V white, W black) {

    for (int i = 0; i < 9; i++) {
        SDL_DestroyTexture(black[i].imageTexture);
    }

    for (int i = 0; i < 9; i++) {
        SDL_DestroyTexture(white[i].imageTexture);
    }

    SDL_DestroyTexture(queen.imageTexture);
    SDL_DestroyTexture(striker.imageTexture);

}
