#ifndef PAIR_HPP
# define PAIR_HPP

# include <string>

namespace ft {

template<typename K1, typename V1> 
class pair
{
  public:
    typedef K1  key_type;
    typedef V1  value_type;

    key_type        first;
    value_type      second;

    pair():first(), second(){};
    pair(const key_type & K, const value_type & V): first(K), second(V){}
    
    template< class U1, class U2 >
    pair( const pair<U1, U2>& other ) : first(other.first), second(other.second) {}

    template< class U1, class U2 >
    pair( const std::pair<U1, U2>& other ) : first(other.first), second(other.second) {}

    pair&       operator=(const pair& other){
        first = other.first;
        second = other.second;
        return (*this);
    }
};

}

#endif