/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wester <wester@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 15:47:54 by wester        #+#    #+#                 */
/*   Updated: 2021/04/22 11:54:58 by wester        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <algorithm>
# include "../../Additionals/Traits.hpp"
# include "../../Additionals/RandomAccessIterator.hpp"

namespace ft{
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	
  public:
  
	typedef 	T 					value_type;
	typedef 	Alloc				allocator_type;
	typedef 	value_type&			reference;
	typedef 	const value_type&	const_reference;
	typedef 	value_type*			pointer;
	typedef 	const value_type*	const_pointer;
	typedef		ptrdiff_t			difference_type;
	typedef		size_t				size_type;
	
	typedef		RandomAccessIterator<value_type> iterator;
	typedef		ConstRandomAccessIterator<value_type> const_iterator;
	typedef		ReverseRandomAccessIterator<value_type> reverse_iterator;
	typedef		ConstReverseRandomAccessIterator<value_type> const_reverse_iterator;
	
  private:

	pointer   	     	_data;
	size_type    		_size;
	size_type    		_capacity;
	allocator_type		_alloc;

	void		reAlloc(size_t newCapacity)
	{
		value_type*		newBlock = new T[newCapacity];//_alloc.allocate(newCapacity);  //;

		if (newCapacity < this->_size)
			this->_size = newCapacity;
		for (size_t i = 0; i < this->_size; ++i)
			newBlock[i] = _data[i];

		delete[] this->_data;
		this->_data = newBlock;
		this->_capacity = newCapacity;
	}

	void		reAlloc(size_t newCapacity, const value_type& val)
	{
		value_type*		newBlock = new T[newCapacity];

		if (newCapacity < _size)
			_size = newCapacity;

		size_t i = 0;
		for (; i < _size; ++i)
			newBlock[i] = _data[i];
		newBlock[this->_size] = val;
		clear();
		_size = i;
		_data = newBlock;
		_capacity = newCapacity;

	}

	size_type	distance(iterator first, iterator last)
	{
		size_type count = 0;
		while (first + count != last)
			count++;
		return count;
	}
	
	bool		validate_iterator(iterator position)
	{
		for (iterator it = this->begin(); it != this->end() + 1; ++it)
			if (it == position)
				return false;
		return true;
	}
	
  public:
  	explicit vector(const allocator_type& alloc = allocator_type())
  	{
		this->_size = 0;
	 	this->_capacity = 0;
		this->_alloc = alloc;
		this->_data = nullptr;
  	}


 	template <class InputIterator>
    vector(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last,
            const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc) {
		this->assign(first, last);
	}
	
	explicit vector(size_type n, const value_type &val = value_type(), 
		const allocator_type& alloc = allocator_type())
	{
		this->_data = new value_type[n];
		this->_size = 0;
		this->_capacity = n;
		this->_alloc = alloc;
		this->assign(n, val); 
	}

	vector(const vector& other){
		this->_data = new value_type[other._size];
		this->_capacity = other._size;
		this->_size = 0;
		this->_alloc = other._alloc;
		this->assign(other.begin(), other.end());
	}

	vector&		operator=(const vector& other){
		delete[] this->_data;
		this->_data = new value_type[other._capacity];
		this->_capacity = other._capacity;
		this->_size = 0;
		this->_alloc = other._alloc;
		this->assign(other.begin(), other.end());
		return *this;
	}

	~vector(){
		this->clear();
		delete[] this->_data;
	}

	iterator				begin()				{return iterator(_data);}
	const_iterator			begin() 	const	{return const_iterator(_data);}
	iterator				end()				{return iterator(&_data[_size]);}
	const_iterator			end() 		const	{return const_iterator(&_data[_size]);}
	reverse_iterator		rbegin()			{return reverse_iterator(&_data[_size - 1]);}
	const_reverse_iterator	rbegin()	const	{return const_reverse_iterator(&_data[_size - 1]);}
	reverse_iterator		rend()				{return reverse_iterator(_data -1);}
	const_reverse_iterator	rend()		const	{return const_reverse_iterator(_data - 1);}


	size_type		size() const { return _size; }

	size_type		max_size() const { return _alloc.max_size(); }
	
	void			resize(size_type n, value_type val = value_type())
	{
		while (n < this->_size)
			this->pop_back();
		while (n > this->_size)
			this->push_back(val);
		
	}

	size_type		capacity() const { return this->_capacity; }

	bool			empty() const 
	{
		if (this->_size == 0)
			return true;
		return false;
	}

	void			reserve(size_type n)
	{
		if (n > this->_capacity)
			reAlloc(n);
	}
	
	reference 			operator[](size_type n) { return _data[n]; }

	const_reference 	operator[](size_type n) const { return _data[n]; }
	
	reference			at(size_type n)
	{
		if (n < 0 || n > this->_size)
			throw std::out_of_range("out of range");
		return this->_data[n];
	}

	const_reference			at(size_type n) const
	{
		if (n < 0 || n > this->_size)
			throw std::out_of_range("out of range");
		return this->_data[n];
	}

	reference 			front() { return this->_data[0]; }
	
	const_reference 	front() const { return this->_data[0]; }

	reference 			back() { return this->_data[this->_size - 1]; }
	
	const_reference 	back() const { return this->_data[this->_size - 1]; }
	
	template <class InputIterator>
        void assign (typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
		this->clear();
		for (; first != last; ++first)
			this->push_back(*first);
	}
	
	void		assign(size_type n, const value_type &val)
	{
		this->clear();
		for (size_type i = 0; i < n; ++i)
			this->push_back(val);
	}
  
	void		push_back(const value_type& val)
	{
		if (this->_size >= this->_capacity)
		{
			if (this->_capacity == 0)
				reAlloc(1, val);
			else
				reAlloc(this->_capacity + this->_capacity, val);
		}
		else
			this->_data[this->_size] = val;
		this->_size++;
	}
	
	void		pop_back()
	{
		if (_size > 0)
			_size--;
	}
	
	iterator	insert(iterator position, const value_type& val)
	{
		size_type i = distance(begin(), position);
		insert(position, 1, val);
		return iterator(&_data[i]);
	}

	void		insert(iterator position, size_type n, const value_type& val)
	{
		vector tmp2(position, end());
		
		_size = distance(begin(), position);
		for (; n > 0; --n)
			push_back(val);
		for (iterator it = tmp2.begin(); it != tmp2.end(); ++it)
			push_back(*it);
	}

	template <class InputIterator>
    void 		insert(iterator position, typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last)
	{
		vector tmp;
	
		iterator pos_tmp = position;
		tmp._capacity = distance(position, this->end());
		tmp._data = new value_type[tmp._capacity];
		tmp.assign(position, this->end());
		this->_size = this->distance(this->begin(), pos_tmp);
		for (; first != last; ++first)
			this->push_back(*first);
		for (iterator it = tmp.begin(); it != tmp.end(); ++it)
			push_back(*it);
	}
	
	iterator	erase(iterator position)
	{
		size_type pos = distance(begin(), position);
		if (this->validate_iterator(position))
			return this->begin();
		for (iterator last = this->end(); position != last; ++position)
			*position = *(position + 1);
		this->_size--;
		return iterator(&_data[pos]);
	}
	
	iterator	erase(iterator first, iterator last)
	{
		if (this->validate_iterator(first) || this->validate_iterator(last))
			return this->begin();
		size_type n = distance(first, last);
		for (iterator end = this->end(); first != end - n; ++first)
			*first = *(first + n);
		this->_size -= n;
		return first - (n + 1);
	}
	
	void		swap(vector& x)
	{
		pointer   	     	tmp_data;
		size_type    		tmp_size;
		size_type    		tmp_capacity;
	
		tmp_data = x._data;
		tmp_size = x._size;
		tmp_capacity = x._capacity;

		x._data = this->_data;
		x._size = this->_size;
		x._capacity = this->_capacity;

		this->_data = tmp_data;
		this->_size = tmp_size;
		this->_capacity = tmp_capacity;
	}

	void		clear()
	{
		while (_size > 0)
			_size--;
	}
};
	
template<class T, class Alloc>
	bool 		operator==(const vector<T,Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		for (size_t i = 0; lhs.begin() + i != lhs.end(); ++i){
			if (*(lhs.begin() + i) != *(rhs.begin() + i))
				return false;
		}
		return (lhs.size() == rhs.size() && lhs.capacity() == rhs.capacity());
	}	

template<class T, class Alloc>
	bool 		operator!=(const vector<T,Alloc>& lhs, const vector<T, Alloc>& rhs)
	{	
		return (!(lhs == rhs));
	}

template<class T, class Alloc>
	bool 		operator<(const vector<T,Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

template<class T, class Alloc>
	bool 		operator<=(const vector<T,Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(rhs <lhs));
	}

template<class T, class Alloc>
	bool 		operator>(const vector<T,Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (rhs <lhs);
	}
	
template<class T, class Alloc>
	bool 		operator>=(const vector<T,Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
	
template <class T, class Alloc>
 	void 		swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		vector<T, Alloc> tmp;

		tmp = x;
		x = y;
		y = tmp;
	}
	
}

#endif
