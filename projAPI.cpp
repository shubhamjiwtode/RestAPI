// projAPI.cpp : Defines the entry point for the console application.
//#pragma comment(lib, "server_API")
//C:\Users\srjiwtod\node\src\
//C:\Users\srjiwtod\node\deps\v8\include\
//C:\Users\srjiwtod\node\deps\uv\include\

#include <node.h>

#include <v8.h>
#include <uv.h>
#include <string>
#include <vector>
#include <unordered_map>
//#include "addon.h"
//#include "../proj 4/Project4/server_API/server_API.h";
//#include "../proj 4/Project4/Reply/Reply.h";
//#include "../proj 4/Project4/FileSystem-Windows/FileSystemDemo/FileSystem.h"
using namespace std;
using namespace v8;
//using namespace addon_NS;
//void GetDb(const v8::FunctionCallbackInfo<Value>& args);
//void GetDB_Vec(const v8::FunctionCallbackInfo<v8::Value>& args);
void Method(const v8::FunctionCallbackInfo<Value>& args);
//addon_NS::DBrequest unpack_DBrequest(Isolate* isolate, const v8::FunctionCallbackInfo<v8::Value>& args);

void init(Handle <Object> exports, Handle<Object> module) {
	//NODE_SET_METHOD(exports, "GetDB_Vec", GetDB_Vec);
    NODE_SET_METHOD(exports, "hello", Method);
   // NODE_SET_METHOD(exports,"GetDb",GetDb);
	// we'll register our functions to make them callable from node here..
}

// void GetDb(const v8::FunctionCallbackInfo<Value>& args){
//     Isolate* isolate = args.GetIsolate();
// 	replyNS::dbReplyDirs dbMap=ServerNS::DB_Files();
// 	Local<Map> map= Map::New(isolate);
// 	string x=std::to_string(dbMap.size());
// 	args.GetReturnValue().Set(String::NewFromUtf8(isolate, "xxxxx"));

// }

void Method(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

// void GetDB_Vec(const v8::FunctionCallbackInfo<v8::Value>& args) 
// {
// 	Isolate* isolate = args.GetIsolate();
// 	addon_NS::DBrequest dbrequest= unpack_DBrequest(isolate,args);
// 	int x=addon_NS::test(dbrequest);
// 	Local<Number> retval = v8::Number::New(isolate, x);
// 	args.GetReturnValue().Set(retval);
    
// }

// addon_NS::DBrequest unpack_DBrequest(Isolate* isolate, const v8::FunctionCallbackInfo<v8::Value>& args) {
// 	DBrequest dbrequest;

// 	Handle<Object> dbreq_obj = Handle<Object>::Cast(args[0]);
// 	Handle<Value> cmd = dbreq_obj->Get(String::NewFromUtf8(isolate, "command"));
// 	v8::String::Utf8Value utfvalue(cmd);
// 	std::string x = std::string(*utfvalue, utfvalue.length());
// 	dbrequest.setcmd(x);
// 	return dbrequest;
// }


// associates the module name with initialization logic
NODE_MODULE(addon, init)