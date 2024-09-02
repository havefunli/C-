//#include <iostream>
//#include <vector>
//
//class T
//{
//public:
//	T(int A, int B)
//		: _A(A)
//		, _B(B)
//	{}
//
//	~T()
//	{
//		std::cout << "Destroy T" << std::endl;
//	}
//
//	int _A;
//	int _B;
//};
//
//
//int main()
//{
//	std::vector<T> v;
//
//	for (int i = 0; i < 3; ++i)
//	{
//		v.emplace_back(i, i + 1);
//	}
//
//	return 0;
//}


#include <queue>

int main()
{
	std::queue<int> queue;
	queue.pop();

	return 0;
}
