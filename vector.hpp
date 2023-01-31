#pragma once
#include <iostream>
#include <memory>
#include <exception>
namespace ft{
	template <class Category, class T>
  	class iterator {
	public:
    	typedef T         value_type;
    	typedef ptrdiff_t  difference_type;
    	typedef T*   pointer;
    	typedef T& reference;
    	typedef Category  iterator_category;
		//OPERATORS
		reference operator*() const{
			return *i_ptr;
		};
		pointer operator->(){
			return i_ptr;
		};
		iterator & operator++(){
			i_ptr++;
			return (*this);
		};
		iterator & operator--(){
			i_ptr--;
			return (*this);
		};
		iterator operator++(int){
			iterator tmp = *this;
			++(*this);
			return (tmp);
		};
		iterator operator--(int){
			iterator tmp = *this;
			--(*this);
			return (tmp);
		};
		iterator operator+=(){
			
		};
		iterator operator-=(){
			
		};
		bool operator==(const iterator & rhs){
			
		};
		bool operator>(const iterator & rhs){
			
		};
		iterator operator<(const iterator & rhs){
			
		};
		bool operator>=(const iterator & rhs){
			
		};
		bool operator<=(const iterator & rhs){
			
		};
		bool operator!=(const iterator & rhs){
			
		};
		//MEMBER FUNCTIONS
		iterator begin(){
			return i_ptr[0];
		};
		iterator end(){
			return ;
		};
	private:
		pointer i_ptr;
  };
	template < class T, class Alloc = std::allocator<T> > 
	class vector{
		public:
			typedef T&						reference;
			typedef Alloc					allocator_type;
			typedef T& 						const_reference;
			typedef T* 						pointer;
			typedef const T*				const_pointer;
			typedef size_t 					size_type;
			typedef T						value_type;
			typedef ptrdiff_t				difference_type;
			typedef typename ft::iterator 	iterator;
			// typedef typename iterator_traits<iterator>::difference_type difference_type;

			// CONSTRUCTORS
			explicit vector (const allocator_type& alloc = allocator_type()){
				this->alloc = alloc;
				this->arr = NULL;
				this->v_size = 0;
				this->v_capacity = 0;
			};
			// fill (2)	
			// explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
			// 	this->alloc = alloc;
			// 	this->v_size = n;
			// 	this->v_capacity = 0;
			// 	this->arr = alloc.allocator(v_capacity);
			// 	for (size_type i = 0; i < n; i++)
			// 		alloc.construct(&arr[i], val);
			// };
			// range (3)	
			// template <class InputIterator>
			// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			// copy (4)	
			vector (const vector& x){
				this = x;
			}
			//Assignment op
			vector& operator=(const vector& x){
				this->v_size = x.v_size;
				this->v_capacity = x.v_capacity;
				this->arr = alloc.allocate(v_capacity);
				*this->arr = *(x.arr);
				return (*this);
			}

			//ITERATORS
			// iterator begin();
			// const_iterator begin() const;
			// iterator end();
			// const_iterator end() const;
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

			//v_capacity
			size_type size() const{
				return v_size;
			};
			size_type max_size() const{
				return (4611686018427387903);
			};
			void resize (size_type n, value_type val = value_type())
			{
				size_type tmp_size = v_size;
				if (n > v_capacity)
				{
					if (n < v_capacity * 2)
						v_capacity *= 2 ;
					else
						v_capacity = n;
					pointer tmp = alloc.allocate(v_size);
					for (size_t i = 0; i < v_size; i++)
						alloc.construct(&tmp[i], arr[i]);
					clear();
					arr = alloc.allocate(v_capacity);
					for (size_type i = 0; i < tmp_size; i++)
						alloc.construct(&arr[i], tmp[i]);
					for (size_type i = tmp_size; i < n; i++)
							alloc.construct(&arr[i], val);
				}
				else 
				{
					if (n < v_size)
					{
						for (size_type i = n; i < v_size; i++)
							alloc.destroy(&arr[i]);
					}
					else
					{
						for (size_type i = v_size; i < n; i++)
							alloc.construct(&arr[i], val);
					}
				}
				v_size = n;
			};
			size_type capacity() const{
				return v_capacity;
			};
			bool empty() const{
				if (v_size)
					return false;
				return true;
			};
			void reserve (size_type n){
				if (n > v_capacity)
				{
					pointer tmp = arr;
					v_capacity = n;
					clear();
					arr = alloc.allocate(v_capacity);
					for (size_t i = 0; i < v_size; i++)
						alloc.construct(&arr[i], tmp[i]);
				}
			};

