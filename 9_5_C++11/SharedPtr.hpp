#pragma once

#include <iostream>
#include <atomic>
#include <stdio.h>
#include <functional>

// ������ָ�뻹����ȱ��
// ������Ķ����� T[] ʱ��ɾ��������������

namespace MyPtr
{
	template <class T>
	class SharedPtr
	{
	private:
		// �������� 0 ʱ����
		void destructor()
		{
			_Del(_Ptr);
			_Ptr = nullptr;
			delete _RefCounts;
			_RefCounts = nullptr;
		}

	public:
		// ���캯��(Ĭ��ɾ����)
		SharedPtr(T* Ptr)
			: _Ptr(Ptr)
			, _RefCounts(new std::atomic<int>(1))
			, _Del([](T* val) {delete val; })
		{}

		// ���캯��(�Զ���ɾ����)
		template<class D>
		SharedPtr(T* Ptr, D Del)
			: _Ptr(Ptr)
			, _RefCounts(new std::atomic<int>(1))
			, _Del(Del)
		{}

		// ��������
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
			// ���ü���
			--(*_RefCounts);
			if (*_RefCounts == 0)
			{
				destructor();
			}
		}

		SharedPtr<T>& operator=(const SharedPtr<T>& sp)
		{
			if (this != &sp) // ��ֹ���Ҹ�ֵ
			{
				clear(); // �ͷŵ�ǰ��Դ

				_Ptr = sp._Ptr;
				_RefCounts = sp._RefCounts;
				_Del = sp._Del; // ����ɾ����
				++(*_RefCounts);
			}
			return *this;
		}

		int use_count()
		{
			return *_RefCounts;
		}

		// ��������
		~SharedPtr()
		{
			// ���ü���
			--(*_RefCounts);
			if (*_RefCounts == 0)
			{
				destructor();
			}
		}

	private:
		T* _Ptr;
		std::atomic<int>* _RefCounts; // ���ü�������֤ԭ���ԣ�
		std::function<void(T*)> _Del; // �Զ���ɾ����
	};
}