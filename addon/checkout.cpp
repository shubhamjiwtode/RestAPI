#include "checkout.h"


bool checkout::makecheckout(string file,string nspace,string ver){
	string lookname=file+nspace+ver;


	if(dbcore_.contains(lookname)){
		if(ver=="x"){
			//if version x latest file will be checkedout
			return true;
		}
		return true;
	}
	else
	{
		return false;
	}

}