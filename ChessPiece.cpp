#ifndef CHESS_PAWN_CPP
#define CHESS_PAWN_CPP

#include "ChessPiece.h"

ChessPiece::ChessPiece(int color, std::pair<int, int> loc, const char symbol)
	: m_color(color), m_loc(std::move(loc)), m_symbol(symbol) {}

void ChessPiece::moveTo(std::pair<int,int> loc) {
	m_loc = loc;
}

#endif
