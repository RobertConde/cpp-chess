#include <ostream>

#include "ChessPiece.cpp"

struct Board;   // Forward declaration of board

struct Pawn : ChessPiece {
private:
	bool m_moved = false;

public:
	explicit Pawn(int color, std::pair<int, int> loc);

	bool move(Board *brd, std::pair<int, int> loc);
};

#include "Board.cpp"
