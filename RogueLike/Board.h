#pragma once

#include "iostream"
#include "string"

class Board{
public:
	Board();

	void initFull(std::string filePath = "^");
	void initEncoded(std::string filePath = "^");
	void run();

	~Board();


private:


	void take(std::string stream);

	int width = 20;
	int height = 10;
	char board[20][10];
	
};

