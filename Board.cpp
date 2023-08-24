#include "headers/Board.h"
#include "headers/CarromPiece.h"
#include "headers/Vector.h"


void newBoardState(Striker* striker, White* white, Black* black, Queen* queen) {

    striker->setPosition(Vector<float>(centerOffset, WIN_HEIGHT - STRIKER_PIECE_SIZE - 115));
    queen->setPosition(Vector<float>(centerOffset, centerOffset));

    Vector<float> whitePositions[9] = {
        Vector<float>(centerOffset - CARROM_PIECE_SIZE * 2, centerOffset - CARROM_PIECE_SIZE * 1.15),
        Vector<float>(centerOffset, centerOffset - CARROM_PIECE_SIZE),
        Vector<float>(centerOffset + CARROM_PIECE_SIZE * 1.75, centerOffset - CARROM_PIECE_SIZE * 1.75),

        Vector<float>(centerOffset - CARROM_PIECE_SIZE, centerOffset),
        Vector<float>(centerOffset - CARROM_PIECE_SIZE * 1.15, centerOffset - CARROM_PIECE_SIZE * 2),
        Vector<float>(centerOffset + CARROM_PIECE_SIZE, centerOffset),

        Vector<float>(centerOffset - CARROM_PIECE_SIZE * 1.75, centerOffset + CARROM_PIECE_SIZE * 1.75),
        Vector<float>(centerOffset, centerOffset + CARROM_PIECE_SIZE),
        Vector<float>(centerOffset + CARROM_PIECE_SIZE * 2, centerOffset)
    };

    Vector<float> blackPositions[9] = {

        Vector<float>(centerOffset - CARROM_PIECE_SIZE, centerOffset - CARROM_PIECE_SIZE),
        Vector<float>(centerOffset, centerOffset - CARROM_PIECE_SIZE * 2.1),
        Vector<float>(centerOffset + CARROM_PIECE_SIZE, centerOffset - CARROM_PIECE_SIZE),

        Vector<float>(centerOffset - CARROM_PIECE_SIZE * 2, centerOffset),
        Vector<float>(centerOffset + CARROM_PIECE_SIZE * 1.15, centerOffset + CARROM_PIECE_SIZE * 2),
        Vector<float>(centerOffset + CARROM_PIECE_SIZE * 2, centerOffset + CARROM_PIECE_SIZE * 1.15),

        Vector<float>(centerOffset - CARROM_PIECE_SIZE, centerOffset + CARROM_PIECE_SIZE),
        Vector<float>(centerOffset, centerOffset + CARROM_PIECE_SIZE * 2.1),
        Vector<float>(centerOffset + CARROM_PIECE_SIZE, centerOffset + CARROM_PIECE_SIZE)
    };

    for (int i = 0; i < 9; i++)
    {
        white[i].setPosition(whitePositions[i]);
        black[i].setPosition(blackPositions[i]);
    }
}
