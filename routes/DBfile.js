var express= require('express');
var router=express.Router();

router.get('/:keyid',(req,res,next)=>{
	const Id = req.params.keyid;
	res.status(200).json({

		message:'handling file  get in dbfile',
		id: Id
	});
});

router.patch('/:keyid',(req,res,next)=>{
	res.status(200).json({
		message:'handling file change'
	});
});

module.exports=router;
