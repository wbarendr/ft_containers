#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

# include <cstddef>
# include <string>


template<typename T>
class RandomAccessIterator
{

  public:
	typedef T                                   value_type;
	typedef T& 			                        reference;
	typedef T*			                        pointer;
	typedef size_t                              size_type;
	typedef ptrdiff_t                           difference_type;
	typedef RandomAccessIterator                self_type;
	typedef std::random_access_iterator_tag     iterator_category;

  private:
	pointer _array;

  public:
	RandomAccessIterator()
	{
		_array = NULL;
	}

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

	reference 					operator[](const difference_type &index) 
	{ 
		return _array[index]; 
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

	const pointer&				get_ptr() const 
	{ 
		return _array; 
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

template<typename T>
class ReverseRandomAccessIterator
{

  public:
	typedef T                                   value_type;
	typedef T&                                  reference;
	typedef T*                                  pointer;
	typedef size_t                              size_type;
	typedef ptrdiff_t                           difference_type;
	// typedef RandomAccessIterator_Tag     iterator_category;
	typedef ReverseRandomAccessIterator         self_type;

  private:
	pointer _array;

  public:

	ReverseRandomAccessIterator()
	{
		_array = NULL;
	}

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

	reference 					operator[](const difference_type &index) 
	{ 
		return (_array[index]); 
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

	const pointer&				get_ptr() const 
	{ 
		return _array; 
	}
};

template<typename T>
class ConstRandomAccessIterator
{

  public:
	typedef T                                   value_type;
	typedef const T& 			                reference;
	typedef const T*			                pointer;
	typedef size_t                              size_type;
	typedef ptrdiff_t                           difference_type;
	typedef ConstRandomAccessIterator           self_type;
	typedef std::random_access_iterator_tag     iterator_category;

  private:
	pointer _array;

  public:
	ConstRandomAccessIterator()
	{
		_array = NULL;
	}

	ConstRandomAccessIterator(pointer array)
	{
		this->_array = array;
	}

	ConstRandomAccessIterator(const self_type& other)
	{
		this->_array = other._array;
	}

	ConstRandomAccessIterator&       operator=(const self_type& other)
	{
		this->_array = other._array;
		return (*this);
	}

	ConstRandomAccessIterator(const RandomAccessIterator<T> &other) 
	{
		_array = other.get_ptr();
	}

	~ConstRandomAccessIterator()
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

	reference 					operator[](const difference_type &index) 
	{ 
		return (_array[index]); 
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
		// friend bool operator<(const ConstRandomAccessIterator<T2, reference2, pointer2> &lhs,
		//                       const ConstRandomAccessIterator<T2, reference2, pointer2> &rhs) { return (lhs._ptr < rhs._ptr); };

		// template<typename T2, typename reference2, typename pointer2>
		// friend bool operator>(const ConstRandomAccessIterator<T2, reference2, pointer2> &lhs,
		//                       const ConstRandomAccessIterator<T2, reference2, pointer2> &rhs) { return (rhs < lhs);};

		// template<typename T2, typename reference2, typename pointer2>
		// friend bool operator<=(const ConstRandomAccessIterator<T2, reference2, pointer2> &lhs,
		//                        const ConstRandomAccessIterator<T2, reference2, pointer2> &rhs) { return !(rhs < lhs); };

		// template<typename T2, typename reference2, typename pointer2>
		// friend bool operator>=(const ConstRandomAccessIterator<T2, reference2, pointer2> &lhs,
		//                        const ConstRandomAccessIterator<T2, reference2, pointer2> &rhs) { return !(lhs < rhs); };

		// template<typename T2, typename reference2, typename pointer2>
		// friend bool operator==(const ConstRandomAccessIterator<T2, reference2, pointer2> &lhs,
		//                        const ConstRandomAccessIterator<T2, reference2, pointer2> &rhs) { return (lhs._ptr == rhs._ptr); };

		// template<typename T2, typename reference2, typename pointer2>
		// friend bool operator!=(const ConstRandomAccessIterator<T2, reference2, pointer2> &lhs,
		//                        const ConstRandomAccessIterator<T2, reference2, pointer2> &rhs) { return !(lhs == rhs); };
};

template<typename T>
class ConstReverseRandomAccessIterator
{

  public:
	typedef T                                   value_type;
	typedef const T&                            reference;
	typedef const T*                            pointer;
	typedef size_t                              size_type;
	typedef ptrdiff_t                           difference_type;
	// typedef RandomAccessIterator_Tag     iterator_category;
	typedef ConstReverseRandomAccessIterator    self_type;

  private:
	pointer _array;

  public:

	ConstReverseRandomAccessIterator()
	{
		_array = NULL;
	}

	ConstReverseRandomAccessIterator(pointer array)
	{
		this->_array = array;
	}

	ConstReverseRandomAccessIterator(const self_type& other)
	{
		this->_array = other._array;
	}

	ConstReverseRandomAccessIterator(const ReverseRandomAccessIterator<T> &other) 
	{
		_array = other.get_ptr();
	}

	ConstReverseRandomAccessIterator&       operator=(const self_type& other)
	{
		this->_array = other._array;
		return (*this);
	}

	~ConstReverseRandomAccessIterator()
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

	reference 					operator[](const difference_type &index) 
	{ 
		return (_array[index]); 
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
