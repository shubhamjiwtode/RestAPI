#include "addon.h"


 std::string storageRoot = "../Storage";
using Msg = std::string;
using path = std::string;
using Dirs = std::vector<std::string>;
using Files = std::vector<std::string>;

using namespace addon_NS;
//-----< returns json of all files>-------------
std::vector<std::vector<std::string>> dirJson::getdirJson()
{
	std::vector<std::vector<std::string>> reply;
	return reply;
}

void dirJson::setdirJson(dir_files dirfiles) 
{
	dirVector = dirfiles;
}

double addon_NS::test(DBrequest& db)
{
		if (db.command=="Hello")
		{
		return 1;	/* code */
		}
		return 0;
}
