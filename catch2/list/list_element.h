//
// Created by Tuan Perera on 01.01.21.
//

#ifndef LIST_ELEMENT_H
# define LIST_ELEMENT_H

namespace ft {
    template<typename T>
    class list_element {
        public:
    		// Variables
            T					data;
            list_element<T>		*next;
            list_element<T>		*prev;

		// Functions
			explicit list_element(const T &init_data = 0) : data(init_data), next(NULL), prev(NULL) {}
			list_element(const list_element &src) : data(src.data), next(src.next), prev(src.prev) { }
            ~list_element() { }

            list_element&    operator=(const list_element &rhs) {
                if (this != rhs) {
                    this->data = rhs.data;
                    this->next = rhs.next;
                    this->prev = rhs.prev;
                }
                return *this;
            }

            bool        operator==(const list_element &rhs) {
                return (this->data == rhs.data &&
                		this->next == rhs.next &&
                		this->prev == rhs.prev);
            }

            bool        operator!=(const list_element &rhs) {
                return (this->data != rhs.data ||
                		this->next != rhs.next ||
                		this->prev != rhs.prev);
            }
    };
};

#endif //LIST_ELEMENT_H
