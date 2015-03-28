#include <iostream>
#include <map>
#include <string>
#include <boost/property_map/property_map.hpp>


template <typename AddressMap>
void foo(AddressMap address)
{
  typedef typename boost::property_traits<AddressMap>::value_type value_type;
  typedef typename boost::property_traits<AddressMap>::key_type key_type;

  value_type old_address, new_address;
  key_type fred = "Fred";
  old_address = get(address, fred);
  new_address = "384 Fitzpatrick Street";
  put(address, fred, new_address);

  key_type joe = "Joe";
  value_type& joes_address = address[joe];
  joes_address = "325 Cushing Avenue";
}

int
main()
{
  std::map<std::string, std::string> name2address;
  boost::associative_property_map< std::map<std::string, std::string> >
    address_map(name2address);

  name2address.insert(make_pair(std::string("Fred"), 
                                std::string("710 West 13th Street")));
  name2address.insert(make_pair(std::string("Joe"), 
                                std::string("710 West 13th Street")));

  foo(address_map);
  
  for (std::map<std::string, std::string>::iterator i = name2address.begin();
       i != name2address.end(); ++i)
    std::cout << i->first << ": " << i->second << "\n";

  return EXIT_SUCCESS;
}




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
//ptree::const_assoc_iterator it = pt.find("a");
//if( it == pt.not_found() )
//{
//	cout<< "That value does not exist"<<endl;
//	}else{
//		
//	}
//	
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






