#pragma once
#include "string"
#include "vector"
#include  "Sector.h"

class Loader{
public:
	Loader();

	void load(std::string filePath, std::string& stream, bool encoded);

	~Loader();


private:
	void decode(std::string& stream);
	
};

