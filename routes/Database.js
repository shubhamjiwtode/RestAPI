var express=require('express');
var router=express.Router();
const multer =require('multer');
//Strorage location for incoming files
const storage=multer.diskStorage({
    destination: function(req,file,cb){
    	cb(null,'./Storage/');
    },
    filename:function(req,file,cb){
    	cb(null,file.originalname );
    }
});
const upload= multer({storage:storage});

const permission=require('../wall/permission');

const MetaData=require('../models/metaData');
const MetaReq=require('../models/metaReq');

//returning whole database list
router.get('/',(req,res,next)=>{
	res.status(200).json({
		message:'handling get ',
		request:{
			type:'GET',
			description:'To get json of whole database',
			url:'http://localhost:3000/'
		}
	});
});

//checkin-in the file
router.post('/:token',permission,upload.single('checkinfile'),(req,res,next)=>{
	console.log(req.file.path);
	const file= new MetaData( {
		filename:req.body.filename,
	    namespace:req.body.namespace,
		status:req.body.status,
		children:req.body.children,
		categories:req.body.categories,
		descrip:req.body.descrip
	});
    var error = file.validateSync();
    //console.log(error);
    if(error)
    {
    	res.status(500).json({
		message:'file checkin error',
		createdEntry: error,
		request:{
			type:'POST',
			description:'Checking-in file',
			url:'http://localhost:3000/'
		}
	});
    }
    else
    {
        res.status(201).json({
		message:'file checkin successful',
		createdEntry: file,
		request:{
			type:'POST',
			description:'Checking-in file',
			url:'http://localhost:3000/'
		}
	});
    }
});

//to get metadata
router.get('/:keyid',(req,res,next)=>{
	const Id = req.params.keyid;
	const file=new MetaReq({
        filename:req.body.filename,
	    namespace:req.body.namespace,
		version:req.body.status
	});

	var error = file.validateSync();
    console.log(error);
    if(error)
    {
    	res.status(500).json({
		message:'handling get metadata',
		createdEntry: error,
		request:{
			type:'GET',
			description:'Checking-in file',
			url:'http://localhost:3000/'+Id
		}
	});
    }
    else
    {
        res.status(201).json({
		message:'handling get metadata',
		createdEntry: file,
		request:{
			type:'GET',
			description:'Checking-in file',
			url:'http://localhost:3000/'+Id
		}
	});
    }
});

module.exports=router;