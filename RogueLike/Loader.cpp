#include "Loader.h"
#include "iostream"
#include "fstream"
#include "vector"
#include "Sector.h"
#include "Decoder.h"

Loader::Loader(){
}

/*
	Loads the information and populates a string object
*/
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
		decode(stream);


}
/*
	Decodes the correct encoded standards in the example
*/
void Loader::decode(std::string& stream){
	
	std::string tmp = stream;
	std::vector<Sector> sectors;
	Sector tmpSec;


	//loop through for key elements of parenthesis
	for(int i = 0; i < tmp.size(); i++){
		if(tmp.c_str()[i] == '('){
			tmpSec.beginning = i+1;
		}
		if(tmp.c_str()[i] == ')'){
			tmpSec.ending = i;
			sectors.push_back(tmpSec);
		}


	}


	for(int i = 0; i < sectors.size(); i++){
		std::cout << i << "- " << sectors[i].beginning << " to " << sectors[i].ending << "\n";
	}

	Decoder::decode(sectors, stream);





}


Loader::~Loader(){



}
