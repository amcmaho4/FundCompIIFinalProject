// Hello World example
// This example shows basic usage of DOM-style API.
#include "rapidjson/writer.h"
#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON
#include "rapidjson/filestream.h"   // wrapper of C stream for prettywriter as output
#include <rapidjson/filereadstream.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>     // std::cout
#include <fstream> 
using namespace rapidjson;
using namespace std;

int main(int, char*[]) {


FILE* pFile = fopen("file2", "r");
char buffer[65536];
FileReadStream is(pFile, buffer, sizeof(buffer));
rapidjson::Document dlast;

dlast.ParseStream<0, UTF8<>, FileReadStream>(is);
   if ( dlast[ "a" ].IsObject() ) {
        rapidjson::StringBuffer sb;
        rapidjson::Writer<rapidjson::StringBuffer> writer( sb );
        dlast[ "a" ].Accept( writer );
        std::cout << sb.GetString() << std::endl;

//       assert(document1[ "a" ].IsObject());    // Document is a JSON value represents the root of DOM. Root can be either an object or array.

   // assert(dlast[ "a" ].HasMember("z"));
  // assert(dlast[ "a" ]["z"].IsString());
    printf("hello = %s\n", dlast[ "a" ]["z"].GetString());
    }

//    printf("hello = %s\n", dlast[ "a" ]["z"].GetString());
rapidjson::Document document1;
std::string test =  "{\"a\":{\"z\": \"anna\"}} ";
if ( document1.Parse<0>( test.c_str() ).HasParseError() ) {
    std::cout << "Error parsing" << std::endl;
} else {
    if ( document1[ "a" ].IsObject() ) {
        rapidjson::StringBuffer sb;
        rapidjson::Writer<rapidjson::StringBuffer> writer( sb );
        document1[ "a" ].Accept( writer );
        std::cout << sb.GetString() << std::endl;

//	 assert(document1[ "a" ].IsObject());    // Document is a JSON value represents the root of DOM. Root can be either an object or array.

    assert(document1[ "a" ].HasMember("z"));
   assert(document1[ "a" ]["z"].IsString());
    printf("hello = %s\n", document1[ "a" ]["z"].GetString());
    }


// iterate through and look at the types


static const char* kTypeNames[] = { "Null", "False", "True", "Object", "Array", "String", "Number" };

for (Value::ConstMemberIterator itr = dlast.MemberBegin();itr != dlast.MemberEnd(); ++itr)
{
    printf("Type of member %s is %s\n", itr->name.GetString(), kTypeNames[itr->value.GetType()]);


if(strcmp(kTypeNames[itr->value.GetType()], "Object")==0){
//	findObjects(dlast, itr->name.GetString() , kTypeNames[itr->value.GetType()]);
	rapidjson::Document document1;
	rapidjson::StringBuffer sb;
        rapidjson::Writer<rapidjson::StringBuffer> writer( sb );
        dlast[itr->name.GetString()].Accept( writer );
        std::cout << sb.GetString() << std::endl;
	if ( document1.Parse<0>(sb.GetString() ).HasParseError() ) {
    		std::cout << "Error parsing" << std::endl;
	} else {
	for (Value::ConstMemberIterator itr = document1.MemberBegin();itr != document1.MemberEnd(); ++itr)
	{
   	 printf("Type of member %s is %s\n",itr->name.GetString(), kTypeNames[itr->value.GetType()]);
	}		
	}
}else{
	//return 0
}
}
}
    return 0;
}
//void findObjects(Document doc, string jstr , string jtype){
//    	static const char* kTypeNames[] = { "Null", "False", "True", "Object", "Array", "String", "Number" };
//	if(strcmp(jtype, "Object")!=0) return;// base case
//	rapidjson::Document document1;
//        rapidjson::StringBuffer sb;
//        rapidjson::Writer<rapidjson::StringBuffer> writer( sb );
//        doc[jstr].Accept( writer );
//        std::cout << sb.GetString() << std::endl;
//        if ( document1.Parse<0>(sb.GetString() ).HasParseError() ) {
//               std::cout << "Error parsing" << std::endl;
//               return;
//        }
// 	for (Value::ConstMemberIterator itr = document1.MemberBegin();itr != document1.MemberEnd(); ++itr)
//        {
//	findObjects(doc, itr->name.GetString(), kTypeNames[itr->value.GetType()] );
//        // printf("Type of member %s is %s\n",itr->name.GetString(), kTypeNames[itr->value.GetType()]);
//      	}
//}


