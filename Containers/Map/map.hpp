#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>

# include <algorithm>
# include "mapNode.hpp"
# include "../../Additionals/BiDirectionalIterator.hpp"
# include "../../Additionals/Traits.hpp"
# include "pair.hpp"
# include <map>

#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

namespace ft
{
template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > > 
class map{

  public:
	typedef Key                                                 key_type;
	typedef T                                                   mapped_type;
	typedef ft::pair<Key, T>                              		value_type;
	typedef Compare                                             key_compare;
	// typedef ft::value_comp                                      value_compare;
	typedef Alloc                                               allocator_type;
	typedef T&                                                  reference;
	typedef const T&                                            const_reference;
	typedef T*                                                  pointer;
	typedef const T*                                            const_pointer;
	typedef std::ptrdiff_t                                      difference_type;
	typedef size_t                                              size_type;

	typedef mapNode<value_type>*                                node_pointer;
	typedef mapNode<value_type>                                 node;

	typedef BiDirectionalIterator<value_type, node, pointer, reference>             iterator;
	// typedef ConstBidirectionalIterator<value_type, node>        const_iterator;
	// typedef RevBidirectionalIterator<value_type, node>          reverse_iterator;
	// typedef ConstRevBidirectionalIterator<value_type, node>     const_reverse_iterator;

  private: 
	node_pointer 	_root;
	node_pointer 	_first;
	node_pointer 	_last;
	size_type		_size;
	key_compare		_compare;
	allocator_type 	_alloc;

  public:
	//                  constructors
	explicit map (const key_compare& compare = key_compare(), const allocator_type& alloc = allocator_type()){
		_size = 0;
		_compare = compare;
		_alloc = alloc;
		make_tree();
	}

	value_type         insert(const value_type& val){ // verander de return hier nog naar pair....
		if (_size == 0){
			this->_root->data = val;
			_size = 1;
		}
		else {
			node_pointer tmp = _root;
			searchSpot(val, tmp);
		}
		return val; // check dit even

	};

	void				print_node(std::string root_path)
	{
		node_pointer tmp = _root;

		std::cout << "X";
		for (int i = 0; root_path[i]; ++i){
			if (root_path[i] == 'L'){
				if (tmp->left == NULL)
					return ;
				tmp = tmp->left;
			}
			if (root_path[i] == 'R'){
				if (tmp->right == NULL)
					return ;
				tmp = tmp->right;
			}
		}
		if (tmp->data.key){
			if (tmp->color)
				std::cout << RED << tmp->data.key << RESET;
			else 
				std::cout << BLUE << tmp->data.key << RESET;
		}
	}

	void				print_tree()
	{
		std::string root_path;
		int layer = 0;
		root_path = "";
		int starting_tabs = 10;
		int starting_gap = 8;
		while (layer < 4)
		{
			float nodes_in_layer = pow(2, layer);
			// std::cout << "nodes in layer: " << nodes_in_layer << std::endl;
			root_path.clear();
			int tmp_tabs = starting_tabs;
			int tmp_gap = starting_gap;
			for (int tmp_layer = layer; tmp_layer; --tmp_layer)
			{
				root_path.append("L");
				tmp_gap = tmp_gap / 2;
				tmp_tabs -= tmp_gap;
			}
			while (root_path.find('L') != std::string::npos){
				if (root_path.find('R') == std::string::npos)
					for (; tmp_tabs; --tmp_tabs)
						std::cout << "       ";
				else 
					for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
						std::cout << "       ";
				print_node(root_path);

				// std::cout << root_path;
				int L_found = root_path.find_last_of('L');
				root_path[L_found] = 'R';
				++L_found;
				for (;L_found != root_path.size(); ++L_found){
					root_path[L_found] = 'L';
				}
			}
			if (root_path.find('R') == std::string::npos)
				for (; tmp_tabs; --tmp_tabs)
					std::cout << "       ";
			else 
				for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
					std::cout << "       ";
			print_node(root_path);
			std::cout << std::endl << std::endl << std::endl;
			layer++;
		}
	}

  private:

	void                make_first(const value_type& val, node_pointer tmp)
	{
		std::cout << "make_first" << std::endl;
		node_pointer new_node = new node(val);

		tmp->left = new_node;
		new_node->parent = tmp;
		new_node->left = this->_first;
		this->_first->parent = new_node;
		++_size;

	}

	void                make_last(const value_type& val, node_pointer tmp)
	{
		std::cout << "make_last" << std::endl;
		node_pointer new_node = new node(val);

		tmp->right = new_node;
		new_node->parent = tmp;
		new_node->right = this->_last;
		this->_last->parent = new_node;
		++_size;

	}

	void                make_left(const value_type& val, node_pointer tmp)
	{
		std::cout << "make_left" << std::endl;
		node_pointer new_node = new node(val);

		tmp->left = new_node;
		new_node->parent = tmp;
		++_size;

		// new_node->left = this->_first;
		// this->_first->parent = new_node;
	}

	void                make_right(const value_type& val, node_pointer tmp)
	{
		std::cout << "make_right" << std::endl;
		node_pointer new_node = new node(val);

		tmp->right = new_node;
		new_node->parent = tmp;
		++_size;
	}

	void                searchSpot(const value_type& val, node_pointer tmp)
	{
		std::cout << "key of val:" << val.key << "  key of node:" << tmp->data.key << std::endl;
		if (val.key == tmp->data.key){
			std::cout << "Key already used" << std::endl;
			return ;
		}
		else if (_compare(val.key, tmp->data.key)){
			std::cout << "LEFT" << std::endl;
			if (tmp->left == this->_first)
				return make_first(val, tmp);
			if (tmp->left != NULL && tmp->left){
				searchSpot(val, tmp->left);
				return ;
			}
			return make_left(val, tmp);
		}
		std::cout << "RIGHT" << std::endl;
		if (tmp->right == this->_last)
			return make_last(val, tmp);
		if (tmp->right != NULL && tmp->right != this->_last){
			searchSpot(val, tmp->right);
			return ;
		}
		return make_right(val, tmp);
	}

	void                make_tree(const value_type& val = value_type()){
		this->_root = new node(val);
		this->_root->color = BLACK;

		this->_first = new node();
		this->_last = new node();
		
		this->_root->left = this->_first;
		this->_root->right = this->_last;

		this->_first->parent = _root;
		this->_last->parent = _root;

	}

	

};
}

#endif
