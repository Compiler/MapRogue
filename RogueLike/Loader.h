#pragma once
#include "string"
#include "vector"

class Loader{
public:
	Loader();


	void loadFull(std::string filePath, std::string& stream);
	void loadStand(std::string filePath, std::string& stream);


	~Loader();


private:
	void decode(std::string contents, std::string& stream);
	void rewire(std::vector<std::string>& stream, std::string consc);
};

