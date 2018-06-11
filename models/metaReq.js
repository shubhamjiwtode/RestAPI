var mongoose=require('mongoose');


var metaSchema= mongoose.Schema({
    filename:{type:String,required:true},
	namespace: {type:String,required:true},
	version: {type:String,default:'0'},
});


module.exports=mongoose.model('MetaReq',metaSchema);
