#pragma once
#include <iostream>
#include <memory>
#include <exception>
#include <limits>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
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
			typedef   ft::iterator<const T> 		const_iterator;
			typedef  ft::reverse_iterator<const_iterator>   	const_reverse_iterator;
			typedef  ft::reverse_iterator<iterator> 		reverse_iterator;

			// CONSTRUCTORS
			explicit vector (const allocator_type& alloc = allocator_type()){
				this->alloc = alloc;
				this->arr = NULL;
				this->v_size = 0;
				this->v_capacity = 0;
			}
			// fill (2)	
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):alloc(alloc){
				this->v_size = n;
				this->v_capacity = n;
				this->arr = this->alloc.allocate(n);
				for (size_type i = 0; i < v_size; i++)
					this->alloc.construct(&arr[i], val);
			}

			// range (3)	
			template <typename InputIterator>
			vector (InputIterator first, typename ft::EnableIf<ft::is_Integral<InputIterator>::value,InputIterator>::type last, const allocator_type& alloc = allocator_type()){
				if(ft::is_input_iterator<typename ft::iterator_traits<InputIterator>::iterator_category>::value)
				{
					// std::cout << "here"<<std::endl;
					v_size = 0;
					v_capacity = 0;
					this->alloc = alloc;
					this->arr = this->alloc.allocate(v_capacity);
					for (InputIterator it = first; it != last; it++)
						push_back(*it);
				}
				else{
					v_size = std::distance(first, last);
					v_capacity = v_size;
					this->alloc = alloc;
					this->arr = this->alloc.allocate(v_capacity);
					size_type i = 0;
					for (InputIterator it = first; it != last; it++)
					{
						this->alloc.construct(&arr[i], *it);
						i++;
					}
				}
			}

			// copy (4)	
			vector (const vector& x){
				this->arr = alloc.allocate(x.v_capacity);
				for (size_t i = 0; i < x.v_size; i++)
					alloc.construct(&arr[i], x.arr[i]);
				alloc = x.alloc;
				this->v_capacity = x.v_capacity;
				this->v_size = x.v_size;
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
			}
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
				return reverse_iterator(&arr[v_size]);
			};
			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(&arr[v_size]);
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
				if (n > max_size())
					throw(std::length_error("exception"));
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
				if (n < v_capacity){
					clear();
					v_size = n;
					for (size_type i = 0; i < v_size; i++)
						alloc.construct(&arr[i], val);
				}
				else {
					clear();
					if (arr)
						alloc.deallocate(arr, v_capacity);
					arr = alloc.allocate(n);
					v_size = n;
					v_capacity = n;
					for (size_type i = 0; i < v_size; i++)
						alloc.construct(&arr[i], val);
				}
			};
			
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last){
				ft::vector<T> tmp(first, last);
				clear();
				if (arr)
					alloc.deallocate(arr, v_capacity);
				v_capacity = tmp.capacity();
				v_size = tmp.size();
				arr = alloc.allocate(tmp.capacity());
				for (size_type i = 0; i < v_size; i++)
					alloc.construct(&arr[i], tmp[i]);
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
			
			//MODIFIERS
			
			// // // single element (1)	
			iterator insert (iterator position, const value_type& val){
				size_type res = 0;
				size_type tmp_size = v_size + 1;
				size_type tmp_capacity = v_capacity;
				pointer tmp = alloc.allocate(v_capacity);
				for (size_t i = 0; i < v_size; i++)
					tmp[i] = arr[i];
				iterator tmp_it = begin();
				if(v_capacity > tmp_size){
					v_size += 1;
					size_type i = 0;
					for (size_type r = 0; r < tmp_size - 1; r++)
						alloc.destroy(&arr[r]);
					for (size_type pos = 0 ; pos < v_size; pos++)
					{
						if (tmp_it + pos == position)
						{
							res =  pos;
							alloc.construct(&arr[pos], val);
						}
						else{
							alloc.construct(&arr[pos], tmp[i]);
							i++;
						}
					}
				}
				else{
					if(!v_capacity){
						arr = alloc.allocate(1);
						alloc.construct(&arr[0], val);
						v_capacity++;
						v_size++;
					}
					else{
						clear();
						if (arr)
							alloc.deallocate(arr, v_capacity);
						if(tmp_size < v_capacity * 2)
							v_capacity *= 2;
						else
							v_capacity += 1;
						arr = alloc.allocate(v_capacity);
						v_size = tmp_size;
						size_type i = 0;
						for (size_type pos = 0 ; pos < v_size; pos++)
						{
							if (tmp_it + pos == position)
							{
								alloc.construct(&arr[pos], val);
								res = pos;
							}
							else{
								alloc.construct(&arr[pos], tmp[i]);
								i++;
							}
						}
					}
				}
				alloc.deallocate(tmp, tmp_capacity);
				return (arr + res);
			}
			// // // fill (2)	
			void insert (iterator position, size_type n, const value_type& val){
				if (n > 0)
				{
					if (n > max_size())
						throw(std::length_error("exception"));
					size_type tmp_size = v_size;
					size_type tmp_capacity = v_capacity;
					pointer tmp = alloc.allocate(v_capacity);
					for (size_t i = 0; i < v_size; i++)
						tmp[i] = arr[i];
					iterator tmp_it = begin();
					if(v_capacity > v_size + n){
						v_size += n;
						size_type i = 0;
						for (size_type count = 0; count < tmp_size; count++)
							alloc.destroy(&arr[count]);
						for (size_type pos = 0 ; pos < v_size; pos++)
						{
							if (tmp_it + pos == position)
							{
								for (size_t count = pos; count < pos + n; count++)
									alloc.construct(&arr[count], val);
								pos = pos + n - 1;
							}
							else{
								alloc.construct(&arr[pos], tmp[i]);
								i++;
							}
						}
					}
					else{
						if(!v_capacity){
							arr = alloc.allocate(n);
							for (size_type i = 0; i < n; i++)	
								alloc.construct(&arr[i], val);
							v_capacity = n;
							v_size = n;
						}
						else{
							clear();
							if (arr)
								alloc.deallocate(arr, v_capacity);
							if(tmp_size + n < v_capacity * 2)
								v_capacity *= 2;
							else
								v_capacity += n;
							arr = alloc.allocate(v_capacity);
							v_size = tmp_size + n;
							size_type i = 0;
							for (size_type pos = 0 ; pos < v_size; pos++)
							{
								if (tmp_it + pos == position)
								{
									for (size_t count = pos; count < pos + n; count++)
										alloc.construct(&arr[count], val);
									pos = pos + n - 1;
								}
								else{
									alloc.construct(&arr[pos], tmp[i]);
									i++;
								}
							}
						}
					}
					alloc.deallocate(tmp, tmp_capacity);
				}
			}
			// // // range (3)	
			template <class InputIterator>
			void insert (iterator position, typename ft::EnableIf<ft::is_Integral<InputIterator>::value,InputIterator>::type first, InputIterator last){
					vector<T> v(first, last);
					size_type n = v.size();
					if (n > 0)
					{
						size_type tmp_size = v_size;
						size_type tmp_capacity = v_capacity;
						pointer tmp = alloc.allocate(v_capacity);
						for (size_t i = 0; i < v_size; i++)
							tmp[i] = arr[i];
						iterator tmp_it = begin();
						if(v_capacity > v_size + n){
							v_size += n;
							size_type i = 0;
							for (size_type count = 0; count < tmp_size; count++)
								alloc.destroy(&arr[count]);
							for (size_type pos = 0 ; pos < v_size; pos++)
							{
								if (tmp_it + pos == position)
								{
									size_type i = 0;
									for (size_t count = pos; count < pos + n; count++, i++)
										alloc.construct(&arr[count], v[i]);
									pos = pos + n - 1;
								}
								else{
									alloc.construct(&arr[pos], tmp[i]);
									i++;
								}
							}
						}
						else{
							if(!v_capacity && (position == begin() || position == end())){
								arr = alloc.allocate(n);
								for (size_type i = 0; i < n; i++)	
									alloc.construct(&arr[i],  v[i]);
								v_capacity = n;
								v_size = n;
							}
							else{
								clear();
								if (arr)
									alloc.deallocate(arr, v_capacity);
								if(tmp_size + n < v_capacity * 2)
									v_capacity *= 2;
								else
									v_capacity = (n + tmp_size);
								arr = alloc.allocate(v_capacity);
								v_size = tmp_size + n;
								size_type i = 0;
								for (size_type pos = 0 ; pos < v_size; pos++)
								{
									if (tmp_it + pos == position)
									{
										size_type i = 0;
										for (size_t count = pos; count < pos + n; count++, i++)
											alloc.construct(&arr[count],  v[i]);
										pos = pos + n - 1;
									}
									else{
										alloc.construct(&arr[pos], tmp[i]);
										i++;
									}
								}
							}
						}
						alloc.deallocate(tmp, tmp_capacity);
					}
			};

			iterator erase (iterator position){
                return erase(position, position + 1);
            };
            iterator erase (iterator first, iterator last){
                size_t diff =   std::distance(begin(), first);
                size_t len = std::distance(first, last);
                for(size_t i = len + diff; i < v_size; i++)
                    arr[diff++] = arr[i];
                while (len > 0){
                    pop_back();
                    len--;
                }
                return (first);
            };
			void swap (vector& x){
				pointer _arr;
				size_type _capacity;
				size_type _size;

				_arr = this->arr;
				_capacity = this->v_capacity;
				_size = this->v_size;

				arr = x.arr;
				v_capacity = x.v_capacity;
				v_size = x.v_size;

				x.arr = _arr;
				x.v_capacity = _capacity;
				x.v_size = _size;
			};


		

			private:
				size_type 		v_capacity;
				size_type 		v_size;
				pointer 		arr;
				allocator_type 	alloc;
	};
	// //NON MEMBER FUNCTIONS
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
		x.swap(y);
	};
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
			return true;
		if (lhs.size() <= rhs.size())
		{
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (lhs.get_array()[i] < rhs.get_array()[i])
					return true;
			}
		}
		return false;
	};
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() > rhs.size())
			return false;
		if (lhs.size() < rhs.size())
			return true;
		if (lhs.size() >= rhs.size())
		{
			for (size_t i = 0; i < rhs.size(); i++)
			{
				if (lhs.get_array()[i] > rhs.get_array()[i])
					return false;
			}
		}
		return true;
	};
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() > rhs.size())
			return true;
		if (lhs.size() >= rhs.size())
		{
			for (size_t i = 0; i < rhs.size(); i++)
			{
				if (lhs.get_array()[i] > rhs.get_array()[i])
					return true;
			}
		}
		return false;
	};
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() < rhs.size())
			return false;
		if (lhs.size() > rhs.size())
			return true;
		if (lhs.size() >= rhs.size())
		{
			for (size_t i = 0; i < rhs.size(); i++)
			{
				if (lhs.get_array()[i] < rhs.get_array()[i])
					return false;
			}
		}
		return true;
	};
}
