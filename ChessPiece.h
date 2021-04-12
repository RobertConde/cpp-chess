#include <ostream>
#include <cxxabi.h>

#include "PairMath.cpp"

struct Board;   // Forward declaration

struct ChessPiece {
public:
	static const int COLOR_WHITE = 0;
	static const int COLOR_BLACK = 1;

	static const int MOVE_INVALID = 2;
	static const int MOVE_MOVE = 3;
	static const int MOVE_CAPTURE = 4;

	const char m_symbol_white = 'W';
	const char m_symbol_black = 'B';

	int m_color;
	std::pair<int,int> m_loc;

	explicit ChessPiece(int color, std::pair<int, int> loc, const char symbol_white, const char symbol_black);

	char* getPieceType();

	friend std::ostream& operator <<(std::ostream& os, ChessPiece& piece) {
		if (piece.m_color == ChessPiece::COLOR_WHITE)
			os << piece.m_symbol_white;
		else
			os << piece.m_symbol_black;

		return os;
	}

	virtual int moveType(Board* brd, std::pair<int,int> loc) = 0;  // Pure virtual function (makes class abstract--no keyword)

	void moveTo(std::pair<int,int> loc);
};
