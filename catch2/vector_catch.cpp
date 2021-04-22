#include "catch.hpp"

#include <vector>
#include "../Containers/Vector/Vector.hpp"


TEST_CASE( "vector - empty container constructor (default constructor)", "[vector]" ) {
    ft::vector<int> first;                                // empty list of ints
    REQUIRE(first.size() == 0);
}

TEST_CASE( "vector - fill constructor", "[vector]" ) {
    ft::vector<int> second (4,100);                // four ints with value 100
    REQUIRE(second.size() == 4);
}

TEST_CASE( "vector - range constructor", "[vector]" ) {
    ft::vector<int> second (5,100);
    ft::vector<int> third (second.begin(),second.end());  // iterating through second
    REQUIRE(third.size() == 5);
    REQUIRE(third.capacity() == 8);
}

TEST_CASE( "vector - copy constructor", "[vector]" ) {
    ft::vector<int> second (5,100);
    ft::vector<int> fourth (second);                       // a copy of second
    REQUIRE(fourth.size() == second.size());
}

TEST_CASE( "vector - assignment operator", "[vector]" ) {
    ft::vector<int> second (5,100);

    ft::vector<int> fourth;
    fourth = second;                      // a copy of second

    REQUIRE(fourth.size() == second.size());
}

TEST_CASE( "vector - begin", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(*ft_vector.begin() == *std_vector.begin());
}

TEST_CASE( "vector - rbegin", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(*ft_vector.rbegin() == *std_vector.rbegin());
}

TEST_CASE( "vector - size", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(ft_vector.size() == std_vector.size());
}

TEST_CASE( "vector - max_size", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    REQUIRE(ft_vector.max_size() == std_vector.max_size());
}

TEST_CASE( "vector - resize", "[vector]" ) {
    ft::vector<int> ft_vector;
    for (int i=1; i<=10; i++) ft_vector.push_back(i);

    ft_vector.resize(10);
    REQUIRE(ft_vector.size() == 10);

    ft_vector.resize(5);
    REQUIRE(ft_vector.size() == 5);

    ft_vector.resize(15);
    REQUIRE(ft_vector.size() == 15);
}

TEST_CASE( "vector - capacity", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(ft_vector.capacity() == std_vector.capacity());
}

TEST_CASE( "vector - empty", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    REQUIRE(ft_vector.empty() == std_vector.empty());

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(ft_vector.empty() == std_vector.empty());
}

TEST_CASE( "vector - reserve", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    ft_vector.reserve(25);
    std_vector.reserve(25);

    REQUIRE(ft_vector.capacity() == std_vector.capacity());
}

TEST_CASE( "vector - shrink to fit", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    // ft_vector.shrink_to_fit();
    std_vector.shrink_to_fit();

    REQUIRE(ft_vector.size() == std_vector.size());
}

TEST_CASE( "vector - operator []", "[vector]" ) {
    ft::vector<int> ft_vector;

    for (int i=0; i<=5; i++) ft_vector.push_back(i);

    REQUIRE(ft_vector[0] == 0);
    REQUIRE(ft_vector[3] == 3);
}

