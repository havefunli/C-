#include <iostream>
#include <memory>


class TestA : public std::enable_shared_from_this<TestA>
{
public:
    TestA() = default;
    ~TestA()
    {
        std::cout << "~TestA" << std::endl;
    }

    std::shared_ptr<TestA> GetPtr()
    {
        return shared_from_this();
    }
};

int main()
{
    TestA t1;
    auto ptr1 = t1.GetPtr();
    return 0;
}