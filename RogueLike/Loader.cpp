#include "Loader.h"
#include "iostream"
#include "fstream"
#include "vector"

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
	std::vector<std::string> strings;
	std::string tmp ="";
	int indexb[10] = {0,0,0,0,0,0,0,0,0,0};
	int indexe[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for(int i = 0; i < contents.size(); i++){
		//std::cout << contents.c_str()[i];
		if(contents.c_str()[i] == '('){
			indexb[beg] = i;
		}
		if(contents.c_str()[i] == ')'){
			indexe[beg] = i;
			beg++;
		}


	}


	//rewire(strings, stream);



}

void Loader::rewire(std::vector<std::string>& stream, std::string consc){
	//for(int i = 0; i < stream.size(); i++)
	//	std::cout << stream[i] << "\n";

}

Loader::~Loader(){



}
