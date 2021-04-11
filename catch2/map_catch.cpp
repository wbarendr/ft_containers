#include "catch.hpp"

#include <map>
#include "../Containers/Map/map.hpp"

TEST_CASE("map - Testing constructor 1")
{
    ft::map<int, std::string>   my_map;
    ft::pair<int, std::string>  first_pair(8, "hello");
    ft::pair<int, std::string>  second_pair(10, "doei");
    ft::pair<int, std::string>  third_pair(9, "of toch niet");
    ft::pair<int, std::string>  fourth_pair(4, "doei");
    ft::pair<int, std::string>  fifth_pair(3, "doei");
    ft::pair<int, std::string>  sixth_pair(18, "doei");


    my_map.insert(first_pair);
    my_map.insert(second_pair);
    my_map.insert(third_pair);
    my_map.insert(fourth_pair);
    my_map.insert(fifth_pair);
    my_map.insert(sixth_pair);
    // my_map.insert(first_pair);
    my_map.print_tree();
}