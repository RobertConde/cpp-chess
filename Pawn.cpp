#ifndef CHESS_PAWN
#define CHESS_PAWN

#include "Pawn.h"

Pawn::Pawn(int color, std::pair<int,int> loc) : Piece(color, loc, 'P') {}

bool Pawn::move(Board* brd, std::pair<int,int> loc) {
	std::cout << "Attempting to movePiece " << typeid(this).name()
	          << " from <" << m_loc.first << ","<<  m_loc.second << ">"
	          << " to <" << loc.first << ","<<  m_loc.second << ">.";

	return false;
}

#endif
