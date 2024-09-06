#pragma once

#include <iostream>
#include <atomic>
#include <stdio.h>
#include <functional>

// 该智能指针还存在缺陷
// 当传入的对象是 T[] 时，删除操作存在问题

namespace MyPtr
{
	template <class T>
	class SharedPtr
	{
	private:
		// 当计数置 0 时调用
		void destructor()
		{
			_Del(_Ptr);
			_Ptr = nullptr;
			delete _RefCounts;
			_RefCounts = nullptr;
		}

	public:
		// 构造函数(默认删除器)
		SharedPtr(T* Ptr)
			: _Ptr(Ptr)
			, _RefCounts(new std::atomic<int>(1))
			, _Del([](T* val) {delete val; })
		{}

		// 构造函数(自定义删除器)
		template<class D>
		SharedPtr(T* Ptr, D Del)
			: _Ptr(Ptr)
			, _RefCounts(new std::atomic<int>(1))
			, _Del(Del)
		{}

		// 拷贝构造
		SharedPtr(const SharedPtr<T>& sp)
			: _Ptr(sp._Ptr)
			, _RefCounts(sp._RefCounts)
			, _Del(sp._Del)
		{
			++(*_RefCounts);
		}


		T& operator* ()
		{
			return *_Ptr;
		}

		T* operator->()
		{
			return _Ptr;
		}

		void clear()
		{
			// 引用减少
			--(*_RefCounts);
			if (*_RefCounts == 0)
			{
				destructor();
			}
		}

		SharedPtr<T>& operator=(const SharedPtr<T>& sp)
		{
			if (this != &sp) // 防止自我赋值
			{
				clear(); // 释放当前资源

				_Ptr = sp._Ptr;
				_RefCounts = sp._RefCounts;
				_Del = sp._Del; // 复制删除器
				++(*_RefCounts);
			}
			return *this;
		}

		int use_count()
		{
			return *_RefCounts;
		}

		// 析构函数
		~SharedPtr()
		{
			// 引用减少
			--(*_RefCounts);
			if (*_RefCounts == 0)
			{
				destructor();
			}
		}

	private:
		T* _Ptr;
		std::atomic<int>* _RefCounts; // 引用计数（保证原子性）
		std::function<void(T*)> _Del; // 自定义删除器
	};
}