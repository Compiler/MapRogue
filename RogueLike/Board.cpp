#include "Board.h"
#include "fstream"



Board::Board(){
}



void Board::initFull(std::string filePath){

	std::string stream;
	loader.loadFull(filePath, stream);
	take(stream);
}

void Board::initEncoded(std::string filePath){
	std::string stream;
	loader.loadStand(filePath, stream);
	take(stream);

}


void Board::take(std::string stream){
	int index = 0;
	int counter = 0;
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			index = (i * 10) + j;

			board[index % 20][counter] = stream.c_str()[index];
			std::cout << stream.c_str()[index] << " added to board[" << counter << "][" << index%20 << "]\n";
	
			if(index % 20 == 0 && i > 0){
				counter++;
			}
		}
	}

}


void Board::run(bool checkForInput){

	if(checkForInput){
		while(true){
			char input;
			draw();
			std::cin >> input;
		}
		
	} else{
		
		while(true){
			
			draw();
			
		}

	}

}


void Board::draw(){
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			std::cout<<board[j][i];
		}
		std::cout<<"\n";
	}
	int i = 0;
	


}


Board::~Board(){

}
