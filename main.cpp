// #include <iostream>
// // #include <vector>
 
// #include <vector>

#include "vector.hpp"
// int main()
// {
//     ft::vector<int> vec;
// 	std::vector<int> vecc;


// 	vec.push_back(1);
// 	vec.push_back(2);
// 	vec.push_back(3);
// 	vec.push_back(4);
// 	vec.push_back(43);
// 	vec.resize(18);
// 	vec.push_back(4);
// 	// vec.resize(2);

// 	vecc.push_back(1);
// 	vecc.push_back(2);
// 	vecc.push_back(3);
// 	vecc.push_back(4);
// 	vecc.push_back(43);
// 	vecc.resize(18);
// 	vecc.push_back(4);
// 	// vecc.resize(2);
	
// 	int i = -1;
// 	while(++i < (int)vec.size())
// 		std::cout<<vec[i]<<"|";
// 	i = -1;
// 	while(++i < (int)vecc.size())
// 		std::cout<<vecc[i];

// 	std::cout<<"  "<<vec.size()<<"   "<< vec.capacity()<<std::endl;
// 	std::cout<<vecc.size()<<"   "<< vecc.capacity()<<std::endl;

//     // // 5 elements are inserted
//     // // in the vector
//     // vec.push_back(1);
//     // vec.push_back(2);
//     // vec.push_back(3);
//     // vec.push_back(4);
//     // vec.push_back(5);
// 	// cout << vec.size() << std::endl;
// 	// cout << vec.capacity()<< std::endl;
//     // cout << "Contents of vector before resizing:"
//     //      << endl;
 
//     // // displaying the contents of
//     // // the vector before resizing
//     // for (int i = 0; i < vec.size(); i++)
//     //     cout << vec[i] << " ";
 
//     // cout << endl;
//  	// cout << vec.size() << "   " << vec.capacity()<< endl;
//     // // vector is resized
//     // vec.resize(12);
// 	// // vec.push_back(4);
//     // // vec.push_back(5);
//     // cout << "Contents of vector after resizing:"<< endl;
     
//     // // displaying the contents
//     // // of the vector after resizing
//     // for (int i = 0; i < vec.size(); i++)
//     //     cout << vec[i] << " ";
//  	// cout << endl;
// 	// cout << vec.size() << "   " << vec.capacity()<< endl;
// 	// vec.resize(5);
// 	// cout << "Contents of vector after resizing:"<< endl;
// 	// for (int i = 0; i < vec.size(); i++)
//     //     cout << vec[i] << " ";
// 	// cout << endl;
//  	// cout << vec.size() << "   " << vec.capacity()<< endl;
// 	// vec.resize(4);
// 	// cout << "Contents of vector after resizing:"<< endl;
// 	// for (int i = 0; i < vec.size(); i++)
//     //     cout << vec[i] << " ";
// 	// cout << endl;
//  	// cout << vec.size() << "   " << vec.capacity()<< endl;
//     return 0;
// }


// // vector comparisons
// #include <iostream>
// #include <vector>

// int main ()
// {
  
//   // std::vector<int> foo (3,10);   // three ints with a value of 100
//   // std::vector<int> bar (2,100);   // two ints with a value of 200
//   // foo.reserve(300);
//   // std::cout << foo.capacity() <<"    " << *foo.end() << std::endl;
//   // if (foo==bar) std::cout << "foo and bar are equal\n";
//   // if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   // if (foo< bar) std::cout << "foo is less than bar\n";
//   // if (foo> bar) std::cout << "foo is greater than bar\n";
//   // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   // if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

//   ft::vector<double> fooo(3,100);
//   fooo.resize(100);   // three ints with a value of 100
//   // for (int i = 0; i < 26; ++i) {
//   //           fooo.push_back(45.0123);
//   //           // CHECK_AND_PRINT_ALL(v);
//   //       }
//   //       for (int i = 0; i < 26; ++i) {
//   //          std::cout <<  fooo[i] << std::endl;
//   //           // CHECK_AND_PRINT_ALL(v);
//   //       }
//         system("Leaks containers");
//   // ft::vector<int> baar (2,100);   // two ints with a value of 200
//   // fooo.reserve(300);
//   // std::cout << fooo.capacity() <<"    " << *fooo.end() << std::endl;
//   // if (fooo==baar) std::cout << "foo and bar are equal\n";
//   // if (fooo!=baar) std::cout << "foo and bar are not equal\n";
//   // if (fooo< baar) std::cout << "foo is less than bar\n";
//   // if (fooo> baar) std::cout << "foo is greater than bar\n";
//   // if (fooo<=baar) std::cout << "foo is less than or equal to bar\n";
//   // if (fooo>=baar) std::cout << "foo is greater than or equal to bar\n";

//   return 0;
// }


#include<iostream>
#include<iterator> // for iterators
#include<vector> // for vectors
// using namespace std;
int main()
{
    // ft::vector<int> ar(2, 100);
    //   ar.push_back(45);
    // // Declaring iterator to a vector
    // ft::vector<int>::reverse_iterator ptr;
      
    // // Displaying vector elements using begin() and end()
    // std::cout << "The vector elements are : ";
    // // for (ptr = ar.begin(); ptr < ar.end(); ptr++)
    // //     std::cout << *ptr << " ";
    // ptr--;
	// // ptr+=1;
	// std::cout <<std::endl << *ptr << " ";

	//  std::vector<int> arr(2, 100);
    //   arr.push_back(45);
    // // Declaring iterator to a vector
    // std::vector<int>::iterator ptrr;
      
    // // Displaying vector elements using begin() and end()
    // std::cout << "The vector elements are : ";
    // for (ptrr = arr.begin(); ptrr < arr.end(); ptrr++)
    //     std::cout << *ptrr << " ";
    // ptrr -=2;
	// ptrr+=1;
	// std::cout <<std::endl << *ptrr << " ";
    {

       std::vector<long> v1(5, 64);
        std::vector<long> v2(5, 48);

        if (v1 <= v2) {
            std::cout << "Less than or equal...";
        }
    }
// {

//     std::vector<long> v1(5, 64);
//     std::vector<long> v2;
//     if (v1 >= v2) {
//                 std::cout <<"Equal.." <<std::endl;
//             }
// }
// {

//     std::vector<long> v1;
//     std::vector<long> v2(5, 32);
//     if (v1 >= v2) {
//                 std::cout <<"Equal..." <<std::endl;
//             }
// }
// {

//     std::vector<long> v1(5, 64);
//     std::vector<long> v2(5, 48);
//     if (v1 >= v2) {
//                 std::cout <<"Equal...." <<std::endl;
//             }
// }
// {
//     std::vector<long> v1(5, 64);
//     std::vector<long> v2(5, 64);
// if (v1 >= v2) {
//                 std::cout <<"Equal....." <<std::endl;
//             }
// }
    return 0;    
}