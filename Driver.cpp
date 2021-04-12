#include <iostream>

#include "Board.cpp"

int main() {
	std::cout << "Hello, World!" << std::endl;

	ChessPiece* pwn = new Pawn(ChessPiece::MOVE_WHITE, std::make_pair(1, 1));
	std::cout << *pwn << std::endl;

	Board brd;
	std::cout << brd << std::endl;

	std::cout << (brd.movePiece(std::make_pair(0, 1), std::make_pair(0,3)) ? "T" : "F")  << std::endl;

	std::cout << brd << std::endl;

	return 0;
}

