/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Queue.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wester <wester@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 11:52:36 by wester        #+#    #+#                 */
/*   Updated: 2021/04/22 12:33:57 by wester        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "../List/List.hpp"
# include "../Vector/Vector.hpp"
# include <list>
# include <vector>
# include <deque>


namespace ft
{
    template <class T, class Container = std::deque<T> >
    class queue
    {
      public:
        typedef T               value_type;
        typedef Container       container_type;
        typedef size_t          size_type;

      private:
        container_type _container;
    
      public:
        explicit queue (const container_type& ctnr = container_type()) : _container(ctnr) {}
  
        bool                empty() const   { return _container.empty();  }
    
        size_type           size()  const   { return _container.size();   }  
    
        value_type&         front()         { return _container.front();  }
    
        const value_type&   front()   const { return _container.front();  }

        value_type&         back()          { return _container.back();   }
    
        const value_type&   back()   const  { return _container.back();   }
    
        void push(const value_type& val)    { _container.push_back(val);  }
    
        void                pop()           { _container.pop_front();     }
    
        template <class O, class Contain>
		friend bool operator== (const queue<O,Contain>& lhs, const queue<O,Contain>& rhs);

		template <class O, class Contain>
		friend bool operator< (const queue<O,Contain>& lhs, const queue<O,Contain>& rhs);

    };

    template <class T, class Container>
    bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs){
    return (lhs._container == rhs._container);    }
  
    template <class T, class Container>
    bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs){
        return !(lhs == rhs);    }

    template <class T, class Container>
    bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs){
        return (lhs._container < rhs._container);    }

    template <class T, class Container>
    bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs){
        return (lhs < rhs) || (lhs == rhs);    }

    template <class T, class Container>
    bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs){
        return !(lhs <= rhs);    }

    template <class T, class Container>
    bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs){
        return !(lhs < rhs);    }

}

#endif
