#pragma once
#include <cassert>
#include <vector>
#include <algorithm>

/*
默认是一个大堆
*/
class Heap {
public:
	Heap() = default;

	// 添加
	void push(int num) {
		_nums.push_back(num);
		
		int currentIndex = _nums.size() - 1;
		int parentIndex = (currentIndex - 1) / 2;
		// 向上调整
		while (currentIndex > 0) {
			if (_nums[currentIndex] < _nums[parentIndex]) {
				break;
			}
			std::swap(_nums[currentIndex], _nums[parentIndex]);
			currentIndex = parentIndex;
			parentIndex = (parentIndex - 1) / 2;
		}
	}
	
	// 获取头部
	int top() const {
		assert(!_nums.empty());
		return _nums.front();
	}

	// 删除
	void pop() {
		assert(!_nums.empty());
		// 交换删除最后一个
		std::swap(_nums.front(), _nums.back());
		_nums.pop_back();

		// 向下调整
		int parentIndex = 0;
		while (parentIndex < _nums.size()) {
			int biggerIndex = parentIndex;
			// 左孩子判断
			int leftChild = 2 * parentIndex + 1;
			if (leftChild < _nums.size() && _nums[biggerIndex] < _nums[leftChild]) {
				biggerIndex = leftChild;
			}
			// 右孩子判断
			int rightChild = leftChild + 1;
			if (rightChild < _nums.size() && _nums[biggerIndex] < _nums[rightChild]) {
				biggerIndex = rightChild;
			}
			// 满足条件了
			if (biggerIndex == parentIndex) {
				break;
			}
			// 调整
			std::swap(_nums[parentIndex], _nums[biggerIndex]);
			parentIndex = biggerIndex;
		}
	}

	// 大小
	int size() const {
		return _nums.size();
	}

private:
	std::vector<int> _nums;
};