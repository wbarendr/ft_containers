#include "catch.hpp"

#include <map>
#include "../Containers/Map/map.hpp"

ft::map<int, std::string>       MyMap(){
    ft::map<int, std::string> my_map;

    my_map.insert(ft::pair<int, std::string>(10, "doei10"));
    my_map.insert(ft::pair<int, std::string>(5, "doei5"));
    my_map.insert(ft::pair<int, std::string>(-5, "doei-5"));
    my_map.insert(ft::pair<int, std::string>(7, "doei7"));
    my_map.insert(ft::pair<int, std::string>(20, "doei20"));
    my_map.insert(ft::pair<int, std::string>(30, "doei30"));
    my_map.insert(ft::pair<int, std::string>(32, "doei32"));
    my_map.insert(ft::pair<int, std::string>(38, "doei38"));
    my_map.insert(ft::pair<int, std::string>(41, "doei41"));
    my_map.insert(ft::pair<int, std::string>(35, "doei35"));
    my_map.insert(ft::pair<int, std::string>(39, "doei39"));
    my_map.insert(ft::pair<int, std::string>(45, "doei45"));

    return my_map;

}

ft::map<int, std::string>       MyMap2(){
    ft::map<int, std::string> my_map;

    my_map.insert(ft::pair<int, std::string>(13, "doei10"));
    my_map.insert(ft::pair<int, std::string>(8, "doei5"));
    my_map.insert(ft::pair<int, std::string>(1, "doei-5"));
    my_map.insert(ft::pair<int, std::string>(11, "doei7"));
    my_map.insert(ft::pair<int, std::string>(17, "doei20"));
    my_map.insert(ft::pair<int, std::string>(6, "doei20"));
    my_map.insert(ft::pair<int, std::string>(15, "doei30"));
    my_map.insert(ft::pair<int, std::string>(25, "doei32"));
    my_map.insert(ft::pair<int, std::string>(22, "doei38"));
    my_map.insert(ft::pair<int, std::string>(27, "doei41"));

    return my_map;

}

ft::map<int, std::string>       MyMap3(){
    ft::map<int, std::string> my_map;

    my_map.insert(ft::pair<int, std::string>(7, "doei7"));
    my_map.insert(ft::pair<int, std::string>(18, "doei5"));
    my_map.insert(ft::pair<int, std::string>(3, "doei-5"));
    my_map.insert(ft::pair<int, std::string>(10, "doei7"));
    my_map.insert(ft::pair<int, std::string>(22, "doei20"));
    my_map.insert(ft::pair<int, std::string>(8, "doei20"));
    my_map.insert(ft::pair<int, std::string>(11, "doei30"));
    my_map.insert(ft::pair<int, std::string>(26, "doei32"));

    return my_map;

}

ft::map<int, std::string>       MyMap4(){
    ft::map<int, std::string> my_map;

    my_map.insert(ft::pair<int, std::string>(5, "doei7"));
    my_map.insert(ft::pair<int, std::string>(1, "doei7"));
    my_map.insert(ft::pair<int, std::string>(8, "doei-5"));
    my_map.insert(ft::pair<int, std::string>(4, "doei20"));
    my_map.insert(ft::pair<int, std::string>(2, "doei5"));
    my_map.insert(ft::pair<int, std::string>(9, "doei30"));
    my_map.insert(ft::pair<int, std::string>(7, "doei20"));

    return my_map;

}

ft::map<int, std::string>       MyMap5(){
    ft::map<int, std::string> my_map;

    my_map.insert(ft::pair<int, std::string>(7, "doei7"));
    my_map.insert(ft::pair<int, std::string>(18, "doei7"));
    my_map.insert(ft::pair<int, std::string>(3, "doei-5"));
    my_map.insert(ft::pair<int, std::string>(10, "doei20"));
    my_map.insert(ft::pair<int, std::string>(22, "doei5"));
    my_map.insert(ft::pair<int, std::string>(8, "doei30"));
    my_map.insert(ft::pair<int, std::string>(11, "doei20"));
    my_map.insert(ft::pair<int, std::string>(26, "doei20"));

    return my_map;

}

