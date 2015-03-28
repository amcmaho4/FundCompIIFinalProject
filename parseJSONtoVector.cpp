#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>
#include <sstream>
#include <vector>
namespace pt = boost::property_tree;
namespace jsp = boost::property_tree::json_parser;

// pushing back mapped values into a vector
// example of how to use get_child
int main()
{
   const std::string json = "{\"numberValues\":[1,2,3]}";
	
   std::stringstream ss(json);
   pt::ptree p;
   jsp::read_json(ss, p);
   std::vector<int> v;
	
	pt::ptree this_ = p.get_child("numberValues");
   for (const auto& tree : this_)
   {
      v.push_back(tree.second.get<int>(""));
   }
   for (auto i : v)
   {
      std::cout << i << std::endl;
   }
}
