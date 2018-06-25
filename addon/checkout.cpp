#include "checkout.h"


bool checkout::makecheckout(string file,string nspace,string ver){
	string lookname=file+nspace+ver;


	if(ver=="x"){
		string midname=file+nspace;
		int ver =version_.getlatest(midname);
		string finalname=namspace+"|"+filnam+"."+std::to_string(ver);
			//if version x latest file will be checkedout
		return true;
	}

	if(dbcore_.contains(lookname)){

		dpay=dbcore_.getmetadata(lookname);

		return true;
	}
	else
	{

		return false;
	}

}