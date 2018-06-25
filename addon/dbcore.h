#pragma once
#include <string>
#include <vector>
#include<unordered_map>
#include "payload.h"

using namespace std; 



 

class dbcore{
public:
	dbcore(unordered_map<string,payload>& db):dB(db){}
	void addtodb(string& key,payload pay);
	bool contains(string key);
	std::vector<string> getkeys();
	unordered_map<string,payload> getDB(){return dB;}
	payload getmeta(string key){return dB[key];}
	unordered_map<string,payload>::iterator begin() { return dB.begin(); }
    unordered_map<string,payload>::iterator end() { return dB.end(); }
	 unordered_map<string,payload>& dB;
};

