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
    typedef iterator iterator_type;
    //CONSTRUCTORS
    reverse_iterator():It(nullptr){};
    // initialization (2)	
    explicit reverse_iterator (iterator_type it):It(it){};
    // copy (3)	
    template <class Iter>
    reverse_iterator (const reverse_iterator<Iter>& rev_it){
        this->It = rev_it.base();
    };
    iterator_type base() const{
        return It;
    };

operator reverse_iterator<const iterator>(iterator) const {
         return reverse_iterator<const iterator>(It); };
    //OPERATORS
    reference operator*() const{        
        return *It;
    };
    pointer operator->() const{
        return (It.get_it());
        // return It;
    };
    reference operator[] (difference_type n) const{
        return It[n];
    };
    reverse_iterator operator+(difference_type n) const{
        return reverse_iterator(It + n);
    };
    reverse_iterator operator-(difference_type n) const{
        return reverse_iterator(It - n);
    };
    reverse_iterator & operator++() {
        It++;
        return (*this);
    };
    reverse_iterator & operator--() {
        It--;
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
        It = It - n;
        return (*this);
    };
    reverse_iterator& operator-=(difference_type n) {
        It = It + n;
        return (*this);
    };
    template <class R, class L>
    friend bool operator==(reverse_iterator<R>lhs,  reverse_iterator<L> rhs){
        if (lhs.It == rhs.It)
            return true;
        return false;
    };
    template <class R, class L>
    friend bool operator>(reverse_iterator<R>lhs,  reverse_iterator<L> rhs) {
         if (lhs.It.get_it() > rhs.It.get_it() )
            return true;
        return false;
    };
    template <class R, class L>
    friend bool operator<(reverse_iterator<R>lhs,  reverse_iterator<L> rhs) {
        if (lhs.It.get_it()  < rhs.It.get_it() )
            return true;
        return false;
    };
    template <class R, class L>
    friend bool operator>=(reverse_iterator<R> lhs,  reverse_iterator<L> rhs) {
        if (lhs.It.get_it()  >= rhs.It.get_it() )
            return true;
        return false;
    };
    template <class R, class L>
    friend bool operator<=(reverse_iterator<R>lhs,  reverse_iterator<L> rhs){
         if (lhs.It.get_it()  <= rhs.It.get_it() )
            return true;
        return false;
    };
template <class R, class L>
	friend bool operator!=(reverse_iterator<R>lhs,  reverse_iterator<L> rhs) {
		if (lhs.It.get_it()  != rhs.It.get_it() )
            return true;
        return false;
		};		
   
	private:
		iterator_type It;
  };
template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator- ( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
    return (lhs.base() - rhs.base());
};
    template <class Iterator>
  reverse_iterator<Iterator> operator+ ( typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it){
    return (rev_it + n);
  };
}