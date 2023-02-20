#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterator.hpp"
#include <iterator>
#include <sstream>
#include <string>
using namespace std;

int main(void) {
     ft::Vector<char> v(1e7, 'a');
    //  v.insert();
  std::cout << v.capacity()<< std::endl;
}

