#pragma once
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include <iostream>

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
    explicit reverse_iterator (iterator_type it){     
        It = it;
};
    // copy (3)	
    template <class Iter>
    reverse_iterator (const reverse_iterator<Iter>& rev_it){
        It  =  rev_it.base();
    };
    iterator_type base() const{
        return It;
    };
    operator reverse_iterator<const iterator>() const {
        return reverse_iterator<const iterator>(this->It); };

    //OPERATORS
    reference operator*() const{    
        iterator tmp = It;    
        return *--tmp;
    };
    pointer operator->() const{
        return (&operator*());
    };
    reference operator[] (difference_type n) const{
        return *(It - n - 1);
    };
    reverse_iterator operator+(difference_type n) const{
         
        return reverse_iterator(It - n);
    };
    reverse_iterator operator-(difference_type n) const{
        return reverse_iterator(It + n);
    };
    reverse_iterator & operator++() {
        --It;
        return (*this);
    };
    reverse_iterator & operator--() {
        ++It;
        return (*this);
    };
    reverse_iterator operator++(int) {
        reverse_iterator tmp = *this;
        --It;
        return (tmp);
    };
    reverse_iterator operator--(int) {
        reverse_iterator tmp = *this;
        ++It;
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
    template <class R>
    reverse_iterator<R>  operator=(const reverse_iterator<R> &lhs){
        this->It = lhs.base();
        return (*this);
    };
    template <class R, class L>
    friend bool operator==(const reverse_iterator<R> &lhs,  const reverse_iterator<L> &rhs){
        return  (lhs.base() == rhs.base());
    };
    template <class R, class L>
    friend bool operator>(const reverse_iterator<R> &lhs,  const reverse_iterator<L> &rhs) {
         if (lhs.base() < rhs.base() )
            return true;
        return false;
    };
    template <class R, class L>
    friend bool operator<(const reverse_iterator<R> &lhs,  const reverse_iterator<L> &rhs) {
        if (lhs.base()  > rhs.base())
            return true;
        return false;
    };
    template <class R, class L>
    friend bool operator>=(const reverse_iterator<R> &lhs,  const reverse_iterator<L> &rhs) {
        if (lhs.base()  <= rhs.base() )
            return true;
        return false;
    };
    template <class R, class L>
    friend bool operator<=(const reverse_iterator<R> &lhs,  const reverse_iterator<L> &rhs){
         if (lhs.base()  >= rhs.base() )
            return true;
        return false;
    };
    template <class R, class L>
	friend bool operator!=(const reverse_iterator<R> &lhs,  const reverse_iterator<L> &rhs) {
		if (lhs.base() == rhs.base())
            return false;
        return true;
		};	
   
	private:
		iterator_type It;
  };
    template <class It>
    typename reverse_iterator<It>::difference_type operator-( const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs){
        return (rhs.base() - lhs.base());
    };
    template <class sa>
    reverse_iterator<sa> operator+( typename reverse_iterator<sa>::difference_type n, const reverse_iterator<sa>& rev_it){
        return reverse_iterator <sa>(rev_it + n);
    };
   
}