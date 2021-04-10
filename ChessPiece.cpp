#ifndef CHESS_PAWN_CPP
#define CHESS_PAWN_CPP

#include "ChessPiece.h"

ChessPiece::ChessPiece(int color, std::pair<int, int> pos, const char symbol)
	: m_color(color), m_loc(pos), m_symbol(symbol) {}

#endif