TEST_CASE( "vector - at", "[vector]" ) {
    ft::vector<int> myvector (10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;

    REQUIRE(myvector.at(3) == 3);
    REQUIRE(myvector.at(6) == 6);
}

TEST_CASE( "vector - front", "[vector]" ) {
    ft::vector<int> myvector (10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;

    REQUIRE(myvector.front() == 0);
}

TEST_CASE( "vector - back", "[vector]" ) {
    ft::vector<int> myvector (10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;

    REQUIRE(myvector.back() == 9);
}

TEST_CASE( "vector - assign", "[vector]" ) {
    ft::vector<int> first;
    ft::vector<int> second;
    ft::vector<int> third;

    first.assign (7,100);             // 7 ints with a value of 100
    REQUIRE(first.size() == 7);
    REQUIRE(*first.begin() == 100);

    ft::vector<int>::iterator it;
    it=first.begin()+1;
    REQUIRE(*it == 100);

    ft::vector<int>::iterator it_end;
    it_end=first.end()-1;
    REQUIRE(*it_end == 100);

    second.assign (it,it_end); // the 5 central values of first
    REQUIRE(second.size() == 5);
    REQUIRE(*second.begin() == 100);
}

TEST_CASE( "vector - insert", "[vector]" ) {
    ft::vector<int> myvector (3,100);
    ft::vector<int>::iterator it;

    std::vector<int> realvector (3,100);
    std::vector<int>::iterator std_it;

    it = myvector.begin();
    it = myvector.insert ( it , 200 );

    std_it = realvector.begin();
    std_it = realvector.insert(std_it, 200);

    REQUIRE(myvector.size() == realvector.size());
    REQUIRE(*it == *std_it);
}

TEST_CASE( "vector - erase", "[vector]" ) {
    ft::vector<int> myvector;
    std::vector<int> realvector;

    // initialize iterators
    ft::vector<int>::iterator it;
    std::vector<int>::iterator std_it;

    // set some values (from 1 to 10)
    for (int i=1; i<=8; i++) myvector.push_back(i);
    for (int i=1; i<=8; i++) realvector.push_back(i);

    REQUIRE(8 == realvector.size());
    REQUIRE(8 == myvector.size());

    // erase the 6th element
    it = myvector.erase (myvector.begin()+5);
    std_it = realvector.erase (realvector.begin()+5);

    REQUIRE(*it == *std_it);
    REQUIRE(*realvector.begin() == *myvector.begin());
    REQUIRE(realvector.size() == myvector.size());

    // erase the first 3 elements:
    it = myvector.erase (myvector.begin(),myvector.begin()+3);
    std_it = realvector.erase (realvector.begin(),realvector.begin()+3);

    REQUIRE(myvector.size() == realvector.size());
    REQUIRE(myvector.at(0) == realvector.at(0));
    REQUIRE(*it == *std_it);
    REQUIRE(*myvector.begin()+3 == *realvector.begin()+3);
}

TEST_CASE( "vector - swap", "[vector]" ) {
    std::vector<int> foo (3,100);   // three ints with a value of 100
    std::vector<int> bar (5,200);   // five ints with a value of 200

    foo.swap(bar);
    REQUIRE(foo.size() == 5);
    REQUIRE(*foo.begin() == 200);
    REQUIRE(bar.size() == 3);
    REQUIRE(*bar.begin() == 100);
}

TEST_CASE(" vector - relational operator overloads", "[vector]") {
    ft::vector<int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    ft::vector<int> b;
    b.push_back(10);
    b.push_back(20);
    b.push_back(30);
    ft::vector<int> c;
    c.push_back(30);
    c.push_back(20);
    c.push_back(10);

    REQUIRE((a == b) == true);
    REQUIRE((b != c) == true);
    REQUIRE((b < c) == true);
    REQUIRE((c > b) == true);
    REQUIRE((a <= b) == true);
    REQUIRE((a >= b) == true);

    REQUIRE((a <= b) == true);
    REQUIRE((a > b) == false);
    REQUIRE((a < b) == false);
    REQUIRE((a != b) == false);
    REQUIRE((b > c) == false);
    REQUIRE((b == c) == false);
    REQUIRE((b != c) == true);
}

TEST_CASE(" vector - subtracting two iterators", "[vector]") {
    ft::vector<int> myvector (3,100);
    ft::vector<int>::iterator it;
    ft::vector<int>::iterator it2;

    it = myvector.begin();
    it2 = myvector.end();
    // REQUIRE(it2 - it == 3);
}

TEST_CASE("vector-default constructor", "[vector]")
{
	ft::vector<int> 	own;
	std::vector<int> 	real;
	
	REQUIRE(own.size() == real.size());
}

TEST_CASE("vector-size and value constructor", "[vector]")
{
	ft::vector<int> 	own(5, 3);
	std::vector<int> 	real(5, 3);

	REQUIRE(own.size() == real.size());
	REQUIRE(own[2] == real[2]);
}

TEST_CASE("vector-iterator instanciation", "[vector]")
{
	ft::vector<int>		own(6, 100);
	std::vector<int>	real(6, 100);

	ft::vector<int>		own2(own.begin(), own.end());
	std::vector<int>	real2(real.begin(), real.end());
	
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2[0] ==  real2[0]);
	REQUIRE(own2[1] == real2[1]);

	own.clear();
	real.clear();
	int sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 1;
	}
	own.pop_back();
	real.pop_back();
	ft::vector<int> 	own3(own.begin() + 1, own.end());
	std::vector<int>	real3(real.begin() + 1, real.end());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own3[0] == real3[0]);
	REQUIRE(own3[1] == real3[1]);
}

