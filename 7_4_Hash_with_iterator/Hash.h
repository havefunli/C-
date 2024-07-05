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

	// 前置声明
	template<class K, class T, class KeyOfT, class Hash>
	class HashBucket;

	template<class T>
	struct Elem {
		Elem(const T& val = T()) {
			_val = val;
		}

		T _val;
		Elem* _next = nullptr;
	};

	template<class Key, class T, class KeyOfT, class Hash>
	struct _HTIterator {

		typedef Elem<T> Elem;
		typedef _HTIterator Self;
		typedef HashBucket<Key, T, KeyOfT, Hash>* PtrForHT;

		_HTIterator(Elem* node, PtrForHT pht) 
			: _node(node)
			, _pht(pht)
		{}

		Elem* _node = nullptr;
		PtrForHT _pht = nullptr;

		T& operator* () {
			return _node->_val;
		}

		T* operator->() {
			return &(_node->_val);
		}

		bool operator!=(const Self& it) {
			if (it._node != _node) {
				return true;
			}
			else {
				return false;
			}
		}

		Self& operator++() {
			// 当前节点并未完成
			if (_node->_next) {
				_node = _node->_next;
			}
			// 当前结点以及遍历完成
			else {
				KeyOfT _kot;
				Hash _hs;

				size_t table_size = _pht->_ht.size();
				size_t hashi = (_hs(_kot(_node->_val)) % table_size) + 1;
				for (; hashi < table_size; ++hashi) {
					if (_pht->_ht[hashi] != nullptr) {
						_node = _pht->_ht[hashi];
						break;
					}
				}
				if (hashi == table_size) {
					_node = nullptr;
				}
			}

			return *this;
		 }
	};

	template<class Key, class T, class KeyOfT, class Hash>
	class HashBucket {
		// 前置声明友元类
		template<class K, class T, class KeyOfT, class Hash>
		friend struct _HTIterator;

		typedef Elem<T> Elem;
	public:

		typedef _HTIterator<Key, T, KeyOfT, Hash> iterator;
		
		iterator begin() {
			for (size_t i = 0; i < _ht.size(); ++i) {
				if (_ht[i]) {
					return iterator(_ht[i], this);
				}
			}
			return end();
		}

		iterator end() {
			return iterator(nullptr, this);
		}

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
		pair<iterator, bool> Insert(const T& val) {
			// 哈希值
			Hash _hs;
			// 仿函数，因为不确定 val 的类型
			KeyOfT _kt;

			iterator it = Find(_kt(val));
			if (it != end()) return { it, false };

			Elem* newnode = new Elem(val);

			// 如果超过负载因子，则扩容
			if (_size >= _ht.size()) {
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

			return make_pair(iterator(newnode, this), true);
		}

		// 删除
		bool Erase(const Key& key) {
			Hash _hs;
			size_t hashi = _hs(key) % _ht.size();

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
		iterator Find(const Key& key) {
			Hash _hs;
			KeyOfT _kt;
			
			size_t hashi = _hs(key) % _ht.size();
			Elem* cur = _ht[hashi];

			while (cur != nullptr) {
				if (_kt(cur->_val) == key) {
					return iterator(cur, this);
				}
				cur = cur->_next;
			}

			return iterator(nullptr, this);
		}

	private:
		vector<Elem*> _ht;
		size_t _size;
	};
}

