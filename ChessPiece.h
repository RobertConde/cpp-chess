#include <ostream>
#include "PairMath.cpp"

struct Board;   // Forward declaration

struct ChessPiece {
public:
	static const int MOVE_WHITE = 0;
	static const int MOVE_BLACK = 1;

	static const int MOVE_INVALID = 2;
	static const int MOVE_MOVE = 3;
	static const int MOVE_CAPTURE = 4;

	const char m_symbol = '*';

	int m_color;
	std::pair<int,int> m_loc;

	explicit ChessPiece(int color, std::pair<int, int> loc, const char symbol);

	friend std::ostream& operator <<(std::ostream& os, ChessPiece& piece) {
		os << piece.m_symbol;

		return os;
	}

	virtual int moveType(Board* brd, std::pair<int,int> loc) = 0;  // Pure virtual function (makes class abstract--no keyword)

	void moveTo(std::pair<int,int> loc);
};
