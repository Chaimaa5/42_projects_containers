#pragma once
#include <iostream>

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
		iterator(pointer ptr){
			
			i_ptr = ptr;
		};
		iterator(const iterator & I){
			*this = I;
		};
		iterator& operator=(const iterator & I){
			this->i_ptr = I.i_ptr;
			return (*this);
		};
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
		// iterator operator+=(int n){
		// 	i_ptr += n;
			
		// };
		// iterator operator-=(int n){
		// 	i_ptr -= n;
		// };
		// bool operator==(const iterator & rhs){
			
		// };
		// bool operator>(const iterator & rhs){
			
		// };
		// iterator operator<(const iterator & rhs){
			
		// };
		// bool operator>=(const iterator & rhs){
			
		// };
		// bool operator<=(const iterator & rhs){
			
		// };
		// bool operator!=(const iterator & rhs){
			
		// };		
	private:
		pointer i_ptr;
  };
}