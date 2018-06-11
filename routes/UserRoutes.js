var express=require('express');
var router=express.Router();
var mongoose=require('mongoose');
var bcrypt=require('bcrypt');
var fs=require('fs');
var jwt=require('jsonwebtoken');

const User=require('../models/users');
const Validator=require('../User_lookup');
const UserCheck=require('../loginHandler');

router.post('/signup',(req,res,next)=>{
	bcrypt.hash(req.body.password,10,(err,hash)=>{
			if(err){
				return res.status(500).json
				({
					error:err,
					request:{
						type:"POST"
					}
				})
			}else
			{
				const user=new User({
		        _id:new mongoose.Types.ObjectId(),
		        email:req.body.email,
		        password:hash
		    	});
				var result=Validator(user._id,user.email,user.password);
				if(result===false)
				{
					return res.status(500).json({
					message:'signup failed',
					//error:Validator(user._id,user.email,user.password)
				});
	      		}else{
	      			if(result===409){
	      				return res.status(409).json({
					     message:'Email id taken'});
	      				}
	      				else{
	      					return res.status(200).json({
					message:'Successfully signed up'
					});
					}
	      		}
			}
	})

});


router.post('/login',(req,res,next)=>{
	if(UserCheck(req.body.email)===false)
	{
		return res.status(401).json({
			message:'Authentication failed'
		});
	}
	var rawdata=fs.readFileSync('userinfo.json');
	let info=JSON.parse(rawdata);
    var mail=req.body.email;
	bcrypt.compare(req.body.password,info[mail].password,(err,result)=>{
		if(err){
			return res.status(401).json({
				message:'Authentication failed'
			});
		}
		if (result) {
			const token=jwt.sign({email:mail,userId:info[mail].id
			},
			process.env.JWT_KEY,{}
			)
			return res.status(200).json({
				message:'Authentication Successfull',
				token:token
			});
		}
		return res.status(401).json({
				message:'Authentication failed'
				
			});
	})

});
module.exports=router;