TEST_CASE("vector-copy constructor", "[vector]")
{
	ft::vector<int> 	own1(5, 5);
	std::vector<int> 	real1(5, 5);

	ft::vector<int> 	own2(own1);
	std::vector<int> 	real2(real1);

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2[2] == real2[2]);
}

TEST_CASE("operator= function", "[vector]")
{
	ft::vector<int> 	own1(5, 5);
	std::vector<int> 	real1(5, 5);
	
	ft::vector<int> own2;
	std::vector<int> real2;

	own2 = own1;
	real2 = real1;

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2[2] == real2[2]);
	REQUIRE(own2.capacity() == real2.capacity());
}


/*-----------------ITERATORS-----------------*/
TEST_CASE("vector-begin function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);
	
	ft::vector<int>::iterator own_it = own.begin();
	std::vector<int>::iterator real_it = real.begin();

	REQUIRE(*own_it == *real_it);
}

TEST_CASE("vector-const begin function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);
	
	ft::vector<int>::const_iterator own_it = own.begin();
	std::vector<int>::const_iterator real_it = real.begin();

	REQUIRE(*own_it == *real_it);
}

TEST_CASE("vector-end function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);
	
	ft::vector<int>::iterator own_ite = own.end();
	std::vector<int>::iterator real_ite = real.end();

	own_ite--;
	real_ite--;
	REQUIRE(*own_ite == *real_ite);
}

TEST_CASE("vector-const end function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);
	
	ft::vector<int>::const_iterator own_ite = own.end();
	std::vector<int>::const_iterator real_ite = real.end();

	own_ite--;
	real_ite--;
	REQUIRE(*own_ite == *real_ite);
}

TEST_CASE("vector-rbegin function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	ft::vector<int>::reverse_iterator own_rit = own.rbegin();
	ft::vector<int>::reverse_iterator old_own_rit;
	std::vector<int>::reverse_iterator real_rit = real.rbegin();
	std::vector<int>::reverse_iterator old_real_rit;

	++own_rit;
	++real_rit;
	REQUIRE(*own_rit == *real_rit);
	
	old_own_rit = own_rit++;
	old_real_rit = real_rit++;
	REQUIRE(*old_real_rit == *old_own_rit);
}

TEST_CASE("vector-const rbegin function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	ft::vector<int>::const_reverse_iterator own_rit = own.rbegin();
	ft::vector<int>::const_reverse_iterator old_own_rit;
	std::vector<int>::const_reverse_iterator real_rit = real.rbegin();
	std::vector<int>::const_reverse_iterator old_real_rit;

	++own_rit;
	++real_rit;
	REQUIRE(*own_rit == *real_rit);
	
	old_own_rit = own_rit++;
	old_real_rit = real_rit++;
	REQUIRE(*old_real_rit == *old_own_rit);
}

TEST_CASE("vector-rend function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	ft::vector<int>::reverse_iterator own_rite = own.rend();
	ft::vector<int>::reverse_iterator old_own_rite;
	std::vector<int>::reverse_iterator real_rite = real.rend();
	std::vector<int>::reverse_iterator old_real_rite;

	--own_rite;
	--real_rite;
	REQUIRE(*own_rite == *real_rite);
	
	old_own_rite = own_rite--;
	old_real_rite = real_rite--;
	REQUIRE(*old_real_rite == *old_own_rite);
}

TEST_CASE("vector-const rend function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	ft::vector<int>::const_reverse_iterator own_rite = own.rend();
	ft::vector<int>::const_reverse_iterator old_own_rite;
	std::vector<int>::const_reverse_iterator real_rite = real.rend();
	std::vector<int>::const_reverse_iterator old_real_rite;

	--own_rite;
	--real_rite;
	REQUIRE(*own_rite == *real_rite);
	
	old_own_rite = own_rite--;
	old_real_rite = real_rite--;
	REQUIRE(*old_real_rite == *old_own_rite);
}


