var fs= require('fs');

function validateUser(id_,email,pass){


	var rawdata=fs.readFileSync('userinfo.json');
	let info=JSON.parse(rawdata);
    var mail=info[email]||"NA"
    if(mail==="NA")
    {
    info[email]={id:id_,password:pass}
    var json = JSON.stringify(info);
    fs.writeFile('userinfo.json', json,'utf8',(err)=>{
    	if(err)
    		return false;
    });
    return true;
    }
    else
    {
    	return 409;
    }
}

module.exports=validateUser;
