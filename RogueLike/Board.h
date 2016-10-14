#pragma once

#include "iostream"
#include "string"
#include "Loader.h"

class Board{
public:
	Board();

	void initFull(std::string filePath = "^");
	void initEncoded(std::string filePath = "^");
	void run(bool checkForInput);

	~Board();


private:


	void take(std::string stream);
	void draw();

	int width = 20;
	int height = 10;
	char board[20][10];

	Loader loader;
	
};

