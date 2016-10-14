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
	decode(finalString, stream);

}

void Loader::decode(std::string contents, std::string& stream){
	int beg = 0;
	int end = 0;
	for(int i = 0; i < contents.size(); i++){
		if(contents.c_str()[i] == '('){
			beg = i;
			std::cout << i;
		}
		if(contents.c_str()[i] == ')'){
			end = i;
			for(int k = 0; k < end - beg; k++)
				std::cout << contents.c_str()[k] << "-";
		}

	}



}

Loader::~Loader(){



}
