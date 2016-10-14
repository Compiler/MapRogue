#pragma once
#include "Sector.h"
#include "string"
#include "iostream"
#include "StringEncode.h"
#include "vector"

class Decoder{

public:

	static void decode(std::vector<Sector>& sectors, std::string& stream){
	
		std::cout << "Original stream:\n" << stream << std::endl;
		std::vector<StringEncode> pieces;
		StringEncode tmpS;
		for(int i = 0; i < sectors.size(); i++){

			std::string tmp = stream.substr(sectors[i].beginning, sectors[i].ending - sectors[i].beginning);
		    std::size_t pos = tmp.find_last_not_of("0123456789");

			int amount = std::stoi(tmp.substr(0, pos));
			std::cout << "Print " << amount << " of " << tmp[pos] << std::endl;
			tmpS.amount = amount;
			tmpS.key = tmp[pos];
			pieces.push_back(tmpS);

		}

		std::string finalString = "";
		for(int i = 0; i < pieces.size(); i++)
			for(int k = 0; k < pieces[i].amount; k++)
				finalString += pieces[i].key;

	//	bool tra = !stream.empty() && stream.find_first_not_of("0123456789") == std::string::npos;

		stream = finalString;
	}


};