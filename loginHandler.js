var fs= require('fs');

function validateLogin(email){


	var rawdata=fs.readFileSync('userinfo.json');
	let info=JSON.parse(rawdata);
    var mail=info[email]||"NA"
    if(mail==="NA")
    {
    return false;
    }
    return true;
}

module.exports=validateLogin;
