#include "Loader.h"
#include "iostream"
#include "fstream"


Loader::Loader(){
}


void Loader::loadFull(std::string filePath, std::string& stream){


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


}
void Loader::loadStand(std::string filePath, std::string& stream){
	

}



Loader::~Loader(){
}
