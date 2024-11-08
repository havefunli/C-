#pragma once
#include <memory>
#include <utility>
#include <typeinfo>

class holder {
public:
    virtual ~holder() = default;  // ����������ȷ����ȷ�ͷ��ڴ�
    virtual holder* clone() = 0;  // ���ڸ���
    virtual void* data() = 0;  // ���ڷ��ʴ洢��ֵ
    virtual const std::type_info& type() = 0;  // �洢��ֵ������
};

template <typename T>
class placeholder : public holder {
public:
    placeholder(const T& value) 
        : _value(value)
    {}

    placeholder* clone() override 
    {
        return new placeholder(_value);
    }

    void* data() override 
    {
        return &_value;
    }

    const std::type_info& type()
    {
        return typeid(_value);
    }

private:
    T _value;
};


class Any
{
public:
    Any() = default; // �޲ε�

    template <class T> // ������Ҫģ�庯��������������
    Any(const T& val)
        : _holder(std::make_unique<placeholder<T>>(val))
    {}

    Any(const Any& other)
        : _holder(other._holder->clone())
    {}

    Any& operator=(Any other)
    {
        if (&other != this)
        {
            std::swap(other._holder, _holder);
            return *this;
        }
    }

    template <class T >
    T& any_cast() 
    {
        if (typeid(T) == _holder->type())
        {
            return *static_cast<T*>(_holder->data());
        }
        else
        {
            throw std::bad_cast();
        }
    }


    ~Any() = default;  // ����ָ������ڴ棬�����˺ܶ�



private:
    std::unique_ptr<holder> _holder; // ʹ������ָ������ڴ����
};