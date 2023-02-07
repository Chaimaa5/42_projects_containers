// // // #include <iostream>
// // // // #include <vector>
 
// // // #include <vector>

// // #include "vector.hpp"
// // // int main()
// // // {
// // //     ft::vector<int> vec;
// // // 	std::vector<int> vecc;


// // // 	vec.push_back(1);
// // // 	vec.push_back(2);
// // // 	vec.push_back(3);
// // // 	vec.push_back(4);
// // // 	vec.push_back(43);
// // // 	vec.resize(18);
// // // 	vec.push_back(4);
// // // 	// vec.resize(2);

// // // 	vecc.push_back(1);
// // // 	vecc.push_back(2);
// // // 	vecc.push_back(3);
// // // 	vecc.push_back(4);
// // // 	vecc.push_back(43);
// // // 	vecc.resize(18);
// // // 	vecc.push_back(4);
// // // 	// vecc.resize(2);
	
// // // 	int i = -1;
// // // 	while(++i < (int)vec.size())
// // // 		std::cout<<vec[i]<<"|";
// // // 	i = -1;
// // // 	while(++i < (int)vecc.size())
// // // 		std::cout<<vecc[i];

// // // 	std::cout<<"  "<<vec.size()<<"   "<< vec.capacity()<<std::endl;
// // // 	std::cout<<vecc.size()<<"   "<< vecc.capacity()<<std::endl;

// // //     // // 5 elements are inserted
// // //     // // in the vector
// // //     // vec.push_back(1);
// // //     // vec.push_back(2);
// // //     // vec.push_back(3);
// // //     // vec.push_back(4);
// // //     // vec.push_back(5);
// // // 	// cout << vec.size() << std::endl;
// // // 	// cout << vec.capacity()<< std::endl;
// // //     // cout << "Contents of vector before resizing:"
// // //     //      << endl;
 
// // //     // // displaying the contents of
// // //     // // the vector before resizing
// // //     // for (int i = 0; i < vec.size(); i++)
// // //     //     cout << vec[i] << " ";
 
// // //     // cout << endl;
// // //  	// cout << vec.size() << "   " << vec.capacity()<< endl;
// // //     // // vector is resized
// // //     // vec.resize(12);
// // // 	// // vec.push_back(4);
// // //     // // vec.push_back(5);
// // //     // cout << "Contents of vector after resizing:"<< endl;
     
// // //     // // displaying the contents
// // //     // // of the vector after resizing
// // //     // for (int i = 0; i < vec.size(); i++)
// // //     //     cout << vec[i] << " ";
// // //  	// cout << endl;
// // // 	// cout << vec.size() << "   " << vec.capacity()<< endl;
// // // 	// vec.resize(5);
// // // 	// cout << "Contents of vector after resizing:"<< endl;
// // // 	// for (int i = 0; i < vec.size(); i++)
// // //     //     cout << vec[i] << " ";
// // // 	// cout << endl;
// // //  	// cout << vec.size() << "   " << vec.capacity()<< endl;
// // // 	// vec.resize(4);
// // // 	// cout << "Contents of vector after resizing:"<< endl;
// // // 	// for (int i = 0; i < vec.size(); i++)
// // //     //     cout << vec[i] << " ";
// // // 	// cout << endl;
// // //  	// cout << vec.size() << "   " << vec.capacity()<< endl;
// // //     return 0;
// // // }


// // // // vector comparisons
// // // #include <iostream>
// // // #include <vector>

// // // int main ()
// // // {
  
// // //   // std::vector<int> foo (3,10);   // three ints with a value of 100
// // //   // std::vector<int> bar (2,100);   // two ints with a value of 200
// // //   // foo.reserve(300);
// // //   // std::cout << foo.capacity() <<"    " << *foo.end() << std::endl;
// // //   // if (foo==bar) std::cout << "foo and bar are equal\n";
// // //   // if (foo!=bar) std::cout << "foo and bar are not equal\n";
// // //   // if (foo< bar) std::cout << "foo is less than bar\n";
// // //   // if (foo> bar) std::cout << "foo is greater than bar\n";
// // //   // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
// // //   // if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

// // //   ft::vector<double> fooo(3,100);
// // //   fooo.resize(100);   // three ints with a value of 100
// // //   // for (int i = 0; i < 26; ++i) {
// // //   //           fooo.push_back(45.0123);
// // //   //           // CHECK_AND_PRINT_ALL(v);
// // //   //       }
// // //   //       for (int i = 0; i < 26; ++i) {
// // //   //          std::cout <<  fooo[i] << std::endl;
// // //   //           // CHECK_AND_PRINT_ALL(v);
// // //   //       }
// // //         system("Leaks containers");
// // //   // ft::vector<int> baar (2,100);   // two ints with a value of 200
// // //   // fooo.reserve(300);
// // //   // std::cout << fooo.capacity() <<"    " << *fooo.end() << std::endl;
// // //   // if (fooo==baar) std::cout << "foo and bar are equal\n";
// // //   // if (fooo!=baar) std::cout << "foo and bar are not equal\n";
// // //   // if (fooo< baar) std::cout << "foo is less than bar\n";
// // //   // if (fooo> baar) std::cout << "foo is greater than bar\n";
// // //   // if (fooo<=baar) std::cout << "foo is less than or equal to bar\n";
// // //   // if (fooo>=baar) std::cout << "foo is greater than or equal to bar\n";

// // //   return 0;
// // // }


// // #include<iostream>
// // #include<iterator> // for iterators
// // #include<vector> // for vectors
// // // using namespace std;
// // int main()
// // {
// //     ft::vector<int> ar(2);
// //       ar.push_back(45);
// //     // Declaring iterator to a vector
// //     ft::vector<int>::reverse_iterator ptr;
      
