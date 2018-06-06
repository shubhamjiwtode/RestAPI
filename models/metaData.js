const mongoose=require('mongoose');

const metaSchema=mongoose.Schema({

	filename: String,
	namespace: String,
	status: String,
	children: String,
	categories: String
});

module.exports=mongoose.model('MetaData',metaSchema);