
var rainfall = require("./build/Release/addon.node");
var DBrequest={ "command": "Hello"};
console.log(rainfall.hello());
console.log(rainfall.GetDB_Vec(DBrequest));
console.log(rainfall.GetDb());
