#ifndef BiDirectionalIterator_HPP
# define BiDirectionalIterator_HPP

# include <cstddef>
# include <string>
// # include "Node.hpp"

namespace ft
{

template<typename T, typename node>
class BiDirectionalIterator
{
  public:
	typedef std::bidirectional_iterator_tag         iterator_category;
	typedef node*                                   iterator_type;
	typedef T                                       value_type;
	typedef std::ptrdiff_t                          difference_type;
	typedef T&			                            reference;
	typedef T* 		                                pointer;

  private:
	iterator_type element;

  public:

	BiDirectionalIterator(): element(nullptr)
	{}

	explicit BiDirectionalIterator(iterator_type it) : element(it) 
	{}

	BiDirectionalIterator(const BiDirectionalIterator& other)
	{
		*this = other;
	}

	BiDirectionalIterator&      operator=(const BiDirectionalIterator& other)
	{
		this->element = other.element;
		return *this;
	}

	~BiDirectionalIterator() {};

	reference       operator*() {return element->data;}

	pointer         operator->() {return &element->data;}

	bool            operator==(const BiDirectionalIterator& other) const
	{
		if (this->element == other.element)
			return true;
		return false;
	}

	bool            operator!=(const BiDirectionalIterator& other) const
	{
		if (this->element == other.element)
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

	const iterator_type&                getNode() const {return element;}

	// template<typename T2, typename Node2>
	// friend bool operator== (const BiDirectionalIterator<T2, Node2, T2&, T2*>& lhs, const BiDirectionalIterator<T2, Node2, T2&, T2*>& rhs) {return (lhs._ptr == rhs._ptr);};

	// template<typename T2, typename Node2>
	// friend bool operator!= (const BiDirectionalIterator<T2, Node2, T2&, T2*>& lhs, const BiDirectionalIterator<T2, Node2, T2&, T2*>& rhs) {return !(lhs == rhs);;};

};

template<typename T, typename node>
class ConstBiDirectionalIterator
{
  public:
	typedef std::bidirectional_iterator_tag         iterator_category;
	typedef node*                                   iterator_type;
	typedef T                                       value_type;
	typedef std::ptrdiff_t                          difference_type;
	typedef const T& 	                            reference;
	typedef const T*                                pointer;

  private:
	iterator_type element;

  public:

	ConstBiDirectionalIterator(): element(nullptr)
	{}

	explicit ConstBiDirectionalIterator(iterator_type it) : element(it) 
	{}

	ConstBiDirectionalIterator(const ConstBiDirectionalIterator& other)
	{
		*this = other;
	}

	ConstBiDirectionalIterator (const BiDirectionalIterator<T, node>& other) 
	{
		element = other.getNode();
	}

	ConstBiDirectionalIterator&      operator=(const ConstBiDirectionalIterator& other)
	{
		this->element = other.element;
		return *this;
	}

	~ConstBiDirectionalIterator() {};

	reference       operator*() {return element->data;}

	pointer         operator->() {return &element->data;}

	bool            operator==(const ConstBiDirectionalIterator& other) const
	{
		if (this->element == other.element)
			return true;
		return false;
	}

	bool            operator!=(const ConstBiDirectionalIterator& other) const
	{
		if (this->element == other.element)
			return false;
		return true;
	}

	ConstBiDirectionalIterator&       operator++()
	{
		this->element = this->element->getnext();
		return (*this);
	}

	ConstBiDirectionalIterator       operator++(int)
	{
		ConstBiDirectionalIterator tmp(*this);
		this->element = this->element->getnext();
		return (tmp);
	}

	ConstBiDirectionalIterator&       operator--()
	{
		this->element = this->element->getprevious();
		return (*this);
	}

	ConstBiDirectionalIterator       operator--(int)
	{
		ConstBiDirectionalIterator tmp(*this);
		this->element = this->element->getprevious();
		return (tmp);
	}

	iterator_type                getNode(){return element;}

	// template<typename T2, typename Node2>
	// friend bool operator== (const ConstBiDirectionalIterator<T2, Node2, T2&, T2*>& lhs, const ConstBiDirectionalIterator<T2, Node2, T2&, T2*>& rhs) {return (lhs._ptr == rhs._ptr);};

