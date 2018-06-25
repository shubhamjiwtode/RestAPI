 #pragma once
// #pragma comment(lib, "version.lib")
//#pragma comment(lib, "Persist.lib")
//#include "dbcore.h"
//#include "filetransfer.h"
#include <fstream>
#include "version.h"
#include <string>
#include <vector>
#include<unordered_map>
#include "Persist.h"
#include<iostream>
using namespace std;




class checkin{
public:
	checkin(unordered_map<string,payload>& db):persist(db),dbcore_(db),version_(db){}
	bool makecheckin(payload pay);
private:
	//std::unordered_map<string,payload>& db_;
	dbcore dbcore_;
	version version_;
	payload dpay;
	Persist persist;
	//filetransfer fileXfer;
};



