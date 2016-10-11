#include "Board.h"
#include "fstream"


Board::Board(){
}



void Board::initFull(std::string filePath){

}

void Board::initEncoded(std::string filePath){

	if(filePath.c_str()[0] == '^'){
		std::cout << "default valued map initialized\n";
		//default
		for(int i = 0; i < width; i++){
			for(int j = 0; j < height; j++){
				board[i][j] = '_';
			}
		}
	} else{
		std::cout << "Loading map...\n\n\n";
		std::ifstream file("MapLocation//" + filePath);
		std::string line, finalString;
		
		if(file.fail()){
			std::cout << "map loading failed... coudln't load " << filePath;
		}
		while(std::getline(file, line)){
			std::cout << line;
			finalString += line;
		}

			
		take(finalString);


	}




}


void Board::take(std::string stream){
	int index = 0;
	int counter = 0;
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			index = (i * 10) + j;

			board[counter][index % 20] = stream.c_str()[index];
			std::cout << stream.c_str()[index] << " added to board[" << counter << "][" << index%20 << "]\n";
			
			if(index % 20 == 0){
				counter++;
			}
		}
	}


}


void Board::run(){

}



Board::~Board(){

}
