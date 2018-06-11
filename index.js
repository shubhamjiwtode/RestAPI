var express        =         require("express");
var bodyParser     =         require("body-parser");
var mongoose       =         require('mongoose');
const morgan       =         require('morgan');
var app            =         express();




//including routes
var database_router=require('./routes/Database');
var file_router=require('./routes/DBfile');
var user_routes=require('./routes/UserRoutes');


//for logger
app.use(morgan('dev'));
//to make Storage folder static
app.use(express.static('Storage'));
//for parsing url body
app.use(bodyParser.urlencoded({extended:false}));
app.use(bodyParser.json());

//to handle the CORS(cross origin resource sharing) error
app.use((req,res,next)=>{
	res.header('Access-Control-Allow-Origin','*');
	res.header('Access-Control-Allow-Headers','*');
	if(req.method==='OPTIONS'){
		res.header('Access-Control-Allow-Methods','GET,POST,PATCH,DELETE');
		return res.status(200).json({});
	}
	next();
})

//Routes for the request
app.use('/auth',user_routes);
app.use('/database',database_router);
app.use('/file',file_router);


//setting error message
app.use((req,res,next)=>{
	const error=new Error('Not Found');
	error.status=404;
	next(error);
});

app.use((error,req,res,next)=>{
	res.status(error.status||500);
	res.json({
		error:{
			message: error.message
		}
	})
});

app.listen(3000);