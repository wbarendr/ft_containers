#ifndef NODE_HPP
# define NODE_HPP

# include <cstddef>

namespace ft
{

template <typename T>
class node
{
  public:
    node*   prev;    
    T       data;
    node*   next;

    explicit node(): prev(nullptr), data(), next(nullptr){};
    explicit node(const T& data): prev(nullptr), data(data), next(nullptr){};
    
    node(const node& other){ *this = other; };
    node&   operator=(const node& other){
        prev = other.prev;
        data = other.data;
        next = other.next;
        return *this;
    }

    ~node(){};

    bool    operator==(const node& other) const{
        if (this->prev == other.prev && this->next == other.next && this->data == other.data)
            return true;
        return false;
    }

    bool    operator!=(const node& other) const{
        return (!(*this == other));
    }

    node*   getnext() {return this->next; };
    node*   getprevious() {return this->prev; };
};

}

#endif