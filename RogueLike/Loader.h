#pragma once
#include "string"


class Loader{
public:
	Loader();


	void loadFull(std::string filePath, std::string& stream);
	void loadStand(std::string filePath, std::string& stream);


	~Loader();


private:
	void decode(std::string contents, std::string& stream);
};

