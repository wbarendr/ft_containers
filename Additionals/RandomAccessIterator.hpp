#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

# include <cstddef>
# include <string>


template<typename T, typename reference, typename pointer>
class RandomAccessIterator
{
  private:
    pointer _array;

  public:
    typedef T                                   value_type;
    // typedef value_type*                                  pointer;
    // typedef value_type&                                  reference;
    typedef size_t                              size_type;
    typedef ptrdiff_t                           difference_type;
    typedef RandomAccessIterator                self_type;
    typedef std::random_access_iterator_tag     iterator_category;

    RandomAccessIterator():
        _array(NULL)
    {}

    RandomAccessIterator(pointer array)
    {
        this->_array = array;
    }

    RandomAccessIterator(const self_type& other)
    {
        this->_array = other._array;
    }

    RandomAccessIterator&       operator=(const self_type& other)
    {
        this->_array = other._array;
        return (*this);
    }

    ~RandomAccessIterator()
    {
    }

    reference                   operator*()
    {
        return (*this->_array);
    }

    pointer                     operator->()
    {
        return this->_array; // (&(*this->array))
    }

    bool                        operator==(const self_type& other) const
    {
        if (this->_array != other._array)
            return false;
        return true;
    }

    bool                        operator!=(const self_type& other) const
    {
        if (this->_array != other._array)
            return true;
        return false;
    }

    self_type&                  operator++() //prefix
    {
        this->_array++;
        return (*this);
    }

    self_type                   operator++(int) // postfix
    {
        self_type ret(*this);
        this->_array++;
        return ret;
    }

    self_type                  operator+(const difference_type& diff)
    {
        self_type ret(*this);
        ret._array += diff;
        return ret;
    }

    self_type&                 operator+=(const difference_type& diff)
    {
        this->_array += diff;
        return (*this);
    }

    self_type&                  operator--() //prefix
    {
        this->_array--;
        return (*this);
    }

    self_type                   operator--(int) // postfix
    {
        self_type ret(*this);
        this->_array--;
        return ret;
    }

    self_type                  operator-(const difference_type& diff)
    {
        self_type ret(*this);
        ret._array -= diff;
        return ret;
    }

    self_type&                 operator-=(const difference_type& diff)
    {
        this->_array -= diff;
        return (*this);
    }

    // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        // template<typename T2, typename reference2, typename pointer2>
        // friend bool operator<(const RandomAccessIterator<T2, reference2, pointer2> &lhs,
        //                       const RandomAccessIterator<T2, reference2, pointer2> &rhs) { return (lhs._ptr < rhs._ptr); };

        // template<typename T2, typename reference2, typename pointer2>
        // friend bool operator>(const RandomAccessIterator<T2, reference2, pointer2> &lhs,
        //                       const RandomAccessIterator<T2, reference2, pointer2> &rhs) { return (rhs < lhs);};

        // template<typename T2, typename reference2, typename pointer2>
        // friend bool operator<=(const RandomAccessIterator<T2, reference2, pointer2> &lhs,
        //                        const RandomAccessIterator<T2, reference2, pointer2> &rhs) { return !(rhs < lhs); };

        // template<typename T2, typename reference2, typename pointer2>
        // friend bool operator>=(const RandomAccessIterator<T2, reference2, pointer2> &lhs,
        //                        const RandomAccessIterator<T2, reference2, pointer2> &rhs) { return !(lhs < rhs); };

        // template<typename T2, typename reference2, typename pointer2>
        // friend bool operator==(const RandomAccessIterator<T2, reference2, pointer2> &lhs,
        //                        const RandomAccessIterator<T2, reference2, pointer2> &rhs) { return (lhs._ptr == rhs._ptr); };

        // template<typename T2, typename reference2, typename pointer2>
        // friend bool operator!=(const RandomAccessIterator<T2, reference2, pointer2> &lhs,
        //                        const RandomAccessIterator<T2, reference2, pointer2> &rhs) { return !(lhs == rhs); };
};

template<typename T, typename reference, typename pointer>
class ReverseRandomAccessIterator
{
  private:
    pointer _array;

  public:
    typedef T                                   value_type;
    typedef size_t                              size_type;
    typedef ptrdiff_t                           difference_type;
    // typedef RandomAccessIterator_Tag     iterator_category;
    typedef ReverseRandomAccessIterator         self_type;

    ReverseRandomAccessIterator(pointer array)
    {
        this->_array = array;
    }

    ReverseRandomAccessIterator(const self_type& other)
    {
        this->_array = other._array;
    }

    ReverseRandomAccessIterator&       operator=(const self_type& other)
    {
        this->_array = other._array;
        return (*this);
    }

    ~ReverseRandomAccessIterator()
    {
    }

    reference                   operator*()
    {
        return (*this->_array);
    }

    pointer                     operator->()
    {
        return this->_array; // (&(*this->array))
    }

    bool                        operator==(const self_type& other) const
    {
        if (this->_array != other._array)
            return false;
        return true;
    }

    bool                        operator!=(const self_type& other) const
    {
        if (this->_array != other._array)
            return true;
        return false;
    }

    self_type&                  operator++() //prefix
    {
        this->_array--;
        return (*this);
    }

    self_type                   operator++(int) // postfix
    {
        self_type ret(*this);
        this->_array--;
        return ret;
    }

    self_type                  operator+(const difference_type diff)
    {
        self_type ret(*this);
        ret._array -= diff;
        return ret;
    }

    self_type&                 operator+=(const difference_type diff)
    {
        this->_array -= diff;
        return (*this);
    }

    self_type&                  operator--() //prefix
    {
        this->_array++;
        return (*this);
    }

    self_type                   operator--(int) // postfix
    {
        self_type ret(*this);
        this->_array++;
        return ret;
    }

    self_type                  operator-(const difference_type diff)
    {
        self_type ret(*this);
        ret._array += diff;
        return ret;
    }

    self_type&                 operator-=(const difference_type diff)
    {
        this->_array += diff;
        return (*this);
    }
};

#endif
