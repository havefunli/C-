#include "any.hpp"
#include <string>
#include <iostream>

int main()
{
	Any A = 1;
	Any B = std::string("ABCD");

	std::cout << A.any_cast<int>() << std::endl;

	return 0;
}