#include "addon.h"
#include <string>



payload unpack::unpackpayload(Isolate * isolate, const Handle<Object> payload_obj)
{
	
	std::vector<string> v;
	
	Handle<Value> filename_Value = payload_obj->Get(String::NewFromUtf8(isolate,"filename"));
	v8::String::Utf8Value utfValue(filename_Value);
	std::string fileName = std::string(*utfValue, utfValue.length());
	pay.setfilename(fileName);
	
	Handle<Value> namespace_Value = payload_obj->Get(String::NewFromUtf8(isolate,"namespace"));
	v8::String::Utf8Value utfValue1(namespace_Value);
	std::string nameSpace = std::string(*utfValue1, utfValue1.length());
	pay.setnamespace(nameSpace);

	Handle<Value> descrip_Value = payload_obj->Get(String::NewFromUtf8(isolate,"description"));
	v8::String::Utf8Value utfValue2(descrip_Value);
	std::string Descrip = std::string(*utfValue2, utfValue2.length());
	pay.setdescrip(Descrip);

	Handle<Array> array = Handle<Array>::Cast(payload_obj->Get(String::NewFromUtf8(isolate,"dependencies")));
	int count = array->Length();
	for ( int i = 0; i < count; i++ ) {
		Handle<Value> child_Value = Handle<Object>::Cast(array->Get(i));//->Get(String::NewFromUtf8(isolate, "date"));
		v8::String::Utf8Value utfValue3(child_Value);
		std::string child = std::string(*utfValue3, utfValue3.length());
		v.push_back(child);
	}
	pay.setdependency(v);
	
	Handle<Value> status_Value = payload_obj->Get(String::NewFromUtf8(isolate,"status"));
	v8::String::Utf8Value utfValue4(status_Value);
	std::string Status = std::string(*utfValue4, utfValue4.length());
  	pay.setstatus(Status);

  	Handle<Value> datetime_Value = payload_obj->Get(String::NewFromUtf8(isolate,"datetime"));
  	v8::String::Utf8Value utfValue5(datetime_Value);
	std::string dateTime = std::string(*utfValue5, utfValue5.length());
	pay.setdatetime(dateTime);

  	return pay;

}