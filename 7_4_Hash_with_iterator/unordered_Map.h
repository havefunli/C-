#pragma once
#include "Hash.h"

namespace myHash {
	template<class Key, class T, class Hash = HashFunc<Key>>
	class unordered_map {

	private:
		struct MapKeyOfT {
			const Key& operator()(const pair<Key, T>& kv) {
				return kv.first;
			}
		};

	public:
		typedef typename HashBucket<Key, pair<Key, T>, MapKeyOfT, Hash>::iterator iterator;

		iterator begin() {
			return _hb.begin();
		}

		iterator end() {
			return _hb.end();
		}

		pair<iterator, bool> insert(const pair<Key, T>& kv) {
			return _hb.Insert(kv);
		}

		bool erase(const Key& key) {
			return _hb.Erase(key);
		}

		iterator find(const Key& key) {
			return _hb.Find(key);
		}


		T& operator[](const Key& key) {
			pair<iterator, bool> ret = insert(make_pair(key, T()));

			return ret.first->second;
		}

	private:
		HashBucket<Key, pair<Key, T>, MapKeyOfT, Hash> _hb;
	};
}
