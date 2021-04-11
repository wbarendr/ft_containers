#ifndef BiDirectionalIterator_HPP
# define BiDirectionalIterator_HPP

// # include <cstddef>
// # include "Node.hpp"

namespace ft
{

template<typename T, typename node_pointer, typename reference_, typename pointer_>
class BiDirectionalIterator
{
  public:
    typedef std::bidirectional_iterator_tag         iterator_category;
    typedef node_pointer                            *iterator_type;
    typedef T                                       value_type;
    typedef std::ptrdiff_t                          difference_type;
    typedef pointer_                                pointer;
    typedef reference_                              reference;

  private:
    node_pointer element;

  public:

    BiDirectionalIterator(): element(nullptr)
    {}

    explicit BiDirectionalIterator(node_pointer it) : element(it) 
    {}

    BiDirectionalIterator(const BiDirectionalIterator& other)
    {
        this->element = other.element;
    }

    BiDirectionalIterator&      operator=(const BiDirectionalIterator& other)
    {
        this->element = other.element;
        return *this;
    }

    reference       operator*()
    {
        return this->element->data;
    }

    pointer         operator->()
    {
        return &(this->element->data);
    }

    bool            operator==(const BiDirectionalIterator& other) const
    {
        if (*this->element == *other.element)
            return true;
        return false;
    }

    bool            operator!=(const BiDirectionalIterator& other) const
    {
        if (*this->element == *other.element)
            return false;
        return true;
    }

    BiDirectionalIterator&       operator++()
    {
        this->element = this->element->getnext();
        return (*this);
    }

    BiDirectionalIterator       operator++(int)
    {
        BiDirectionalIterator tmp(*this);
        this->element = this->element->getnext();
        return (tmp);
    }

    BiDirectionalIterator&       operator--()
    {
        this->element = this->element->getprevious();
        return (*this);
    }

    BiDirectionalIterator       operator--(int)
    {
        BiDirectionalIterator tmp(*this);
        this->element = this->element->getprevious();
        return (tmp);
    }

    node_pointer                getNode(){return element;}

    // template<typename T2, typename Node2>
    // friend bool operator== (const BiDirectionalIterator<T2, Node2, T2&, T2*>& lhs, const BiDirectionalIterator<T2, Node2, T2&, T2*>& rhs) {return (lhs._ptr == rhs._ptr);};

    // template<typename T2, typename Node2>
    // friend bool operator!= (const BiDirectionalIterator<T2, Node2, T2&, T2*>& lhs, const BiDirectionalIterator<T2, Node2, T2&, T2*>& rhs) {return !(lhs == rhs);;};

};

template<typename T, typename node_pointer, typename reference_, typename pointer_>
class ReverseBiDirectionalIterator
{
  public:
    typedef std::bidirectional_iterator_tag         iterator_category;
    typedef node_pointer                            *iterator_type;
    typedef T                                       value_type;
    typedef std::ptrdiff_t                          difference_type;
    typedef pointer_                                pointer;
    typedef reference_                              reference;

  private:
    node_pointer element;

  public:

    ReverseBiDirectionalIterator(): element(nullptr)
    {}

    explicit ReverseBiDirectionalIterator(node_pointer it) : element(it)
    {}

    ReverseBiDirectionalIterator(const ReverseBiDirectionalIterator& other)
    {
        this->element = other.element;
    }

    ReverseBiDirectionalIterator&      operator=(const ReverseBiDirectionalIterator& other)
    {
        this->element = other.element;
        return *this;
    }

    reference       operator*()
    {
        return this->element->_data;
    }

    pointer         operator->()
    {
        return &(this->element->_data);
    }

    bool            operator==(const ReverseBiDirectionalIterator& other) const
    {
        if (*this->element == *other.element)
            return true;
        return false;
    }

    bool            operator!=(const ReverseBiDirectionalIterator& other) const
    {
        if (*this->element == *other.element)
            return false;
        return true;
    }

    ReverseBiDirectionalIterator&       operator++()
    {
        this->element = this->element->getprevious();
        return (*this);
    }

    ReverseBiDirectionalIterator&       operator++(int)
    {
        ReverseBiDirectionalIterator tmp(*this);
        this->element = this->element->getprevious();
        return (tmp);
    }

    ReverseBiDirectionalIterator&       operator--()
    {
        this->element = this->element->getnext();
        return (*this);
    }

    ReverseBiDirectionalIterator&       operator--(int)
    {
        ReverseBiDirectionalIterator tmp(*this);
        this->element = this->element->getnext();
        return (tmp);
    }
};
}

#endif