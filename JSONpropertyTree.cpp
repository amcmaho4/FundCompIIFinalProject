//
//  JSONpropertyTree.cpp
//  
//
//  Created by Anna Jo McMahon on 3/28/15.
//
//

#include "JSONpropertyTree.h"
#include <stdio.h>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string>
#include <iostream>
#include <boost/optional/optional.hpp>

using namespace std;
using boost::property_tree::ptree;

JSONpropertyTree::JSONpropertyTree(string file, ptree &pt2){
	read_json(file, pt2);
	pt = pt2;
}

string indent(int level) {
	string s;
	for (int i=0; i<level; i++) s += "  ";
	return s;
}


void JSONpropertyTree::printTree(ptree &pt, int level){
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
