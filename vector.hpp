#pragma once
#include <iostream>
#include <memory>
#include <exception>
#include <limits>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
namespace ft{
	template < class T, class Alloc = std::allocator<T> > 
	class vector{
		public:
			typedef T&							reference;
			typedef Alloc						allocator_type;
			typedef T& 							const_reference;
			typedef T* 							pointer;
			typedef const T*					const_pointer;
			typedef size_t 						size_type;
			typedef T							value_type;
			typedef ptrdiff_t					difference_type;
			typedef  ft::iterator<T> 				iterator;
			typedef  ft::reverse_iterator<iterator> 		reverse_iterator;
			typedef  ft::iterator<const T> 			const_iterator;
			typedef  ft::reverse_iterator<const iterator>   	const_reverse_iterator;
			// typedef typename iterator_traits<iterator>::difference_type difference_type;

			// CONSTRUCTORS
			explicit vector (const allocator_type& alloc = allocator_type()){
				this->alloc = alloc;
				this->arr = NULL;
				this->v_size = 0;
				this->v_capacity = 0;
			};
			// fill (2)	
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
				
				this->alloc = alloc;
				this->v_size = n;
				this->v_capacity = n;
				this->arr = this->alloc.allocate(v_capacity);
				for (size_type i = 0; i < n; i++)
					this->alloc.construct(&arr[i], val);
			};