std::map<int, std::string>      StdMap(){
    std::map<int, std::string> not_my_map;

    not_my_map.insert(std::pair<int, std::string>(10, "doei10"));
    not_my_map.insert(std::pair<int, std::string>(5, "doei5"));
    not_my_map.insert(std::pair<int, std::string>(-5, "doei-5"));
    not_my_map.insert(std::pair<int, std::string>(7, "doei7"));
    not_my_map.insert(std::pair<int, std::string>(20, "doei20"));
    not_my_map.insert(std::pair<int, std::string>(30, "doei30"));
    not_my_map.insert(std::pair<int, std::string>(32, "doei32"));
    not_my_map.insert(std::pair<int, std::string>(38, "doei38"));
    not_my_map.insert(std::pair<int, std::string>(41, "doei41"));
    not_my_map.insert(std::pair<int, std::string>(35, "doei35"));
    not_my_map.insert(std::pair<int, std::string>(39, "doei39"));
    not_my_map.insert(std::pair<int, std::string>(45, "doei45"));

    return not_my_map;
}

TEST_CASE("map - testing all delete node option")
{
    ft::map<int, std::string>   my_map1 = MyMap2();
    ft::map<int, std::string>   my_map2 = MyMap2();
    ft::map<int, std::string>   my_map3 = MyMap2();
    ft::map<int, std::string>   my_map4 = MyMap2();
    ft::map<int, std::string>   my_map5 = MyMap3();
    ft::map<int, std::string>   my_map6 = MyMap4();
    ft::map<int, std::string>   my_map7 = MyMap2();
    ft::map<int, std::string>   my_map8 = MyMap2();
    ft::map<int, std::string>   my_map9 = MyMap5();
    ft::map<int, std::string>   my_map10 = MyMap2();

    // my_map1.print_tree();
    // std::cout << "deleting 6" << std::endl;
    // my_map1.erase(my_map1.find(6));
    // my_map1.print_tree();

    // my_map2.print_tree();
    // std::cout << "deleting 1" << std::endl;
    // my_map2.erase(my_map2.find(1));
    // my_map2.print_tree();

    // my_map3.print_tree();
    // std::cout << "deleting 17" << std::endl;
    // my_map3.erase(my_map3.find(17));
    // my_map3.print_tree();

    // my_map4.print_tree();
    // std::cout << "deleting 25" << std::endl;
    // my_map4.erase(my_map4.find(25));
    // my_map4.print_tree();

    // my_map5.print_tree();
    // std::cout << "deleting 18" << std::endl;
    // my_map5.erase(my_map5.find(18));
    // my_map5.print_tree();

    // my_map6.manipulate(my_map6.find(2));
    // my_map6.print_tree();
    // std::cout << "deleting 2" << std::endl;
    // my_map6.erase(my_map6.find(2));
    // my_map6.print_tree();

    // my_map7.print_tree();
    // std::cout << "deleting 13" << std::endl;
    // my_map7.erase(my_map7.find(13));
    // my_map7.print_tree();

    // my_map8.print_tree();
    // std::cout << "deleting 8" << std::endl;
    // my_map8.erase(my_map8.find(8));
    // my_map8.print_tree();

    // my_map9.print_tree();
    // std::cout << "deleting 3" << std::endl;
    // my_map9.erase(my_map9.find(3));
    // my_map9.print_tree();

    // my_map10.print_tree();
    // std::cout << "deleting 11" << std::endl;
    // my_map10.erase(my_map10.find(11));
    // my_map10.print_tree();
}

TEST_CASE("map - Testing constructor range")
{
    ft::map<int, std::string> map1;
    map1.insert(ft::pair<int, std::string>(20, "doei"));
    map1.insert(ft::pair<int, std::string>(17, "doei"));
    map1.insert(ft::pair<int, std::string>(18, "deze"));
    map1.insert(ft::pair<int, std::string>(22, "doei"));
    // map1.print_tree();
    map1.insert(ft::pair<int, std::string>(23, "doei"));
    // map1.print_tree();
    map1.insert(ft::pair<int, std::string>(19, "doei"));

    // map1.print_tree();
    ft::map<int, std::string>::iterator it1 = map1.begin();
    ft::map<int, std::string>::iterator it2 = map1.end();
    it1++;
    it2--;
    it2--;
    ft::map<int, std::string> map2(it1, it2);
    // std::cout << "end:" << it2->first << std::endl;
    // map2.print_tree();
    ft::map<int, std::string>::iterator it3 = map2.begin();
    REQUIRE(map2.begin()->first == 18);
    REQUIRE(map2.begin()->second == "deze");
    it3++;
    REQUIRE(it3->first == 19);
    REQUIRE(it3->second == "doei");
    it3++;
    REQUIRE(it3->first == 20);
    REQUIRE(it3->second == "doei");
    it3++;
    REQUIRE(it3->first == 0);
    REQUIRE(it3->second == "");
}

