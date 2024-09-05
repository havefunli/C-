#pragma once
#include <iostream>
#include <atomic>

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
			delete _Ptr; // 缺陷，万一管理的指针时 T[]
			_Ptr = nullptr;
			delete _RefCounts;
			_RefCounts = nullptr;
		}

	public:
		// 构造函数
		SharedPtr(T* Ptr)
			: _Ptr(Ptr)
			, _RefCounts(new std::atomic<int>(1))
		{}

		// 拷贝构造
		SharedPtr(const SharedPtr<T>& sp)
			: _Ptr(sp._Ptr)
		{
			// 引用增加
			++(*sp._RefCounts);
			_RefCounts = sp._RefCounts;   
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
			// 对自己赋值
			if (sp._Ptr == _Ptr)
			{
				return *this;
			}

			// 先释放现在自己占用的资源
			clear();

			// 绑定新的资源
			_Ptr = sp._Ptr;
			_RefCounts = sp._RefCounts;
			++(*_RefCounts);

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
	};
}