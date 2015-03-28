//
//  test.cpp
//  
//
//  Created by Anna Jo McMahon on 3/28/15.
//
//

//
//  parseTree.cpp
//
//
//  Created by Anna Jo McMahon on 3/24/15.
//
//


//#define foreach         BOOST_FOREACH
//#define reverse_foreach BOOST_REVERSE_FOREACH
#include <stdio.h>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string>
#include <iostream>
#include <boost/optional/optional.hpp>

using namespace std;
using boost::property_tree::ptree;

string indent(int level) {
	string s;
	for (int i=0; i<level; i++) s += "  ";
	return s;
}

void printTree (ptree &pt, int level) {
	if (pt.empty()) {
		cerr << "\""<< pt.data()<< "\"";
	} else {
		if (level) cerr << endl;
		cerr << indent(level) << "{" << endl;
		for (ptree::iterator pos = pt.begin(); pos != pt.end();) {
			cerr << indent(level+1) << "\"" << pos->first << "\": ";
			printTree(pos->second, level + 1);
			++pos;
			if (pos != pt.end()) {
				cerr << ",";
			}
			cerr << endl;
		}
		cerr << indent(level) << " }";
	}
	return;
}

void parse_tree(const ptree& pt, std::string key)
{
	std::string nkey;
	
	if (!key.empty())
	{
		// The full-key/value pair for this node are key / pt.data()
		nkey = key + ".";
		cout<<nkey<<endl;
	}
	
	ptree::const_iterator end = pt.end();
	for (ptree::const_iterator it = pt.begin(); it != end; ++it)
	{
		parse_tree(it->second, nkey + it->first);
	}
}

void printWindData(const ptree& node)
{
	//	BOOST_FOREACH(const ptree::value_type& child, node.get_child("speed")) {
	//		std::cout<< "windy data"<<endl;
	//	}
}

int main(int, char*[]) {
	string tagfile = "file2.json";
	ptree pt;
	bool success = true;
	//try {
	read_json(tagfile, pt);
	printWindData(pt);
	printTree(pt, 0);
	parse_tree(pt, "");
	boost::optional<float> v = pt.get_optional<float>("query.results.channel.wind.chill");
	cout<< v <<endl;
	
	//ptree::const_iterator it = pt.find("chill");
	//double pi = boost::lexical_cast<double>(it->second._ptree_data__());
	
	//use get_optional if you are not sure that it exists
	
	//	int pi = pt.get<int>("chill");     // get double
	//	cout<< pi <<endl;
	
	//	ptree pt;
	//	/* ... */
	//	float v = pt.get<float>("a.path.to.float.value");
	
	//	ptree::const_iterator itt = pt.find("windchill");
	//	string windchill = (itt->second._ptree_data__());
	//		cout<< windchill <<endl;
//	
//	ptree::const_assoc_iterator it = pt.find("a");
//	if( it == pt.not_found() )
//	{
//		cout<< "That value does not exist"<<endl;
//	}else{
//	}
//	
	
	
	
	
	
	
	//	boost::optional< ptree& > child = node.get_child_optional( "possibly_missing_node" );
	//	if( !child )
	//	{
	//		cout<< "dnexists"<<endl;
	//	}
	//	tree_type::const_iterator end = tree.end();
	//	for (your_tree_type::const_iterator it = tree.begin(); it != end; ++it)
	
	//	typedef std::map<int, int> map_type;
	//	map_type map = /* ... */;
	//
	//	BOOST_FOREACH(const map_type::value_type& myPair, map)
	//	{
	//		// ...
	//	}
	
	cerr << endl;
	return success;
}

