var jwt=require('jsonwebtoken');

module.exports=(req,res,next)=>{
	try{
		

	const decoded=jwt.verify(req.params.token,process.env.JWT_KEY);
	req.userdata=decoded;
	next();
	}
	catch(error){
		return res.status(401).json({
			message:'Authentication failed'
		});
	}

}