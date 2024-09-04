#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>
using namespace std;

namespace LQ {
	// �Ƚϴ�С�º���
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
		// ��ʼ������
		priority_queue(){}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last) {
			while (first != last) {
				_con.push_back(*first);
				adjust_up(_con.size() - 1);
			}
		}

		// ���µ���(����ɾ���� ��/С ��)
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

		// ���ϵ���(���ڲ���Ԫ�غ����)
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

		// β�庯��
		void push(const T& val) {
			_con.push_back(val);
			adjust_up(_con.size() - 1);
		}

		// ͷɾ
		void pop() {
			assert(size() > 0);

			swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}
		
		// ��ȡ����Ԫ��
		const T& top() {
			assert(size() > 0);

			return _con[0];
		}

		// ��ȡ��С
		size_t size() {
			return _con.size();
		}

		// �Ƿ�Ϊ��
		bool empty() {
			return _con.empty();
		}

	private:
		Container _con;
	};
}