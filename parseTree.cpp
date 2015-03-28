//
//  parseTree.cpp
//  
//
//  Created by Anna Jo McMahon on 3/24/15.
//
//


#define foreach         BOOST_FOREACH
#define reverse_foreach BOOST_REVERSE_FOREACH
#include <stdio.h>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string>
#include <iostream>
#include <boost/optional/optional.hpp>
#include <boost/lexical_cast.hpp>

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



void parseForFullPath(const ptree& pt, string key)
{
	string nkey;
	if (!key.empty()){
		nkey = key + ".";
		cout<<nkey<<endl;
	}
	ptree::const_iterator end = pt.end();
	for (ptree::const_iterator it = pt.begin(); it != end; ++it){
		parseForFullPath(it->second, nkey + it->first);
	}
}

void findDataMemberWithFullPath(const ptree& pt, string key){
	boost::optional<float> v = pt.get_optional<float>(key);
	cout<< v <<endl;
	
}

void storeInAVector(const ptree& pt, string key){
	// template so that make more than string vecs
	vector<string> v;
	ptree this_ = pt.get_child(key);
	for (const auto& tree : this_){
		v.push_back(tree.second.get<string>(""));
	}
	for (auto i : v){
		std::cout << i << std::endl;
	}
}




int main(int, char*[]) {
	string tagfile = "file2.json";
	ptree pt;
	// "ptree" or property tree is a struct defined by boosts' lib
	read_json(tagfile, pt);
	printTree(pt, 0);
	
	parseForFullPath(pt, ""); // this gives you all the full paths,  which can be used in the below function
	findDataMemberWithFullPath(pt, "query.results.channel.wind.chill");

	

	//Template this function to make it more useable
	storeInAVector(pt, "query"); // stores the string results of this query in a vector
	
	// another way to loop through tree
	BOOST_FOREACH(const ptree::value_type &v, pt.get_child("query")) {
		cout<< v.first; // v.first is the name of the child
		cout<< ": " << v.second.data()<< endl; // v.second is the child tree
	}
	
	//ptree::const_iterator it = pt.find("chill");
	//double pi = boost::lexical_cast<double>(it->second._ptree_data__());

	cerr << endl; // cerr is like cout but error checking(?), outputs immediately
}


