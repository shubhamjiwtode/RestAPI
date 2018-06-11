var express= require('express');
var router=express.Router();

const permission=require('../wall/permission');


//checkout file
router.get('/:keyid',(req,res,next)=>{
	const Id = req.params.keyid;
	res.status(200).json({

		message:'handling file  get in dbfile',
		request:{
			type:'GET',
			description:'To get json of whole database',
			url:'http://localhost:3000/'+Id
		}
	});
});


//editing file
router.patch('/:keyid/:token',permission,(req,res,next)=>{
	var Id = req.params.keyid;
	res.status(200).json({
		message:'handling file change',
		request:{
			type:'PATCH',
			description:'To Edit meta of file in database',
			url:'http://localhost:3000/'+Id
		}
	});
});

module.exports=router;