/*-----------------Capcity-----------------*/
TEST_CASE("vector-size function", "[vector]")
{
	ft::vector<int> 	own(6, 3);
	std::vector<int> 	real(6, 6);

	REQUIRE(own.size() == real.size());
}

TEST_CASE("vector-max_size function", "[vector]")
{
	ft::vector<int> 	own(6, 3);
	std::vector<int> 	real(6, 6);

	own.clear();
	real.clear();
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.max_size() == real.max_size());
}

TEST_CASE("vector-resize function", "[vector]")
{
	ft::vector<int> 	own(8, 5);
	std::vector<int> 	real(8, 5);

	own.resize(2, 2);
	real.resize(2, 2);

	REQUIRE(own.size() == real.size());
	REQUIRE(own[1] == real[1]);
}

TEST_CASE("vector-capacity function", "[vector]")
{
	ft::vector<int> own(8, 5);
	std::vector<int> real(8, 5);

	own.resize(2, 2);
	real.resize(2, 2);

	REQUIRE(own.capacity() == real.capacity());
}

TEST_CASE("vector-empty function", "[vector]")
{
	ft::vector<int> 	own(5, 3);
	std::vector<int>	real(5, 3);
	
	ft::vector<int> 	empty_own;
	std::vector<int>	empty_real;

	own.clear();
	real.clear();

	REQUIRE(own.empty() == real.empty());
	REQUIRE(empty_own.empty() == empty_real.empty());
}

TEST_CASE("vector-reserve function", "[vector]")
{
	ft::vector<int>		own(6, 10);
	std::vector<int>	real(6, 10);

	own.reserve(100);
	real.reserve(100);
	
	REQUIRE(own.capacity() == real.capacity());

	// try
	// {
	// 	own.reserve(own.max_size() + 1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	// try
	// {
	// 	real.reserve(real.max_size() + 1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}



/*-----------------Element Access-----------------*/
TEST_CASE("vector-operator[] function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real[i] = sum;
		own[i] = sum;
		sum += 1;
	}
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);
	REQUIRE(own[2] == real[2]);
	REQUIRE(own[3] == real[3]);
}

