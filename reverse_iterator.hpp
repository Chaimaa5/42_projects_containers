#pragma once
#include <iostream>
#include "iterator.hpp"
#include "iterator_traits.hpp"

namespace ft{
	template <class iterator>
  	class reverse_iterator {
	public:
    typedef typename iterator_traits<iterator>::value_type        value_type;
    typedef typename iterator_traits<iterator>::difference_type   difference_type;
    typedef typename iterator_traits<iterator>::pointer 	        pointer;
    typedef typename iterator_traits<iterator>::reference         reference;
    typedef typename iterator_traits<iterator>::iterator_category iterator_category;
    //CONSTRUCTORS
    reverse_iterator():It(nullptr){};
    // initialization (2)	
    explicit reverse_iterator (iterator it):It(it){};
    // copy (3)	
    template <class iterator_type>  
    reverse_iterator (const reverse_iterator<iterator_type>& rev_it){
        *this = rev_it;
    };

    // iterator_type base() const;

    //OPERATORS
    reverse_iterator& operator=(const reverse_iterator & I){
        this->It = I.It;
        return (*this);
    };
    reference operator*() const{
        iterator tmp = It;
        return *--tmp;
    };
    pointer operator->() const{
        // return &(operator*());
        return It;
    };
    reverse_iterator operator+(difference_type n) const{
        return reverse_iterator(It - n);
    };
    reverse_iterator operator-(difference_type n) const{
        return reverse_iterator(It + n);
    };
    reverse_iterator & operator++() {
        It--;
        return (*this);
    };
    reverse_iterator & operator--() {
        It++;
        return (*this);
    };
    reverse_iterator operator++(int) {
        reverse_iterator tmp = *this;
        --(*this);
        return (tmp);
    };
    reverse_iterator operator--(int) {
        reverse_iterator tmp = *this;
        ++(*this);
        return (tmp);
    };
    reverse_iterator& operator+=(difference_type n) {
        It -= n;
        return (*this);
    };
    reverse_iterator& operator-=(difference_type n) {
        It += n;
        return (*this);
    };
    bool operator==(reverse_iterator rhs) const{
        if (rhs.It == It)
            return true;
        return false;
    };
    bool operator>(const reverse_iterator & rhs) const{
        if (It > rhs.It)
            return true;
        return false;
    };
    bool operator<(const reverse_iterator & rhs) const{
        if (It < rhs.It)
            return true;
        return false;
    };
    bool operator>=(const reverse_iterator & rhs) const{
        if (It >= rhs.It)
            return true;
        return false;
    };
    bool operator<=(const reverse_iterator & rhs) const{
        if (It <= rhs.It)
            return true;
        return false;
    };

		bool operator!=(reverse_iterator p) const{
			if (It != p.It)
				return true;
			return false;
		};		
	private:
		iterator It;
  };
//   template <class iterator>
//   reverse_iterator<iterator> operator-(const reverse_iterator<iterator>& it, typename reverse_iterator<iterator>::difference_type n) {
// 	it.It = it.It - n;
// 	return it;
//   };
//   template <class iterator>
//   reverse_iterator<iterator> operator+(const reverse_iterator<iterator>& it, typename reverse_iterator<iterator>::difference_type n) {
// 	it.It = it.It + n;
// 	return it;
//   };
//   template <class T>
// 	typename reverse_iterator<iterator>::difference_type operator-(const reverse_iterator<iterator>& a, const iterator<iterator>& b) {
// 	a.It -= b.It;
// 	return a;
//   };
}