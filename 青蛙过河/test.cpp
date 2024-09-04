#include <iostream>
#include <vector>
using namespace std;

int dp_method(vector<int>& cost, int s, int t) {
	vector<int> dp(cost.size(), 0);


}

int main() {
	int L = 0;
	cin >> L;

	int s = 0, t = 0, m = 0;
	cin >> s >> t >> m;

	vector<int> cost(L, 0);
	vector<int> stones(m);

	for (int i = 0; i < m; i++) {
		int stone = 0;
		cin >> stone;
		stones.push_back(stone);
	}

	for (int i = 0; i < m; i++) {
		cost[stones[i]] = 1;
	}

	return dp_method(cost, s, t);
}