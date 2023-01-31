#pragma once
#include <iostream>
#include <memory>

namespace ft{
	template < class T, class Alloc = allocator<T> > class vector{
		public:
			typedef typename allocator_type::reference	reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename size_t size_type;
			typedef typename ft::vector<T>::iterator iterator;
			typedef typename iterator_traits<iterator>::difference_type difference_type;

			// CONSTRUCTORS
			explicit vector (const allocator_type& alloc = allocator_type());
			// fill (2)	
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			// range (3)	
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			// copy (4)	
			vector (const vector& x){
				this = x;
			}
			//Assignment op
			vector& operator=(const vector& x){
				//op
				return (*this);
			}

			//ITERATORS
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;

			//CAPACITY
			size_type size() const;
			size_type max_size() const;
			void resize (size_type n, value_type val = value_type());
			size_type capacity() const;
			bool empty() const;
			void reserve (size_type n);

			//ACCESS ELEMENTS
			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;
			reference at (size_type n);
			const_reference at (size_type n) const;
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;

			//MODIFIERS
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last);
			void assign (size_type n, const value_type& val);
			void pop_back();
			// single element (1)	
			iterator insert (iterator position, const value_type& val);
			// fill (2)	
			void insert (iterator position, size_type n, const value_type& val);
			// range (3)	
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last);
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void swap (vector& x);
			void clear();

			//ALLOCATOR
			allocator_type get_allocator() const;

			// Template specializations
			template < class T, class Alloc = allocator<T> > class vector; // generic template
			template <class Alloc> class vector<bool,Alloc>;               // bool specialization


			//NON MEMBER FUNCTIONS

			template <class T, class Alloc>
			void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
			template <class T, class Alloc>
			bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			template <class T, class Alloc>
			bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			template <class T, class Alloc>
			bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			template <class T, class Alloc>
			bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			template <class T, class Alloc>
			bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			template <class T, class Alloc>
			bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	};
}