TEST_CASE("vector-at function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	REQUIRE(own.at(0) == real.at(0));
	REQUIRE(own.at(1) == real.at(1));
	REQUIRE(own.at(2) == real.at(2));
	REQUIRE(own.at(3) == real.at(3));
	// try
	// {
	// 	own.at(6);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	// try
	// {
	// 	real.at(6);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}

TEST_CASE("vector-front function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	REQUIRE(own.front() == real.front());
}

TEST_CASE("vector-back function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	REQUIRE(own.back() == real.back());
}


/*-----------------Modifiers-----------------*/

TEST_CASE("vector-assign fucntion with itarators", "[vector]")
{
	ft::vector<int>		own1(5, 100);
	ft::vector<int>		own2;
	std::vector<int>	real1(5, 100);
	std::vector<int>	real2;

	own2.assign(own1.begin(), own1.begin() + 3);
	real2.assign(real1.begin(), real1.begin() + 3);

	ft::vector<int>::iterator own_it = own2.begin();
	std::vector<int>::iterator real_it = real2.begin();

	REQUIRE(own2.size() == real2.size());
	while (own_it != own2.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("vector-assign function with n and val", "[vector]")
{
	ft::vector<int>		own;
	std::vector<int>	real;

	own.assign(20, 20);
	real.assign(20 , 20);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
	REQUIRE(own.at(3) == real.at(3));
}

TEST_CASE("vector-push_back function", "[vector]")
{
	int sum = 10;
	ft::vector<int>		own;
	std::vector<int>	real;
	
	for(int i = 0; i < 4; ++i)
	{	
		own.push_back(sum);
		real.push_back(sum);
		sum += 10;
	}
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);
	REQUIRE(own[2] == real[2]);
}

TEST_CASE("vector-pop_back function", "[vector]")
{
	int sum = 10;
	ft::vector<int>		own;
	std::vector<int>	real;
	
	for(int i = 0; i < 4; ++i)
	{	
		own.push_back(sum);
		real.push_back(sum);
		sum += 10;
	}
	REQUIRE(own.size() == real.size());
	own.pop_back();
	real.pop_back();
	REQUIRE(own.size() == real.size());
	REQUIRE(own[2] == real[2]);
}

TEST_CASE("vector-insert function", "[vector]")
{
	ft::vector<int>		own(6, 100);
	std::vector<int>	real(6, 100);
	
	ft::vector<int>::iterator	it_own = own.begin();
	std::vector<int>::iterator	it_real = real.begin();

	it_own = own.insert(it_own, 200);
	it_real = real.insert(it_real, 200);
	
	// for (ft::vector<int>::iterator it = own.begin(); it != own.end(); ++it){
	// 	std::cout << "loop: " << *it << std::endl;
	// }
	// std::cout << "own: " << *it_own << std::endl;
	// std::cout << "begin: " << *own.begin() << std::endl;
	// std::cout << "real: " << *it_real << std::endl;
	//  200 100 100 100 100 100 100
	//  ^
	REQUIRE(*it_own == *it_real);
	
	own.insert(it_own, 2, 300);
	real.insert(it_real, 2, 300);
	// 300 300 200 100 100 100 100 100 100
	// ^   ^
	
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);

	ft::vector<int> 	own1(2, 400);
	std::vector<int>	real2(2, 400);

	it_own = own.begin();
	it_real = real.begin();

	own.insert(it_own + 2, own1.begin(), own1.end());
	real.insert(it_real + 2, real2.begin(), real2.end());
	// 300 300 400 400 200 100 100 100 100 100 100
	//         ^   ^
	REQUIRE(own[2] == real[2]);
	REQUIRE(own[3] == real[3]);
	
	int myarray[] = {101, 102, 103};

	it_own = ft::vector<int>::iterator(myarray);

	own.insert(own.begin(), it_own, it_own + 3);
	real.insert(real.begin(), myarray, myarray + 3);
	// 101 102 103 300 300 400 400 200 100 100 100 100 100 100
	// ^   ^   ^
	
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);
	REQUIRE(own[2] == real[2]);
	REQUIRE(own.size() == real.size());
	
}
TEST_CASE("vector-erase function", "[vector]")
{
	ft::vector<int>		own;
	std::vector<int>	real;
	int sum = 0;
	
	ft::vector<int>::iterator	it_own;
	std::vector<int>::iterator	it_real;
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 1;
	}
	//  0 1 2 3 4 5 6 7 8 9
	
	it_own = own.erase(own.begin() + 4);
	it_real = real.erase(real.begin() + 4);
	// 0 1 2 3 5 6 7 8 9
	//         ^
	
	REQUIRE(own[4] == real[4]);
	REQUIRE(*it_own == *it_real);
	
	it_own = own.erase(own.begin(), own.end() - 4);
	it_real = real.erase(real.begin(), real.end() - 4);
	// 6 7 8 9
	// ^
	
	REQUIRE(own[0] == real[0]);
	REQUIRE(*it_own == *it_real);
	
}
TEST_CASE("vector-swap function", "[vector]")
{
	ft::vector<int> 	own(4, 100);
	ft::vector<int> 	own2(5, 300);
	std::vector<int> 	real(4, 100);
	std::vector<int>	real2(5, 300);
	
	own.swap(own2);
	real.swap(real2);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.capacity() == real.capacity());
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);
	REQUIRE(own[2] == real[2]);
}

TEST_CASE("vector-clear function", "[vector]")
{
	ft::vector<int>		own(10, 100);
	std::vector<int>	real(10, 100);

	own.clear();
	real.clear();

	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.size() == real.size());
	REQUIRE(own.capacity() == real.capacity());
}

/*-----------------Relational Operators-----------------*/
TEST_CASE("vector-operation overloaders", "[vector]")
{
	ft::vector<int> 	own(4, 200);
	ft::vector<int> 	own2(4, 100);
	ft::vector<int> 	own3(4, 200);
	std::vector<int>	real(4, 200);
	std::vector<int>	real2(4, 100);
	std::vector<int>	real3(4, 200);


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
