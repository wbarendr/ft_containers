/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   List.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wester <wester@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/02 22:06:55 by wester        #+#    #+#                 */
/*   Updated: 2021/04/06 16:30:30 by wester        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <memory>

# include <algorithm>
# include "Node.hpp"
# include "BiDirectionalIterator.hpp"
# include "../../Additionals/Traits.hpp"

namespace ft {
	
template <typename T, typename Allocator = std::allocator<T> > 
class list
{

  public:

	typedef T					value_type;
	typedef Allocator			allocator_type;
	typedef value_type&			reference;
	typedef const value_type& 	const_reference;
	typedef value_type*			pointer;
	typedef const value_type*	const_pointer;
	typedef size_t				size_type;
	typedef ptrdiff_t 			difference_type;

	typedef node<value_type> 	node;
	typedef node*				node_pointer;
	
	typedef BiDirectionalIterator<value_type, node_pointer, reference, pointer> iterator;
	typedef BiDirectionalIterator<value_type, node_pointer, const_reference, const_pointer> const_iterator;
	typedef ReverseBiDirectionalIterator<value_type, node_pointer, reference, pointer> reverse_iterator;
	typedef ReverseBiDirectionalIterator<value_type, node_pointer, const_reference, const_pointer> const_reverse_iterator;

  private:
	node_pointer		_head;
	node_pointer		_tail;
	size_type			_total;
	allocator_type		_alloc;

	void		createEndNodes()
	{
		this->_head = new node();
		this->_tail = new node();
		this->_head->next = this->_tail;
		this->_tail->prev = this->_head;
		this->_total = 0;
	}
	
	iterator		change(node* first, node* second)
	{
		first->prev->next = second;
		second->next->prev = first;
		first->next = second->next;
		second->prev = first->prev;
		second->next = first;
		first->prev = second;
		if (iterator(second) != begin())
			return iterator(second);
		return iterator(first);
	}

  public:

					//CONSTRUCTORS
	explicit list(const allocator_type& alloc = allocator_type()){
		createEndNodes();
		_alloc = alloc;
	};

	explicit list(size_type n, const T& value = T(), const allocator_type& alloc = allocator_type()){
		createEndNodes();
		this->_alloc = alloc;
		assign(n, value);
	};

	template <class InputIterator>
    list (typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first,
			InputIterator last, const allocator_type& alloc = allocator_type()){
		createEndNodes();
		this->_alloc = alloc;
		assign(first, last);
	};

	list(const list& other){
		createEndNodes();
		assign(other.begin(), other.end());
	};

	list&		operator=(const list& other)
	{
		clear();
		_head->_next = _tail;
        _tail->_prev = _head;
		assign(other.begin(), other.end());
		return *this;
	};

	~list(){
		clear();
		delete _head;
		delete _tail;
	}
	
					//ITERATORES
	iterator				begin()				{return iterator(_head->next);}
	const_iterator			begin() 	const	{return const_iterator(_head->next);}
	iterator				end()				{return iterator(_tail);}
	const_iterator			end() 		const	{return const_iterator(_tail);}
	reverse_iterator		rbegin()			{return iterator(_tail->prev);}
	const_reverse_iterator	rbegin()	const	{return const_iterator(_tail->prev);}
	reverse_iterator		rend()				{return iterator(_head);}
	const_reverse_iterator	rend()		const	{return const_iterator(_head);}

					//CAPACITY
	bool 					empty()		const	{return !_total;}
	size_type 				size() 		const	{return _total;}
	size_type 				max_size() 	const	{return _alloc.max_size();}
	
					//ELEMENT ACCESS
	reference 				front()				{return reference(_head->next->data);}
	const_reference 		front() 	const	{return const_reference(_head->next->data);}
	reference 				back()				{return reference(_tail->prev->data);}
	const_reference 		back() 		const	{return const_reference(_tail->prev->data);}
	
					//MODIFIERS
	template <class InputIterator>
    void 		assign(typename enable_if<is_input_iterator<InputIterator>::value,
						InputIterator>::type first, InputIterator last) 
	{
		for (; first != last; ++first)
			push_back(*first);
	}

	void		assign(size_type n, const value_type&  val)
	{
		for (size_type i = 0; i < n; ++i)
			push_back(val);
	}

	void 		push_front(const value_type& val){
		node *new_node = new node(val);
		
		// new_node->data = val;
		new_node->next = _head->next;
		new_node->prev = _head;
		new_node->next->prev = new_node;
		_head->next = new_node;
		_total += 1;
	}
	
	void 		pop_front(){
		node* tmp = _head->next;
		
		if (!_total)
			return ;
			
		_head->next->next->prev = _head;
		_head->next = _head->next->next;
		delete tmp;
		_total -= 1;
	}
	
	void		push_back(const value_type& val)
	{
		node *new_node = new node(val);

		new_node->next = _tail;
		new_node->prev = _tail->prev;
		_tail->prev = new_node;
		new_node->prev->next = new_node;
		_total += 1;
	}
	
	void		pop_back(){
		node* tmp = _tail->prev;
		
		if (!_total)
			return ;
			
		_tail->prev->prev->next = _tail->prev;
		_tail->prev = _tail->prev->prev;
		delete tmp;
		_total -= 1;

	}
	
	iterator 	insert(iterator position, const value_type& val){
		node* new_node  = new node(val);

		node* pos = position.getNode();
		new_node->next = pos;
		new_node->prev = pos->prev;
		pos->prev->next = new_node;
		pos->prev = new_node;
		_total += 1;
		return iterator(new_node);
	}
	
    void 		insert(iterator position, size_type n, const value_type& val){
		for (size_type i = 0; i < n; ++i){
			insert(position, val);
		}
	}
	
	template <class InputIterator>
    void 		insert(iterator position, typename enable_if<is_input_iterator<InputIterator>::value,
						InputIterator>::type first, InputIterator last){
		for (;first != last; ++first)
			insert(position, *first);
	}

	iterator 	erase(iterator position){
		node* pos = position.getNode();
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		delete pos;
		this->_total -= 1;
		return position++;
	}
	
	iterator 	erase(iterator first, iterator last){
		for (; first != last; ++first){
			erase(first);
		}
		return last;	
	}
	
	void 		swap(list& other){
		node_pointer		tmp_head = this->_head;
		node_pointer		tmp_tail = this->_tail;
		size_type			tmp_total = this->_total;

		this->_head = other._head;
		this->_tail = other._tail;
		this->_total = other._total;
		
		other._head = tmp_head;
		other._tail = tmp_tail;
		other._total = tmp_total;
	}

	void 		resize(size_type n, value_type val = value_type()){
		while (n < this->_total)
			pop_back();
		while (n > this->_total)
			push_back(val);
	}
	
	void		clear()
	{
		while (this->_total > 0)
			pop_back();
	}

	void			transfer(iterator position, node* transfer_node)
	{
		node* pos = position.getNode();
		transfer_node->next = pos;
		transfer_node->prev = pos->prev;
		pos->prev->next = transfer_node;
		pos->prev = transfer_node;
		_total += 1;
	}
	//				OPERATIONS
	void 		splice(iterator position, list& other){
		for (iterator it = other.begin(); it != other.end();){
			++it;
			transfer(position, it.getNode()->prev);
			other._total--;
		}
		other._head->next = other._tail;
		other._tail->prev = other._head;
	}
	
	void 		splice(iterator position, list& other, iterator i){
		node* transfer_node = i.getNode();
		
		transfer_node->next->prev = transfer_node->prev;
		transfer_node->prev->next = transfer_node->next;
		transfer(position, transfer_node);
		other._total--; 
	}
	
	void 		splice(iterator position, list& other, iterator first, iterator last){
		node* transfer_node;// = i.getNode();
		for (;first != last;){
			transfer_node = first.getNode();
			++first;
			transfer_node->next->prev = transfer_node->prev;
			transfer_node->prev->next = transfer_node->next;
			transfer(position, transfer_node);
			other._total--; 
		}
	}
	
	void 		remove(const value_type& val){
		for (iterator it = begin(); it != end(); ++it)
			if (*it == val)
				erase(it);
	}

	template <class Predicate>
  	void 		remove_if(Predicate pred){
		for (iterator it = begin(); it != end(); ++it)
			if (pred(it))
				erase(it);
	}

	void 		unique(){
		iterator first = begin();
		iterator second = begin();
		second++;
		for (; second != end();){
			if (*first == *second){
				iterator tmp = second;
				second++;
				erase(tmp);
			}
			else {
				first++;
				second++;
			}
		}
	}
	
	template <class BinaryPredicate>
  	void 		unique(BinaryPredicate binary_pred){
		iterator first = begin();
		iterator second = begin();
		second++;
		for (; second != end();){
			if (binary_pred(first, second)){
				iterator tmp = second;
				second++;
				erase(tmp);
			}
			else {
				first++;
				second++;
			}
		}	  
	}

	
	void			merge(list& other){
		iterator it_other = other.begin();
		iterator it = begin();
		while (it_other != other.end()){
			while (it.getNode()->data <= it_other.getNode()->data && it != end())
				++it;
			if (it == end() && it_other != other.end()){
				++it_other;
				transfer(it, it_other.getNode()->prev);
				other._total--;
			}
			while (it_other.getNode()->data < it.getNode()->data && it_other != other.end()){
				++it_other;
				transfer(it, it_other.getNode()->prev);
				other._total--;
			}
		}
		other._head->next = other._tail;
		other._tail->prev = other._head;
	}

	template <class Compare>
  	void 			merge(list& other, Compare comp){
		iterator it_other = other.begin();
		iterator it = begin();
		while (it_other != other.end()){
			while (!comp(it.getNode()->data, it_other.getNode()->data) && it != end())
				++it;
			if (it == end() && it_other != other.end()){
				++it_other;
				transfer(it, it_other.getNode()->prev);
				other._total--;
			}
			while (comp(it.getNode()->data, it_other.getNode()->data) && it_other != other.end()){
				++it_other;
				transfer(it, it_other.getNode()->prev);
				other._total--;
			}
		}
		other._head->next = other._tail;
		other._tail->prev = other._head;
	}

	void			sort(){ // bubble sort?
		iterator second = begin();
		second++;
		while (second != end()){
			if (second.getNode()->data < second.getNode()->prev->data)
				second = change(second.getNode()->prev, second.getNode());
			else
				++second;
		}
	}
	
	template <class Compare>
    void 		sort(Compare comp){
		iterator second = begin();
		second++;
		while (second != end()){
			if (comp(second.getNode()->prev->data, second.getNode()->data))
				second = change(second.getNode()->prev, second.getNode());
			else
				++second;
		}
	}
};
	template <class T, class Alloc>
  	bool 		operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return false;
		BiDirectionalIterator<T, node<T>*, const T&, const T*> lhs_begin = lhs.begin();
		BiDirectionalIterator<T, node<T>*, const T&, const T*> rhs_begin = rhs.begin();
		while (lhs_begin != lhs.end()){
			if (*lhs_begin != *rhs_begin)
				return false;
			++lhs_begin;
			++rhs_begin;
		}
		return (rhs_begin == rhs.end());
	}
	  
	template <class T, class Alloc>
  	bool 		operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		  return !(lhs == rhs);
	}

	template <class T, class Alloc>
  	bool 		operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
  	bool 		operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		  return !(lhs > rhs);
	}

	template <class T, class Alloc>
  	bool 		operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		return (!(lhs == rhs) && !(lhs < rhs));	  
	}
	  
	template <class T, class Alloc>
  	bool 		operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		return !(lhs < rhs);
	}
	
	template <class T, class Alloc>
	void 		swap(list<T,Alloc>& x, list<T,Alloc>& y){
		BiDirectionalIterator<T, node<T>*, T&, T*> xbegin = x.begin();
		
		x.splice(xbegin, y);
		y.splice(y.begin(), x, xbegin, x.end());
		
	}
}

#endif
