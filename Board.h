#include <vector>
#include <utility>

#include "ChessPiece.cpp"

// Forward declarations of pieces
struct Pawn;
struct Rook;
struct King;

struct Board {
public:
	std::vector<std::vector<ChessPiece*>> m_board = std::vector<std::vector<ChessPiece*>>(8, std::vector<ChessPiece*>(8, nullptr));
	bool m_rotated = false;

	Board();

	friend std::ostream& operator <<(std::ostream& os, Board& brd) {
		os << " *--------*" << "\n";

		for (char y = 'H'; y >= 'A'; --y) {
			os << (!brd.m_rotated ? (y - 'A') + 1 : (7 - (y - 'A'))) << "|";

			for (int x = 1; x <= 8; ++x) {
				ChessPiece* currPiece = brd.m_board[x - 1][y - 'A'];

				if (currPiece == nullptr)
					os << " ";
				else
					os << *currPiece;
			}

			os << "|\n";
		}
		os << " *--------*\n" << "  ";

		for(int X = 1; X <= 8; ++X)
			os << (char) (!brd.m_rotated ? (X - 1) + 'A': (7 - (X - 1)) + 'A');
		os << std::endl;

		return os;
	}

	friend std::istream& operator >>(std::istream& is, Board& brd) {
		// Translate coordinates
		int x1 = is.get() - 'A',
			y1 = is.get() - '1',
			x2 = is.get() - 'A',
			y2 = is.get() - '1';
		is.get();	// Newline

		if (brd.m_rotated) {
			x1 = 7 - x1;
			y1 = 7 - y1;

			x2 = 7 - x2;
			y2 = 7 - y2;
		}

		std::cout << "X" << x1 << "Y" << y1 << " | "  << "X" << x2 << "Y" << y2 << std::endl;

		brd.movePiece(std::make_pair(x1, y1), std::make_pair(x2, y2));

		return is;
	}

	bool isEmpty(std::pair<int,int> loc);

	bool movePiece(std::pair<int,int> loc1, std::pair<int,int> loc2);

	void rotateBoard();

	// Check is non-inclusive on both points, only checks the path between
	bool checkClearPath(std::pair<int,int> loc1, std::pair<int,int> loc2, std::pair<int,int> delta);
};

#include "Pawn.cpp"
#include "Rook.cpp"
#include "King.cpp"