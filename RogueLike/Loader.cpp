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
	for(int i = 0; i < contents.size(); i++){
		if(contents.c_str()[i] == '('){
			beg = i;
		}
		if(contents.c_str()[i] == ')'){
			end = i;
			for(int k = 1; k < end - beg; k++){
				tmp += contents.c_str()[k];
			}
			strings.push_back(tmp);
			tmp = "";
			
		}


	}


	std::cout << strings[0] << "\n";



}

Loader::~Loader(){



}
