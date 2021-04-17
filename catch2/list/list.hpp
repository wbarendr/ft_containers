/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 16:48:28 by tuperera      #+#    #+#                 */
/*   Updated: 2020/12/17 17:25:25 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <memory>
# include <iostream>
# include "list_element.h"
# include "list_iterator.h"
# include "reverse_list_iterator.h"
# include "traits.h"

namespace ft {
	template<class T, class Allocator = std::allocator<T> >
	class list {
		private:
			list_element<T>							*_head;
			list_element<T>							*_tail;
			size_t 									_size;
			Allocator								_allocator;

		public:
			typedef T								value_type;
			typedef Allocator						allocator_type;
			typedef std::size_t						size_type;
			typedef std::ptrdiff_t					difference_type;
			typedef T								&reference;
            typedef const T							&const_reference;
            typedef T								*pointer;
            typedef const T							*const_pointer;

			typedef list_iterator<T, reference, pointer>						iterator;
			typedef list_iterator<T, const_reference, const_pointer>			const_iterator;
			typedef reverse_list_iterator<T, reference, pointer>				reverse_iterator;
			typedef reverse_list_iterator<T, const_reference, const_pointer>	const_reverse_iterator;

		public:
			explicit list (const allocator_type& alloc = allocator_type()) {
				this->_head = new list_element<T>();
				this->_tail = new list_element<T>();
				this->_head->next = this->_tail;
				this->_tail->prev = this->_head;
				this->_size = 0;
				this->_allocator = alloc;
			}

			explicit list (size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
				this->_head = new list_element<T>();
				this->_tail = new list_element<T>();
				this->_head->next = this->_tail;
				this->_tail->prev = this->_head;
				this->_size = 0;
				this->assign(n, val);
				this->_allocator = alloc;
			}

			template <class InputIterator>
  			list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				  typename ft::enable_if<ft::is_iterator<typename InputIterator::iterator_category>::value, T>::type* = NULL) {
				this->_head = new list_element<T>();
				this->_tail = new list_element<T>();
				this->_head->next = this->_tail;
				this->_tail->prev = this->_head;
				this->_size = 0;
				this->_allocator = alloc;
				InputIterator tmp = first;
				while (tmp != last) {
					push_back(*tmp);
					tmp++;
				}
				if (*tmp == 0)
					push_back(*first);
				else
					push_back(*tmp);
			}

			list (const list& src) {
				this->_head = new list_element<T>();
				this->_tail = new list_element<T>();
				this->_head->next = this->_tail;
				this->_tail->prev = this->_head;
				this->_size = 0;
				for (typename list<T>::const_iterator it = src.begin(); it != src.end(); it++) {
					this->push_back(*it);
				}
				this->_allocator = src._allocator;
			}

            ~list() {
				this->clear();
				if (this->_head)
					delete this->_head;
				if (this->_tail)
					delete this->_tail;
            }

			list&		operator=(const list& rhs) {
				this->_head = new list_element<T>();
				this->_tail = new list_element<T>();
				this->_head->next = this->_tail;
				this->_tail->prev = this->_head;
				this->_size = 0;
				for (typename list<T>::const_iterator it = rhs.begin(); it != rhs.end(); it++) {
					this->push_back(*it);
				}
				this->_allocator = rhs._allocator;
				return *this;
			}

			// Iterators
			iterator begin() {
				return (iterator(this->_head->next));
			}

			const_iterator begin() const {
				return (const_iterator(this->_head->next));
			}

			iterator end() {
				return (iterator(this->_tail));
			}

			const_iterator end() const {
				return (const_iterator(this->_tail));
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(this->_tail->prev));
			}

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(this->_tail->prev));
			}

			reverse_iterator rend() {
				return (reverse_iterator(this->_head));
			}

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(this->_head));
			}

			// Capacity
			bool		empty() const {
				return (this->_size == 0);
			}

			size_type	size() const {
				return (this->_size);
			}

			size_type	max_size() const {
				return (size_type(-1) / sizeof(list_element<T>));
			}

			// Element access
			reference front() {
				return (this->_head->next->data);
			}

			const_reference front() const {
				return (this->_head->next->data);
			}

			reference back() {
				return (this->_tail->prev->data);
			}

			const_reference back() const {
				return (this->_tail->prev->data);
			}

			// Modifiers
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
				typename ft::enable_if<ft::is_iterator<typename InputIterator::iterator_category>::value, T>::type* = NULL) {
				InputIterator tmp = first;
				this->clear();
				while (tmp != last) {
					push_back(*tmp);
					tmp++;
				}
				if (*tmp == 0)
					push_back(*first);
				else
					push_back(*tmp);
			}

			void assign (size_type n, const value_type& val) {
				this->clear();
				this->insert(this->end(), n, val);
			}

			void push_front (const value_type& val) {
				list_element<T> *new_elem = new list_element<T>(val);
				new_elem->prev = this->_head;
				new_elem->next = this->_head->next;
				this->_head->next->prev = new_elem;
				this->_head->next = new_elem;
				this->_size++;
			}

			void pop_front() {
				if (this->_size) {
					list_element<T> *tmp = this->_head->next->next;
					delete this->_head->next;
					this->_head->next = tmp;
					tmp->prev = this->_head;
					this->_size--;
				}
			}

			void push_back (const value_type& val) {
				list_element<T> *new_elem = new list_element<T>(val);
				new_elem->next = this->_tail;
				new_elem->prev = this->_tail->prev;
				this->_tail->prev->next = new_elem;
				this->_tail->prev = new_elem;
				this->_size++;
			}

			void pop_back() {
				if (this->_size) {
					list_element<T> *tmp = this->_tail->prev->prev;
					delete this->_tail->prev;
					this->_tail->prev = tmp;
					tmp->next = this->_tail;
					this->_size--;
				}
			}

			iterator insert(iterator position, const value_type& val) {
				list_element<T> *new_ele = new list_element<T>(val);
				new_ele->next = position.pos;
				new_ele->prev = position.pos->prev;
				position.pos->prev->next = new_ele;
				position.pos->prev = new_ele;
				this->_size++;
				return (iterator(new_ele));
			}

			void insert(iterator position, size_type n, const value_type& val) {
				while (n > 0) {
					insert(position, val);
					n--;
				}
			}

			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
			   typename ft::enable_if<ft::is_iterator<typename InputIterator::iterator_category>::value, T>::type* = NULL) {
				while (first != last) {
					insert(position, *first);
					first++;
				}
			}

			iterator erase(iterator position) {
				if (this->_size) {
					list_element<T> *tmp = position.pos->next;
					position.pos->next->prev = position.pos->prev;
					position.pos->prev->next = position.pos->next;
					delete position.pos;
					position.pos = tmp;
					this->_size--;
				}
				return (position);
			}

			iterator erase(iterator first, iterator last) {
				while(first != last) {
					first = erase(first);
				}
				if (last.pos == this->_tail)
					return (iterator(this->_tail));
				else
					return (erase(first));
			}

			void swap (list& x) {
				swapi(this->_head, x._head);
				swapi(this->_tail, x._tail);
				swapi(this->_size, x._size);
				swapi(this->_allocator, x._allocator);
			}

			void resize (size_type n, value_type val = value_type()) {
				if (n < this->_size) {
					while (this->_size > n)
						pop_back();
				}
				else if (n > this->_size) {
					insert(this->end(), (n - this->_size), val);
				}
			}

			void clear() {
				this->erase(this->begin(), this->end());
			}

			// Operations
			void splice (iterator position, list& x) {
				this->insert(position, x.begin(), x.end());
				x.clear();
			}

			void splice (iterator position, list& x, iterator i) {
				this->insert(position, *i);
				x.erase(i);
			}

			void splice (iterator position, list& x, iterator first, iterator last) {
				while (first != last) {
					splice(position, x, first);
					first++;
				}
			}

			void remove (const value_type& val) {
				typename ft::list<T>::iterator it;
				for (it = this->begin(); it != this->end(); it++) {
					if (*it == val)
						it = erase(it);
				}
			}

			template <class Predicate>
			void remove_if (Predicate pred) {
				typename ft::list<T>::iterator it;
				for (it = this->begin(); it != this->end(); it++) {
					if (*it && pred(*it))
						it = this->erase(it);
				}
			}

			void unique() {
				typename ft::list<T>::iterator it;

				for (it = this->begin(); it != this->end(); it++) {
					if (it.pos && it != this->begin() && *it == it.pos->prev->data)
						it = this->erase(it);
				}
			}

			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred) {
				typename ft::list<T>::iterator it;

				for (it = this->begin(); it != this->end(); it++) {
					if (binary_pred(*it, it.pos->prev->data))
						it = this->erase(it);
				}
			}

			void merge (list& x) {
				ft::list_element<T> *pointer = this->_head->next;
				ft::list_element<T> *x_pointer = x._head->next;
				size_t 				m_size = this->size(),
									x_size = x.size();

				while (m_size && x_size) {
					if (pointer->data < x_pointer->data) {
						pointer = pointer->next;
						m_size--;
					}
					else {
						this->insert(iterator(pointer), x_pointer->data);
						x_pointer = x_pointer->next;
						x_size--;
					}
				}
				if (x_size)
					insert(this->end(), iterator(x_pointer), x.end());
				x.clear();
			}

			template <class Compare>
			void merge (list& x, Compare comp) {
				ft::list_element<T> *pointer = this->_head->next;
				ft::list_element<T> *x_pointer = x._head->next;
				size_t 				m_size = this->size(),
						x_size = x.size();

				while (m_size && x_size) {
					if (comp(pointer->data, x_pointer->data)) {
						pointer = pointer->next;
						m_size--;
					}
					else {
						this->insert(iterator(pointer), x_pointer->data);
						x_pointer = x_pointer->next;
						x_size--;
					}
				}
				x.clear();
			}

			void sort() {
				typename ft::list<T>::iterator it;
				typename ft::list<T>::iterator it2;
				bool unsorted = true;
				while(unsorted) {
					unsorted = false;
					it = this->begin();

					while(it != this->end()) {
						it2 = it;
						it2++;
						if(*it2 < *it && it2 != this->end()) {
							this->swap(it, it2);
							unsorted = true;
						}
						it++;
					}
				}
			}

			template <class Compare>
			void sort (Compare comp) {
				typename ft::list<T>::iterator it;
				typename ft::list<T>::iterator it2;
				bool unsorted = true;
				while(unsorted) {
					unsorted = false;
					it = this->begin();

					while(it != this->end()) {
						it2 = it;
						it2++;
						if(comp(*it2, *it) && it2 != this->end()) {
							this->swap(it, it2);
							unsorted = true;
						}
						it++;
					}
				}
			}

			void reverse() {
				size_t n = this->size(), i = this->size();
				typename ft::list<T>::iterator it = this->begin();
				while (n) {
					this->push_front(*it);
					it++;
					n--;
				}
				while (i) {
					this->pop_back();
					i--;
				}
			}

			// Observers
			allocator_type get_allocator() const {
				return this->_allocator;
			}

		private:
			void swap(iterator &pos1, iterator &pos2) {
				T tmp;
				tmp = pos1.pos->data;
				pos1.pos->data = pos2.pos->data;
				pos2.pos->data = tmp;
			}

			template<typename U>
			void swapi(U& first, U& second) {
				U tmp = first;
				first = second;
				second = tmp;
			}

		template <class I, class Alloc>
		friend void swap (ft::list<I,Alloc>& x, ft::list<I,Alloc>& y);
	};
};

// Non-member function overloads
template <class T, class Alloc>
bool operator== (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	if (lhs.size() == rhs.size()) {
		typename ft::list<T>::const_iterator it_lhs = lhs.begin();
		typename ft::list<T>::const_iterator it_rhs = rhs.begin();
		while (it_lhs != lhs.end()) {
			if (*it_lhs != *it_rhs)
				return (false);
			it_lhs++;
			it_rhs++;
		}
		return (true);
	}
	return (false);
}

template <class T, class Alloc>
bool operator!= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	if (lhs.size() == rhs.size()) {
		typename ft::list<T>::const_iterator it_lhs = lhs.begin();
		typename ft::list<T>::const_iterator it_rhs = rhs.begin();
		while (it_lhs != lhs.end()) {
			if (*it_lhs != *it_rhs)
				return (true);
			it_lhs++;
			it_rhs++;
		}
		return (false);
	}
	return (true);
}

template <class T, class Alloc>
bool operator<  (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	typename ft::list<T>::const_iterator it_lhs = lhs.begin();
	typename ft::list<T>::const_iterator it_rhs = rhs.begin();
	if (lhs == rhs || lhs.size() > rhs.size())
		return (false);
	if (lhs.size() == rhs.size()) {
		while (it_lhs != lhs.end()) {
			if (*it_lhs > *it_rhs)
				return (false);
			it_lhs++;
			it_rhs++;
		}
	}
	return (true);
}

template <class T, class Alloc>
bool operator<= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return (!(rhs < lhs));
}

template <class T, class Alloc>
bool operator>  (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return (rhs < lhs);
}

template <class T, class Alloc>
bool operator>= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return (!(lhs < rhs));
}

namespace ft {
	template <class I, class Alloc>
	void swap (ft::list<I,Alloc>& x, ft::list<I,Alloc>& y) {
		ft::list<I> *tmp = new ft::list<I>;
		tmp->_head = y._head;
		tmp->_tail = y._tail;
		tmp->_size = y._size;

		y._head = x._head;
		y._tail = x._tail;
		y._size = x._size;

		x._head = tmp->_head;
		x._tail = tmp->_tail;
		x._size = tmp->_size;
		delete tmp;
	}
}

#endif