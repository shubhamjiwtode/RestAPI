#pragma once
#include <node.h>

#include <v8.h>
#include <uv.h>
#include <string>
#include "payload.h"

using namespace v8;




using namespace std;

class unpack{
	payload pay;
public:
payload unpackpayload(Isolate * isolate, const Handle<Object> payload_obj);

};



