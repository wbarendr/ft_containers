#include "catch.hpp"

#include <list>
#include "list/list.hpp"

TEST_CASE("List - Testing constructor 1")
{
    ft::list<int> my_vec;
    REQUIRE(my_vec.size() == 0);
}

TEST_CASE("List - Testing constructor 2")
{
    ft::list<int> my_vec;

    my_vec.push_back(8);
    my_vec.push_back(7);
    my_vec.push_back(6);
    REQUIRE(my_vec.size() == 3);
    my_vec.clear();
    REQUIRE(my_vec.size() == 0);
}

TEST_CASE("List - Testing constructor 3")
{
    ft::list<int> my_vec(5, 6);
    REQUIRE(my_vec.size() == 5);
}

TEST_CASE("List - Testing copy constructor")
{
    ft::list<int> my_vec(5, 6);

    ft::list<int> vec_cpy(my_vec);
    REQUIRE(vec_cpy.size() == 5);
}

TEST_CASE("List - testing empty")
{
    ft::list<std::string> my_vec;

    REQUIRE(my_vec.empty() == true);
    my_vec.push_back("hello");
    REQUIRE(my_vec.empty() == false);
    my_vec.push_back("hello");
    my_vec.clear();
    REQUIRE(my_vec.empty() == true);
}

TEST_CASE("List - testing size")
{
    ft::list<std::string> my_vec;

    REQUIRE(my_vec.size() == 0);
    my_vec.push_back("hello");
    my_vec.push_back("hello");
    my_vec.push_back("hello");
    REQUIRE(my_vec.size() == 3);

    ft::list<std::string> my_vec2(8, "hallo");
    REQUIRE(my_vec2.size() == 8);
}

TEST_CASE("List - element access")
{
    ft::list<std::string> my_vec;
    my_vec.push_back("hello");
    my_vec.push_back("how");
    my_vec.push_back("are");
    my_vec.push_back("you");
    REQUIRE(my_vec.front() == "hello");
    REQUIRE(my_vec.back() == "you");

    ft::list<int>          my_vec2;
    my_vec2.push_back(8);
    my_vec2.push_back(9);
    my_vec2.push_back(10);
    my_vec2.push_back(11);
    const int con_in = my_vec2.front();
    REQUIRE(con_in == 8);
    const int con_in2 = my_vec2.back();
    REQUIRE(con_in2 == 11);
}

TEST_CASE("List - Popping & Pushing"){
    ft::list<int> my_vec(3, 42);
    my_vec.pop_front();
    my_vec.pop_front();
    my_vec.pop_front();
    my_vec.pop_front();
    my_vec.pop_front();
    my_vec.push_front(-1);
    REQUIRE(my_vec.back() == -1);
    my_vec.pop_back();
    my_vec.pop_back();
    my_vec.pop_back();
    my_vec.push_back(11);
    my_vec.push_back(22);
    REQUIRE(my_vec.back() == 22);
    REQUIRE(my_vec.front() == 11);
}

TEST_CASE("List - Insert Functions"){
    ft::list<int> my_vec(3, 42);
    ft::list<int>::iterator it = my_vec.begin();

    it++;
    ft::list<int>::iterator new_it = my_vec.insert(it, 11);
    it--;
    ft::list<int>::iterator it2 = my_vec.begin();
    REQUIRE(*it2 == 42);
    it2++;
    REQUIRE(*it2 == 11);
    it2++;
    REQUIRE(*it2 == 42);
    it2++;

    my_vec.insert(it2, 3, 108);
    it2--;
    REQUIRE(*it2 == 108);
    it2--;
    REQUIRE(*it2 == 108);

    ft::list<int> my_vec2(4, 99);
    ft::list<int> my_vec_in(3, 33);
    ft::list<int>::iterator it3 = my_vec2.begin();
    it3++;
    it3++;
    my_vec2.insert(it3, my_vec_in.begin(), my_vec_in.end());
    // for (ft::list<int>::iterator it3 = my_vec2.begin(); it3 != my_vec2.end(); ++it3){
    //     std::cout << "[" << *it3 << "]" << std::endl;
    // }
    REQUIRE(*it3 == 99);
    it3--;
    for (int i = 0; i < 3; ++i){
        REQUIRE(*it3 == 33);
        it3--;
    }
    REQUIRE(*it3 == 99);
}

