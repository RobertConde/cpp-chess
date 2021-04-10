#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include <ostream>

#include "ChessPiece.cpp"

struct Board;   // Forward declaration of board

struct Pawn : ChessPiece {
private:
	bool m_moved = false;

public:
	explicit Pawn(int color, std::pair<int, int> loc);

	bool move(Board *brd, std::pair<int, int> loc);
};

#include "Board.h"

//B DEFINITIONS HERE
Pawn::Pawn(int color, std::pair<int,int> loc) : ChessPiece(color, loc, 'P') {}

bool Pawn::move(Board* brd, std::pair<int,int> loc) {
	std::cout << "Attempting to movePiece " << typeid(this).name()
		<< " from <" << m_loc.first << ","<<  m_loc.second << ">"
		<< " to <" << loc.first << ","<<  m_loc.second << ">.";

	return false;
}

#endif //CHESS_PAWN_H