TEST_CASE("map - Testing COPY-Constructor")
{
    ft::map<int, std::string> map1;
    map1.insert(ft::pair<int, std::string>(20, "doei"));
    map1.insert(ft::pair<int, std::string>(17, "doei"));
    map1.insert(ft::pair<int, std::string>(18, "deze"));
    map1.insert(ft::pair<int, std::string>(22, "doei"));
    map1.insert(ft::pair<int, std::string>(23, "doei"));
    map1.insert(ft::pair<int, std::string>(19, "doei"));

    ft::map<int, std::string>::iterator it1 = map1.begin();
    ft::map<int, std::string>::iterator it2 = map1.end();
    it1++;
    it2--;
    it2--;
    ft::map<int, std::string> map2(map1);
    // std::cout << "end:" << it2->first << std::endl;
    // map1.print_tree();
    // map2(map1);
    // map2.print_tree();
    ft::map<int, std::string>::iterator it3 = map2.begin();
    REQUIRE(map2.begin()->first == 17);
    REQUIRE(map2.begin()->second == "doei");
    it3++;
    REQUIRE(it3->first == 18);
    REQUIRE(it3->second == "deze");
    it3++;
    REQUIRE(it3->first == 19);
    REQUIRE(it3->second == "doei");
    it3++;
    REQUIRE(it3->first == 20);
    REQUIRE(it3->second == "doei");
}

TEST_CASE("map - Testing operator=")
{
    ft::map<int, std::string> map1;
    map1.insert(ft::pair<int, std::string>(20, "doei"));
    map1.insert(ft::pair<int, std::string>(17, "doei"));
    map1.insert(ft::pair<int, std::string>(18, "deze"));

    ft::map<int, std::string> map2 = map1;

    // map2.print_tree();

}

TEST_CASE("map - Testing reverse Iterator, empty, size and clear")
{
    ft::map<int, std::string> my_map = MyMap();
    std::map<int, std::string> std_map = StdMap();

    ft::map<int, std::string>::iterator it = my_map.begin();
    ft::map<int, std::string>::iterator it2 = my_map.end();
    ft::map<int, std::string>::reverse_iterator it3 = my_map.rbegin();
    ft::map<int, std::string>::reverse_iterator it4 = my_map.rend();

    // std::cout << "-----------" << std::endl;
    // for (; it3 != it4; ++it3)
    //     std::cout << it3->first << std::endl;
    // my_map.print_tree();
    REQUIRE(it3->first == 45);
    ++it3;
    REQUIRE(it3->first == 41);
    ++it3;
    REQUIRE(it3->first == 39);
    ++it3;
    REQUIRE(it3->first == 38);
    it3++;
    REQUIRE(it3->first == 35);
    it3++;
    REQUIRE(it3->first == 32);
    it3++;
    REQUIRE(it3->first == 30);
    it3++;
    REQUIRE(it3->first == 20);
    it3++;
    REQUIRE(it3->first == 10);
    it3++;
    REQUIRE(it3->first == 7);
    it3++;
    REQUIRE(it3->first == 5);
    it3++;
    REQUIRE(it3->first == -5);
    it3++;
    REQUIRE(it3->first == 0);

    REQUIRE(my_map.empty() == false);
    REQUIRE(my_map.size() == 12);
    my_map.clear();
    REQUIRE(my_map.empty() == true);

}

