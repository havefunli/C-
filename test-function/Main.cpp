#include <iostream>
#include <functional>
#include <string>

class Func;

// 任务类型，接受 Func* 类型的参数
using Task = std::function<void(Func*)>;

// Func 类定义
class Func
{
public:
    Func(int num)
        : _val(num)
    {}

    void SetTask(Task task)
    {
        _task = task;
    }

    void Dowork()
    {
        _task(this);  // 执行任务并传递当前对象的指针
    }

    int GetVal()
    {
        return _val;
    }

private:
    int _val;
    Task _task;
};

// 一个简单的任务函数
void PrintVal(Func* f)
{
    std::cout << "Func's value is: " << f->GetVal() << std::endl;
}

int main() {
    //Func* f = new Func(42);

    //f->SetTask(PrintVal);

    //f->Dowork(); 

    //auto task = std::bind(&Func::Dowork, f);

    //delete f;

    //task();

    //return 0;

    std::string str;
    str.reserve(10);
    std::cout << str.size() << std::endl;
    std::cout << str << std::endl;

    std::string st;
    st.resize(10);
    std::cout << st.size() << std::endl;
    std::cout << st << std::endl;
}
