#include <iostream>
#include <vector>
using namespace std;

namespace myHash{
	// 哈希表中每一个元素的状态
	enum State { EMPTY, EXIST, DELETE };

	// 哈希函数
	template<class T>
	struct HashFunc {
		size_t operator()(const T& key) {
			return key;
		}
	};

	// 哈希函数
	template<>
	struct HashFunc<string> {
		size_t operator()(const string& key) {
			size_t hash = 0;
			for (auto ch : key){
				hash *= 131;
				hash += ch;
			}

			return hash;
		}
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable{
		struct Elem{
			pair<K, V> _val;
			State _state = EMPTY;
		};

	public:
		HashTable(size_t capacity = 10)
			: _ht(capacity), 
			  _size(0)
		{}

		// 插入
		bool Insert(const pair<K, V>& val) {
			if (Find(val.first)) return false;

			// 如果超过负载因子，则扩容
			if (_size * 10 / _ht.size() > 7) {
				HashTable<K, V> _temp(_ht.size() * 2);

				for (size_t i = 0; i < _ht.size(); ++i) {
					if (_ht[i]._state == EXIST) {
						_temp.Insert(_ht[i]._val);
					}
				}
				swap(_ht, _temp._ht);
			}

			// 正常插入逻辑
			Hash _hs;
			size_t hashi = _hs(val.first) % _ht.size();
			while (_ht[hashi]._state == EXIST) {
				hashi++;
				hashi %= _ht.size();
			}

			_ht[hashi]._val = val;
			_ht[hashi]._state = EXIST;
			_size++;

			return true;
		}

		// 查找
		Elem* Find(const K& key) {
			Hash _hs;
			size_t hashi = _hs(key) % _ht.size();

			// 线性探测
			while (_ht[hashi]._state != EMPTY) {
				if (_ht[hashi]._state == EXIST && _ht[hashi]._val.first == key) {
					return &_ht[hashi];
				}

				hashi++;
				hashi %= _ht.size(); // 避免超出范围
			}

			return nullptr;
		}

		// 删除
		bool Erase(const K& key) {
			Elem* ptr = Find(key);
			if (ptr == nullptr) return false;

			// 标记改变
			ptr->_state = DELETE;
			_size--;

			return true;
		}

		size_t Size()const{
			return _size;
		}

		bool Empty() const{
			return _size == 0;
		}

	private:
		vector<Elem> _ht;
		size_t _size;
	};


	template<class K, class V, class Hash = HashFunc<K>>
	class HashBucket {
		struct Elem {
			Elem(const pair<K, V>& val = pair<K, V>{}) {
				_val = val;
			}

			pair<K, V> _val;
			Elem* _prev = nullptr;
			Elem* _next = nullptr;
		};
	public:
		HashBucket(size_t capacity = 10)
			: _ht(capacity, nullptr)
			, _size(0)
		{}

		// 插入
		bool Insert(const pair<K, V>& val) {
			if (Find(val.first)) return false;

			Elem* newnode = new Elem(val);
			// 如果超过负载因子，则扩容
			if (_size * 10 / _ht.size() > 1) {
				HashBucket<K, V> _temp(_ht.size() * 2);

				for (size_t i = 0; i < _ht.size(); ++i) {
					if (_ht[i]._state == EXIST) {
						_temp.Insert(_ht[i]._val);
					}
				}
				swap(_ht, _temp._ht);
			}

			// 正常插入逻辑
			Hash _hs;
			size_t hashi = _hs(val.first) % _ht.size();
			// 头插法
			newnode->_next = _ht[hashi];
			if (_ht[hashi]) _ht[hashi]->_prev = newnode;
			_ht[hashi] = newnode;
			_size++;

			return true;
		}

		// 删除
		bool Erase(const K& key) {
			Elem* node = Find(key);
			if (node == nullptr) return false;

			// 指向改变
			Hash _hs;
			size_t hashi = _hs(key) % _ht.size();
			if (node->_prev == nullptr) {
				_ht[hashi] = node->_next;
				_ht[hashi]->_prev = nullptr;
			}
			else {
				_ht[hashi]->_prev->_next = node->_next;
				node->_next->_prev = _ht[hashi]->_prev;
			}

			delete node;
			_size--;

			return true;
		}

		// 查找
		Elem* Find(const K& key) {
			Hash _hs;
			size_t hashi = _hs(key) % _ht.size();
			Elem* node = _ht[hashi];

			while (node != nullptr) {
				if (node->_val.first == key) return node;
				node = node->_next;
			}

			return nullptr;
		}


	private:
		vector<Elem*> _ht;
		size_t _size;
	};
}

