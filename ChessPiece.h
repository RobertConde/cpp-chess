#include <ostream>

struct Board;   // Forward declaration

struct ChessPiece {
public:
	static const int WHITE = 0;
	static const int BLACK = 1;
	const char m_symbol;

protected:
	int m_color;
	std::pair<int,int> m_loc;
public:
	explicit ChessPiece(int color, std::pair<int, int> pos, const char symbol);

	friend std::ostream& operator <<(std::ostream& os, ChessPiece& piece) {
		os << piece.m_symbol;

		return os;
	}

	virtual bool move(Board* brd, std::pair<int,int> loc) = 0;  // Pure virtual function (makes class abstract--no keyword)
};
