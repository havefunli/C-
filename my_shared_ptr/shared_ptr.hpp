#pragma once



namespace my_shared_ptr{
	template <class T>
	class shared_ptr {
	private:
		
		void clear() {
			_ptr = nullptr;
			*_count--;
		}

	public:
		shared_ptr() 
			: _ptr(nullptr), _count(nullptr)
		{}
		
		shared_ptr(T* ptr) 
			: _ptr(ptr), _count(new int(1))
		{}

		shared_ptr(shared_ptr& other) {
			_ptr = other._ptr;
			_count = other._count;
			*_count++;
		}

		~shared_ptr() {
			*_count--;
			if (*_count != 0) {
				_count = nullptr;
				_ptr = nullptr;
				return;
			}
			else {
				delete _ptr;
				delete _count;
			}
		}

		shared_ptr& operator= (shared_ptr& other){
			clear();
			_ptr = other._ptr;
			_count = other._count;
			*_count++;
		}



	private:
		T* _ptr;
		int* _count;
	};
}
