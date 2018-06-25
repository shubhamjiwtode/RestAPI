///////////////////////////////////////////////////////////////////////
// Persist.cpp - persist DbCore<PayLoad> to and from XML file        //
// ver 1.0                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2018         //
///////////////////////////////////////////////////////////////////////

//----< test stub >----------------------------------------------------



#include "Persist.h"

//----< constructor >------------------------------------------------

  
 // Persist::Persist(std::unordered_map<string,payload> db) 

  //----< show file name >---------------------------------------------

 
  void Persist::identify(std::ostream& out)
  {
    out << "\n  \"" << __FILE__ << "\"";
  }
  //----< add key to shard collection >--------------------------------
  /*
  * - when sharding, a db record is persisted if, and only if, its key
      is contained in the shard collection
  */

  // Persist& Persist::addShardKey(const Key& key)
  // {
  //   shardKeys_.push_back(key);
  //   return *this;
  // }
  //----< does the shard key collection contain key? >-----------------

  
  bool Persist::containsKey(const string& key)
  {
    std::vector<string>::iterator start = shardKeys_.begin();
    std::vector<string>::iterator end = shardKeys_.end();
    return std::find(start, end, key) != end;
  }
  //----< set the shardKeys collection >-------------------------------

  
  // Persist& Persist::shard(const Keys& keys)
  // {
  //   shardKeys_ = keys;
  //   return *this;
  // }
  //----< empty the shardKeys collection >-----------------------------

 
  // Persist& Persist::removeShard()
  // {
  //   shardKeys_.clear();
  // }
  //----< persist database record to XML string >----------------------

  
  void Persist::toXmlRecord(Sptr pDb, const string& key, payload& pay)
  {
    std::string stat;
    Sptr pRecord = makeTaggedElement("dbRecord");
    pDb->addChild(pRecord);
    Sptr pKey = makeTaggedElement("key", key);
    pRecord->addChild(pKey);
  
    Sptr pValue = makeTaggedElement("value");
    pRecord->addChild(pValue);
    Sptr pName = makeTaggedElement("file", pay.getfilename());
    pValue->addChild(pName);
    Sptr pNamespace = makeTaggedElement("namespace", pay.getnamespace());
    pValue->addChild(pNamespace);
    Sptr pDescrip = makeTaggedElement("description", pay.getdescrip());
    pValue->addChild(pDescrip);
  if (pay.getstatus() == "0"){stat = "Close"; }
  else { stat = "Open"; }
  Sptr pstat = makeTaggedElement("status", stat);
  pValue->addChild(pstat);
  Sptr pdate = makeTaggedElement("DateTime", pay.getdatetime());
  pValue->addChild(pdate);
    Sptr pChildren = makeTaggedElement("children");
    pValue->addChild(pChildren);
    for (auto child : pay.getdependency())
    {
      Sptr pChild = makeTaggedElement("child", child);
      pChildren->addChild(pChild);
    }
    Sptr ppath = makeTaggedElement("Path", pay.getpath());
    pValue->addChild(ppath);

    
  }
  //----< persist, possibly sharded, database to XML string >----------
  /*
  * - database is sharded if the shardKeys collection is non-empty
  */
 
  std::string Persist::toXml()
  {
    Sptr pDb = makeTaggedElement("db");
    pDb->addAttrib("type", "MainDatabase");
    Sptr pDocElem = makeDocElement(pDb);
    XmlDocument xDoc(pDocElem);

    // if (shardKeys_.size() > 0)               ////have to look/////
    // {
    //   for (auto key : shardKeys_)
    //   {
    //     payload pay=db_[key];
    //     DbElement<P> elem = db_[key];
    //     toXmlRecord(pDb, key, elem);
    //   }
    // }
    // else
 
      for (auto item : db_)
      {
        toXmlRecord(pDb, item.first, item.second);
      }
    
    std::string xml = xDoc.toString();
    return xml;
  }
  //----< retrieve database from XML string >--------------------------
  /*
  * - Will clear db and reload if augment is false
  */
  
  // bool Persist::fromXml(const Xml& xml, bool augment)
  // {
  //   XmlProcessing::XmlDocument doc(xml);
  //   if(!augment)
  //     db_.dbStore().clear();
  //   std::vector<Sptr> pRecords = doc.descendents("dbRecord").select();
  //   for (auto pRecord : pRecords)
  //   {
  //     Key key;
  //     DbElement<P> elem;
  //     P pl;

  //     std::vector<Sptr> pChildren = pRecord->children();
  //     for (auto pChild : pChildren)
  //     {
  //       if (pChild->tag() == "key")
  //       {
  //         key = pChild->children()[0]->value();
  //       }
  //       else
  //       {
  //         std::vector<Sptr> pValueChildren = pChild->children();
  //         std::string valueOfTextNode;
  //         for (auto pValueChild : pValueChildren)
  //         {
  //           std::string tag = pValueChild->tag();
  //           if (pValueChild->children().size() > 0)
  //             valueOfTextNode = pValueChild->children()[0]->value();
  //           else
  //             valueOfTextNode = "";

  //           if (tag == "name")
  //           {
  //             elem.name(valueOfTextNode);
  //           }
  //           else if (tag == "description")
  //           {
  //             elem.descrip(valueOfTextNode);
  //           }
  //           else if (tag == "dateTime")
  //           {
  //             elem.dateTime(valueOfTextNode);
  //           }
  //           else if (tag == "children")
  //           {
  //             for (auto pChild : pValueChild->children())
  //             {
  //               valueOfTextNode = pChild->children()[0]->value();
  //               elem.children().push_back(valueOfTextNode);
  //             }
  //           }
  //           else if (tag == "payload")
  //           {
  //             pl = PayLoad::fromXmlElement(pValueChild);
  //             elem.payLoad(pl);
  //           }
  //         }
  //       }
  //       db_[key] = elem;
  //     }
  //   }
  //   return true;
  // }