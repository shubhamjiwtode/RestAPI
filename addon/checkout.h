 #pragma once

#include <fstream>
#include "version.h"
#include <string>
#include <vector>
#include<unordered_map>

#include<iostream>
using namespace std;




class checkout{
public:
	checkout(unordered_map<string,payload>& db):dbcore_(db),version_(db){}
	bool makecheckout(string file,string nspace,string ver);
private:
	//std::unordered_map<string,payload>& db_;
	dbcore dbcore_;
	version version_;
	payload dpay;
	
	//filetransfer fileXfer;
};
