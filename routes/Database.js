var express=require('express');
var router=express.Router();
const mongoose=require('mongoose');
const MetaData=require('../models/metaData');

router.get('/',(req,res,next)=>{
	res.status(200).json({
		message:'handling get '
	});
});

router.post('/',(req,res,next)=>{
	
	const file= new MetaData({
		filename:req.body.filename,
		namespace:req.body.namespace,
		status:req.body.status,
		children:req.body.children,
		categories:req.body.categories,
		descrip:req.body.descrip
	});

	res.status(201).json({
		message:'handling post',
		createdEntry: file
	});
});

router.get('/:filekey',(req,res,next)=>{
	res.status(200).json({
		message:'handling get file key'
	});
});

module.exports=router;