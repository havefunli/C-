#include <iostream>
#include <cstring> // for memcpy
#include <string>

using namespace std;

class Arr {
public:
    Arr()
        : _arr(new int[10]), _size(0) // ������������СΪ10
    {}

    ~Arr() {
        delete[] _arr;
    }

    // �������캯��
    Arr(const Arr& other)
        : _arr(new int[10]), _size(other._size) {
        memcpy(_arr, other._arr, other._size * sizeof(int)); // �����ڴ渴��
        cout << "Arr(const Arr& other)" << endl;
    }

    // �ƶ����캯��
    Arr(Arr&& other) noexcept
        : _arr(nullptr), _size(0) { // ��ʼ��Ϊ��ȫֵ
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
    process(arg); // ����ת��������������ֵ���
}

int main() {
    int A = 10;
    int B = 12;

    // ����ָ��
    const int *ptr1 = &A;
    (*ptr1) += 10;    // ��������Ϊָ���ֵ�ǳ���
    ptr1 = &B;        // ����

    // ָ�볣��
    int* const ptr2 = &A;;
    (*ptr2) += 10;    // ����
    ptr2 = &B;        // ��������Ϊָ���ǳ���


    return 0;
}

