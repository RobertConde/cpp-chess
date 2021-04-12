#ifndef CHESS_King
#define CHESS_King

#include "King.h"

King::King(int color, std::pair<int,int> loc) : ChessPiece(color, loc, 'K', 'k') {}

int King::moveType(Board* brd, std::pair<int,int> loc) {
	std::pair<int,int> delta = (loc - m_loc);
	// Capturing moves
	if (((delta.first == 0 ^ delta.second == 0) ^ (std::abs(delta.first) + std::abs(delta.second) == 2)) && brd->checkClearPath(this->m_loc, loc, delta))	// Capture up-left or up-right
		return ChessPiece::MOVE_CAPTURE;

	return MOVE_INVALID;
}

#endif
