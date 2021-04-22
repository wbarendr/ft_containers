#include "catch.hpp"

#include <queue>
#include "../Containers/Queue/Queue.hpp"

TEST_CASE("queue - testing and comparing queue functions")
{
    ft::queue<int> my_queue;
    std::queue<int> std_queue;


    REQUIRE(my_queue.empty() == true);
    REQUIRE(std_queue.empty() == true);

    my_queue.push(8);
    my_queue.push(9);
    my_queue.push(10);
    my_queue.push(14);

    std_queue.push(8);
    std_queue.push(9);
    std_queue.push(10);
    std_queue.push(14);

    REQUIRE(my_queue.size() == 4);
    REQUIRE(std_queue.size() == 4);
    REQUIRE(my_queue.front() == 8);
    REQUIRE(std_queue.front() == 8);
    REQUIRE(my_queue.back() == 14);
    REQUIRE(std_queue.back() == 14);

    my_queue.pop();
    std_queue.pop();
    REQUIRE(my_queue.front() == 9);
    REQUIRE(std_queue.front() == 9);

}

TEST_CASE("queue - testing operators")
{   
    ft::queue<int> my_queue;
    ft::queue<int> my_queue2;
    ft::queue<int> my_queue3;

    my_queue.push(8);
    my_queue.push(9);
    my_queue.push(10);

    my_queue2.push(8);
    my_queue2.push(9);
    my_queue2.push(10);

    my_queue3.push(8);
    my_queue3.push(8);
    my_queue3.push(10);

    REQUIRE(my_queue == my_queue2);
    REQUIRE(my_queue != my_queue3);
    REQUIRE(my_queue > my_queue3);
    REQUIRE(my_queue3 < my_queue2);
    REQUIRE(my_queue3 <= my_queue2);
    REQUIRE(my_queue >= my_queue3);

}