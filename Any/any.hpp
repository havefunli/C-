#pragma once
#include <memory>
#include <utility>
#include <typeinfo>

class holder {
public:
    virtual ~holder() = default;  // 析构函数，确保正确释放内存
    virtual holder* clone() = 0;  // 用于复制
    virtual void* data() = 0;  // 用于访问存储的值
    virtual const std::type_info& type() = 0;  // 存储的值的类型
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
    Any() = default; // 无参的

    template <class T> // 这里需要模板函数接受任意类型
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


    ~Any() = default;  // 智能指针管理内存，方便了很多



private:
    std::unique_ptr<holder> _holder; // 使用智能指针便于内存管理
};