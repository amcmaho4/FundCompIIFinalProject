
#include <boost/property_tree/ptree.hpp> 
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <cstdlib>
#include <iostream>
using namespace std;
//NOT WORKING
//COULD BE HELPFUL, uses URLs

int ParseJson()
{
  std::string str = "{\"code\":0,\"images\":[{\"url\":\"fmn057/20111221/1130/head_kJoO_05d9000251de125c.jpg\"},{\"url\":\"fmn057/20111221/1130/original_kJoO_05d9000251de125c.jpg\"}]}";
  using namespace boost::property_tree;

  std::stringstream ss(str);
  ptree pt;
  try{    
    read_json(ss, pt);
  }
  catch(ptree_error & e) {
    return 1; 
  }

  try{
    int code = pt.get<int>("code");   // "code"value
    ptree image_array = pt.get_child("images");  // get_child
    
    // 
    BOOST_FOREACH(boost::property_tree::ptree::value_type &v, image_array)
    {
      std::stringstream s;
      write_json(s, v.second);
      std::string image_item = s.str();
    }
  }
  catch (ptree_error & e)
  {
    return 2;
  }
  return 0;
}
