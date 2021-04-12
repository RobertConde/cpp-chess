#ifndef CHESS_King
#define CHESS_King

#include "King.h"

King::King(int color, std::pair<int,int> loc) : ChessPiece(color, loc, 'w', 'b') {}

int King::moveType(Board* brd, std::pair<int,int> loc) {
	std::pair<int,int> delta = (loc - m_loc);
	// Capturing moves
	if ((delta.first == 0 ^ delta.second == 0) && brd->checkClearPath(this->m_loc, loc, delta))	// Capture up-left or up-right
		return ChessPiece::MOVE_CAPTURE;

	return MOVE_INVALID;
}

#endif
