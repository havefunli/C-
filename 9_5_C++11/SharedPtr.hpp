#pragma once
#include <iostream>
#include <atomic>

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
			delete _Ptr; // ȱ�ݣ���һ�����ָ��ʱ T[]
			_Ptr = nullptr;
			delete _RefCounts;
			_RefCounts = nullptr;
		}

	public:
		// ���캯��
		SharedPtr(T* Ptr)
			: _Ptr(Ptr)
			, _RefCounts(new std::atomic<int>(1))
		{}

		// ��������
		SharedPtr(const SharedPtr<T>& sp)
			: _Ptr(sp._Ptr)
		{
			// ��������
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
			// ���ü���
			--(*_RefCounts);
			if (*_RefCounts == 0)
			{
				destructor();
			}
		}

		SharedPtr<T>& operator=(const SharedPtr<T>& sp)
		{
			// ���Լ���ֵ
			if (sp._Ptr == _Ptr)
			{
				return *this;
			}

			// ���ͷ������Լ�ռ�õ���Դ
			clear();

			// ���µ���Դ
			_Ptr = sp._Ptr;
			_RefCounts = sp._RefCounts;
			++(*_RefCounts);

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
	};
}