TEST_CASE("List - erase functions"){
    ft::list<int> my_vec;

    my_vec.push_back(8);
    my_vec.push_back(12);
    ft::list<int>::iterator it = my_vec.end();
    it--;
    my_vec.erase(it);
    REQUIRE(my_vec.back() == 8);

    my_vec.insert(my_vec.begin(), 6, 77);
    my_vec.insert(my_vec.begin(), 6);
    // for (ft::list<int>::iterator it3 = my_vec.begin(); it3 != my_vec.end(); ++it3){
    //     std::cout << "[" << *it3 << "]" << std::endl;
    // }
    REQUIRE(my_vec.size() == 8);
    ft::list<int>::iterator f1 = my_vec.begin();
    f1++;
    f1++;
    ft::list<int>::iterator l1 = my_vec.end();
    l1--;
    l1--;
    my_vec.erase(f1, l1);
    // for (ft::list<int>::iterator it3 = my_vec.begin(); it3 != my_vec.end(); ++it3){
    //     std::cout << "[" << *it3 << "]" << std::endl;
    // }
    REQUIRE(my_vec.size() == 4);
    // system("leaks a.out | grep bytes");
}

TEST_CASE("List - swapper die swap swap"){
    ft::list<std::string> my_vec(5, "Marco");
    ft::list<std::string> my_vec2(3, "Polo");

    my_vec.swap(my_vec2);
    REQUIRE(my_vec.front() == "Polo");
    REQUIRE(my_vec.size() == 3);
    REQUIRE(my_vec2.back() == "Marco");
    REQUIRE(my_vec2.size() == 5);
}

TEST_CASE("List - resize jooo life"){
    ft::list<std::string> my_vec(5, "Marco");
    ft::list<std::string> my_vec2(3, "Polo");

    my_vec.resize(8, "Polo");
    my_vec2.resize(1, "not using this");
    REQUIRE(my_vec.back() == "Polo");
    REQUIRE(my_vec.size() == 8);
    REQUIRE(my_vec2.back() == "Polo");
    REQUIRE(my_vec2.size() == 1);
}

TEST_CASE("List - splice it twice"){
    ft::list<int> my_vec(3, 42);
    ft::list<int> my_vec2(5, 1);

    my_vec.splice(my_vec.begin(), my_vec2);
    REQUIRE(my_vec.size() == 8);
    REQUIRE(my_vec2.size() == 0);

    ft::list<int> my_vec3(5, 14);

    ft::list<int>::iterator f1 = my_vec.begin();
    f1++;
    ft::list<int>::iterator f3 = my_vec3.begin();
    f3++;
    ft::list<int>::iterator l3 = my_vec3.end();
    l3--;
    my_vec.splice(f1, my_vec3, f3, l3);
    REQUIRE(my_vec3.size() == 2);
    REQUIRE(my_vec.size() == 11);
    REQUIRE(my_vec.front() == 1);
    // for (ft::list<int>::iterator it3 = my_vec.begin(); it3 != my_vec.end(); ++it3){
    //     std::cout << "[" << *it3 << "]" << std::endl;
    // }
    // for (ft::list<int>::iterator it3 = my_vec3.begin(); it3 != my_vec3.end(); ++it3){
    //     std::cout << "[" << *it3 << "]" << std::endl;
    // }
}

bool    odd_num(ft::list<int>::iterator it){
    if (*it % 2 == 1)
        return true;
    return false;
}

