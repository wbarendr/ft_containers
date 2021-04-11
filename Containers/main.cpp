/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wester <wester@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/02 14:45:42 by wester        #+#    #+#                 */
/*   Updated: 2021/04/02 14:54:48 by wester        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
int main()
{
    std::allocator<int> _alloc;
    
    std::vector<unsigned int, int> vec;
    
    vec.assign(10, 10);

    for (size_t i = 0; vec[i]; ++i)
        std::cout << vec[i] << std::endl;
    return 0;
}