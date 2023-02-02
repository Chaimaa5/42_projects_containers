namespace ft{
	template <class Iterator> 
	struct iterator_traits{
		typedef typename Iterator::value_type 			value_type;
   		typedef typename Iterator::difference_type		difference_type;
   		typedef typename Iterator::pointer 				pointer;
   		typedef typename Iterator::reference 			reference;
   		typedef typename Iterator::iterator_category	iterator_category;
	};
	template <class T> 
	class iterator_traits<T*>{
		typedef T value_type;
   		typedef ptrdiff_t difference_type;
   		typedef T* pointer;
   		typedef T& reference;
   		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class T> 
	class iterator_traits<const T*>{
		typedef T value_type;
   		typedef ptrdiff_t difference_type;
   		typedef const T* pointer;
   		typedef const T& reference;
   		typedef std::random_access_iterator_tag iterator_category;
	};
}



//  using iterator_concept  = contiguous_iterator_tag;
//     using iterator_category = random_access_iterator_tag;
//     using value_type        = remove_cv_t<T>;
//     using difference_type   = ptrdiff_t;
//     using pointer           = T*;
    // using reference         = T&;