#pragma once
#include <cassert>
#include <vector>
#include <algorithm>

/*
Ĭ����һ�����
*/
class Heap {
public:
	Heap() = default;

	// ���
	void push(int num) {
		_nums.push_back(num);
		
		int currentIndex = _nums.size() - 1;
		int parentIndex = (currentIndex - 1) / 2;
		// ���ϵ���
		while (currentIndex > 0) {
			if (_nums[currentIndex] < _nums[parentIndex]) {
				break;
			}
			std::swap(_nums[currentIndex], _nums[parentIndex]);
			currentIndex = parentIndex;
			parentIndex = (parentIndex - 1) / 2;
		}
	}
	
	// ��ȡͷ��
	int top() const {
		assert(!_nums.empty());
		return _nums.front();
	}

	// ɾ��
	void pop() {
		assert(!_nums.empty());
		// ����ɾ�����һ��
		std::swap(_nums.front(), _nums.back());
		_nums.pop_back();

		// ���µ���
		int parentIndex = 0;
		while (parentIndex < _nums.size()) {
			int biggerIndex = parentIndex;
			// �����ж�
			int leftChild = 2 * parentIndex + 1;
			if (leftChild < _nums.size() && _nums[biggerIndex] < _nums[leftChild]) {
				biggerIndex = leftChild;
			}
			// �Һ����ж�
			int rightChild = leftChild + 1;
			if (rightChild < _nums.size() && _nums[biggerIndex] < _nums[rightChild]) {
				biggerIndex = rightChild;
			}
			// ����������
			if (biggerIndex == parentIndex) {
				break;
			}
			// ����
			std::swap(_nums[parentIndex], _nums[biggerIndex]);
			parentIndex = biggerIndex;
		}
	}

	// ��С
	int size() const {
		return _nums.size();
	}

private:
	std::vector<int> _nums;
};