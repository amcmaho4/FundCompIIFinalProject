nclude "rapidjson/writer.h"
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
    ////////////////////////////////////////////////////////////////////////////
    // 1. Parse a JSON text string to a document.


FILE* pFile = fopen("file", "r");
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

    assert(dlast[ "a" ].HasMember("z"));
   assert(dlast[ "a" ]["z"].IsString());
return 0
}
}

}
