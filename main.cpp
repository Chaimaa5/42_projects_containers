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


// vector comparisons
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> foo (3,10);   // three ints with a value of 100
  std::vector<int> bar (2,100);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";


  return 0;
}