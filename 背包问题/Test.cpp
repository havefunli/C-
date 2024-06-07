#include <iostream>
#include <vector>
using namespace std;

void knapsack(vector<int>& weights, int T, vector<int>& selected, vector<vector<int>>& result, int start) {
    if (T == 0) {
        result.push_back(selected);
        return;
    }
    for (int i = start; i < weights.size(); i++) {
        if (T - weights[i] >= 0) {
            selected.push_back(weights[i]);
            knapsack(weights, T - weights[i], selected, result, i + 1);
            selected.pop_back();
        }
    }
}

int main() {
    vector<int> weights = { 1,8,4,3,5,2 };
    int T = 10;
    vector<int> selected;
    vector<vector<int>> result;

    knapsack(weights, T, selected, result, 0);

    cout << "当 T = " << T << " 所有能装满背包的方案为：" << endl;
    for (auto& solution : result) {
        for (auto index : solution) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}
