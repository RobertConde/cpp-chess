#include <ostream>

#include "ChessPiece.cpp"

struct Board;   // Forward declaration of board

struct Rook : ChessPiece {
private:
	bool m_moved = false;

public:
	explicit Rook(int color, std::pair<int, int> loc);

	int moveType(Board *brd, std::pair<int, int> loc);

	void moveTo(std::pair<int,int> loc);
};

#include "Board.cpp"
