#pragma once
#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

class payload{
public:
	payload(){};
	void setnamespace(std::string _namespace){namespace_=_namespace;}
	string getnamespace(){return namespace_;}
	void setfilename(std::string file){filename_=file;}
	string getfilename(){return filename_;}
	void setdependency(std::vector<string> depend){dependency_=depend;}
	std::vector<string> getdependency(){return dependency_;}
	void setdatetime(string datetime){datetime_=datetime;}
	string getdatetime(){return datetime_;}
	void setstatus(string status){status_=status;}
	string getstatus(){return status_;}
	void setpath(string path){path_=path;}
	string getpath(){return path_;}
	void setdescrip(std::string descrip){description_=descrip;}
	string getdescrip(){return description_;}


private:

	string namespace_="na";
	string filename_="na";
	std::vector<string> dependency_;
	string description_="na";
	string datetime_="na";
	string status_="na";
	string path_="na";

};