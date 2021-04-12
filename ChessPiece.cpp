#ifndef CHESS_PAWN_CPP
#define CHESS_PAWN_CPP

#include "ChessPiece.h"

ChessPiece::ChessPiece(int color, std::pair<int, int> loc, const char symbol_white, const char symbol_black)
	: m_color(color), m_loc(std::move(loc)), m_symbol_white(symbol_white), m_symbol_black(symbol_black) {}

char* ChessPiece::getPieceType() {
	return abi::__cxa_demangle(typeid(*this).name(),0,0,new int);
}
void ChessPiece::moveTo(std::pair<int,int> loc) {
	m_loc = loc;
}

#endif
