#ifndef BiDirectionalIterator_HPP
# define BiDirectionalIterator_HPP

# include <cstddef>
# include <string>
// # include "Node.hpp"

namespace ft
{

template<typename T, typename node, typename reference_, typename pointer_>
class BiDirectionalIterator
{
  public:
	typedef std::bidirectional_iterator_tag         iterator_category;
	typedef node*                                   iterator_type;
	typedef T                                       value_type;
	typedef std::ptrdiff_t                          difference_type;
	typedef reference_                              reference;
	typedef pointer_                                pointer;

  private:
	iterator_type element;

  public:

	BiDirectionalIterator(): element(nullptr)
	{}

	explicit BiDirectionalIterator(iterator_type it) : element(it) 
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

	iterator_type                getNode(){return element;}

	// template<typename T2, typename Node2>
	// friend bool operator== (const BiDirectionalIterator<T2, Node2, T2&, T2*>& lhs, const BiDirectionalIterator<T2, Node2, T2&, T2*>& rhs) {return (lhs._ptr == rhs._ptr);};

	// template<typename T2, typename Node2>
	// friend bool operator!= (const BiDirectionalIterator<T2, Node2, T2&, T2*>& lhs, const BiDirectionalIterator<T2, Node2, T2&, T2*>& rhs) {return !(lhs == rhs);;};

};

template<typename T, typename node, typename reference_, typename pointer_>
class ReverseBiDirectionalIterator
{
  public:
	typedef std::bidirectional_iterator_tag         iterator_category;
	typedef node*									iterator_type;
	typedef T                                       value_type;
	typedef std::ptrdiff_t                          difference_type;
	typedef pointer_                                pointer;
	typedef reference_                              reference;

  private:
	iterator_type element;

  public:

	ReverseBiDirectionalIterator(): element(nullptr)
	{}

	explicit ReverseBiDirectionalIterator(iterator_type it) : element(it)
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

	ReverseBiDirectionalIterator&       operator--(int)
	{
		ReverseBiDirectionalIterator tmp(*this);
		this->element = this->element->getnext();
		return (tmp);
	}

	iterator_type                       getNode() {return element;}
};
}

#endif