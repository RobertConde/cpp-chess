#include <iostream>

#include "Board.cpp"

int main() {
	std::cout << "Hello, World!" << std::endl;

	//std::cout<<"\033[31;1;4mHello\033[0m" <<std::endl;

	//std::cout << "\u001b[37m" << "P" << '\u001b[0m' << std::endl;
/*
	ChessPiece* pwn = new Pawn(ChessPiece::COLOR_WHITE, std::make_pair(1, 1));
	std::cout << *pwn << std::endl;
*/
	Board brd;
	//std::cout << brd;

	//std::cout << (brd.movePiece(std::make_pair(0, 1), std::make_pair(1,2)) ? "T" : "F")  << std::endl << brd;

	//brd.rotateBoard();

	while(true) {
		std::cout << brd;

		std::cin >> brd;
	}

	//std::cout << (brd.movePiece(std::make_pair(1, 1), std::make_pair(1,3)) ? "T" : "F")  << std::endl << brd;

	return 0;
}
