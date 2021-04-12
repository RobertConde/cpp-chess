#include <ostream>

#include "ChessPiece.cpp"

struct Board;   // Forward declaration of board

struct King : ChessPiece {
private:

public:
	explicit King(int color, std::pair<int, int> loc);

	int moveType(Board *brd, std::pair<int, int> loc);
};

#include "Board.cpp"
