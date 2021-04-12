#ifndef CHESS_PAWN
#define CHESS_PAWN

#include "Pawn.h"

Pawn::Pawn(int color, std::pair<int,int> loc) : ChessPiece(color, loc, 'P') {}

int Pawn::moveType(Board* brd, std::pair<int,int> loc) {
	std::cout << "Attempting to move a Pawn"
	          << " from <" << m_loc.first << ","<<  m_loc.second << ">"
	          << " to <" << loc.first << ","<<  loc.second << ">." << std::endl;

	std::pair<int,int> delta = (loc - m_loc);

	if (brd->isEmpty(loc))	// Non-capturing moves
		if (delta == std::make_pair(0,1) || delta == std::make_pair(0,2) && !m_moved)	// One or two forward
			if (brd->checkClearPath(this->m_loc, loc, delta))	// Check path is clear (always clear for one forward)
				return ChessPiece::MOVE_MOVE;
	else	// Capturing moves
		if (delta == std::make_pair(-1,1) || delta == std::make_pair(1,1))	// Capture up-left or up-right
			return ChessPiece::MOVE_CAPTURE;

	return MOVE_INVALID;
}

void Pawn::moveTo(std::pair<int,int> loc) {
	ChessPiece::moveTo(loc);

	m_moved = true;
}

#endif
