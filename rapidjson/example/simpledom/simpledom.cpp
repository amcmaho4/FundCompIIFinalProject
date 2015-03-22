// JSON simple example
// This example does not handle errors.

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON
#include "rapidjson/filestream.h"   // wrapper of C stream for prettywriter as output
#include <cstdio>
#include <cstdlib>
#include <iostream>     // std::cout
#include <fstream>
using namespace rapidjson;
using namespace std;
using namespace rapidjson;

int main() {
    // 1. Parse a JSON string into DOM.
int array_size = 1024; // define the size of character array
        char * json = new char[array_size]; // allocating an array of 1kb
        int position = 0; //this will be used incremently to fill characters in the array 

        ifstream fin ("file"); //opening an input stream for file test.txt
        /*checking whether file could be opened or not. If file does not exist or don't have read permissions, file
  stream could not be opened.*/
  if(fin.is_open()){
                while(!fin.eof() && position < array_size)
                {
                        fin.get(json[position]); //reading one character from file to array
                        position++;
}
}

//     char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);

    // 2. Modify it by DOM.
    Value& s = d["count"];
    s.SetInt(s.GetInt() + 1);

    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
	cout<< "after"<<endl;	    
return 0;
}
