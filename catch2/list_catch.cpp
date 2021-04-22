#include "catch.hpp"

#include <list>
#include "../Containers/List/List.hpp"

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

TEST_CASE("List - operator=")
{
    ft::list<int> my_vec(5, 6);

    ft::list<int> vec_other(10, 8);
    vec_other = my_vec;
    REQUIRE(vec_other.size() == 5);
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

bool    odd_num(const int& value){
    if (value % 2 == 1)
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

bool        too_close(const int& first, const int& second){
    if (second - first < 5)
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
    return count_first > count_second;
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

TEST_CASE("List -  swap")
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

TEST_CASE("List -  reverse")
{
    ft::list<int> my_vec;

    my_vec.push_back(33);
    my_vec.push_back(88);
    my_vec.push_back(92);
    my_vec.push_back(122);


    my_vec.reverse();
    ft::list<int>::const_iterator it3 = my_vec.begin();
    REQUIRE(*it3 == 122);
    it3++;
    REQUIRE(*it3 == 92);
    it3++;
    REQUIRE(*it3 == 88);
    it3++;
    REQUIRE(*it3 == 33);
}
/*-----------------CONSTRUCTORS-----------------*/
TEST_CASE("list-Empty container constructor", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
}

TEST_CASE("list-Fill constructor", "[list]")
{
	ft::list<int>	own(5, 100);
	std::list<int>	real(5, 100);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

TEST_CASE("list-Range constructor", "[list]")
{
	ft::list<int>		own(6, 100);
	ft::list<int>		own2(own.begin(), own.end());
	std::list<int>		real(6, 100);
	std::list<int>		real2(real.begin(), real.end());

	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();
	
	own_it = own2.begin();
	real_it = real2.begin();

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own2.front() == real2.front());
	REQUIRE(own2.back() == real2.back());

	while (own_it != own2.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-Copy constructor", "[list]")
{
	ft::list<int>		own(6, 100);
	ft::list<int>		own2(own);
	std::list<int>		real(6, 100);
	std::list<int>		real2(real);


	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own2.front() == real2.front());
	REQUIRE(own2.back() == real2.back());
}

TEST_CASE("list-Assign content", "[list]")
{
	ft::list<int>		own(6, 100);
	ft::list<int>		own2;
	std::list<int>		real(6, 100);
	std::list<int>		real2;

	own2 = own;
	real2 = real;
	
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own2.front() == real2.front());
	REQUIRE(own2.back() == real2.back());
	// REQUIRE(own2.get_allocator() == real2.get_allocator());
	
}

/* ------------ ITERATORS ------------ */
TEST_CASE("list-begin function", "[list]")
{
	ft::list<int> 	own(4, 3);
	std::list<int> 	real(4, 3);
	
	ft::list<int>::iterator own_it = own.begin();
	std::list<int>::iterator real_it = real.begin();

	REQUIRE(*own_it == *real_it);
}

TEST_CASE("list-const begin function", "[list]")
{
	ft::list<int> 	own(4, 3);
	std::list<int> 	real(4, 3);
	
	ft::list<int>::const_iterator own_it = own.begin();
	std::list<int>::const_iterator real_it = real.begin();

	REQUIRE(*own_it == *real_it);
}

TEST_CASE("list-end function", "[list]")
{
	ft::list<int> 	own(4, 3);
	std::list<int> 	real(4, 3);
	
	ft::list<int>::iterator own_ite = own.end();
	std::list<int>::iterator real_ite = real.end();

	own_ite--;
	real_ite--;
	REQUIRE(*own_ite == *real_ite);
}

TEST_CASE("list-const end function", "[list]")
{
	ft::list<int> 	own(4, 3);
	std::list<int> 	real(4, 3);
	
	ft::list<int>::const_iterator own_ite = own.end();
	std::list<int>::const_iterator real_ite = real.end();

	own_ite--;
	real_ite--;
	REQUIRE(*own_ite == *real_ite);
}

TEST_CASE("list-rbegin function", "[list]")
{
	int sum = 0;
	ft::list<int>		own(5);
	std::list<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.push_back(sum);
		own.push_back(sum);
		sum += 1;
	}
	
	ft::list<int>::reverse_iterator own_rit = own.rbegin();
	ft::list<int>::reverse_iterator old_own_rit;
	std::list<int>::reverse_iterator real_rit = real.rbegin();
	std::list<int>::reverse_iterator old_real_rit;

	++own_rit;
	++real_rit;
	REQUIRE(*own_rit == *real_rit);
	
	old_own_rit = own_rit++;
	old_real_rit = real_rit++;
	REQUIRE(*old_real_rit == *old_own_rit);
}

TEST_CASE("list-const rbegin function", "[list]")
{
	int sum = 0;
	ft::list<int>		own(5);
	std::list<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.push_back(sum);
		own.push_back(sum);
		sum += 1;
	}
	
	ft::list<int>::const_reverse_iterator own_rit = own.rbegin();
	ft::list<int>::const_reverse_iterator old_own_rit;
	std::list<int>::const_reverse_iterator real_rit = real.rbegin();
	std::list<int>::const_reverse_iterator old_real_rit;

	++own_rit;
	++real_rit;
	REQUIRE(*own_rit == *real_rit);
	
	old_own_rit = own_rit++;
	old_real_rit = real_rit++;
	REQUIRE(*old_real_rit == *old_own_rit);
}

TEST_CASE("list-rend function", "[list]")
{
	int sum = 0;
	ft::list<int>		own(5);
	std::list<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.push_back(sum);
		own.push_back(sum);
		sum += 1;
	}
	
	ft::list<int>::reverse_iterator own_rite = own.rend();
	ft::list<int>::reverse_iterator old_own_rite;
	std::list<int>::reverse_iterator real_rite = real.rend();
	std::list<int>::reverse_iterator old_real_rite;

	--own_rite;
	--real_rite;
	REQUIRE(*own_rite == *real_rite);
	
	old_own_rite = own_rite--;
	old_real_rite = real_rite--;
	REQUIRE(*old_real_rite == *old_own_rite);
}

