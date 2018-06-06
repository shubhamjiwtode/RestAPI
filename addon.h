#pragma once

#include <string>
#include <vector>


namespace addon_NS {


	const std::string storageRoot = "../Storage";
	using dir_files = std::vector<std::vector<std::string>>;
	using Msg = std::string;
	using path = std::string;
	using Dirs = std::vector<std::string>;
	using Files = std::vector<std::string>;


    
	class dirJson
	{
	public:
		dir_files getdirJson();
		void setdirJson(dir_files dirfilesObj);
	private:
		dir_files dirVector;
	};

	class DBrequest 
	{
	public:
		Msg command;
		void setcmd(Msg& msg)
		{
			command = msg;
		}
		

	};

	double test(DBrequest & db);
	
}