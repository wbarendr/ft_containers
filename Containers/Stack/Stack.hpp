/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wester <wester@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 10:17:52 by wester        #+#    #+#                 */
/*   Updated: 2021/04/22 12:05:25 by wester        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../List/List.hpp"
# include "../Vector/Vector.hpp"
# include <list>
# include <vector>
# include <deque>

namespace ft
{
    template <class T, class Container = std::deque<T> >
    class stack
    {
      public:
        typedef T               value_type;
        typedef Container       container_type;
        typedef size_t          size_type;

      private:
        container_type _container;
    
      public:
        explicit stack (const container_type& ctnr = container_type()) : _container(ctnr) {}
  
        bool                empty() const { return _container.empty();  }
    
        size_type           size()  const { return _container.size();   }  
    
        value_type&         top()         { return _container.back();   }
    
        const value_type&   top()   const { return _container.back();   }
    
        void push(const value_type& val)  { _container.push_back(val);  }
    
        void                pop()         { _container.pop_back();      }
    
        template <class O, class Contain>
		friend bool operator== (const stack<O,Contain>& lhs, const stack<O,Contain>& rhs);

		template <class O, class Contain>
		friend bool operator< (const stack<O,Contain>& lhs, const stack<O,Contain>& rhs);

    };

    template <class T, class Container>
    bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
    return (lhs._container == rhs._container);    }
  
    template <class T, class Container>
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return !(lhs == rhs);    }

    template <class T, class Container>
    bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return (lhs._container < rhs._container);    }

    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return (lhs < rhs) || (lhs == rhs);    }

    template <class T, class Container>
    bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return !(lhs <= rhs);    }

    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return !(lhs < rhs);    }

}

#endif
