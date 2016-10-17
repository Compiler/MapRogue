#include "Board.h"
#include "fstream"



Board::Board(){
}


/*
	Calls full loader
*/
void Board::initFull(std::string filePath){

	std::string stream;
	loader.load(filePath, stream, false);
	take(stream);
}
/*
	Calls the decoder loader
*/
void Board::initEncoded(std::string filePath){
	std::string stream;
	loader.load(filePath, stream, true);
	take(stream);

}

/*
	Converts a stream of text to a 2d array
*/
void Board::take(std::string stream){
	int index = 0;
	int counter = 0;
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			index = (i * 10) + j;

			board[index % 20][counter] = stream.c_str()[index];
	
			if(index % 20 == 0 && i > 0){
				counter++;
			}
		}
	}

}

/*
	Convenience method to act as the entrance point to the rest of
	the application
*/
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

/*
	Draws the board followed by a ton of next lines
*/
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
