#include <memory>
#include <iostream>


int main()
{
	std::shared_ptr<int> sp = std::make_shared<int>(1);
	std::cout << sp << std::endl;

	int* ptr = nullptr;
	ptr = sp.get();
	(*ptr)++;
	std::cout << ptr << std::endl;

	return 0;
}