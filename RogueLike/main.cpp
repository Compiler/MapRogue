
#include "iostream"
#include "Board.h"

int main(){
	Board board;

	board.initEncoded("map.txt");
	board.run(true);

	char tmpVar;
	std::cin >> tmpVar;
	return 0;
}