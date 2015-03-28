#ifdef _MSC_VER
#include <boost/config/compiler/visualc.hpp>
#endif
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
 
int main()
{
    try
    {
        std::stringstream ss;
        ss <<" { \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4] }";
 
        boost::property_tree::ptree pt;
        boost::property_tree::read_json(ss, pt);
 
        BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("a"))
        {
            assert(v.first.empty()); // array elements have no names
    std::cout << v.second.data()<<" here" << std::endl;
        }
        return EXIT_SUCCESS;
    

 if (pt.empty()) {
    cerr << "\""<< pt.data()<< "\"";
  } else {
    //if (level) cerr << endl;
	  
    cerr << " " << "{" << endl;
	  for (boost::property_tree::ptree::iterator pos = pt.begin(); pos != pt.end();) {
      cerr << "    " << "\"" << pos->first << "\": ";
   //   printTree(pos->second, 2);
      ++pos; 
      if (pos != pt.end()) {
        cerr << ","; 
      }
      cerr << endl;
    } 
    cerr << " " << " }";
 	 }

	}
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return EXIT_FAILURE;
}
