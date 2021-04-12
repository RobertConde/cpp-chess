#ifndef CHESS_BOARD
#define CHESS_BOARD

#include "Board.h"

Board::Board() {
	// Place Pawns
	for (char x = 'A'; x <= 'H'; ++x) {
		int X = x - 'A';

		m_board[X][1] = new Pawn(ChessPiece::COLOR_WHITE, std::make_pair(X, 1));
		m_board[X][2] = new Pawn(ChessPiece::COLOR_BLACK, std::make_pair(X, 2));
		m_board[X][6] = new Pawn(ChessPiece::COLOR_BLACK, std::make_pair(X, 7));
	}
}

bool Board::isEmpty(std::pair<int,int> loc) {
	return m_board[loc.first][loc.second] == nullptr;
}

bool Board::movePiece(std::pair<int,int> loc1, std::pair<int,int> loc2) {
	ChessPiece** CP_loc_1 = &m_board[loc1.first][loc1.second];
	ChessPiece** CP_loc_2 = &m_board[loc2.first][loc2.second];


	std::cout << "Attempting to move a " << (*CP_loc_1)->getPieceType()
			  << " from <" << (*CP_loc_1)->m_loc.first << ","<<  (*CP_loc_1)->m_loc.second << ">"
			  << " to <" << loc2.first << ","<<  loc2.second << "> [" << (*CP_loc_2 == nullptr ? "Empty" : (*CP_loc_2)->getPieceType()) << "]." << std::endl;
	int moveType = (*CP_loc_1)->moveType(this, loc2);
	if (moveType != ChessPiece::MOVE_INVALID) {	// If move not irregular (not a move)
		if (moveType == ChessPiece::MOVE_CAPTURE) {    // If moveType is capture
			if (!isEmpty(loc2) && (*CP_loc_1)->m_color != (*CP_loc_2)->m_color) {    // If is able to get captured, get captured
					std::cout << "GET CAPTURED!!!" << std::endl;

					*CP_loc_2 = nullptr;    //NOT NECESSARY
			} else	// Can't capture
				return false;
		}

		*CP_loc_2 = *CP_loc_1;
		*CP_loc_1 = nullptr;

		(*CP_loc_2)->moveTo(loc2);

		return true;
	}

	return false;
}

bool Board::checkClearPath(std::pair<int,int> loc1, std::pair<int,int> loc2, std::pair<int,int> delta) {
	std::pair<int,int> move;
	if (delta.first == 0 ^ delta.second == 0) {	// Vertical and horizontal
		int nonzeroComp = std::max(delta.first, delta.second);

		move = std::make_pair(delta.first / nonzeroComp, delta.second / nonzeroComp);
	} else {
		int magFirst = std::abs(delta.first),
			magSecond = std::abs(delta.second);

		move = std::make_pair(delta.first / magFirst, delta.second / magSecond);
	}

	std::pair<int,int> curr = std::make_pair(loc1.first + move.first, loc1.second + move.second);
	while (curr != loc2) {	// Check places on (loc1, loc2)
		if (!isEmpty(curr))	// If something in path, return false
			return false;

		curr = std::make_pair(curr.first + move.first, curr.second + move.second);
	}

	return true;
}

#endif
