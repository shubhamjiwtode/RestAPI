
var mongoose=require('mongoose');


var metaSchema= mongoose.Schema({
    filename:{type:String,required:true},
	namespace: {type:String,required:true},
	status: {type:String,required:true},
	children: {type:String, required:true},
	categories: {type:String,required:true},
	descrip:{type:String,required:true}
});


module.exports=mongoose.model('MetaData',metaSchema);