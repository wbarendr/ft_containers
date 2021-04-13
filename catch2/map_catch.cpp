#include "catch.hpp"

#include <map>
#include "../Containers/Map/map.hpp"

TEST_CASE("map - Testing constructor 1")
{
    ft::map<int, std::string>   my_map;
    ft::pair<int, std::string>  first_pair(1, "hello");
    ft::pair<int, std::string>  second_pair(2, "doei");
    ft::pair<int, std::string>  third_pair(3, "of toch niet");
    ft::pair<int, std::string>  fourth_pair(4, "doei");
    ft::pair<int, std::string>  fifth_pair(5, "doei");
    ft::pair<int, std::string>  sixth_pair(6, "doei");
    ft::pair<int, std::string>  seventh_pair(7, "doei");
    ft::pair<int, std::string>  eighth_pair(8, "doei");
    ft::pair<int, std::string>  ninth_pair(9, "doei");
    ft::pair<int, std::string>  tenth_pair(10, "doei");
    ft::pair<int, std::string>  eleventh_pair(11, "doei");
    ft::pair<int, std::string>  twelth_pair(12, "doei");
    ft::pair<int, std::string>  thirteenth_pair(13, "doei");
    ft::pair<int, std::string>  fourteenth_pair(14, "doei");
    ft::pair<int, std::string>  fifteenth_pair(15, "doei");
    ft::pair<int, std::string>  sixteenth_pair(16, "doei");


    my_map.insert(third_pair);
    my_map.insert(ninth_pair);
    my_map.print_tree();
    my_map.insert(tenth_pair);
    my_map.insert(eleventh_pair);
    my_map.insert(twelth_pair);
    my_map.print_tree();
    my_map.insert(fourth_pair);
    my_map.insert(second_pair);
    my_map.insert(first_pair);
    my_map.insert(thirteenth_pair);
    my_map.insert(fifteenth_pair);
    my_map.insert(fourteenth_pair);
    my_map.insert(ft::pair<int, std::string>(25, "doei"));
    my_map.insert(first_pair);
    my_map.insert(sixth_pair);
    my_map.insert(ft::pair<int, std::string>(26, "doei"));
    my_map.insert(ft::pair<int, std::string>(27, "doei"));
    my_map.insert(ft::pair<int, std::string>(28, "doei"));
    my_map.insert(sixteenth_pair);
    my_map.insert(ft::pair<int, std::string>(17, "doei"));
    my_map.insert(ft::pair<int, std::string>(18, "doei"));
    my_map.insert(ft::pair<int, std::string>(19, "doei"));
    my_map.insert(ft::pair<int, std::string>(20, "doei"));
    my_map.insert(fifth_pair);
    my_map.insert(eighth_pair);
    my_map.insert(seventh_pair);
    my_map.insert(ft::pair<int, std::string>(21, "doei"));
    my_map.insert(ft::pair<int, std::string>(22, "doei"));
    my_map.insert(ft::pair<int, std::string>(23, "doei"));
    my_map.insert(ft::pair<int, std::string>(24, "doei"));
    my_map.print_tree();
}