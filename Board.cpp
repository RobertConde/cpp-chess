#ifndef CHESS_BOARD
#define CHESS_BOARD

#include "Board.h"

Board::Board() {
	// Place Pawns
	for (char x = 'A'; x <= 'H'; ++x) {
		m_board[x - 'A'][1] = new Pawn(Pawn::WHITE, std::make_pair(x, 1));
		m_board[x - 'A'][6] = new Pawn(Pawn::BLACK, std::make_pair(x, 7));
	}
}

bool Board::movePiece(std::pair<int,int> loc1, std::pair<int,int> loc2) {
	return m_board[loc1.first][loc1.second]->move(this, loc2);
}

#endif
