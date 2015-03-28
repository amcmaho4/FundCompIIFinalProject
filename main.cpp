//
//  main.cpp
//  
//
//  Created by Anna Jo McMahon on 3/28/15.
//
//

#include <stdio.h>
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


int main(int, char*[]) {
	ptree &pt2;
	JSONpropertyTree pTree("file2.json", pt2);
	pTree.printTree(pt2, 0);

}