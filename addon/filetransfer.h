#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;


class transfer
{
public:
	void toRepo(string from,string to,string nameSpaces);
	void toStore(string from,string to);
	
};