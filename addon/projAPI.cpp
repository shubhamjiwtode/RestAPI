// projAPI.cpp : Defines the entry point for the console application.

#pragma once
#include <node.h>

#include <v8.h>
#include <uv.h>
#include <string>
#include <vector>
#include <unordered_map>
//#include "E:/MS/Summerprojects/proj 4/Project4/server_API/server_API.h"
//#include "../proj 4/Project4/server_API/server_API.h"


#include "rainfall.h"
#include "addon.h"
#include "checkin.h"
#include "checkout.h"

using namespace std;
using namespace v8;


unordered_map<string,payload> db;

void Method(const v8::FunctionCallbackInfo<Value>& args);
void checkinMethod(const v8::FunctionCallbackInfo<Value>& args);
void getDBMethod(const v8::FunctionCallbackInfo<Value>& args);
void checkoutMethod(const v8::FunctionCallbackInfo<Value>& args);

void init(Handle <Object> exports, Handle<Object> module) {
	
    NODE_SET_METHOD(exports, "hello", Method);
    NODE_SET_METHOD(exports, "checkinM", checkinMethod);
    NODE_SET_METHOD(exports,"database",getDBMethod);
    NODE_SET_METHOD(exports,"checkoutM",checkinMethod);
}



void Method(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
 std::string xx="shubham";
 
 //v8::Local<v8::String> hTextJS = v8::String::NewFromUtf8(v8::Isolate::GetCurrent(), sText.c_str())
  v8::Local<v8::String> source =
        v8::String::NewFromUtf8(isolate, xx.c_str());
  args.GetReturnValue().Set(source);
}

void checkinMethod(const v8::FunctionCallbackInfo<Value>& args){
Isolate* isolate = args.GetIsolate();
   unpack unpack_;
  payload pay = unpack_.unpackpayload(isolate, Handle<Object>::Cast(args[0]));
  string xx;
  checkin _check(db);
  if(_check.makecheckin(pay))
  {
  	xx="woho";
  }else{
  	xx="fuck";
  }
  v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate, xx.c_str());
  args.GetReturnValue().Set(source);
}

void getDBMethod(const v8::FunctionCallbackInfo<Value>& args){
  Isolate* isolate = args.GetIsolate();
  dbcore dbcore_(db);
  std::vector<string> v;
  v=dbcore_.getkeys();
  Local<Array> result_list = Array::New(isolate);
  for (int i=0;i<v.size();i++)
  {
     v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate,v[i].c_str());
    /* code */
    result_list->Set(i,source);
  }
  args.GetReturnValue().Set(result_list);
}

void checkoutMethod(const v8::FunctionCallbackInfo<Value>& args){
  checkout checkout_(db);
  //checkout_.makecheckout();
}


NODE_MODULE(addon, init)