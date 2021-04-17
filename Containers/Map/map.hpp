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
# include <string>

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
	typedef value_type&                                         reference;
	typedef const value_type&                                   const_reference;
	typedef value_type*                                         pointer;
	typedef const value_type*                                   const_pointer;
	typedef std::ptrdiff_t                                      difference_type;
	typedef size_t                                              size_type;

	typedef mapNode<value_type>*                                node_pointer;
	typedef mapNode<value_type>                                 node;

	typedef BiDirectionalIterator<value_type, node, reference, pointer>  					iterator;
	typedef BiDirectionalIterator<value_type, node, const_reference, const_pointer>			const_iterator;
	typedef ReverseBiDirectionalIterator<value_type, node, reference, pointer>          	reverse_iterator;
	typedef ReverseBiDirectionalIterator<value_type, node, const_reference, const_pointer>	const_reverse_iterator;

  private: 
	node_pointer 	_root;
	node_pointer 	_first;
	node_pointer 	_last;
	size_type		_size;
	key_compare		_compare;
	allocator_type 	_alloc;

  public:
	//      CONSTRUCTORS
	explicit map(const key_compare& compare = key_compare(), const allocator_type& alloc = allocator_type())
	{
		_size = 0;
		_compare = compare;
		_alloc = alloc;
		make_tree();
	}

	template <class InputIterator>
    map(InputIterator first, InputIterator last, const key_compare& compare = key_compare(),
        const allocator_type& alloc = allocator_type())
	{
		_size = 0;
		_compare = compare;
		_alloc = alloc;
		make_tree();
        insert(first, last);
    }

	map(const map& other){
		_size = 0;
		_compare = other._compare;
		_alloc = other._alloc;
		make_tree();
        insert(other.begin(), other.end());
	};

	~map(){
		clear();
		delete _root;
		delete _first;
		delete _last;
	}

	map 				operator=(const map& other)
	{
		clear();
		_compare = other._compare;
		_alloc = other._alloc;
        insert(other.begin(), other.end());
		return *this;
	}


	// 		ITERATORS
	iterator						begin(){ return iterator(_first->parent);};	
	const_iterator					begin() const { return const_iterator(_first->parent);};	
	iterator						end(){ return iterator(_last);};	
	const_iterator					end() const { return const_iterator(_last);};	
	reverse_iterator				rbegin() { return reverse_iterator(_last->parent);};	
	const_reverse_iterator			rbegin() const { return const_reverse_iterator(_last->parent);};	
	reverse_iterator				rend(){ return reverse_iterator(_first);};	
	const_reverse_iterator			rend() const { return const_reverse_iterator(_first);};	

	bool							empty() const {return _size == 0;}
	size_type						size() const {return _size;}
	size_type 						max_size() const{ return _alloc.max_size();}

	mapped_type& 					operator[] (const key_type& k){
		iterator it = find(k);
		if (it == end()){
			value_type pair(k, mapped_type());
			insert(pair);
			return find(k)->second;
		}
		return it->second;
	};

	pair<iterator, bool>        insert(const value_type& val) // verander de return hier nog naar pair....
	{
		bool ret = false;
		if (_size == 0 || find(val.first) == end())
			ret = true;
		if (_size == 0){
			this->_root->data = val;
			_size = 1;
			_first->parent = _root;
			_last->parent = _root;
		}
		else {
			node_pointer tmp = _root;
			searchSpot(val, tmp);
		}
		RBT_Rules();
		iterator it = find(val.first);
		return ft::pair<iterator, bool>(it, ret); // check dit even
	}

	iterator 					insert(iterator position, const value_type& val){
		(void)position;
		return insert(val).first;
	}

	template <class InputIterator>
    void insert (typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last)
	{
        for (;first != last; ++first) {
            insert(*first);
        }
    }


	iterator						find(const key_type& k){
		node_pointer tmp = _root;
		while (tmp != _first && tmp != _last){
			if (k == tmp->data.first)
				return iterator(tmp);
			if (_compare(k, tmp->data.first)){
				if (tmp->left)
					tmp = tmp->left;
				else 
					return end();
			}
			else {
				if (tmp->right)
					tmp = tmp->right;
				else 
					return end();
			}
		} 
		return end();
	}

	const_iterator			find(const key_type& k) const{
		node_pointer tmp = _root;
		while (tmp != _first && tmp != _last){
			if (k == tmp->data.first)
				return const_iterator(tmp);
			if (_compare(k, tmp->data.first)){
				if (tmp->left)
					tmp = tmp->left;
				else 
					return end();
			}
			else {
				if (tmp->right)
					tmp = tmp->right;
				else 
					return end();
			}
		} 
		return end();
	}

	// void 					erase(typename enable_if<is_input_iterator<iterator>::value, iterator>::type position)
	// {
	// 	// node_pointer tmp[_size];
	// 	// tmp[_size] = NULL;

	// 	// size_t i = 0;
	// 	// iterator it = begin();
	// 	// for (;it != position; ++it)
	// 	// 	tmp[i] = it.getNode();
	// 	// position++;
	// 	// for (; position != end(); ++position)  
	// 	// 	tmp.push_back(position);
	// 	// ft::vector<mapNode*>::iterator it = tmp.begin;
		
	// 	// for (; tmp[i]; ++i)
	// 	// 	std::cout << tmp[i]->data.first << std::endl;
	// 		// insertion(*it); 
	// 	map tmp(begin(), position);
	// 	position++;
	// 	tmp.insert(position, end());
	// 	// tmp.print_tree();
	// 	*this = tmp;
	// }

	size_type 				erase(const key_type& k)
	{
		iterator it = find(k);
		if (it == end())
			return 0;
		erase(it);
		return (1);
	}

	void 					erase(iterator first, iterator last)
	{
		map tmp(first, last);
		for (iterator it = tmp.begin(); it != tmp.end(); ++it)
			erase(it->first);
	}

	void 					swap(map& other){
		map tmp;

		tmp._root = other._root;
		tmp._first = other._first;
		tmp._last = other._last;
		tmp._alloc = other._alloc;
		tmp._compare = other._compare;
		tmp._size = other._size;

		other._root = this->_root;
		other._first = this->_first;
		other._last = this->_last;
		other._alloc = this->_alloc;
		other._compare = this->_compare;
		other._size = this->_size;

		this->_root = tmp._root;
		this->_first = tmp._first;
		this->_last = tmp._last; 
		this->_alloc = tmp._alloc;
		this->_compare = tmp._compare;
		this->_size = tmp._size;
	}

		// std::cout << "key of val:" << val.key << "  key of node:" << tmp->data.key << std::endl;
		// if (val.first == tmp->data.first){
		// 	std::cout << "key already used" << std::endl;
		// 	return ;
		// }
		// else if (_compare(val.first, tmp->data.first)){
		// 	// std::cout << "LEFT" << std::endl;
		// 	if (tmp->left == this->_first)
		// 		return make_first(val, tmp);
		// 	if (tmp->left != NULL && tmp->left){
		// 		searchSpot(val, tmp->left);
		// 		return ;
		// 	}
		// 	return make_left(val, tmp);
		// }
		// // std::cout << "RIGHT" << std::endl;
		// if (tmp->right == this->_last)
		// 	return make_last(val, tmp);
		// if (tmp->right != NULL && tmp->right != this->_last){
		// 	searchSpot(val, tmp->right);
		// 	return ;
		// }
		// return make_right(val, tmp);
	// }
	// void							clear()
	// {
	// 	for (iterator it = begin(); it != end(); ++it)
	// 		delete *it;
	// 	_size = 0;
	// }

	// void							transplant(node_pointer one, node_pointer two)
	// {
	// 	node tmp;
		
	// 	if (one != NULL){
	// 		tmp.parent = one->parent;
	// 		tmp.left = one->left;
	// 		tmp.right = one->right;
	// 		tmp.color = one->color;
	// 		if (one->right != NULL)
	// 			one->right->parent = &tmp;
	// 		if (one->left != NULL)
	// 			one->left->parent = &tmp;
	// 		if (one->parent != NULL){
	// 			if (one == one->parent->left)
	// 				one->parent->left = &tmp;
	// 			else if (one == one->parent->right)
	// 				one->parent->right = &tmp;
	// 		}
	// 	}

	// 	std::cout << "here I am3" << std::endl;
	// 	if (two == NULL)
	// 		one = NULL;
	// 	else {
	// 		if (one != NULL)
	// 		{
	// 			one->parent = two->parent;
	// 			one->left = two->left;
	// 			one->right = two->right;
	// 			one->color = two->color;
	// 		}
	// 		std::cout << "here I am4" << std::endl;
	// 		if (two->right != NULL)
	// 			two->right->parent = one;
	// 		if (two->left != NULL)
	// 			two->left->parent = one;
	// 		std::cout << "here I am4" << std::endl;
	// 		if (two->parent != NULL){
	// 			if (two == two->parent->left)
	// 				two->parent->left = one;
	// 			else if (two == two->parent->right)
	// 				two->parent->right = one;
	// 		}
	// 	}

	// 	if (one != NULL){
	// 		two->parent = tmp.parent;
	// 		two->left = tmp.left;
	// 		two->right = tmp.right;
	// 		two->color = one->color;
	// 		if (tmp.right != NULL)
	// 			tmp.right->parent = two;
	// 		if (tmp.left != NULL)
	// 			tmp.left->parent = two;
	// 		if (tmp.parent != NULL){
	// 			if (&tmp == tmp.parent->left)
	// 				tmp.parent->left = two;
	// 			else if (&tmp == tmp.parent->right)
	// 				tmp.parent->right = two;
	// 		}
	// 		if (_root == two)
	// 			_root = one;
	// 		if (_root == one)
	// 			_root = two;
	// 	}
	// }

	void							set_first(){
		node_pointer tmp = _root;

		while (tmp->left != NULL && tmp->left != _first)
			tmp = tmp->left;
		_first->parent = tmp;
		tmp->left = _first;
	}

	void							set_last(){
		node_pointer tmp = _root;

		while (tmp->right != NULL && tmp->right != _last)
			tmp = tmp->right;
		_last->parent = tmp;
		tmp->right = _last;
	}

	node_pointer					step1(node_pointer old, node_pointer* replace){
		std::cout << "STEP 1" << std::endl;
		std::cout << "wie ben ik: " << old->data.first << std::endl; 
		if ((old->right == NULL || old->right == _last) && (old->left == NULL || old->left == _first)){
			*replace = NULL;
			std::cout << "both NULL" << std::endl;
			return NULL;
		}
		if (old->right == NULL || old->right == _last){
			*replace = old->left;
			std::cout << "getal:"<< old->left->data.first << std::endl;
			std::cout << "left NULL" << std::endl;
			return old->left;
		}
		if (old->left == NULL || old->left == _first){
			*replace = old->right;
			std::cout << "getal:"<< old->right->data.first << std::endl;
			std::cout << "right NULL" << std::endl;
			return old->right;
		}
		*replace = old->right;
		while ((*replace)->left != NULL && (*replace)->left != _first)
			(*replace) = (*replace)->left;
		return (*replace)->right;
	}

	bool							splice(node_pointer replace, node_pointer x, node_pointer old) // maak dit weer een void
	{
		std::cout << "splice" << std::endl;
		if (x == NULL && replace == NULL){
			if (old->parent && old->parent->left == old)
				return true; // kan zijn dat dit niet klopt dan kan ik in step 1 zoeken waar die replace vind.
			return false;
		}
		if (x != NULL)
			x->parent = replace->parent;
		if (replace == replace->parent->left)
		{
			replace->parent->left = x;
			return true;
		}
		else 
			replace->parent->right = x;
		return false;
			// if (replace == _first)
			// 	_first = x;
	}


	void							replace_func(node_pointer old, node_pointer replace)
	{
		std::cout << "replace" << std::endl;
		if (_root == old){
			_root = replace;
			if (replace != NULL)
				replace->parent = NULL;
		}
		else {
			if (old == old->parent->left)
				old->parent->left = replace;
			else
				old->parent->right = replace;
			if (replace)
				replace->parent = old->parent;		
		}
		if (old->right != NULL && replace && replace != old->right)
			old->right->parent = replace;
		if (old->left != NULL)
			old->left->parent = replace;
		if (replace != NULL){
			replace->left = old->left;
		}
		if (replace && old->right != replace)
			replace->right = old->right;
		set_first();
		set_last();
		delete old;
		--_size;
	}

	// bool							step2(bool old_col, bool replace_col, node_pointer replace)
	// {
	// 	if (old_col  == RED && replace_col == RED || replace == NULL)
	// 		return true;
	// 	if (old_col == RED && replace_col == BLACK){
	// 		replace->color = RED;
	// 		return false;
	// 	}
	// 	if (old_col == BLACK && replace_col == RED){
	// 		replace->color = BLACK;
	// 		return true;
	// 	}
	// 	return false // case with two black nodes or one black and one NULL
	// }

	// void							step3(node_pointer x, node_pointer w){
	// 	bool x_col;
	// 	bool w_col; 

	// 	if (x == NULL)
	// 		x_col == BLACK;
	// 	else 
	// 		x_col = x->color;
	// 	if (w == NULL)
	// 		w_col == BLACK;
	// 	else 
	// 		w_col = w->color;
	// 	if (x_col == RED)
	// 		case_0()
	// 	else if (x_col == BLACK && w_col == RED)
	// 		case_1();
	// 	else if (x_col == BLACK && w_col == BLACK && w){
	// 		if (w->left == NULL || (w->left && w->left == BLACK))
	// 			if (w->right == NULL || (w->right && w->right == BLACK))
	// 				case_2();
	// 		if (x)
	// 	}
	// 	else if ()
	// }


	void					deleteAll(node_pointer tmp)
	{
		if (tmp->right)
			deleteAll(tmp->right);
		if (tmp->left)
			deleteAll(tmp->left);
		delete tmp;
	}


	void					clear()
	{
		deleteAll(_root);
		_size = 0;
		make_tree();
	}

	void					case_0(node_pointer x)
	{
		std::cout << "CASE 0 !" << std::endl;
		x->color = BLACK;
	}

	void					case_1(node_pointer x, node_pointer w, node_pointer p, bool x_is_left)
	{
		std::cout << "CASE 1 !" << std::endl;
		
		p = w->parent;
		w->color = BLACK;
		if (p)
			p->color = RED;
		print_tree();
		if (x_is_left)
			LeftRotate(w, w->parent);
		else
			RightRotate(w, w->parent);
		if (x_is_left) {
			if (p)
				w = p->right;
		}
		else {
			if (p)
				w = p->left;
		}
		// maybe still change w here. 
		//go on to case 2,3,4
		std::cout << "done with case 1" << std::endl;
		print_tree();
		step3(x, w, p, x_is_left);
	}

	void					case_2(node_pointer x, node_pointer w, node_pointer p)
	{
		std::cout << "CASE 2 !" << std::endl;
		if (w)
			w->color = RED;
		x = p;
		if (x && x->parent)
			p = x->parent;
		else
			p = NULL;
		if (x && x->color == RED)
			x->color = BLACK;
	}

	void					case_3(node_pointer x, node_pointer w, bool x_is_left)
	{
		std::cout << "CASE 3 !" << std::endl;
		print_tree();
		if (x_is_left)
			std::cout << "X = left !" << std::endl;
		if (x_is_left && w && w->left)
			w->left->color = BLACK;
		else if (!x_is_left && w && w->right)
			w->right->color = BLACK;
		print_tree();
		std::cout << "hier" << std::endl;
		if (w)
			w->color = RED;
		
		print_tree();
		std::cout << "w: " << w->data.first << std::endl;
		std::cout << "w->left: " << w->left->data.first << std::endl;
		if (x_is_left){
			RightRotate(w->left, w); // this is probably wrong! left child?? 
			w = w->parent;
			// w = p->left;
		}
		else { 
			LeftRotate(w->right, w); // this is probably wrong! left child?? 
			w = w->parent;
		}
		//might still need to change w
		// if (x_is_left){ // this might need to be refactored
		// std::cout << "parent: " << p->data.first << std::endl;
		// if (p && p->right == x){
		// 	w = p->left;
		// 	std::cout << "parent is alive 1" << std::endl;
		// }
		// else if (p && p->left == x){
		// 	std::cout << "parent is alive 2" << std::endl;
		// 	w = p->right;
		// }
		// std::cout << "done with case 3 !" << std::endl;
		print_tree();
		case_4(x, w, x_is_left);
	}

	void					case_4(node_pointer x, node_pointer w, bool x_is_left)
	{
		std::cout << "CASE 4 !" << std::endl;

		if (!w)
			std::cout << "w = NULL" << std::endl;
		else 
			std::cout << "w = " << w->data.first << "   and w parent = " << w->parent->data.first << std::endl;

		if (x && x->parent){
			if (w)
				w->color = x->parent->color;
		}
		else if (w && w->parent){
			w->color = w->parent->color;
		}
		std::cout << "color w same color as x parent !" << std::endl;
		print_tree();
		if (x && x->parent)
			x->parent->color = BLACK;
		else if (w && w->parent)
			w->parent->color = BLACK;
		std::cout << "something !" << std::endl;
		print_tree();
		// if (w && w->left && !x_is_left)
		// 	w->left->color = BLACK;
		// else if (w && w->right && x_is_left)
		// 	w->right->color = BLACK;
		if (x_is_left){
			if (w && w->right)
				w->right->color = BLACK;
			print_tree();
			LeftRotate(w, w->parent);
		}
		else {
			if (w && w->left)
				w->left->color = BLACK;
			print_tree();
			RightRotate(w, w->parent);
		}
				
	}

	void					manipulate(iterator x)
	{
		node_pointer tmp = x.getNode();

		tmp->color = RED;
		tmp->left->color = BLACK;
		tmp->right->color = BLACK;
	}

	void					step3(node_pointer x, node_pointer w, node_pointer p, bool x_is_left)
	{
		std::cout << "STEP 3 !" << std::endl;
		// node_pointer p = replace->parent;
		// node_pointer r; // child of sibling
		// bool r_col; // colro of child of sibling
		// bool s_left_child = true;
		bool w_left_col = BLACK;
		bool w_right_col = BLACK;
		bool w_col = BLACK;
		bool x_col = BLACK;

		if (!w)
			std::cout << "w = NULL" << std::endl;
		else 
			std::cout << "w = " << w->data.first << std::endl;
		if (x && x->color == RED)// getting all colors of x w and children
			x_col = RED;
		std::cout << "not yets !" << std::endl;
		if (w && w->color == RED)
			w_col = RED;
		std::cout << "not yets !" << std::endl;
		if (w && w->left && w->left->color == RED)
			w_left_col = RED;
		if (w && w->right && w->right->color == RED)
			w_right_col = RED;

		// if (p && // finding out which color x is
		if (x_is_left)
			std::cout << "X = LEFT !" << std::endl;
		if (w_left_col == RED)
			std::cout << "left of W = RED" << std::endl;
		else 
			std::cout << "left of W = BLACK" << std::endl;
		if (w_right_col == RED)
			std::cout << "right of W = RED" << std::endl;
		else 
			std::cout << "right of W = BLACK" << std::endl;
		std::cout << "going to cases !" << std::endl;
		
		if (x_col == RED) // if x = RED
			case_0(x);
		else if (x_col == BLACK)
		{
			if (w_col == RED) // if x = black and w = red
				case_1(x, w, p, x_is_left);
			else if (w_left_col == BLACK && w_right_col == BLACK)
				case_2(x, w, p);
			else if ((x_is_left && w_left_col == RED && w_right_col == BLACK) || (!x_is_left && w_right_col == RED && w_left_col == BLACK))
				case_3(x, w, x_is_left);
			else if ((x_is_left && w_right_col == RED) || (!x_is_left && w_left_col == RED))
				case_4(x, w, x_is_left);
		}


	}


	// )

	void 					erase(typename enable_if<is_input_iterator<iterator>::value, iterator>::type position)
	{
		// _root = tmp._root;
		// _first = tmp._first;
		// _last = tmp._last;
		node_pointer old = position.getNode();
		if (!old || old == _last || old == _first)
			return ;
		node_pointer replace = NULL;
		node_pointer p = NULL;
		node_pointer x = NULL;
		node_pointer w = NULL;
		bool x_is_left = false;
		// node_pointer x_parent;

		if (old == NULL)
			return ;
		bool old_col = old->color; // save color of [to be erased]
		bool replace_col; // save color of [to be erased]

		x = step1(old, &replace);
		// std::cout << "x-data:" << x->data.first << std::endl;
		// std::cout << "replace-data:" << replace->data.first << std::endl;
		if (replace != NULL){
			replace_col = replace->color;
			if (replace && replace->parent && replace->parent->right == replace){
				if (replace == old->right)
					w = old->left;
				else 
					w = replace->parent->left;
				p = replace->parent;
				std::cout << "w here ? 1" << std::endl;
			}
			else if (replace && replace->parent && replace->parent->left == replace){
				if (replace == old->right)
					w = old->left;
				else 
					w = replace->parent->right; // making w the sibling of x
				p = replace->parent;
				std::cout << "w here ? 2" << std::endl;
			}
			if (!w)
				std::cout << "w = NULL" << std::endl;
			else 
				std::cout << "w = " << w->data.first << std::endl;
		}
		else {
			replace_col = BLACK; // dit moet BLACK zijn eigenlijk. 
			if (old->parent){
				if (old == old->parent->left)
					w = old->parent->right;
				else if (old == old->parent->right)
					w = old->parent->left;
			}
		}
		if (splice(replace, x, old))
			x_is_left = true;
		replace_func(old, replace);
		std::cout << "staying alive" << std::endl;
		if (old_col == RED && replace_col == RED){
			std::cout << "RED RED" << std::endl;
			if (replace)
				replace->color = RED;
		}	
		else if (old_col == BLACK && replace_col == RED){
			std::cout << "BLACK RED" << std::endl;
			replace->color = BLACK;
		}
		else {
			if (old_col == RED && replace_col == BLACK && replace){
				replace->color = RED; // deze twee regels zijn niet nodig
			}
			step3(x, w, p, x_is_left);
		}
		// delete old;
		// --_size;
		std::cout << "MADE IT OUT ERASE ALIVE! :)" << std::endl;
		// RBT_Rules();
	}
		// if (step2())
		// 	return ;
		// setp3(x, w);
		// if (tmp_del->left == NULL){
		// 	x = tmp_del->right;
		// 	if (tmp_del->parent){
		// 		if (tmp_del->parent->left == tmp_del)
		// 			tmp_del->parent->left = x;
		// 		if (tmp_del->parent->right == tmp_del)
		// 			tmp_del->parent->right = x;
		// 		x->parent = tmp_del->parent;
		// 	}
		// 	else 
		// 		_root = x;
		// }
		// else if (tmp_del->right == NULL){
		// 	x = tmp_del->left;
		// 	if (tmp_del->parent){
		// 		if (tmp_del->parent->left == tmp_del)
		// 			tmp_del->parent->left = x;
		// 		if (tmp_del->parent->right == tmp_del)
		// 			tmp_del->parent->right = x;
		// 		x->parent = tmp_del->parent;
		// 	}
		// 	else 
		// 		_root = x;
		// }
		// else {
		// 	std::cout << "here I am" << std::endl;
		// 	y = tmp_del->right;
		// 	while (y->left != NULL && y->left != _first)
		// 		y = y->left;
		// 	x = y->right;
		// 	save_color_replace = y->color;
		// 	tmp_del->data = y->data;
		// 	// if (save_color_del == BLACK && save_color_replace == RED)
		// 	// {
		// 	// 	// tmp_del->color = BLACK;

		// 	// }
		// 	if (save_color_del || save_color_replace){
		// 		if (!(save_color_del && save_color_replace)) 
		// 			tmp_del->color = BLACK;
		// 		std::cout << "atleast one was RED" << std::endl;
		// 		if (y->parent == tmp_del){
		// 			if (y->right)
		// 				y->right->parent = tmp_del;
		// 			tmp_del->right = y->right;
		// 		}
		// 		else {
		// 			if (y->right)
		// 				y->right->parent = y->parent;
		// 			y->parent->left = y->right;
		// 		}
		// 		delete y;
		// 	}
		// 	if (save_color_replace == BLACK){
		// 		if (x && x->color == RED){ //case 0

		// 		}


		// 	}
		// 	else { // both cases are black! 

		// 	}
		// }
			// else {
				
			// x = y->right;
			// print_tree();
			// y->parent->left = x;
			// if (x != NULL)
			// 	x->parent = y->parent;
			// // if (save_color_ == RED)
			// // 	delete y;
			// else if (x->color == RED)// note was black
			// {
			// 	x->color = BLACK;
			// 	delete y;
			// }
			// else // 6 cases ...
			// // if (y->parent == tmp_del){
			// // 	x->parent;
			// // }
			// std::cout << "here I am2" << std::endl;
			// transplant(y, x);
			// transplant(tmp_del, y);
			// // y->color = save_color;
			// std::cout << "here I am4" << std::endl;
			// }
		// }
		// do_a_find_first() and find_last() //
		// delete tmp_del;
		// print_tree();
	// }
	// }		

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
		if (tmp->data.first){
			if (tmp->color)
				std::cout << CRED << tmp->data.first << CRESET;
			else 
				std::cout << CYELLOW << tmp->data.first << CRESET;
		}
	}

	void				print_tree()
	{
		std::string root_path;
		int layer = 0;
		root_path = "";
		int starting_tabs = 16;
		int starting_gap = 16;
		while (layer < 5)
		{
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
						std::cout << "   ";
				else 
					for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
						std::cout << "   ";
				print_node(root_path);
				size_t L_found = root_path.find_last_of('L');
				root_path[L_found] = 'R';
				++L_found;
				for (;L_found != root_path.size(); ++L_found){
					root_path[L_found] = 'L';
				}
			}
			if (root_path.find('R') == std::string::npos)
				for (; tmp_tabs; --tmp_tabs)
					std::cout << "   ";
			else 
				for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
					std::cout << "   ";
			print_node(root_path);
			std::cout << std::endl << std::endl << std::endl;
			layer++;
		}
	}

  private: // don't forget to make the printing function private
	bool				findAuntColorFLip(node_pointer tmp)
	{
		node_pointer& GP = tmp->parent->parent;
		if (GP->left != NULL && tmp->parent == GP->left){
			if (GP->right && GP->right->color == RED)
			{
				// std::cout << "COLORFLIP" << std::endl;
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
				// std::cout << "COLORFLIP" << std::endl;
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
		if (tmp->color == RED){
			if (tmp->left != NULL && tmp->left->color == RED){
				// std::cout << "DOUBLE RED left side adjecent" << std::endl; 
				(*tmp_check) = tmp->left;
				return ;
			}
			if (tmp->right != NULL && tmp->right->color == RED){
				// std::cout << "DOUBLE RED right side adjecent" << std::endl; 
				(*tmp_check) = tmp->right;
				return ;
			}
		}
		if (tmp->left != NULL && tmp->left != _first)
			adjecentRedNodes(tmp->left, tmp_check);
		if (tmp->right != NULL)
			return adjecentRedNodes(tmp->right, tmp_check);
	}

	// void				findShortestRoute(node_pointer tmp, size_t *shortest, size_t current)
	// {
	// 	if (tmp == NULL)
	// 		return ;
		
	// 	if (tmp->color == BLACK)
	// 		current++;
	// 	if (tmp->left != NULL && tmp->left != _first)
	// 		findShortestRoute(tmp->left, shortest, current);
	// 	if (tmp->right != NULL && tmp->right != _last)
	// 		findShortestRoute(tmp->right, shortest, current);
	// 	if (tmp->left == NULL || tmp->left == _first || tmp->right == NULL || tmp->right == _last){
	// 		if (*shortest > current)
	// 			*shortest = current;
	// 		return ;
	// 	}
	// 	return ;
	// }

	// void				findLongerRoute(node_pointer tmp, size_t *shortest, size_t current, node_pointer *tmp_check)
	// {
	// 	if (tmp == NULL)
	// 		return ;
	// 	// std::cout << "data:" << tmp->data.first << std::endl;

	// 	if (tmp->color == BLACK)
	// 		current++;

	// 	if (tmp->left != NULL && tmp->left != _first){
	// 		// std::cout << "go left" << std::endl;
	// 		findLongerRoute(tmp->left, shortest, current, tmp_check);
	// 	}
	// 	if (tmp->right != NULL && tmp->right != _last){
	// 		// std::cout << "go right" << std::endl;
	// 		findLongerRoute(tmp->right, shortest, current, tmp_check);
	// 	}

	// 	if (tmp->left == NULL || tmp->left == _first || tmp->right == NULL || tmp->right == _last){
	// 		if (current > *shortest){
	// 			std::cout << "current:" << current << "shortest:" << *shortest << std::endl;
	// 			// (*tmp_check) = tmp;
	// 		}
	// 		return ;
	// 	}
	// 	return ;
	// }

	// void				toManyBlackNodes(node_pointer *tmp_check)
	// {
	// 	// (void)tmp_check;
	// 	// node_pointer tmp = _root;
	// 	// while (tmp->right != _last){
	// 	// 	tmp = tmp->right;
	// 	// }
	// 	// std::cout << "last number: " << tmp->data.first << std::endl;

	// 	// while (tmp->right != last)
	// 	// {

	// 	// 	if (current > first)
	// 	// 		return tmp_check; 
	// 	// 	current = 0
	// 	// }
	// 	// return nullptr;
	// 	size_t current = 0; 
	// 	size_t shortest = 10101010110101; // max size_t
	// 	findShortestRoute(_root, &shortest, current);
	// 	(void)tmp_check;
	// 	std::cout << "shortest: " << shortest << std::endl;

	// 	// std::cout << "shortest:" << shortest << std::endl;
	// 	// std::cout << "shortest:" << shortest << std::endl;
	// 	// std::cout << "shortest:" << shortest << std::endl;
	// 	// std::cout << "shortest:" << shortest << std::endl;
	// 	current = 0;
	// 	findLongerRoute(_root, &shortest, current, tmp_check);
	// 	// std::cout << "tomanyblacknode: " << (*tmp_check)->data.first << std::endl;
	// 	// (*tmp_check) = nullptr;
	// }

	// ROTATERS
	void				reColor(node_pointer child, node_pointer parent, node_pointer GP)
	{
			parent->color = BLACK;
			GP->color = RED;
			child->color = RED;
	}

	void				RightRotate(node_pointer parent, node_pointer GP)
	{
		std::cout << "right_rotate" << std::endl;
		// node_pointer parent = child->parent;
		std::cout << "parent: " << parent->data.first << std::endl;
		std::cout << "GP: " << GP->data.first << std::endl;
		if (GP->parent)
			std::cout << "GP->parent: " << GP->parent->data.first << std::endl;
		// node_pointer GP = parent->parent;

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
		// reColor1(parent, GP);
		// if (parent->left)
		// 	parent->left->color = RED;
	}

	void				LeftRotate(node_pointer parent, node_pointer GP)
	{
		std::cout << "left_rotate" << std::endl;
		// node_pointer parent = child->parent;
		// node_pointer GP = parent->parent;

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
		std::cout << "before recoloring" << std::endl;
		print_tree();

		// reColor1(parent);
		// if (parent->right)
		// 	parent->right->color = RED;
		// parent->color = BLACK;
		// GP->color = RED;
		// child->color = RED;
	}

	void				LeftRightRotate(node_pointer child)
	{
		// std::cout << "left->right rotate" << std::endl;
		node_pointer parent = child->parent;
		node_pointer GP = parent->parent;

		if (GP->parent != NULL){
			if (GP == GP->parent->right)
				GP->parent->right = child;
			else
				GP->parent->left = child;
			child->parent = GP->parent;
		}
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

		child->right = GP;
		GP->parent = child;
		child->left = parent;
		parent->parent = child;

		parent->color = RED;
		GP->color = RED;
		child->color = BLACK;

	}

	void				RightLeftRotate(node_pointer child)
	{
		// std::cout << "right->left rotate" << std::endl;
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
		// if (tmp_check == nullptr)
		// 	toManyBlackNodes(&tmp_check); // vberplaats deze met adjecent
		adjecentRedNodes(tmp, &tmp_check);
		if (tmp_check != nullptr)
			std::cout << tmp_check->data.first << std::endl;
		if (tmp_check != nullptr){
			// std::cout << "SOLVER!!!!!" << std::endl;
			if (findAuntColorFLip(tmp_check) == BLACK){
				if (tmp_check->parent->left != NULL && tmp_check == tmp_check->parent->left){
					// std::cout << "is left child" << std::endl;
					if (tmp_check->parent->parent->left != NULL && tmp_check->parent == tmp_check->parent->parent->left){
						RightRotate(tmp_check->parent, tmp_check->parent->parent);
						reColor(tmp_check, tmp->parent, tmp->parent->right);
					}
					else 
						RightLeftRotate(tmp_check);
				}
				else { 
					// std::cout << "is right child" << std::endl;
					if (tmp_check->parent->parent->right != NULL && tmp_check->parent == tmp_check->parent->parent->right){
						LeftRotate(tmp_check->parent, tmp_check->parent->parent);
						reColor(tmp_check, tmp->parent, tmp->parent->left);
					}
					else
						LeftRightRotate(tmp_check);
				}
			}
			RBT_Rules();
		}
	}		


	void                make_first(const value_type& val, node_pointer tmp)
	{
		// std::cout << "make_first" << std::endl;
		node_pointer new_node = new node(val);

		tmp->left = new_node;
		new_node->parent = tmp;
		new_node->left = this->_first;
		this->_first->parent = new_node;
		++_size;

	}

	void                make_last(const value_type& val, node_pointer tmp)
	{
		// std::cout << "make_last" << std::endl;
		node_pointer new_node = new node(val);

		tmp->right = new_node;
		new_node->parent = tmp;
		new_node->right = this->_last;
		this->_last->parent = new_node;
		++_size;

	}

	void                make_left(const value_type& val, node_pointer tmp)
	{
		// std::cout << "make_left" << std::endl;
		node_pointer new_node = new node(val);

		tmp->left = new_node;
		new_node->parent = tmp;
		++_size;

	}

	void                make_right(const value_type& val, node_pointer tmp)
	{
		// std::cout << "make_right" << std::endl;
		node_pointer new_node = new node(val);

		tmp->right = new_node;
		new_node->parent = tmp;
		++_size;
	}

	void        		searchSpot(const value_type& val, node_pointer tmp)
	{
		// std::cout << "key of val:" << val.key << "  key of node:" << tmp->data.key << std::endl;
		if (val.first == tmp->data.first){
			std::cout << "key already used" << std::endl;
			return ;
		}
		else if (_compare(val.first, tmp->data.first)){
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

		this->_first->parent = _last;
		this->_last->parent = _first;

	}

	

};
}

#endif
