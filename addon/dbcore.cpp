#include "dbcore.h"
#include<iostream>


void dbcore::addtodb(string& key,payload pay){
	dB[key]=pay;
	
}

bool dbcore::contains(std::string key){
	std::unordered_map<std::string,payload>::const_iterator got=dB.find(key);
	if(got==dB.end()){
		return false;
	}
	return true;
}

std::vector<string> dbcore::getkeys(){
	std::vector<string> v;

	for(auto item:dB){
		v.push_back(item.first);
	}

	return v;
}
