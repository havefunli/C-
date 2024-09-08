#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <windows.h>

void MyPrint(const std::string& s)
{
	std::cout << s << std::endl;
}


void func_1()
{
	std::thread t1([&]() {std::cout << "Hello, world!" << std::endl; });
	t1.detach();
}


void FuncPtr(std::shared_ptr<int> sp)
{
	for (size_t i = 0; i < 100; i++)
	{
		*sp += i;
	}

	std::cout << *sp << std::endl;
}

void FuncRef(int& n)
{
	for (size_t i = 0; i < 100; i++)
	{
		n += i;
	}

	std::cout << n << std::endl;
}

void func_2()
{
    // 值传递
    std::shared_ptr<int> sp(new int(0));
    std::thread t1(FuncPtr, sp); // 调用 std::shared_ptr<int> 版本
    t1.join();
    std::cout << *sp << std::endl;

    // 引用传递
    int Num = 0;
    std::thread t2(FuncRef, std::ref(Num)); // 调用 int& 版本
    t2.join();
    std::cout << Num << std::endl;
}


void Increment(int& begin, int end, std::mutex& mtx)
{
	std::unique_lock<std::mutex> lck; // 无参构造
	lck = std::unique_lock<std::mutex>(mtx); // 上锁

	for (int i = 0; i < end; i++)
	{
		begin++;
	}
	lck.unlock(); // 解锁
}


void func_3()
{
	int result = 0;
	std::mutex mtx;

	std::thread t1(Increment, std::ref(result), 10000, std::ref(mtx));
	std::thread t2(Increment, std::ref(result), 20000, std::ref(mtx));

	t1.join();
	t2.join();

	std::cout << "result = " << result << std::endl;
}



void func_4()
{
	int num = 0; // 自增数
	std::mutex mtx; // 锁
	std::condition_variable cv; // 条件变量
	bool RoundOfOne = true; // 判断打印轮次

	std::thread t1([&]()
		{
			while (num < 100)
			{
				std::unique_lock<std::mutex> lck(mtx);
				cv.wait(lck, [&]() { return RoundOfOne; });
				if (num == 100) break;
				num++;
				std::cout << "thread-one => " << num << std::endl;
				RoundOfOne = false;
				cv.notify_one(); // 唤醒线程
			}
		});

	std::thread t2([&]()
		{
			while (num < 100)
			{
				std::unique_lock<std::mutex> lck(mtx);
				cv.wait(lck, [&]() { return !RoundOfOne; });
				if (num > 100) break;
				num++;
				std::cout << "thread-two => " << num << std::endl;
				RoundOfOne = true;
				cv.notify_one(); // 唤醒线程
			}
		});

	t1.join();
	t2.join();
}


int main()
{
	// func_1();
	// func_2();
	// func_3();
	func_4();

	return 0;
}