			// range (3)	
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
				v_size = last - first;
				v_capacity = v_size;
				this->alloc = alloc;
				this->arr = this->alloc.allocate(v_capacity);
				for (size_type i = 0; i < v_size; i++)
					this->alloc.construct(&arr[i], first[i]);
			};

			// copy (4)	
			vector (const vector& x){
				*this = x;
			}


			//Assignment op
			vector& operator=(const vector& x){
				clear();
				if(arr)
					alloc.deallocate(arr, v_capacity);

				this->arr = alloc.allocate(x.v_capacity);
				for (size_t i = 0; i < x.v_size; i++)
					alloc.construct(&arr[i], x.arr[i]);
				alloc = x.alloc;
				this->v_capacity = x.v_capacity;
				this->v_size = x.v_size;
				return (*this);
			}
			//DESTRUCTOR
			~vector(){
				if (arr)
				{
					for (size_type i = 0; i < v_size; i++)
						alloc.destroy(&arr[i]);
					alloc.deallocate(arr, v_capacity);
				}
			};
			//ITERATORS
			iterator begin(){
				return arr;
			};
			iterator end(){
				return &arr[v_size];
			};
			const_iterator begin() const{
				return arr;
			};
			const_iterator end() const{
				return &arr[v_size];
			};
			reverse_iterator rbegin(){
				return reverse_iterator(&arr[v_size - 1]);
			};
			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(&arr[v_size - 1]);
			};
			reverse_iterator rend(){
				return reverse_iterator(arr);
			};
			const_reverse_iterator rend() const{
				return const_reverse_iterator(arr);
			};

			//v_capacity
			size_type size() const{
				return v_size;
			};
			size_type max_size() const{
				if (typeid(T) == typeid(unsigned char) || typeid(T) == typeid( char)) {
      				return 9223372036854775807;
    			} 
				else {
    			  return SIZE_MAX / sizeof(T);
    			}			
			};
			void resize (size_type n, value_type val = value_type())
			{
				size_type tmp_size = v_size;
				size_type capacity = v_capacity;
				if (n > v_capacity)
				{
					if (n < v_capacity * 2)
						v_capacity *= 2 ;
					else
						v_capacity = n;
					pointer tmp = alloc.allocate(v_capacity);
					for (size_t i = 0; i < v_size; i++)
						alloc.construct(&tmp[i], arr[i]);
					clear();
					if (arr)
						alloc.deallocate(arr, capacity);
					arr = alloc.allocate(v_capacity);
					for (size_type i = 0; i <  tmp_size; i++)
						alloc.construct(&arr[i], tmp[i]);
					for (size_type i = tmp_size; i < n; i++)
							alloc.construct(&arr[i], val);
					for (size_t i = 0; i < tmp_size; i++)
						alloc.destroy(&tmp[i]);
					alloc.deallocate(tmp, v_capacity);
				}
				else 
				{
					if (n < v_size)
						for (size_type i = n; i < v_size; i++)
							alloc.destroy(&arr[i]);	
					else
						for (size_type i = v_size; i < n; i++)
							alloc.construct(&arr[i], val);
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
					size_type capacity = v_capacity;
					size_type tmp_size = v_size;
					v_capacity = n;
					pointer tmp = alloc.allocate(v_capacity);
					for (size_t i = 0; i < v_size; i++)
						alloc.construct(&tmp[i], arr[i]);
					clear();
					if (arr)
						alloc.deallocate(arr, capacity);		
					arr = alloc.allocate(v_capacity);
					for (size_t i = 0; i < tmp_size; i++)
						alloc.construct(&arr[i], tmp[i]);
					v_size = tmp_size;
					for (size_t i = 0; i < tmp_size; i++)
						alloc.destroy(&tmp[i]);
					alloc.deallocate(tmp, v_capacity);
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
					throw (std::out_of_range("out of range"));
				return arr[n];
			};
			const_reference at (size_type n) const{
				if (n >= v_size || n < 0)
					throw (std::out_of_range("out of range"));
				return arr[n];
			};
			reference front(){
				return arr[0];
			};
			const_reference front() const{
				return arr[0];
			};
			reference back(){
				return arr[v_size - 1];
			};
			const_reference back() const{
				return arr[v_size - 1];
			};

			//MODIFIERS
			void push_back (const value_type& val){
				resize(v_size + 1, val);
			};
			void pop_back(){
				resize(v_size - 1);
			};
			void assign (size_type n, const value_type& val){
				if (n > 0){
					for (size_type i = 0; i < v_size; i++)
						alloc.destroy(&arr[i]);
					v_size = n;
					for (size_type i = 0; i < v_size; i++)
						alloc.construct(&arr[i], val);
				}
			};
			
			void clear(){
				for (size_type i = 0; i < v_size; i++)
					alloc.destroy(&arr[i]);
				v_size = 0;
			};

			//ALLOCATOR
			allocator_type get_allocator() const{
				return alloc;
			};


			pointer get_array() const{
				return arr;
			}
			// // Template specializations
			// template < class T, class Alloc = allocator<T> > class vector; // generic template
			// template <class Alloc> class vector<bool,Alloc>;               // bool specialization

		
			
			//MODIFIERS
			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last);
			
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


		

			private:
				size_type 		v_capacity;
				size_type 		v_size;
				pointer 		arr;
				allocator_type 	alloc;
	};
	// //NON MEMBER FUNCTIONS
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (rhs.size() == lhs.size())
		{
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (lhs.get_array()[i] != rhs.get_array()[i])
					return false;
			}
		}
		else
			return false;
		return true;
	};
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (!(lhs == rhs))
			return true;
		return false;
	};
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() < rhs.size())
		{
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (lhs.get_array()[i] < rhs.get_array()[i])
					return true;
			}
		}
		else
			return false;
		return true;
	};
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() <= rhs.size())
		{
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (lhs.get_array()[i] <= rhs.get_array()[i])
					return true; 
			}
		}
		else
			return false;
		return true;
	};
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		
		if (lhs.size() > rhs.size())
		{
			for (size_t i = 0; i < rhs.size(); i++)
			{
				if (lhs.get_array()[i] > rhs.get_array()[i])
					return true;
				else
					return false;
			}
		}
		else 
		return false;
	};
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() >= rhs.size())
		{
			for (size_t i = 0; i < rhs.size(); i++)
			{
				if (lhs.get_array()[i] >= rhs.get_array()[i])
					return true;
			}
		}
		else
			return false;
		return true;
	};
}