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
#include "string.h"
using namespace rapidjson;
using namespace std;





int main(int, char*[]) {
FILE* pFile = fopen("file2", "r");
char buffer[65536];
FileReadStream is(pFile, buffer, sizeof(buffer));
rapidjson::Document dlast;
	int unimportant =1;
dlast.ParseStream<0, UTF8<>, FileReadStream>(is);
  // if ( dlast[ "a" ].IsObject() ) {
    //    rapidjson::StringBuffer sb;
      //  rapidjson::Writer<rapidjson::StringBuffer> writer( sb );
       // dlast[ "a" ].Accept( writer );
       // std::cout << sb.GetString() << std::endl;


//    printf("hello = %s\n", dlast[ "a" ]["z"].GetString());
   // }





// iterate through and look at the types


static const char* kTypeNames[] = { "Null", "False", "True", "Object", "Array", "String", "Number" };

for (Value::ConstMemberIterator itr = dlast.MemberBegin();itr != dlast.MemberEnd(); ++itr)
{
    printf("Type of member %s is %s\n", itr->name.GetString(), kTypeNames[itr->value.GetType()]);
	//unimportant = findObjects(dlast, itr->name.GetString() , kTypeNames[itr->value.GetType()]);


if(strcmp(kTypeNames[itr->value.GetType()], "Object")==0){
	//unimportant = findObjects(dlast, itr->name.GetString() , kTypeNames[itr->value.GetType()]);
	rapidjson::Document document1;
	rapidjson::StringBuffer sb;
        rapidjson::Writer<rapidjson::StringBuffer> writer( sb );
        dlast[itr->name.GetString()].Accept( writer );
        std::cout << sb.GetString() << std::endl;
	if ( document1.Parse<0>(sb.GetString() ).HasParseError() ) {
    		std::cout << "Error parsing" << std::endl;
	} else {
		//findObjects(document1, sb.GetString() , jtype);
		
	for (Value::ConstMemberIterator itr = document1.MemberBegin();itr != document1.MemberEnd(); ++itr)
	{
   	 printf("Type of member %s is %s\n",itr->name.GetString(), kTypeNames[itr->value.GetType()]);
	}		
	}
}else{
	//return 0
}
}

    return 0;
}


//int findObjects(Document doc, const char jstr[] , const char jtype[]){
//	static const char* kTypeNames[] = { "Null", "False", "True", "Object", "Array", "String", "Number" };
//	if(strcmp(jtype, "Object")!=0)
//		return 1;// base case
//	rapidjson::Document document1;
//	rapidjson::StringBuffer sb;
//	rapidjson::Writer<rapidjson::StringBuffer> writer( sb );
//	doc[jstr].Accept( writer );
//	std::cout << sb.GetString() << std::endl;
//	
//	if ( document1.Parse<0>(sb.GetString() ).HasParseError() ) {
//		std::cout << "Error parsing" << std::endl;
//		return 1;
//	}
//	for (Value::ConstMemberIterator itr = document1.MemberBegin();itr != document1.MemberEnd(); ++itr)
//	{
//		//findObjects(document1, sb.GetString() , jtype);
//
//		//findObjects(document1, itr->name.GetString(), kTypeNames[itr->value.GetType()] );
//		// printf("Type of member %s is %s\n",itr->name.GetString(), kTypeNames[itr->value.GetType()]);
//	}
//	return 1;
//	
//}





