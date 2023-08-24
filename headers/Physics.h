#pragma once
#include "CarromPiece.h"

void border_collision_checker(CarromPiece* carromPiece);

template <class T>
void movement(T* carromPiece);

void collide_and_rebound(Striker* striker, Queen* queen, White* white, Black* black);

