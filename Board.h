#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>
#include <utility>

#include "ChessPiece.cpp"

// Forward declarations of pieces
struct Pawn;

struct Board {
public:
	std::vector<std::vector<ChessPiece*>> m_board = std::vector<std::vector<ChessPiece*>>(8, std::vector<ChessPiece*>(8, nullptr));

	Board();

	friend std::ostream& operator <<(std::ostream& os, Board& brd) {
		os << " *--------*" << "\n";

		for (char y = 'H'; y >= 'A'; --y) {
			os << y << "|";

			for (int x = 1; x <= 8; ++x) {
				ChessPiece* currPiece = brd.m_board[x - 1][y - 'A'];

				if (currPiece == nullptr)
					os << " ";
				else
					os << *currPiece;
			}

			os << "|\n";
		}
		os << " *--------*\n" << "  12345678\n";

		return os;
	}

	bool movePiece(std::pair<int,int> loc1, std::pair<int,int> loc2);
};

#include "Pawn.h"

//A DEFINITIONS HERE
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

#endif //CHESS_BOARD_H
