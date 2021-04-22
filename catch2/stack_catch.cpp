#include "catch.hpp"

#include <stack>
#include "../Containers/Stack/Stack.hpp"

TEST_CASE("stack - testing and comparing stack functions")
{
    ft::stack<int> my_stack;
    std::stack<int> std_stack;


    REQUIRE(my_stack.empty() == true);
    REQUIRE(std_stack.empty() == true);

    my_stack.push(8);
    my_stack.push(9);
    my_stack.push(10);
    my_stack.push(14);

    std_stack.push(8);
    std_stack.push(9);
    std_stack.push(10);
    std_stack.push(14);

    REQUIRE(my_stack.size() == 4);
    REQUIRE(std_stack.size() == 4);
    REQUIRE(my_stack.top() == 14);
    REQUIRE(std_stack.top() == 14);

    my_stack.pop();
    std_stack.pop();
    REQUIRE(my_stack.top() == 10);
    REQUIRE(std_stack.top() == 10);

}

TEST_CASE("stack - testing operators")
{   
    ft::stack<int> my_stack;
    ft::stack<int> my_stack2;
    ft::stack<int> my_stack3;

    my_stack.push(8);
    my_stack.push(9);
    my_stack.push(10);

    my_stack2.push(8);
    my_stack2.push(9);
    my_stack2.push(10);

    my_stack3.push(8);
    my_stack3.push(8);
    my_stack3.push(10);

    REQUIRE(my_stack == my_stack2);
    REQUIRE(my_stack != my_stack3);
    REQUIRE(my_stack > my_stack3);
    REQUIRE(my_stack3 < my_stack2);
    REQUIRE(my_stack3 <= my_stack2);
    REQUIRE(my_stack >= my_stack3);

}