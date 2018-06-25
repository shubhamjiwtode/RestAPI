#include "version.h"


int version::getlatest(std::string key){
	std::vector<string> v;
	//dbcore dbcore_(db_);
	for(auto item:db_){
		v.push_back(item.first);
	}
	


	std::regex e(key);

	int maxVer=0;
	
	for (auto item:v)
	{
		int max=0;
		if (std::regex_search(item, e))
		{
			std::string rawname;
		    rawname = item.substr(item.find_last_not_of("."), item.length());
		    int max=std::stoi(rawname);
			if (max>maxVer)
			{
				maxVer = max;
			}
		}
	}
	return maxVer;
}