			//ACCESS ELEMENTS
			reference operator[] (size_type n){
				return arr[n];
			};
			const_reference operator[] (size_type n) const{
				return arr[n];
			};
			reference at (size_type n){
				if (n >= v_size|| n < 0)
					throw ("out_of_range");
				return arr[n];
			};
			const_reference at (size_type n) const{
				if (n >= v_size || n < 0)
					throw ("out_of_range");
				return arr[n];
			};
			reference front(){
				return arr[0];
			};
			const_reference front() const{
				return arr[0];
			};
			reference back(){
				return arr[v_size];
			};
			const_reference back() const{
				return arr[v_size];
			};

			//MODIFIERS
			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last);
			// void assign (size_type n, const value_type& val);
			void push_back (const value_type& val){
				resize(v_size + 1, val);
			};
			void pop_back(){
				resize(v_size);
			};
			// // single element (1)	
			// iterator insert (iterator position, const value_type& val);
			// // fill (2)	
			// void insert (iterator position, size_type n, const value_type& val);
			// // range (3)	
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);
			// iterator erase (iterator position);
			// iterator erase (iterator first, iterator last);
			// void swap (vector& x){};
			void clear(){
				for (size_type i = 0; i < v_size; i++)
					alloc.destroy(&arr[i]);
				v_size = 0;
			};

			//ALLOCATOR
			allocator_type get_allocator() const{
				return alloc;
			};

			// // Template specializations
			// template < class T, class Alloc = allocator<T> > class vector; // generic template
			// template <class Alloc> class vector<bool,Alloc>;               // bool specialization

			
			
			private:
				size_type 		v_capacity;
				size_type 		v_size;
				pointer 		arr;
				allocator_type 	alloc;
	};
	// //NON MEMBER FUNCTIONS
	// template <class T, class Alloc>
	// void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
	// template <class T, class Alloc>
	// bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// {
	// 	if (rhs.size() == lhs.size())
	// 	{
	// 		for (size_t i = 0; i < lhs.size(); i++)
	// 		{
	// 			if (lhs.arr[i] != rhs.arr[i])
	// 				return false;
	// 		}
	// 	}
	// 	return true;
	// };
	// template <class T, class Alloc>
	// bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	// 	if (!(lhs == rhs))
	// 		return true;
	// 	return false;
	// };
	// template <class T, class Alloc>
	// bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	// 	if (lhs.size() < rhs.size())
	// 	{
	// 		for (size_t i = 0; i < lhs.size(); i++)
	// 		{
	// 			if (lhs.arr[i] < rhs.arr[i])
	// 				return false;
	// 		}
	// 	}
	// 	return true;
	// };
	// template <class T, class Alloc>
	// bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	// 	if (lhs.size() <= rhs.size())
	// 	{
	// 		for (size_t i = 0; i < lhs.size(); i++)
	// 		{
	// 			if (lhs.arr[i] <= rhs.arr[i])
	// 				return false;
	// 		}
	// 	}
	// 	return true;
	// };
	// template <class T, class Alloc>
	// bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	// 	if (lhs.size() > rhs.size())
	// 	{
	// 		for (size_t i = 0; i < lhs.size(); i++)
	// 		{
	// 			if (lhs.arr[i] > rhs.arr[i])
	// 				return false;
	// 		}
	// 	}
	// 	return true;
	// };
	// template <class T, class Alloc>
	// bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	// 	if (lhs.size() >= rhs.size())
	// 	{
	// 		for (size_t i = 0; i < lhs.size(); i++)
	// 		{
	// 			if (lhs.arr[i] >= rhs.arr[i])
	// 				return false;
	// 		}
	// 	}
	// 	return true;
	// };
}