TEST_CASE("list-const rend function", "[list]")
{
	int sum = 0;
	ft::list<int>		own(5);
	std::list<int>		real(5);

	for(int i = 0; i < 5; i++)
	{
		real.push_back(sum);
		own.push_back(sum);
		sum += 1;
	}
	
	ft::list<int>::const_reverse_iterator own_rite = own.rend();
	ft::list<int>::const_reverse_iterator old_own_rite;
	std::list<int>::const_reverse_iterator real_rite = real.rend();
	std::list<int>::const_reverse_iterator old_real_rite;

	--own_rite;
	--real_rite;
	REQUIRE(*own_rite == *real_rite);
	
	old_own_rite = own_rite--;
	old_real_rite = real_rite--;
	REQUIRE(*old_real_rite == *old_own_rite);
}

/* ------------ CAPACITY ------------ */

TEST_CASE("list-empty function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	REQUIRE(own.empty() == real.empty());
	
	ft::list<int>	own2(5, 100);
	std::list<int>	real2(5, 100);

	real2.clear();
	own2.clear();
	
	REQUIRE(own.empty() == real.empty());
}

TEST_CASE("list-size function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	REQUIRE(own.size() == real.size());
	
	ft::list<int>	own2(5, 100);
	std::list<int>	real2(5, 100);

	REQUIRE(own.size() == real.size());

	real2.clear();
	own2.clear();
	
	REQUIRE(own.size() == real.size());
}

TEST_CASE("list-max_size function", "[list]")
{
	ft::list<int>	own(2, 100);
	std::list<int>	real(2, 100);

	REQUIRE(own.max_size() == real.max_size());
}

/* ------------ ELEMENT ACCESS ------------ */

