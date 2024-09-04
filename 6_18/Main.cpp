#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;


// 利用二分法解决分蛋糕问题
//#include <iostream>
//#include <vector>
//using namespace std;
//
//bool check(int& size, int& people, vector<vector<int>>& arr) {
//    int count = 0;
//    for (int i = 0; i < arr.size(); i++) {
//        count += ((arr[i][0] / size) * (arr[i][1] / size));
//    }
//
//    if (count >= people) return true;
//    else return false;
//}
//
//int main() {
//    int n = 0, k = 0;
//    cin >> n >> k;
//
//    vector<vector<int>> arr(n, { 0, 0 });
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i][0] >> arr[i][1];
//    }
//
//    int left = 0, right = 1e+5;
//    while (left < right) {
//        int mid = (left + right + 1) / 2;
//        if (check(mid, k, arr)) left = mid;
//        else right = mid - 1;
//    }
//
//    cout << left << endl;
//}

#/*include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> map;
    int left = 0, right = 0, oper = 0;
    while (m--) {
        cin >> left >> right >> oper;
        left -= 1;
        while (left < right) {
            map[left++] += oper;
        }
    }

    for (auto& e : map) {
        arr[e.first] += e.second;
    }

    for (auto& e : arr) {
        cout << e << " ";
    }
    return 0;
}*/

//string to_string() {
//    return nullptr;
//}
//
//int main() {
//    string s = to_string();
//    return 0;
//}

class Solution {
public:
    bool is_nums(string num) {
        if (num.size() == 0) return false;

        for (int i = 0; i < num.size(); i++) {
            if (num[i] <= '0' && num[i] >= '9') return false;
        }
        return true;
    }

    string discountPrices(string sentence, int discount) {
        string retStr;

        int pos = 0;
        while (pos < sentence.size()) {
            if (sentence[pos] == '$') {
                retStr.push_back(sentence[pos++]);

                int space = sentence.find(' ', pos);
                string nums = sentence.substr(pos, space - pos);

                if (is_nums(nums)) {
                    double newPrice = stof(nums) * (1 - ((double)discount / 100));
                    retStr.append(to_string(newPrice));
                }
            }

            retStr.push_back(sentence[pos++]);
        }

        return retStr;
    }
};

int main() {
    Solution s;
    s.discountPrices("there are $1 $2 and 5$ candies in the shop", 50);

    return 0;
}