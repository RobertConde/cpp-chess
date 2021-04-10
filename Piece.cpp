#ifndef CHESS_PAWN_CPP
#define CHESS_PAWN_CPP

#include "Piece.h"

Piece::Piece(int color, std::pair<int, int> loc, const char symbol)
	: m_color(color), m_loc(loc), m_symbol(symbol) {}

#endif
