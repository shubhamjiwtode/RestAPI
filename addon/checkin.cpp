#include "checkin.h"

bool checkin::makecheckin(payload pay)
{
	string filnam=pay.getfilename();
	string namspace=pay.getnamespace();
	string lookname=namspace+"|"+filnam+".1";

  
	std::ofstream file;
    file.open("database.xml");

	

	if(dbcore_.contains(lookname)){

		string midname=namspace+"|"+filnam;
		int ver =version_.getlatest(midname);
		string finalname=namspace+"|"+filnam+"."+std::to_string(ver);
		
		dpay=dbcore_.getmeta(finalname);
		std::cout<<"stati"+dpay.getstatus();
		if(dpay.getstatus()=="0")
		{
			string midname=namspace+"|"+filnam;
		    int ver =version_.getlatest(midname);
			ver=ver+1;
			std::cout<<"hi"+std::to_string(ver)+"version";
			finalname=namspace+"|"+filnam+"."+std::to_string(ver);
			dbcore_.addtodb(finalname,pay);
			// string toname=filnam+"."+std::to_string(ver);
			// fileXfer.toRepo(filnam,toname,namspace);
			
	        
	        file << persist.toXml();
	        file.close();
	
			return true;

		}
		else
		{
			int ver =version_.getlatest(midname);
			finalname=namspace+"|"+filnam+"."+std::to_string(ver);
			dbcore_.addtodb(finalname,pay);
			// string toname=filnam+"."+std::to_string(ver);
			// fileXfer.toRepo(filnam,toname,namspace);

			file << persist.toXml();
	        file.close();
			return true;
		}
		
	}
	else
	{

		dbcore_.addtodb(lookname,pay);
		// string toname=filnam+".1";
		// fileXfer.toRepo(filnam,toname,namspace);

		file << persist.toXml();
        file.close();
		return true;
	}

return false; 
}