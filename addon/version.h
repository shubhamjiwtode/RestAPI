#pragma once
#include "dbcore.h"
#include <string>
#include<vector>
#include <regex>
#include <unordered_map>


using namespace std;


class version{
public:
	version(unordered_map<string,payload>& db):db_(db){}

	int getlatest(std::string key);
private:
	std::unordered_map<string,payload> &db_;
};