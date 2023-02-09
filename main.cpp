#include <iostream>
// #include <vector>
#include "vector.hpp"
using namespace std;

int main(void) {
   ft::vector<int> v1(5);

   /* assigned value to vector v1 */
   for (size_t i = 0; i < v1.size(); ++i)
      v1[i] = i + 1;

   /* create a range constructor v2 from v1 */
   ft::vector<int> v2(v1.begin(), v1.end());

   for (size_t i = 0; i < v2.size(); ++i)
      cout << v2[i] << endl;

   return 0;
}