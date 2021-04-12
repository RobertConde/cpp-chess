#ifndef CHESS_ROOK
#define CHESS_ROOK

#include "Rook.h"

Rook::Rook(int color, std::pair<int,int> loc) : ChessPiece(color, loc, 'w', 'b') {}

int Rook::moveType(Board* brd, std::pair<int,int> loc) {
	std::pair<int,int> delta = (loc - m_loc);
	// Capturing moves
	if ((delta.first == 0 ^ delta.second == 0) && brd->checkClearPath(this->m_loc, loc, delta))	// Capture up-left or up-right
		return ChessPiece::MOVE_CAPTURE;

	return MOVE_INVALID;
}

void Rook::moveTo(std::pair<int,int> loc) {
	ChessPiece::moveTo(loc);

	m_moved = true;
}

#endif
