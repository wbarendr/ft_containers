//
// Created by Tuan Perera on 02.01.21.
//

#ifndef LIST_ITERATOR_H
# define LIST_ITERATOR_H
# include "list_element.h"
# include "traits.h"

namespace ft {
	template<typename T, typename R, typename P>
	class list_iterator {
		public:
			// Variables
			list_element<T>						*pos;

			typedef P							pointer;
			typedef R							reference;
			typedef bidirectional_iterator_tag 	iterator_category;

		public:
			// Functions
			list_iterator(list_element<T> *p=0) : pos(p) { }
			list_iterator(const list_iterator& src) : pos(src.pos) {}
			~list_iterator() { }

			list_iterator& operator=(const list_iterator& rhs) {
				if (*this != rhs) {
					this->pos = rhs.pos;
				}
				return *this;
			}

			reference operator*() {
				return pos->data;
			}

			pointer operator->() {
				return &(pos->data);
			}

			bool operator!=(const list_iterator &rhs) {
				return this->pos != rhs.pos;
			}

			list_iterator operator++() {
				pos = pos->next;
				return *this;
			}

			list_iterator operator++(int) {
				list_iterator<T, R, P> out(*this);
				pos = pos->next;
				return out;
			}

			list_iterator operator--() {
				pos = pos->prev;
				return *this;
			}

			list_iterator operator--(int) {
				list_iterator<T, R, P> out(*this);
				pos = pos->prev;
				return out;
			}
	};
}
#endif //LIST_ITERATOR_H
