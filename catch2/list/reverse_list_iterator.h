//
// Created by Tuan Perera on 02.01.21.
//

#ifndef REVERSE_LIiST_ITERATOR_H
# define REVERSE_LIiST_ITERATOR_H
# include "traits.h"

namespace ft {
	template<typename T, typename R, typename P>
	class reverse_list_iterator {
	public:
		// Variables
		list_element<T>	*pos;

		typedef P							pointer;
		typedef R							reference;
		typedef bidirectional_iterator_tag 	iterator_category;

	public:
		// Functions
		reverse_list_iterator() : pos(NULL) { }
		reverse_list_iterator(list_element<T> *p=0) : pos(p) { }
		reverse_list_iterator(const reverse_list_iterator& src) : pos(src.pos) {}
		~reverse_list_iterator() { }

		reverse_list_iterator& operator=(const reverse_list_iterator& rhs) {
			if (this != rhs) {
				this->pos = rhs.pos;
			}
		}

		reference operator*() {
			return pos->data;
		}

		pointer operator->() {
			return &(pos->data);
		}

		bool operator!=(const reverse_list_iterator &rhs) {
			return this->pos != rhs.pos;
		}

		reverse_list_iterator operator++() {
			pos = pos->prev;
			return *this;
		}

		reverse_list_iterator operator++(int) {
			reverse_list_iterator<T, R, P> out(*this);
			pos = pos->prev;
			return *this;
		}

		reverse_list_iterator operator--() {
			pos = pos->next;
			return *this;
		}

		reverse_list_iterator operator--(int) {
			reverse_list_iterator<T, R, P> out(*this);
			pos = pos->next;
			return *this;
		}
	};
}

#endif //REVERSE_LIiST_ITERATOR_H
