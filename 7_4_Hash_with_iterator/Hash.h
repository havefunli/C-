#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace myHash {

	// 哈希函数
	template<class T>
	struct HashFunc {
		size_t operator()(const T& key) {
			return key;
		}
	};

	// 哈希函数(string 特化)
	template<>
	struct HashFunc<string> {
		size_t operator()(const string& key) {
			size_t hash = 0;
			for (auto ch : key) {
				hash *= 131;
				hash += ch;
			}

			return hash;
		}
	};

	template<class Key, class T, class KeyOfT, class Hash>
	class HashBucket {
		struct Elem {
			Elem(const T& val = T()) {
				_val = val;
			}

			T _val;
			Elem* _next = nullptr;
		};
	public:
		HashBucket(size_t capacity = 10)
			: _ht(capacity, nullptr)
			, _size(0)
		{}

		~HashBucket() {
			for (size_t i = 0; i < _ht.size(); ++i) {
				Elem* cur = _ht[i];
				while (cur) {
					Elem* next = cur->_next;
					delete cur;
					cur = next;
				}
				cur = nullptr;
			}
		}

		// 插入
		bool Insert(const T& val) {
			// 哈希值
			Hash _hs;
			// 仿函数，因为不确定 val 的类型
			KeyOfT _kt;
			if (Find(_kt(val))) return false;

			Elem* newnode = new Elem(val);

			// 如果超过负载因子，则扩容
			if (_size * 10 / _ht.size() > 10) {
				vector<Elem*> _temp(_ht.size() * 2, nullptr);

				for (size_t i = 0; i < _ht.size(); ++i) {
					Elem* cur = _ht[i];
					while (cur) {
						Elem* next = cur->_next;

						size_t hashi = _hs(_kt(cur->_val)) % _temp.size();
						cur->_next = _temp[hashi];
						_temp[hashi] = cur;

						cur = next;
					}
				}
				_ht.swap(_temp);
				_temp.~vector();
			}

			size_t hashi = _hs(_kt(val)) % _ht.size();
			// 头插法
			newnode->_next = _ht[hashi];
			_ht[hashi] = newnode;
			_size++;

			return true;
		}

		// 删除
		bool Erase(const Key& key) {
			Hash _hs;
			size_t hashi = _hs(key);

			KeyOfT _kt;
			Elem* cur = _ht[hashi];
			Elem* prev = nullptr;
			while (cur) {
				if (_kt(cur->_val) == key) {
					// 非头节点
					if (prev) {
						prev->_next = cur->_next;
					}
					// 头节点
					else {
						_ht[hashi] = cur->_next;
					}

					delete cur;
					_size--;
					return true;
				}
				else {
					prev = cur;
					cur  = cur->_next;
				}
			}

			return false;
		}

		// 查找
		Elem* Find(const Key& key) {
			Hash _hs;
			KeyOfT _kt;
			
			size_t hashi = _hs(key) % _ht.size();
			Elem* cur = _ht[hashi];

			while (cur != nullptr) {
				if (_kt(cur->_val) == key) {
					return cur;
				}
				cur = cur->_next;
			}

			return nullptr;
		}

	private:
		vector<Elem*> _ht;
		size_t _size;
	};
}