	// template<typename T2, typename Node2>
	// friend bool operator!= (const ConstBiDirectionalIterator<T2, Node2, T2&, T2*>& lhs, const ConstBiDirectionalIterator<T2, Node2, T2&, T2*>& rhs) {return !(lhs == rhs);;};

};

template<typename T, typename node>
class ReverseBiDirectionalIterator
{
  public:
	typedef std::bidirectional_iterator_tag         iterator_category;
	typedef node*									iterator_type;
	typedef T                                       value_type;
	typedef std::ptrdiff_t                          difference_type;
	typedef T*      	                            pointer;
	typedef T&		                                reference;

  private:
	iterator_type element;

  public:

	ReverseBiDirectionalIterator(): element(nullptr)
	{}

	explicit ReverseBiDirectionalIterator(iterator_type it) : element(it)
	{}

	ReverseBiDirectionalIterator(const ReverseBiDirectionalIterator& other)
	{
		*this = other;
	}

	ReverseBiDirectionalIterator&      operator=(const ReverseBiDirectionalIterator& other)
	{
		this->element = other.element;
		return *this;
	}

	~ReverseBiDirectionalIterator() {};

	reference       operator*() {return element->data;}

	pointer         operator->() {return &element->data;}

	bool            operator==(const ReverseBiDirectionalIterator& other) const
	{
		if (*this->element == *other.element)
			return true;
		return false;
	}

	bool            operator!=(const ReverseBiDirectionalIterator& other) const
	{
		if (this->element == other.element)
			return false;
		return true;
	}

	ReverseBiDirectionalIterator&       operator++()
	{
		this->element = this->element->getprevious();
		return (*this);
	}

	ReverseBiDirectionalIterator       operator++(int)
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

	ReverseBiDirectionalIterator       operator--(int)
	{
		ReverseBiDirectionalIterator tmp(*this);
		this->element = this->element->getnext();
		return (tmp);
	}

	const iterator_type&                       getNode() const {return element;}
};

template<typename T, typename node>
class ConstReverseBiDirectionalIterator
{
  public:
	typedef std::bidirectional_iterator_tag         iterator_category;
	typedef node*									iterator_type;
	typedef T                                       value_type;
	typedef std::ptrdiff_t                          difference_type;
	typedef const T*      	                        pointer;
	typedef const T&		                        reference;

  private:
	iterator_type element;

  public:

	ConstReverseBiDirectionalIterator(): element(nullptr)
	{}

	explicit ConstReverseBiDirectionalIterator(iterator_type it) : element(it)
	{}

	ConstReverseBiDirectionalIterator(const ConstReverseBiDirectionalIterator& other)
	{
		*this = other;
	}

	ConstReverseBiDirectionalIterator (const ReverseBiDirectionalIterator<T, node>& other) 
	{
		element = other.getNode();
	}

	ConstReverseBiDirectionalIterator&      operator=(const ConstReverseBiDirectionalIterator& other)
	{
		this->element = other.element;
		return *this;
	}

	~ConstReverseBiDirectionalIterator() {};

	reference       operator*() {return element->data;}

	pointer         operator->() {return &element->data;}

	bool            operator==(const ConstReverseBiDirectionalIterator& other) const
	{
		if (*this->element == *other.element)
			return true;
		return false;
	}

	bool            operator!=(const ConstReverseBiDirectionalIterator& other) const
	{
		if (this->element == other.element)
			return false;
		return true;
	}

	ConstReverseBiDirectionalIterator&       operator++()
	{
		this->element = this->element->getprevious();
		return (*this);
	}

	ConstReverseBiDirectionalIterator       operator++(int)
	{
		ConstReverseBiDirectionalIterator tmp(*this);
		this->element = this->element->getprevious();
		return (tmp);
	}

	ConstReverseBiDirectionalIterator&       operator--()
	{
		this->element = this->element->getnext();
		return (*this);
	}

	ConstReverseBiDirectionalIterator       operator--(int)
	{
		ConstReverseBiDirectionalIterator tmp(*this);
		this->element = this->element->getnext();
		return (tmp);
	}

	iterator_type                       getNode() {return element;}
};
}

#endif