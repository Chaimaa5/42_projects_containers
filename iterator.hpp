#pragma once
#include <iostream>
namespace ft{
	template <class T>
  	class iterator {
	public:
    typedef T           value_type;
    typedef ptrdiff_t   difference_type;
    typedef T*          pointer;
    typedef T&          reference;
    typedef std::random_access_iterator_tag  iterator_category;
    //OPERATORS

    iterator():i_ptr(nullptr){};
    iterator(pointer ptr): i_ptr(ptr){};
 
    template <class type>  
    iterator (const iterator<type>& it){
        *this = it;
    };

    pointer get_it() const{
        return i_ptr;
    }
    // iterator& operator=(const iterator & I){
    //     this->i_ptr = I.i_ptr;
    //     return (*this);
    // };

    reference operator*() const{
        return *i_ptr;
    };
    operator iterator<const value_type>() const {
         return iterator<const value_type>(i_ptr); };
    reference operator[] (difference_type n) const{
        return i_ptr[n];
    };
    pointer operator->() const{
        return i_ptr;
    };
    iterator operator+(difference_type n) const{
        return iterator(i_ptr + n);
    };
    iterator operator-(difference_type n) const{
        return iterator(i_ptr - n);
    };

    friend difference_type operator-(iterator<T> lhs, iterator<T> rhs){
        difference_type i = 0;
        while (rhs != lhs){
            rhs++;
            i++;}
        return (i);
    };
    iterator & operator++() {
        i_ptr++;
        return (*this);
    };
    iterator & operator--() {
        i_ptr--;
        return (*this);
    };
    iterator operator++(int) {
        iterator tmp = *this;
        ++(*this);
        return (tmp);
    };
    iterator operator--(int) {
        iterator tmp = *this;
        --(*this);
        return (tmp);
    };
    iterator& operator+=(difference_type n) {
        i_ptr += n;
        return (*this);
    };
    iterator& operator-=(difference_type n) {
        i_ptr -= n;
        return (*this);
    };
    template <class R, class L>
    friend bool operator==( iterator<R>lhs,  iterator<L> rhs){
        if (lhs.get_it() == rhs.get_it())
            return true;
        return false;
    };
    template <class R, class L>
    friend bool operator>(iterator<R>lhs,  iterator<L> rhs) {
        if (lhs.get_it() > rhs.get_it())
            return true;
        return false;
    };
    template <class R, class L>
    friend bool operator<(iterator<R>lhs,  iterator<L> rhs) {
        if (lhs.get_it() < rhs.i_ptr)
            return true;
        return false;
    };
    template <class R, class L>
    friend bool operator>=(iterator<R> lhs,  iterator<L> rhs) {
        if (lhs.get_it() >= rhs.get_it())
            return true;
        return false;
    };
    template <class R, class L>
    friend bool operator<=(iterator<R>lhs,  iterator<L> rhs){
        if (lhs.get_it() <= rhs.get_it())
            return true;
        return false;
    };
template <class R, class L>
	friend bool operator!=(iterator<R>lhs,  iterator<L> rhs) {
			if (lhs.get_it() != rhs.get_it())
				return true;
			return false;
		};		
	private:
		pointer i_ptr;
  };

//   template <class T>
//   iterator<T> operator-(typename iterator<T>::difference_type n, const iterator<T>& it) {
// 	return iterator<T>(it - n);
//   };
//   template <class T>
//   iterator<T> operator+(typename iterator<T>::difference_type n, const iterator<T>& it) {
// 		return iterator<T>(it + n);

  };
