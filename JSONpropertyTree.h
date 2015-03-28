//
//  JSONpropertyTree.h
//  
//
//  Created by Anna Jo McMahon on 3/28/15.
//
//

#ifndef ____JSONpropertyTree__
#define ____JSONpropertyTree__

#include <stdio.h>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string>
#include <iostream>
#include <boost/optional/optional.hpp>

using namespace std;
using boost::property_tree::ptree;

class JSONpropertyTree{
	
public:
	JSONpropertyTree(string,ptree &);
	void printTree(ptree &, int);
	
private:
	ptree &pt; // holds the parsed tree
};
#endif /* defined(____JSONpropertyTree__) */