// //     // Displaying vector elements using begin() and end()
// //     // std::cout << "The vector elements are : ";
// //     // for (ptr = ar.begin(); ptr < ar.end(); ptr++)
// //     //     std::cout << *ptr << " ";
// //     // ptr--;
// // 	// ptr+=1;
// // 	std::cout <<std::endl << *ptr << " ";
// // // 
// // 	//  std::vector<int> arr(2, 100);
// //     //   arr.push_back(45);
// //     // // Declaring iterator to a vector
// //     // std::vector<int>::iterator ptrr;
      
// //     // // Displaying vector elements using begin() and end()
// //     // std::cout << "The vector elements are : ";
// //     // for (ptrr = arr.begin(); ptrr < arr.end(); ptrr++)
// //     //     std::cout << *ptrr << " ";
// //     // ptrr -=2;
// // 	// ptrr+=1;
// // 	// std::cout <<std::endl << *ptrr << " ";
// //     // {

// //     //    ft::vector<long> v1(5, 64);
// //     //     ft::vector<long> v2(5, 48);

// //     //     if (v1 > v2) {
// //     //         std::cout << "Less than or equal...";
// //     //     }
// //     // }
// // // {

// // //     std::vector<long> v1(5, 64);
// // //     std::vector<long> v2;
// // //     if (v1 >= v2) {
// // //                 std::cout <<"Equal.." <<std::endl;
// // //             }
// // // }
// // // {

// // //     std::vector<long> v1;
// // //     std::vector<long> v2(5, 32);
// // //     if (v1 >= v2) {
// // //                 std::cout <<"Equal..." <<std::endl;
// // //             }
// // // }
// // // {

// // //     std::vector<long> v1(5, 64);
// // //     std::vector<long> v2(5, 48);
// // //     if (v1 >= v2) {
// // //                 std::cout <<"Equal...." <<std::endl;
// // //             }
// // // }
// // // {
// // //     std::vector<long> v1(5, 64);
// // //     std::vector<long> v2(5, 64);
// // // if (v1 >= v2) {
// // //                 std::cout <<"Equal....." <<std::endl;
// // //             }
// // // }
// //     return 0;    
// // }


// #include <iterator> 
// #include <vector> 
// #include <iostream>     // std::cout
// #include "iterator.hpp"    // std::reverse_iterator
// #include "reverse_iterator.hpp"       // std::vector
// #include "vector.hpp"
// int main () {
//   // ft::vector<int> myvector;
//   // for (int i=0; i<10; i++) 
//   //   myvector.push_back(i);

//   // typedef ft::vector<int>::iterator iter_type;

//   //  ft::reverse_iterator<iter_type> rev_end(myvector.rbegin());
//   // //  ft::reverse_iterator<iter_type> rev_begin (myvector.end());
//   // //  std::vector<int>::const_reverse_iterator const_rev(myvector.begin());
//   // // rev_end += 1;
//   // // std::cout << "myvector:";
//   // // iter_type it = rev_end.base();
//   // //  iter_type it2 = rev_begin.base();
//   // // if (rev_end != rev_begin)
//   //   std::cout << ' ' << *rev_end;
//   //   // std::cout << ' ' << *it2;
//   // std::cout << '\n';
// {
//   // ft::vector<int> myvector;
//   // for (int i=0; i<10; i++) 
//   //   myvector.push_back(i);

//   // typedef std::vector<int>::iterator iter_type;

//   //  ft::vector<int>::reverse_iterator rev_end(myvector.rbegin());
//   //  ft::vector<int>::reverse_iterator rev_begin (myvector.end());
//   //  rev_begin =rev_end;
//   //  std::vector<int>::const_reverse_iterator const_rev(myvector.begin());
//   // rev_end += 1;
//   // std::cout << "myvector:";
//   // iter_type it = rev_end.base();
//   //  iter_type it2 = rev_begin.base();
//   // if (rev_end != rev_begin)
//     // std::cout << ' ' << *rev_end;
//     // std::cout << ' ' << *it2;

//     ft::vector<int>a;
//     a.push_back(5);
//     a.push_back(6);
//     a.push_back(8);
//     a.push_back(9);
//     a.push_back(7);
//     ft::vector<int>::reverse_iterator it = a.rend();
//     // ft::vector<int>::reverse_iterator it2 = a.rbegin();
//     it -= 2;
//     --it;
//     std::cout<<*it;

//   std::cout << '\n';
// }
//   return 0;
// }

#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector
#include "iterator.hpp"    // std::reverse_iterator
// // // #include <vector> 
#include "reverse_iterator.hpp"       // std::vector
#include "vector.hpp"
int main () {
  ft::vector<int>a;
  a.push_back(4);
  a.push_back(14);
  a.push_back(41);
  a.push_back(411);
  ft::vector<int>::reverse_iterator i = a.rbegin();
  i--;
  i--;

  std::cout<<*i<<std::endl;
  {
      std::vector<int>a;
  a.push_back(4);
  a.push_back(14);
  a.push_back(41);
  a.push_back(411);
  std::vector<int>::reverse_iterator i = a.rbegin();
  i--;
  i--;
  std::cout<<*i<<std::endl;
  }

  return 0;
}
// // int main () {
// //   ft::vector<int> myvector;
// //   for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

// //   typedef ft::vector<int>::iterator iter_type;
// //   ft::reverse_iterator<iter_type> rev(myvector.rend());
// //   ft::reverse_iterator<iter_type> rev_it;

// //   // rev = rev_it;

// //   std::cout << "The fourth element from the end is: " << *rev << '\n';

// //   return 0;
// // }