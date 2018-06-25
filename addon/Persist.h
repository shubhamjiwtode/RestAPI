#pragma once
///////////////////////////////////////////////////////////////////////
// Persist.h - persist DbCore<P> to and from XML file                //
// ver 1.0                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2018         //
///////////////////////////////////////////////////////////////////////
/*
*  Package Operations:
*  -------------------
*  This package defines a single Persist class that:
*  - accepts a DbCore<P> instance when constructed
*  - persists its database to an XML string
*  - creates an instance of DbCore<P> from a persisted XML string
*  
*  Required Files:
*  ---------------
*  Persist.h, Persist.cpp
*  DbCore.h, DbCore.cpp
*  Query.h, Query.cpp
*  PayLoad.h
*  XmlDocument.h, XmlDocument.cpp
*  XmlElement.h, XmlElement.cpp
*
*  Maintenance History:
*  --------------------
*  ver 1.0 : 12 Feb 2018
*  - first release
*/

//#include "./dbCore.h"


#include "./XmlDocument.h"
#include "./XmlElement.h"
#include "./payload.h"
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace::std;



  using namespace XmlProcessing;
  using Xml = std::string;
  using Sptr = std::shared_ptr<AbstractXmlElement>;

  const bool augment = true;   // do augment
  const bool rebuild = false;  // don't augment

  /////////////////////////////////////////////////////////////////////
  // Persist<P> class
  // - persist DbCore<P> to XML string

 
  class Persist
  {
  public:
    Persist(std::unordered_map<string,payload>& db): db_(db) {}

    static void identify(std::ostream& out = std::cout);
    // Persist& shard(const Keys& keys);
    // Persist& addShardKey(const Key& key);
    // Persist& removeShard();
    string toXml();
   // bool fromXml(const Xml& xml, bool augment = true); 
	// will clear and reload db if augment is false !!!
  private:
    unordered_map<string,payload>& db_;
    //dbcore db_;
    std::vector<string> shardKeys_;
    bool containsKey(const string& key);
    void toXmlRecord(Sptr pDb, const string& key, payload& pay);
  };
  

