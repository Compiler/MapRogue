#include "Loader.h"
#include "iostream"
#include "fstream"
#include "vector"
#include "Sector.h"

Loader::Loader(){
}


void Loader::load(std::string filePath, std::string& stream, bool encoded){
	std::cout << "Loading map...\n\n\n";
	std::ifstream file("MapLocation//" + filePath);
	std::string line, finalString;

	if(file.fail()){
		std::cout << "map loading failed... coudln't load " << filePath;
	}
	while(std::getline(file, line)){
		finalString += line;
	}

	stream = finalString;
	if(encoded)
		decode(finalString, stream);


}

void Loader::decode(std::string contents, std::string& stream){
	std::vector<std::string> strings;

	std::vector<Sector> sectors;
	Sector tmpSec;


	//loop through for key elements of parenthesis
	for(int i = 0; i < contents.size(); i++){
		if(contents.c_str()[i] == '('){
			tmpSec.beginning = i;
		}
		if(contents.c_str()[i] == ')'){
			tmpSec.ending = i;
			sectors.push_back(tmpSec);
		}


	}


	for(int i = 0; i < sectors.size(); i++){
		std::cout << i << "- " << sectors[i].beginning << " to " << sectors[i].ending << "\n";
	}



	rewire(strings, stream);



}

void Loader::rewire(std::vector<std::string>& stream, std::string consc){
	for(int i = 0; i < stream.size(); i++)
		std::cout << stream[i] << "\n";

}

Loader::~Loader(){



}
