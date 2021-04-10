#include <iostream>

#include "Board.cpp"

int main() {
	std::cout << "Hello, World!" << std::endl;

	ChessPiece* pwn = new Pawn(Pawn::WHITE, std::make_pair(1,1));
	std::cout << *pwn << std::endl;

	Board brd;
	std::cout << brd << std::endl;

	return 0;
}
