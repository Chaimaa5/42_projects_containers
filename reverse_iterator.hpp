#pragma once
#include <iostream>

namespace ft{
	template <class T>
  	class iterator {
	public:
    	typedef T         value_type;
    typedef ptrdiff_t  difference_type;
    typedef T*   pointer;
    typedef T& reference;
    typedef std::random_access_iterator_tag  iterator_category;
    //OPERATORS
    iterator(): i_ptr(nullptr){};
    iterator(pointer ptr): i_ptr(ptr){};
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
    pointer operator->() const{
        return i_ptr;
    };
    iterator operator+(difference_type n) {
        return iterator(i_ptr - n);
    };
    iterator operator-(difference_type n) {
        return iterator(i_ptr + n);
    };
    iterator & operator++() {
        i_ptr--;
        return (*this);
    };
    iterator & operator--() {
        i_ptr++;
        return (*this);
    };
    iterator operator++(int) {
        iterator tmp = *this;
        --(*this);
        return (tmp);
    };
    iterator operator--(int) {
        iterator tmp = *this;
        ++(*this);
        return (tmp);
    };
    iterator& operator+=(difference_type n) {
        i_ptr -= n;
        return (*this);
    };
    iterator& operator-=(difference_type n) {
        i_ptr += n;
        return (*this);
    };
    bool operator==(iterator rhs) const{
        if (rhs.i_ptr == i_ptr)
            return true;
        return false;
    };
    bool operator>(const iterator & rhs) const{
        if (i_ptr > rhs.i_ptr)
            return true;
        return false;
    };
    bool operator<(const iterator & rhs) const{
        if (i_ptr < rhs.i_ptr)
            return true;
        return false;
    };
    bool operator>=(const iterator & rhs) const{
        if (i_ptr >= rhs.i_ptr)
            return true;
        return false;
    };
    bool operator<=(const iterator & rhs) const{
        if (i_ptr <= rhs.i_ptr)
            return true;
        return false;
    };
		bool operator<=(const iterator & rhs) const{
			if (i_ptr <= rhs.i_ptr)
				return true;
			return false;
		};
		bool operator!=(iterator p) const{
			if (i_ptr != p.i_ptr)
				return true;
			return false;
		};		
	private:
		pointer i_ptr;
  };
  template <class T>
  iterator<T> operator-(const iterator<T>& it, typename iterator<T>::difference_type n) {
	it.i_ptr = it.i_ptr - n;
	return this;
  };
  template <class T>
  iterator<T> operator+(const iterator<T>& it, typename iterator<T>::difference_type n) {
	it.i_ptr = it.i_ptr + n;
	return this;
  };
  template <class T>
	typename iterator<T>::difference_type operator-(const iterator<T>& a, const iterator<T>& b) {
	a.i_ptr = b.i_ptr;
	return this;
  };
}