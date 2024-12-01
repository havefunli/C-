#include <iostream>
#include <functional>
#include <string>

class Func;

// �������ͣ����� Func* ���͵Ĳ���
using Task = std::function<void(Func*)>;

// Func �ඨ��
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
        _task(this);  // ִ�����񲢴��ݵ�ǰ�����ָ��
    }

    int GetVal()
    {
        return _val;
    }

private:
    int _val;
    Task _task;
};

// һ���򵥵�������
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
