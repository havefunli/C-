#include <iostream>
#include <cstring> // for memcpy
#include <string>

using namespace std;

class Arr {
public:
    Arr()
        : _arr(new int[10]), _size(0) // 修正数组分配大小为10
    {}

    ~Arr() {
        delete[] _arr;
    }

    // 拷贝构造函数
    Arr(const Arr& other)
        : _arr(new int[10]), _size(other._size) {
        memcpy(_arr, other._arr, other._size * sizeof(int)); // 修正内存复制
        cout << "Arr(const Arr& other)" << endl;
    }

    // 移动构造函数
    Arr(Arr&& other) noexcept
        : _arr(nullptr), _size(0) { // 初始化为安全值
        std::swap(_arr, other._arr);
        std::swap(_size, other._size);
        cout << "Arr(Arr&& other)" << endl;
    }

    int* _arr;
    int _size;
};


#include <iostream>
#include <utility>

void process(int& x) { std::cout << "Lvalue reference: " << x << '\n'; }
void process(int&& x) { std::cout << "Rvalue reference: " << x << '\n'; }

template <typename T>
void wrapper(int&& arg) {
    process(arg); // 完美转发，保留参数的值类别
}

int main() {
    int A = 10;
    int B = 12;

    // 常量指针
    const int *ptr1 = &A;
    (*ptr1) += 10;    // 不允许，因为指向的值是常量
    ptr1 = &B;        // 允许

    // 指针常量
    int* const ptr2 = &A;;
    (*ptr2) += 10;    // 允许
    ptr2 = &B;        // 不允许，因为指针是常量


    return 0;
}

