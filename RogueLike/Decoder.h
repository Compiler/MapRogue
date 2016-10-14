#pragma once
#include "Sector.h"
#include "string"
#include "iostream"
#include "vector"

class Decoder{

public:

	static void decode(std::vector<Sector>& sectors, std::string& stream){
	
		std::cout << "Original stream:\n" << stream << std::endl;
		for(int i = 0; i < sectors.size(); i++){
			std::string tmp = stream.substr(sectors[i].beginning, sectors[i].ending - sectors[i].beginning);
			std::cout << sectors[i].beginning << " to " << sectors[i].ending << " is " << tmp << "\n" << std::endl;
		
		}

	//	bool tra = !stream.empty() && stream.find_first_not_of("0123456789") == std::string::npos;
		std::size_t pos = stream.find_last_not_of("0123456789");
	}


};