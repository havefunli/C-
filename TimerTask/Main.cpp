#include "TimerWheel.hpp"

int main() 
{
	std::vector<int> array = { 1,2,3,4,5 };
	int index = 0;
	while (true)
	{
		std::cout << array[index] << " ";
		index = (index + 1) % array.size();

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}
