#pragma once
#include "Hash.h"

namespace myHash{
	template<class K, class Hash = HashFunc<K>>
	class unordered_set {

	private:
		struct SetKeyOfT {
			const K& operator()(const K& key) {
				return key;
			}
		};

	public:

		typedef typename HashBucket<K, K, SetKeyOfT, Hash>::iterator iterator;

		iterator begin() {
			return _hb.begin();
		}

		iterator end() {
			return _hb.end();
		}

		pair<iterator, bool> insert(const K& key) {
			return _hb.Insert(key);
		}

		bool erase(const K& key) {
			return _hb.Erase(key);
		}

		iterator find(const K& key) {
			return _hb.Find(key);
		}

	private:
		HashBucket<K, K, SetKeyOfT, Hash> _hb;
	};
}