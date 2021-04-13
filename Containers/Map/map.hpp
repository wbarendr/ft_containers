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

#define CRESET   "\033[0m"
#define CRED     "\033[31m"      /* Red */
#define CGREEN   "\033[32m"      /* Green */
#define CYELLOW  "\033[33m"      /* Yellow */
#define CBLUE    "\033[34m"      /* Blue */

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


	bool				findAuntColorFLip(node_pointer tmp)
	{
		node_pointer& GP = tmp->parent->parent;
		if (GP->left != NULL && tmp->parent == GP->left){
			if (GP->right && GP->right->color == RED)
			{
				std::cout << "COLORFLIP" << std::endl;
				GP->right->color = BLACK;
				GP->left->color = BLACK;
				GP->color = RED;
				return RED;
			}
			return BLACK;
		}
		if (GP->right != NULL && tmp->parent == GP->right){
			if (GP->left && GP->left->color == RED)
			{
				std::cout << "COLORFLIP" << std::endl;
				GP->right->color = BLACK;
				GP->left->color = BLACK;
				GP->color = RED;
				return RED;
			}
			return BLACK;
		}
		return BLACK;
	}

	void				adjecentRedNodes(node_pointer tmp, node_pointer *tmp_check){
		if (tmp == _last)
			return ;
		// std::cout << tmp->data.key << std::endl;
		if (tmp->color == RED){
			if (tmp->left != NULL && tmp->left->color == RED){
				std::cout << "DOUBLE RED left side adjecent" << std::endl; 
				(*tmp_check) = tmp->left;
				return ;
			}
			if (tmp->right != NULL && tmp->right->color == RED){
				std::cout << "DOUBLE RED right side adjecent" << std::endl; 
				(*tmp_check) = tmp->right;
				return ;
			}
		}
		if (tmp->left != NULL && tmp->left != _first)
			adjecentRedNodes(tmp->left, tmp_check);
		if (tmp->right != NULL)
			return adjecentRedNodes(tmp->right, tmp_check);
	}

	void				RightRotate(node_pointer child)
	{
		std::cout << "right_rotate" << std::endl;
		node_pointer parent = child->parent;
		node_pointer GP = parent->parent;

		if (GP->parent != NULL){
			if (GP == GP->parent->right)
				GP->parent->right = parent;
			else
				GP->parent->left = parent;
		}
		if (parent->right != NULL){
			GP->left = parent->right;
			parent->right->parent = GP;
		}
		else 
		{
			GP->left = NULL;
		}
		parent->parent = GP->parent;
		GP->parent = parent;
		parent->right = GP;
		if (_root == GP)
			_root = parent;
		parent->color = BLACK;
		GP->color = RED;
		child->color = RED;
	}

	void				LeftRotate(node_pointer child)
	{
		std::cout << "left_rotate" << std::endl;
		node_pointer parent = child->parent;
		node_pointer GP = parent->parent;

		if (GP->parent != NULL){
			if (GP == GP->parent->left)
				GP->parent->left = parent;
			else
				GP->parent->right = parent;
		}
		if (parent->left != NULL){
			GP->right = parent->left;
			parent->left->parent = GP;
		}
		else 
		{
			GP->right = NULL;
		}
		parent->parent = GP->parent;
		GP->parent = parent;
		parent->left = GP;
		if (_root == GP)
			_root = parent;
		parent->color = BLACK;
		GP->color = RED;
		child->color = RED;
	}

	void				LeftRightRotate(node_pointer child)
	{
		std::cout << "left->right rotate" << std::endl;
		node_pointer parent = child->parent;
		node_pointer GP = parent->parent;
		print_tree();
		if (GP->parent != NULL){
			if (GP == GP->parent->right)
				GP->parent->right = child;
			else
				GP->parent->left = child;
			child->parent = GP->parent;
		}
		std::cout << "left->right rotate" << std::endl;
		if (_root == GP)
			_root = child;
		if (child->right){
			child->right->parent = GP;
			GP->left = child->right;
		}
		else 
			GP->left = NULL;
		if (child->left){
			child->left->parent = parent;
			parent->right = child->left;
		}
		else 
			parent->right = NULL;
		// print_tree();

		std::cout << "left->right rotate" << std::endl;
		child->right = GP;
		GP->parent = child;
		child->left = parent;
		parent->parent = child;
		std::cout << "left->right rotate" << std::endl;
		parent->color = RED;
		GP->color = RED;
		child->color = BLACK;
		print_tree();

	}

	void				RightLeftRotate(node_pointer child)
	{
		std::cout << "right->left rotate" << std::endl;
		node_pointer parent = child->parent;
		node_pointer GP = parent->parent;

		if (GP->parent != NULL){
			if (GP == GP->parent->left)
				GP->parent->left = child;
			else
				GP->parent->right = child;
			child->parent = GP->parent;

		}
		if (_root == GP)
			_root = child;
		if (child->left){
			child->left->parent = GP;
			GP->right = child->left;
		}
		else 
			GP->right = NULL;
		if (child->right){
			child->right->parent = parent;
			parent->left = child->right;
		}
		else 
			parent->left = NULL;
		child->left = GP;
		GP->parent = child;
		child->right = parent;
		parent->parent = child;
		parent->color = RED;
		GP->color = RED;
		child->color = BLACK;
	}

	void				RBT_Rules(){
		node_pointer tmp = _root;
		node_pointer tmp_check = nullptr;
		if (_root->color == RED)
			_root->color = BLACK;
		std::cout << "pre add" << std::endl;
		adjecentRedNodes(tmp, &tmp_check);
		if (tmp_check != nullptr)
			std::cout << tmp_check->data.key << std::endl;
		if (tmp_check != nullptr){
			if (findAuntColorFLip(tmp_check) == BLACK){
				// std::cout << "data: " << tmp_check->data.key << std::endl;
				// std::cout << "data: " << tmp_check->parent->data.key << std::endl;
				// std::cout << "data: " << tmp_check->parent->parent->data.key << std::endl;
				// std::cout << "data: " << tmp_check->parent->parent->parent->data.key << std::endl;
				print_tree();
				if (tmp_check->parent->left != NULL && tmp_check == tmp_check->parent->left){
					std::cout << "is left child" << std::endl;
					if (tmp_check->parent->parent->left != NULL && tmp_check->parent == tmp_check->parent->parent->left)
						RightRotate(tmp_check);
					else 
						RightLeftRotate(tmp_check);
				}
				else { 
					std::cout << "is right child" << std::endl;
					if (tmp_check->parent->parent->right != NULL && tmp_check->parent == tmp_check->parent->parent->right)
						LeftRotate(tmp_check);
					else
						LeftRightRotate(tmp_check);
				}
			}
			std::cout << "made it out " << std::endl;
			RBT_Rules();
		}
	}		


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
		RBT_Rules();
		return val; // check dit even

	};

	void				print_node(std::string root_path)
	{
		node_pointer tmp = _root;

		std::cout << ".";
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
				std::cout << CRED << tmp->data.key << CRESET;
			else 
				std::cout << CBLUE << tmp->data.key << CRESET;
		}
	}

	void				print_tree()
	{
		std::string root_path;
		int layer = 0;
		root_path = "";
		int starting_tabs = 32;
		int starting_gap = 32;
		while (layer < 6)
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
						std::cout << " ";
				else 
					for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
						std::cout << " ";
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
					std::cout << " ";
			else 
				for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
					std::cout << " ";
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
		// std::cout << "key of val:" << val.key << "  key of node:" << tmp->data.key << std::endl;
		if (val.key == tmp->data.key){
			std::cout << "Key already used" << std::endl;
			return ;
		}
		else if (_compare(val.key, tmp->data.key)){
			// std::cout << "LEFT" << std::endl;
			if (tmp->left == this->_first)
				return make_first(val, tmp);
			if (tmp->left != NULL && tmp->left){
				searchSpot(val, tmp->left);
				return ;
			}
			return make_left(val, tmp);
		}
		// std::cout << "RIGHT" << std::endl;
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