TEST_CASE("list-front function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	int sum = 40;
	const int tim = 100;
	
	
	for (int i  = 0; i < 5; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 10;
	}
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	own.push_front(tim);
	real.push_front(tim);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

TEST_CASE("list-back function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	const int tim = 100;
	int sum = 40;
	
	
	for (int i  = 0; i < 5; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 10;
	}
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	own.push_back(tim);
	real.push_back(tim);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

/* ------------ MODIFIERS ------------ */
TEST_CASE("list-assign with iterators", "[list]")
{
	ft::list<int>		own1(5, 100);
	ft::list<int>		own2;
	std::list<int>		real1(5, 100);
	std::list<int>		real2;


	own2.assign(own1.begin(), own1.end());
	real2.assign(real1.begin(), real1.end());

	ft::list<int>::iterator own_it = own2.begin();
	std::list<int>::iterator real_it = real2.begin();

	REQUIRE(own2.size() == real2.size());
	while (own_it != own2.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-assign size n and type val")
{
	ft::list<int>	own;
	std::list<int>	real;
	own.assign(6, 100);
	real.assign(6, 100);
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

TEST_CASE("list-push_front function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;
	int sum = 10;
	for (int i = 0; i < 10; ++i)
	{
		own.push_front(sum);
		real.push_front(sum);
		sum += 11;
	}
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

TEST_CASE("list-pop_front function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;
	int sum = 10;
	for (int i = 0; i < 10; ++i)
	{
		own.push_front(sum);
		real.push_front(sum);
		sum += 11;
	}
	for (int i = 0; i < 5; ++i)
	{
		own.pop_front();
		real.pop_front();
	}
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

TEST_CASE("list-push_back function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;
	int sum = 10;
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 11;
	}
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

TEST_CASE("list-pop_back function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;
	int sum = 10;
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 11;
	}
	
	for (int i = 0; i < 5; ++i)
	{
		REQUIRE(own.back() == real.back());
		REQUIRE(own.size() == real.size());
		own.pop_back();
		real.pop_back();
	}
	
	own.push_back(2000);
	real.push_back(2000);
	
	REQUIRE(own.back() == real.back());
	REQUIRE(own.size() == real.size());
	own.pop_back();
	real.pop_back();
	
	REQUIRE(own.back() == real.back());
	REQUIRE(own.size() == real.size());
	
}

TEST_CASE("list-insert single element", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	int sum = 5;
	
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 5;
	}

	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();
	
	++own_it; ++own_it;
	++real_it; ++real_it;

	own.insert(own_it, 1000);
	real.insert(real_it, 1000);
	
	own_it = own.begin();
	real_it = real.begin();

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-insert fill", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	int sum = 5;
	
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 5;
	}

	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();
	
	++own_it; ++own_it;
	++real_it; ++real_it;

	own.insert(own_it, 5, 1000);
	real.insert(real_it, 5, 1000);

	own_it = own.begin();
	real_it = real.begin();

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-insert range", "[list]")
{
	ft::list<int>	own;
	ft::list<int>	own2(4, 2000);
	std::list<int>	real;
	std::list<int>	real2(4, 2000);

	int sum = 5;
	
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 5;
	}

	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();
	
	++own_it; ++own_it;
	++real_it; ++real_it;
	
	own.insert(own_it, own2.begin(), own2.end());
	real.insert(real_it, real2.begin(), real2.end());

	own_it = own.begin();
	real_it = real.begin();

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-erase single element", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	int sum = 5;
	
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 5;
	}

	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();
	
	++own_it; ++own_it;
	++real_it; ++real_it;
	
	own.erase(own_it);
	real.erase(real_it);

	own_it = own.begin();
	real_it = real.begin();

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-erase range element", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	int sum = 5;
	
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 5;
	}

	ft::list<int>::iterator		own_it = own.begin();
	ft::list<int>::iterator		own_ite = own.end();
	
	std::list<int>::iterator	real_it = real.begin();
	std::list<int>::iterator	real_ite = real.end();
	
	++own_it; ++own_it;
	++real_it; ++real_it;
	
	own.erase(own_it, own_ite);
	real.erase(real_it, real_ite);

	own_it = own.begin();
	real_it = real.begin();

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-swap ", "[list]")
{
	ft::list<int>	own;
	ft::list<int>	own2;
	std::list<int>	real;
	std::list<int>	real2;
	int sum = 10;
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 11;
	}
	own2.swap(own);
	real2.swap(real);
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own2.front() == real2.front());
	REQUIRE(own2.back() == real2.back());
}

TEST_CASE("list-resize", "[list]")
{
	ft::list<int>	own(5, 100);
	std::list<int>	real(5, 100);
	REQUIRE(own.size() == real.size());
	
	own.resize(10, 200);
	real.resize(10, 200);
	
	REQUIRE(own.back() == real.back());
	REQUIRE(own.size() == real.size());
	
	own.resize(4, 50);
	real.resize(4, 50);
	
	REQUIRE(own.back() == real.back());
	REQUIRE(own.size() == real.size());
	REQUIRE(own.front() == real.front());
}

TEST_CASE("list-clear", "[list]")
{
	ft::list<int>	own(5, 100);
	std::list<int>	real(5, 100);
	
	int sum = 10;
	for (int i = 0; i < 2; ++i)
	{
		REQUIRE(own.size() == real.size());
		REQUIRE(own.empty() == real.empty());

		own.clear();
		real.clear();

		REQUIRE(own.size() == real.size());
		REQUIRE(own.empty() == real.empty());

		own.assign(5, sum);
		real.assign(5, sum);
		sum += 123;
	}
}

/* ------------ OPERATIONS ------------ */

TEST_CASE("list-splice version 1", "[list]")
{
	ft::list<int>	own;
	ft::list<int>	own2;
	std::list<int>	real;
	std::list<int>	real2;

	for (int i = 1; i < 5; ++i)
	{
		own.push_back(i); 
		real.push_back(i);
	} 
	for (int i = 5; i < 7; ++i)
	{
		own2.push_back(i); 
		real2.push_back(i);
	}
	
	own.splice(own.end(), own2);
	real.splice(real.end(), real2);

	
	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();

	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-splice version 2", "[list]")
{
	ft::list<int>	own;
	ft::list<int>	own2;
	std::list<int>	real;
	std::list<int>	real2;

	for (int i = 1; i < 5; ++i)
	{
		own.push_back(i); 
		real.push_back(i);
	} 
	for (int i = 5; i < 7; ++i)
	{
		own2.push_back(i); 
		real2.push_back(i);
	}
	
	ft::list<int>::iterator		own_it = own2.begin();
	std::list<int>::iterator	real_it = real2.begin();
	
	own.splice(own.end(), own2, own_it);
	real.splice(real.end(), real2, real_it);
	
	own_it = own.begin();
	real_it = real.begin();

	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-splice version 3", "[list]")
{
	ft::list<int>	own;
	ft::list<int>	own2;
	std::list<int>	real;
	std::list<int>	real2;

	for (int i = 1; i < 5; ++i)
	{
		own.push_back(i); 
		real.push_back(i);
	} 
	for (int i = 5; i < 10; ++i)
	{
		own2.push_back(i); 
		real2.push_back(i);
	}
	
	ft::list<int>::iterator		own_it = own2.begin();
	ft::list<int>::iterator		own_ite = own2.end();

	std::list<int>::iterator	real_it = real2.begin();
	std::list<int>::iterator	real_ite = real2.end();
	
	own.splice(own.end(), own2, own_it, own_ite);
	real.splice(real.end(), real2, real_it, real_ite);
	
	own_it = own.begin();
	real_it = real.begin();

	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-remove", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	for (int i = 1; i < 10; ++i)
	{
		own.push_back(i); 
		real.push_back(i);
	} 
	
	own.remove(5);
	real.remove(5);

	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
	
	for (int i = 1; i < 10; ++i)
	{
		own.push_back(100); 
		real.push_back(100);
	}

	own_it = own.begin();
	real_it = real.begin();
	
	own.remove(100);
	real.remove(100);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

TEST_CASE("list-remove_if", "[list]")
{
	ft::list<int> own;
	std::list<int> real;

	for (int i = 1; i < 16; ++i)
	{
		own.push_back(i); 
		real.push_back(i);
	}

	// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
	own.remove_if(single_digit);           // 10 11 12 13 14 15 
	own.remove_if(is_odd());               // 10 12 14
	real.remove_if(single_digit);           // 10 11 12 13 14 15
	real.remove_if(is_odd());               // 10 12 14

	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-unique version 1", "[list]")
{
	ft::list<int> own;
	std::list<int> real;

	int suma = 1;
	int sumb = 1;

	
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(suma);
		own.push_back(sumb);
		real.push_back(suma);
		real.push_back(sumb);
		suma += 1;
		sumb += 1;
	}
	// 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10
	own.unique();
	real.unique();
	// 1 2 3 4 5 6 7 8 9 10
	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
	
	own.push_back(10); own.push_back(10); own.push_back(10);
	real.push_back(10); real.push_back(10); real.push_back(10);
	// 1 2 3 4 5 6 7 8 9 10 10 10 10 

	own.unique();
	real.unique();

	own_it = own.begin();
	real_it = real.begin();
	
	// 1 2 3 4 5 6 7 8 9 10
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first) == int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

TEST_CASE("list-unique version 2", "[list]")
{
	ft::list<double>	own;
	std::list<double>	real;

	own.push_back(12.15); real.push_back(12.15);
	own.push_back(2.72); real.push_back(2.72);
	own.push_back(73.0); real.push_back(73.0);
	own.push_back(12.77); real.push_back(12.77);
	own.push_back(12.14); real.push_back(12.14);
	own.push_back(12.77); real.push_back(12.77);
	own.push_back(73.35); real.push_back(73.35);
	own.push_back(72.25); real.push_back(72.25);
	own.push_back(72.3); real.push_back(72.3);
	own.push_back(72.25); real.push_back(72.25);

	own.unique(same_integral_part);
	real.unique(same_integral_part);
	
	ft::list<double>::iterator		own_it = own.begin();
	std::list<double>::iterator	real_it = real.begin();
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
	
	own.unique(is_near());
	real.unique(is_near());

	own_it = own.begin();
	real_it = real.begin();
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
	
}

TEST_CASE("list-merge version 1", "[list]")
{
	ft::list<double>	own1;
	ft::list<double>	own2;
	std::list<double>	real1; 
	std::list<double>	real2;

	own1.push_back (3.1);
	own1.push_back (2.2);
	own1.push_back (2.9);	
	own2.push_back (3.7);
	own2.push_back (7.1);
	own2.push_back (1.4);
	
	real1.push_back (3.1);
	real1.push_back (2.2);
	real1.push_back (2.9);	
	real2.push_back (3.7);
	real2.push_back (7.1);
	real2.push_back (1.4);
	
	own1.sort();
	own2.sort();
	real1.sort();
	real2.sort();	
	
	own1.merge(own2);
	real1.merge(real2);

	ft::list<double>::iterator		own_it = own1.begin();
	std::list<double>::iterator		real_it = real1.begin();
	
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own1.size() == real1.size());
	REQUIRE(own1.empty() == real1.empty());
	REQUIRE(own1.front() == real1.front());
	REQUIRE(own1.back() == real1.back());

	while (own_it != own1.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

TEST_CASE("list-merge version 2", "[list]")
{
	ft::list<double>	own1;
	ft::list<double>	own2;
	std::list<double>	real1; 
	std::list<double>	real2;

	own1.push_back (3.1);
	own1.push_back (2.2);
	own1.push_back (2.9);	
	own2.push_back (3.7);
	own2.push_back (7.1);
	own2.push_back (1.4);
	
	real1.push_back (3.1);
	real1.push_back (2.2);
	real1.push_back (2.9);	
	real2.push_back (3.7);
	real2.push_back (7.1);
	real2.push_back (1.4);
	
	own1.sort();
	own2.sort();
	real1.sort();
	real2.sort();	
	
	own1.merge(own2, mycomparison);
	real1.merge(real2, mycomparison);

	ft::list<double>::iterator		own_it = own1.begin();
	std::list<double>::iterator		real_it = real1.begin();
	
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own1.size() == real1.size());
	REQUIRE(own1.empty() == real1.empty());
	REQUIRE(own1.front() == real1.front());
	REQUIRE(own1.back() == real1.back());

	while (own_it != own1.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-sort version 1", "[list]")
{
	ft::list<std::string>	own;
	std::list<std::string>	real;
	
	real.push_back ("one");
	real.push_back ("two");
	real.push_back ("Three");

	own.push_back ("one");
	own.push_back ("two");
	own.push_back ("Three");

	real.sort();
	own.sort();

	std::list<std::string>::iterator	real_it = real.begin();
	ft::list<std::string>::iterator		own_it = own.begin();
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

TEST_CASE("list-sort version 2", "[list]")
{
	ft::list<std::string>	own;
	std::list<std::string>	real;
	
	real.push_back ("one");
	real.push_back ("two");
	real.push_back ("Three");

	own.push_back ("one");
	own.push_back ("two");
	own.push_back ("Three");

	real.sort(compare_nocase);
	own.sort(compare_nocase);

	std::list<std::string>::iterator	real_it = real.begin();
	ft::list<std::string>::iterator		own_it = own.begin();
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-reverse", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	for (int i = 0; i < 10; ++i) own.push_back(i);
	for (int i = 0; i < 10; ++i) real.push_back(i);

	own.reverse();
	real.reverse();
	
	std::list<int>::iterator	real_it = real.begin();
	ft::list<int>::iterator		own_it = own.begin();
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-operation overloaders", "[list]")
{
	ft::list<int> 	own(4, 200);
	ft::list<int> 	own2(4, 100);
	ft::list<int> 	own3(4, 200);
	std::list<int>	real(4, 200);
	std::list<int>	real2(4, 100);
	std::list<int>	real3(4, 200);


	REQUIRE((own == own3) == true);
	REQUIRE((own == own2) == false);
	REQUIRE((real == real3) == true);
	REQUIRE((real == real2) == false);
	
	REQUIRE((own != own3) == false);
	REQUIRE((own != own2) == true);
	REQUIRE((real != real3) == false);
	REQUIRE((real != real2) == true);
	
	REQUIRE((own < own2) == false);
	REQUIRE((own2 < own3) == true);
	REQUIRE((real < real2) == false);
	REQUIRE((real2 < real3) == true);

	REQUIRE((own < own3) == false);
	REQUIRE((own <= own3) == true);
	REQUIRE((real < real3) == false);
	REQUIRE((real <= real3) == true);

	REQUIRE((own > own2) == true);
	REQUIRE((own2 > own3) == false);
	REQUIRE((real > real2) == true);
	REQUIRE((real2 > real3) == false);

	REQUIRE((own > own3) == false);
	REQUIRE((own >= own3) == true);
	REQUIRE((real > real3) == false);
	REQUIRE((real >= real3) == true);
}
