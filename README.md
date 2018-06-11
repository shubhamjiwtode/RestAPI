This project is about building a rest API for a NoSql database, the server is written in javascript and the core of data base is in cpp.
User can checkin a file with specuing related meatdata, if user checks-in file with open checkin the modification will be saved in same version,while when user closes the checking next modification will be added with new version

MetaData-
{filename,namespace,description,categories,children,status}

* SIGN-UP :- to sign up user need to provide email and prefered password to sign up
#post/auth/signup/
* LOGIN :- after loging in user gets a token to modify the database or to add the file
#post/auth/login/
* To get whole database
#get/database/
* To check in file
#post/database/<token>
* To get the meta data of the file
#get/database/<filename>
* To Checkout file
#get/file/<filename>
* To edit meta data
#patch/file/<filename>/<token>

