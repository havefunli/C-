#include <iostream>
#include <thread>
#include <string>
#include <vector>

void Print(std::string msg) 
{
	std::cout << msg << std::endl;
}

class Foo
{
public:
	void one() { Print("one"); }
	void two() { Print("two"); }
	void three() { Print("three"); }
};

int main()
{
	int index = 1;
	Foo obj;

	std::thread td1 = std::thread(&Foo::one, &obj);
	td1.join();

	std::thread td2 = std::thread(&Foo::two, &obj);
	td2.join();

	std::thread td3 = std::thread(&Foo::three, &obj);
	td3.join();

	return 0;
}