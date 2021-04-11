/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wester <wester@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 15:48:16 by wester        #+#    #+#                 */
/*   Updated: 2021/02/02 08:49:59 by wester        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#include "Vector.hpp"
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <iostream>

struct      Vector3
{
    float x;
    float y;
    float z;

    Vector3() {}
    Vector3(float scalar) 
        : x(scalar), y(scalar), z(scalar) {}
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z) {}
    
    Vector3(const Vector3& other)
        : x(other.x), y(other.y), z(other.z)
    {
        // std::cout << "copy" << std::endl;
    }
    
    Vector3&    operator=(const Vector3& other)
    {
        // std::cout << "copy " << std::endl;
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    ~Vector3()
    {
        // std::cout << "destroyed" << std::endl;
    }
};

template<typename T>
void    PrintVectorG(const ft::vector<T>& vector)
{
    for (size_t i = 0; i < vector.size(); ++i)
            std::cout << RED << vector[i] << std::endl;
    std::cout << "Size: " << vector.size() << std::endl;
    std::cout << "Capacity: " << vector.capacity() << RESET << std::endl;
    // std::cout << "------------" << std::endl;
}

template<typename T>
void    PrintVectorR(const std::vector<T>& vector)
{
    for (size_t i = 0; i < vector.size(); ++i)
            std::cout << RED << vector[i] << std::endl;
    std::cout << "Size: " << vector.size() << std::endl;
    std::cout << "Capacity: " << vector.capacity() << RESET << std::endl;
}

void    PrintVectorG(const ft::vector<char *>& vector)
{
    // for (size_t i = 0; i < vector.size(); ++i){
        
            // std::cout << "hello\n";
        // if (strcmp(vector[i], "yes")) 
        // {
        //     std::cout << "hello\n";

        //     std::cout << GREEN << vector[i] << std::endl;
        // }
    // }
    std::cout << "-----Size: " << vector.size() << std::endl;
    std::cout << "Capacity: " << vector.capacity() << RESET << std::endl;
    // std::cout << "------------" << std::endl;
}

void    PrintVectorR(const std::vector<char *>& vector)
{
    // for (size_t i = 0; i < vector.size(); ++i)
        // if (strcmp(vector[i], "yes")) 
        //     std::cout << RED << vector[i] << std::endl;
    std::cout << "-----Size: " << vector.size() << std::endl;
    std::cout << "Capacity: " << vector.capacity() << RESET << std::endl;
}



void    work_strings()
{
    // std::vector<char *> vector(3);
    ft::vector<char *> myVector(3);
    
    char yes[] = "yes";
    
    myVector.push_back((char *)"I");
    // vector.push_back((char *)"I");
    myVector.push_back((char *)"like");
    // vector.push_back((char *)"like");
    myVector.push_back((char *)"Turtles");
    // vector.push_back((char *)"Turtles");
    for (size_t i = 0; i < 126; ++i){
        myVector.push_back(yes);
        // vector.push_back(yes);
    }

    // PrintVectorR(vector);
    PrintVectorG(myVector);
    
}

void    work_floats()
{
    ft::vector<float> myVector;
    
    myVector.push_back(8.9);
    myVector.push_back(10.00002);
    myVector.push_back(14.12);
    PrintVectorG(myVector);
    
    
    // std::vector<float> vector;

    // vector.push_back(8.9);
    // vector.push_back(10.00002);
    // vector.push_back(14.12);
    // PrintVectorR(vector);
    
}

void    work_ints()
{
    ft::vector<int> myVector;
    
    myVector.push_back(8);
    myVector.push_back(10);
    myVector.push_back(14);
    PrintVectorG(myVector);


    // std::vector<int> vector;
    
    // vector.push_back(8);
    // vector.push_back(10);
    // vector.push_back(14);
    // PrintVectorR(vector);
}

void    PrintVectorG1(const ft::vector<Vector3>& vector)
{
    for (size_t i = 0; i < vector.size(); ++i)
        std::cout << vector[i].x << " -- " << vector[i].y << " -- " << vector[i].z << std::endl;
    
    std::cout << "-----Size: " << vector.size() << std::endl;
    std::cout << "-----Max_Size: " << vector.max_size() << std::endl;
    std::cout << "-----Capacity: " << vector.capacity() << "  empty?: " << vector.empty() << std::endl;
}

void    work_myvector3()
{
    Vector3 Victor(8.9, 11, 217.77);
    Vector3 veccie(4.2);
    Vector3 Victor_copy;
    
    ft::vector<Vector3> myVector;
    myVector.push_back(veccie);
    myVector.clear();
    myVector.push_back(veccie);
    myVector.push_back(Victor);
    myVector.push_back(Victor);

    try {
        Victor_copy = myVector.at(7);
    }
    catch (const std::exception& e){
        std::cout << "OUT OF RANGE" << std::endl;
        Victor_copy = myVector[1];
    }
    Victor_copy = myVector.front();
    Victor_copy = myVector.back();
    
    PrintVectorG1(myVector);
    ft::vector<Vector3> myVector_copy(myVector);
    PrintVectorG1(myVector_copy);
    
    ft::vector<Vector3> myVector_copy2;
    myVector_copy2 = myVector_copy;
    PrintVectorG1(myVector_copy2);
    myVector_copy2.reserve(6);
    myVector_copy2.assign(5, veccie);
    myVector_copy2.resize(4);
    myVector_copy2[3] = Victor_copy;

    PrintVectorG1(myVector_copy2);

    // PrintVectorG1(myVector);

    myVector_copy2.insert(myVector_copy2.begin() + 2, 3, Victor_copy);
    myVector_copy2.insert(myVector_copy2.begin() + 2, myVector.begin(), myVector.end());
    myVector_copy2.erase(myVector_copy2.begin() + 1);
    myVector_copy2.erase(myVector_copy2.end() - 3, myVector_copy2.end());
    myVector_copy2.erase(myVector_copy2.end(), myVector_copy2.end() + 3);

    PrintVectorG1(myVector_copy2);
    swap(myVector, myVector_copy2);

    myVector_copy2.swap(myVector);
    PrintVectorG1(myVector_copy2);
    

}

void    PrintVectorR1(const std::vector<Vector3>& vector)
{
    for (size_t i = 0; i < vector.size(); ++i)
        std::cout << vector[i].x << " -- " << vector[i].y << " -- " << vector[i].z << std::endl;
    
    std::cout << "-----Size: " << vector.size() << std::endl;
    std::cout << "-----Max_Size: " << vector.max_size() << std::endl;
    std::cout << "-----Capacity: " << vector.capacity() << "  empty?: " << vector.empty() << std::endl;
}

void    work_vector3()
{
    Vector3 Victor(8.9, 11, 217.77);
    Vector3 veccie(4.2);
    Vector3 Victor_copy;
    
    std::vector<Vector3> vector;
    vector.push_back(veccie);
    vector.clear();
    vector.push_back(veccie);
    vector.push_back(Victor);
    vector.push_back(Victor);
    
    try {
        Victor_copy = vector.at(7);
    }
    catch (const std::exception& e){
        std::cout << "OUT OF RANGE" << std::endl;
        Victor_copy = vector[1];
    }
    Victor_copy = vector.front();
    Victor_copy = vector.back();

    PrintVectorR1(vector);

    std::vector<Vector3> vector_copy(vector);
    PrintVectorR1(vector_copy);
    std::vector<Vector3> vector_copy2;
    vector_copy2 = vector;
    PrintVectorR1(vector_copy2);
    vector_copy2.reserve(6);
    vector_copy2.assign(5, veccie);
    vector_copy2.resize(4);
    vector_copy2[3] = Victor_copy;
    PrintVectorR1(vector_copy2);

    vector_copy2.insert(vector_copy2.begin() + 2, 3, Victor_copy);
    vector_copy2.insert(vector_copy2.begin() + 2, vector.begin(), vector.end());
    vector_copy2.erase(vector_copy2.begin() + 1);
    vector_copy2.erase(vector_copy2.end() - 3, vector_copy2.end());
    vector_copy2.erase(vector_copy2.end(), vector_copy2.end()) + 3;

    PrintVectorR1(vector_copy2);
    vector_copy2.swap(vector);
    swap(vector, vector_copy2);
    PrintVectorR1(vector_copy2);

    
    
}

int     main()
{
    work_ints();
    std::cout << "*************************" << std::endl;
    work_floats();
    std::cout << "*************************" << std::endl;
    work_strings();
    std::cout << "*************************" << std::endl << GREEN;
    work_myvector3();
    // std::cout << RESET << "*************************" << std::endl << RED;
    // work_vector3();
    std::cout << RESET << "*************************" << std::endl;
    system("leaks vector | grep bytes");
    return 0;
}
