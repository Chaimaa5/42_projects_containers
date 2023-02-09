#include <iostream>
#include "vector.hpp"
namespace ft{

	template < bool condition , class T = void>
	struct EnableIf{
	};

	template <typename T>
	struct EnableIf <true, T>
	{
		typedef T type;
	};

	template <typename I>
	struct is_Integral {
		const static bool value = true;
	};
	template <>
	struct is_Integral<char> {
		const static bool value = false;
	};
	template <>
	struct is_Integral<signed char> {
		const static bool value = false;
	};
	template <>
	struct is_Integral<unsigned char > {
		const static bool value = false;
	};
	template <>
	struct is_Integral<int> {
		const static bool value = false;
	};
	template <>
	struct is_Integral<short int> {
		const static bool value = false;
	};
	template <>
	struct is_Integral<unsigned short int> {
		const static bool value = false;
	};
	template <>
	struct is_Integral<unsigned int> {
		const static bool value = false;
	};
	template <>
	struct is_Integral<long int> {
		const static bool value = false;
	};
	template <>
	struct is_Integral<unsigned long int> {
		const static bool value = false;
	};

}