TEST_CASE("List - remove")
{
    ft::list<int> my_vec;

    my_vec.push_back(42);
    my_vec.push_back(42);
    my_vec.push_back(19);
    my_vec.push_back(11);
    my_vec.push_back(42);
    my_vec.push_back(42);
    my_vec.remove(42);
    // for (ft::list<int>::iterator it3 = my_vec.begin(); it3 != my_vec.end(); ++it3){
    //     std::cout << "[" << *it3 << "]" << std::endl;
    // }
    REQUIRE(my_vec.front() == 19);
    REQUIRE(my_vec.back() == 11);
    my_vec.push_back(22);
    my_vec.remove_if(odd_num);
    REQUIRE(my_vec.front() == 22);
    REQUIRE(my_vec.back() == 22);



}

TEST_CASE("List - Unique")
{
    ft::list<int> my_vec;

    my_vec.push_back(42);
    my_vec.push_back(42);
    my_vec.push_back(19);
    my_vec.push_back(11);
    my_vec.push_back(42);
    my_vec.push_back(42);
    my_vec.unique();
    // for (ft::list<int>::iterator it3 = my_vec.begin(); it3 != my_vec.end(); ++it3){
    //     std::cout << "[" << *it3 << "]" << std::endl;
    // }
    ft::list<int>::iterator f1 = my_vec.begin();
    REQUIRE(*f1 == 42);
    f1++;
    REQUIRE(*f1 == 19);
    f1++;
    REQUIRE(*f1 == 11);
    f1++;
    REQUIRE(*f1 == 42);
    REQUIRE(my_vec.size() == 4);

}

bool        too_close(ft::list<int>::iterator first, ft::list<int>::iterator second){
    if (*second - *first < 5)
        return true;
    return false;
}

TEST_CASE("List - Unique - Function")
{
    ft::list<int> my_vec;

    my_vec.push_back(3);
    my_vec.push_back(7);
    my_vec.push_back(42);
    my_vec.push_back(45);
    my_vec.push_back(46);
    my_vec.push_back(47);
    my_vec.push_back(48);
    my_vec.unique(too_close);
    // for (ft::list<int>::iterator it3 = my_vec.begin(); it3 != my_vec.end(); ++it3){
    //     std::cout << "[" << *it3 << "]" << std::endl;
    // }
    ft::list<int>::iterator f1 = my_vec.begin();
    REQUIRE(*f1 == 3);
    f1++; 
    REQUIRE(*f1 == 42);
    f1++;
    REQUIRE(*f1 == 47);
    f1++;
    REQUIRE(my_vec.size() == 3);

}

TEST_CASE("List - sort")
{
    ft::list<int> my_vec;

    my_vec.push_back(89);
    my_vec.push_back(3);
    my_vec.push_back(2);
    my_vec.push_back(1);

    my_vec.sort();
    ft::list<int>::iterator it = my_vec.begin();
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 3);
    ++it;
    REQUIRE(*it == 89);
}

bool        hasMoreA(std::string first, std::string second){
    int count_first = 0;
    int count_second = 0;

    for (size_t i = 0; i != first.size(); ++i){
        if (first[i] == 'A')
            count_first++;
    }
    for (size_t i = 0; i != second.size(); ++i){
        if (second[i] == 'A')
            count_second++;
    }
    return count_first < count_second;
}

TEST_CASE("List - sort and merge func")
{
    ft::list<std::string> my_vec;
    ft::list<std::string> my_vec2;

    my_vec.push_back("BAAAAAD");
    my_vec.push_back("BCBBDABBC");
    my_vec.push_back("BAAAABA");
    my_vec.push_back("BCBAA");
    my_vec.push_back("FFFAAAAAA");

    my_vec2.push_back("-AAAAA-");
    my_vec2.push_back("--A--A");
    my_vec2.push_back("-AAAA-A");
    my_vec2.push_back("---AAA");
    my_vec2.push_back("---AAAAAA");


    my_vec.sort(hasMoreA);
    my_vec2.sort(hasMoreA);
    ft::list<std::string>::iterator it = my_vec.begin();
    my_vec.merge(my_vec2, hasMoreA);
    // for (ft::list<std::string>::iterator it3 = my_vec.begin(); it3 != my_vec.end(); ++it3){
    //     std::cout << "[" << *it3 << "]" << std::endl;
    // }
    REQUIRE(*it == "FFFAAAAAA");
    ++it;
    REQUIRE(*it == "---AAAAAA");
    ++it;
    REQUIRE(*it == "BAAAAAD");
}

