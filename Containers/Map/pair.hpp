#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

template<typename K1, typename V1> 
class pair
{
  public:
    typedef K1  key_type;
    typedef V1  value_type;

    key_type        key;
    value_type      value;

    pair():key(), value(){};
    pair(const key_type & K, const value_type & V): key(K), value(V){}
    
    template< class U1, class U2 >
    pair( const pair<U1, U2>& other ) : key(other.key), value(other.value) {}

    template< class U1, class U2 >
    pair( const std::pair<U1, U2>& other ) : key(other.key), value(other.value) {}

    pair&       operator=(const pair& other){
        key = other.key;
        value = other.value;
        return (*this);
    }
};

}

#endif