TEST_CASE("map - Bracket operator")
{
    ft::map<int, std::string> my_map = MyMap();
    std::map<int, std::string> std_map = StdMap();

    // my_map.print_tree();
    // std::cout << my_map.find(20)->second << std::endl;
    // std::cout << my_map.find(-5)->second << std::endl;
    // std::cout << my_map.find(5)->second << std::endl;
    REQUIRE(my_map.find(20)->second == "doei20");
    REQUIRE(my_map.find(-5)->second == std_map.find(-5)->second);
    REQUIRE(my_map.find(5)->second == std_map.find(5)->second);

    my_map[31] = "jaja";
    // my_map.print_tree();
    REQUIRE(my_map[31] == "jaja");
    REQUIRE(my_map[32] == "doei32");
}

TEST_CASE("map - insert return")
{
    ft::map<int, std::string> my_map = MyMap();
    std::map<int, std::string> std_map = StdMap();


    ft::pair<ft::map<int, std::string>::iterator, bool> peer;
    peer = my_map.insert(ft::pair<int, std::string>(22, "doei"));
   
    REQUIRE(peer.second == true);
    peer = my_map.insert(ft::pair<int, std::string>(20, "doei"));
    REQUIRE(peer.second == false);
    
    ft::map<int, std::string>::iterator it = my_map.end();
    ft::map<int, std::string>::iterator ret = my_map.insert(it, ft::pair<int, std::string>(-8, "doei"));
    REQUIRE(ret == my_map.begin());
}

TEST_CASE("map - erase and swap functions")
{
    ft::map<int, std::string> my_map = MyMap();
    ft::map<int, std::string> my_map2 = MyMap();

    // my_map.print_tree();
    REQUIRE(my_map.erase(30));
    REQUIRE(my_map.erase(31) == 0);
    // my_map.print_tree();

    ft::map<int, std::string>::reverse_iterator it1 = my_map.rbegin();
    ft::map<int, std::string>::reverse_iterator it2 = my_map.rend();

    for (; it1 != it2; ++it1){
        my_map.erase(it1->first);
        // my_map.print_tree();
    }
    REQUIRE(my_map.size() == 0);    

    REQUIRE(my_map.size() == 0);    
    // my_map.print_tree();
    my_map.insert(my_map2.begin(), my_map2.end());
    REQUIRE(my_map.size() == 12);    
    // my_map.print_tree();
    my_map.erase(my_map.begin(), my_map.end());
    REQUIRE(my_map.size() == 0);    
    // my_map.print_tree();

    my_map.insert(my_map2.begin(), my_map2.end());
    REQUIRE(my_map.size() == 12); 
    my_map.erase(20);
    my_map.erase(32);
    REQUIRE(my_map.size() == 10); 
    REQUIRE(my_map2.size() == 12); 
    my_map.swap(my_map2);
    REQUIRE(my_map.size() == 12); 
    REQUIRE(my_map2.size() == 10); 
    REQUIRE(my_map2.count(30) == 1);
    REQUIRE(my_map2.count(31) == 0);
    // my_map.print_tree();
    // my_map2.print_tree();

    // system("leaks a.out | grep bytes");
}

TEST_CASE("map - bounds")
{
    std::map<int, std::string> std_map = StdMap();
    ft::map<int, std::string> my_map = MyMap();

    REQUIRE(std_map.lower_bound(36)->first == 38);
    REQUIRE(my_map.lower_bound(36)->first == 38);
    REQUIRE(std_map.lower_bound(20)->first == 20);
    REQUIRE(my_map.lower_bound(20)->first == 20);

    // std::cout << "lower bound:" << std_map.upper_bound(35)->first << std::endl;
    // std::cout << "upper bound:" << std_map.lower_bound(35)->first << std::endl;

    REQUIRE(my_map.upper_bound(36)->first == 38);
    REQUIRE(std_map.upper_bound(36)->first == 38);
    REQUIRE(my_map.upper_bound(20)->first == 30);
    REQUIRE(std_map.upper_bound(20)->first == 30);

    REQUIRE(my_map.equal_range(20).first->first == 20);
    REQUIRE(my_map.equal_range(20).second->first == 30);
    REQUIRE(std_map.equal_range(20).first->first == 20);
    REQUIRE(std_map.equal_range(20).second->first == 30);

}
    