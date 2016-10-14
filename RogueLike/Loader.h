#pragma once
#include "string"
#include "vector"

class Loader{
public:
	Loader();

	void load(std::string filePath, std::string& stream, bool encoded);

	~Loader();


private:
	void decode(std::string contents, std::string& stream);
	void rewire(std::vector<std::string>& stream, std::string consc);
};

