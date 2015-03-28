//
//  serialization.cpp
//  
//
//  Created by Anna Jo McMahon on 3/28/15.
//
//

#include <sstream>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;
using namespace std;

void example() {
	// Write json.
	ptree pt;
	pt.put ("foo", "bar");
	ostringstream buf;
	write_json (buf, pt, false);
	string json = buf.str(); // {"foo":"bar"}
	
	// Read json.
	ptree pt2;
	istringstream is (json);
	read_json (is, pt2);
	string foo = pt2.get<string> ("foo");
}

string map2json (const map<string, string>& map) {
	ptree pt;
	for (auto& entry: map)
		pt.put (entry.first, entry.second);
	ostringstream buf;
	write_json (buf, pt, false);
	return buf.str();
}


int main(int, char*[]) {
	example();
}