#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>
using namespace std;

namespace LQ {
	// 比较大小仿函数
	template<class T> 
	struct Less {
		bool operator()(const T& left, const T& right) {
			return left < right;
		}
	};
	template<class T>
	struct Greater {
		bool operator()(const T& left, const T& right) {
			return left > right;
		}
	};


	template<class T, class Container = vector<T>, class Compare = Less<T>>
	class priority_queue {
	public:
		// 初始化函数
		priority_queue(){}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last) {
			while (first != last) {
				_con.push_back(*first);
				adjust_up(_con.size() - 1);
			}
		}

		// 向下调整(用于删除最 大/小 后)
		void adjust_down(size_t parent) {
			size_t child = 2 * parent + 1;

			while (child < size()) {
				if (child + 1 < size() && Compare()(_con[child + 1], _con[child])) {
					child = child + 1;
				}
				if (Compare()(_con[child], _con[parent])) {
					swap(_con[child], _con[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else {
					break;
				}
			}
		}

		// 向上调整(用于插入元素后调整)
		void adjust_up(size_t child) {
			int parent = (child - 1) / 2;

			while (parent >= 0) {
				if (Compare()(_con[child], _con[parent])) {
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else {
					break;
				}
			}
		}

		// 尾插函数
		void push(const T& val) {
			_con.push_back(val);
			adjust_up(_con.size() - 1);
		}

		// 头删
		void pop() {
			assert(size() > 0);

			swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}
		
		// 获取顶部元素
		const T& top() {
			assert(size() > 0);

			return _con[0];
		}

		// 获取大小
		size_t size() {
			return _con.size();
		}

		// 是否为空
		bool empty() {
			return _con.empty();
		}

	private:
		Container _con;
	};
}