#include <iostream>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b, c;

    std::cout << "请输入三个数！" << std::endl;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    if (a < b) swap(&a, &b);
    if (a < c) swap(&a, &c);
    if (b < c) swap(&b, &c);

    std::cout << a << " " << b << " " << c << std::endl;

    return 0;
}