TEST_CASE("List - Merge")
{
    ft::list<int> my_vec;
    ft::list<int> my_vec2;

    my_vec.push_back(3);
    my_vec.push_back(2);
    my_vec.push_back(6);
    my_vec.push_back(5);


    my_vec2.push_back(2);
    my_vec2.push_back(322);
    my_vec2.push_back(1);
    my_vec2.push_back(5);

    my_vec.sort();
    my_vec2.sort();

    my_vec.merge(my_vec2);
    // for (ft::list<int>::iterator it3 = my_vec.begin(); it3 != my_vec.end(); ++it3){
    //     std::cout << "[" << *it3 << "]" << std::endl;
    // }
    REQUIRE(my_vec.size() == 8);
    REQUIRE(my_vec2.size() == 0);
}

TEST_CASE("List - Merge - func")
{
    ft::list<int> my_vec;
    ft::list<int> my_vec2;

    my_vec.push_back(3);
    my_vec.push_back(2);
    my_vec.push_back(6);
    my_vec.push_back(5);


    my_vec2.push_back(2);
    my_vec2.push_back(322);
    my_vec2.push_back(1);
    my_vec2.push_back(5);

    my_vec.sort();
    my_vec2.sort();

    my_vec.merge(my_vec2);
    // for (ft::list<int>::iterator it3 = my_vec.begin(); it3 != my_vec.end(); ++it3){
    //     std::cout << "[" << *it3 << "]" << std::endl;
    // }
    REQUIRE(my_vec.size() == 8);
    REQUIRE(my_vec2.size() == 0);
}

TEST_CASE("List - overload operations")
{
    ft::list<int> my_vec;

    my_vec.push_back(89);
    my_vec.push_back(892);
    my_vec.push_back(8933);
    my_vec.push_back(89444);
    ft::list<int> my_vec2(my_vec);

    REQUIRE(my_vec == my_vec2);
    my_vec2.push_back(89444);
    REQUIRE(my_vec != my_vec2);
    REQUIRE(my_vec < my_vec2);
    REQUIRE(my_vec <= my_vec2);
    REQUIRE(my_vec2 >= my_vec);
    REQUIRE(my_vec2 > my_vec);
    // for (ft::list<int>::iterator it3 = my_vec2.begin(); it3 != my_vec2.end(); ++it3){
    //     std::cout << "[" << *it3 << "]" << std::endl;
    // }

}

TEST_CASE("List - overload swap")
{
    ft::list<int> my_vec;
    ft::list<int> my_vec2;

    my_vec.push_back(33);
    my_vec.push_back(33);
    my_vec.push_back(33);
    my_vec.push_back(33);


    my_vec2.push_back(42);
    my_vec2.push_back(42);
    my_vec2.push_back(42);
    my_vec2.push_back(42);
    swap(my_vec, my_vec2);
    // for (ft::list<int>::iterator it3 = my_vec.begin(); it3 != my_vec.end(); ++it3){
    //     std::cout << "[" << *it3 << "]" << std::endl;
    // }
    // for (ft::list<int>::iterator it3 = my_vec2.begin(); it3 != my_vec2.end(); ++it3){
    //     std::cout << "[" << *it3 << "]" << std::endl;
    // }
    REQUIRE(*my_vec.begin() == 42);
    REQUIRE(my_vec.back() == 42);
    REQUIRE(my_vec2.front() == 33);
    REQUIRE(my_vec2.back() == 33);
}