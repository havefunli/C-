#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 归并排序，需要关注的问题主要是界限问题
//void merge_sort(vector<int>& arr, int left, int right) {
//    if (left == right) return;
//
//    int mid = (left + right) / 2;
//    merge_sort(arr, left, mid);
//    merge_sort(arr, mid + 1, right);
//
//    vector<int> temp;
//    int i = left;
//    int j = mid + 1;
//    while (i <= mid && j <= right) {
//        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
//        else temp.push_back(arr[j++]);
//    }
//    while (i <= mid) temp.push_back(arr[i++]);
//    while (j <= right) temp.push_back(arr[j++]);
//
//    for (int k = left, l = 0; k <= right; k++, l++) {
//        arr[k] = temp[l];
//    }
//}
//
//int main() {
//    int n = 0;
//    cin >> n;
//
//    vector<int> arr(n);
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//
//    merge_sort(arr, 0, n - 1);
//    for (int& e : arr) {
//        cout << e << " ";
//    }
//
//    return 0;
//}

// 利用归并问题解决寻找逆序数
// 第一个需要注意的问题就是 返回值需要使用 long long 来存储，避免越界问题
// 第二个需要注意的问题就是 怎么来记录寻找到的逆序数
// 因为是使用归并排序，所有是左右区间已经是有序的了
// 例：当左区间的数A大于右
// 区间的数满条件时，可以认为A到左区间最右侧的数都是满足条件的
// 所以 ret = mid - i + 1; 
//#include <iostream>
//#include <vector>
//using namespace std;
//
//long long countInverseNumber(vector<int>& arr, int left, int right) {
//    if (left == right) return 0;
//
//    int mid = (left + right) / 2;
//    long long ret = countInverseNumber(arr, left, mid) + countInverseNumber(arr, mid + 1, right);
//
//    vector<int> temp;
//    int i = left, j = mid + 1;
//    while (i <= mid && j <= right) {
//        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
//        else {
//            temp.push_back(arr[j++]);
//            ret += (mid - i + 1);
//        }
//    }
//    while (i <= mid) temp.push_back(arr[i++]);
//    while (j <= right) temp.push_back(arr[j++]);
//
//    for (int i = 0, j = left; i < temp.size(); i++, j++) {
//        arr[j] = temp[i];
//    }
//
//    return ret;
//}
//
//int main() {
//    int n = 0;
//    cin >> n;
//
//    vector<int> arr(n);
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//
//    long long ret = countInverseNumber(arr, 0, n - 1);
//    cout << ret << endl;
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> binarySearch(vector<int>& arr, int q) {
//    int leftClose = 0;
//    int left = 0, right = arr.size() - 1;
//    while (left < right) {
//        int mid = (left + right) / 2;
//        if (arr[mid] >= q) right = mid;
//        else left = mid + 1;
//    }
//    if (arr[left] != q) {
//        return { -1, -1 };
//    }
//    else {
//        leftClose = left;
//        left = 0, right = arr.size() - 1;
//        while (left < right) {
//            int mid = (left + right + 1) / 2;
//            if (arr[mid] <= q) left = mid;
//            else right = mid - 1;
//        }
//    }
//
//    return { leftClose, left };
//}
// 二分法
// 将区间可以分为两个一个是满足该条件的，另一个是不满足条件的
// 选取 mid(左右更新不一致，当左更新时需要额外加1)
// 判断 mid 和 我们条件区间的临界值的关系
// 根据合适的条件更新区间的左右边界
// 最后一定会找到该边界值(如果存在)
//int main() {
//    int n = 0, q = 0;
//    // cin >> n >> q;
//    cin >> n;
//
//    vector<int> arr(n);
//    for (int i = 0; i < n; i++) cin >> arr[i];
//    //vector<int> query(q);
//    //for (int i = 0; i < q; i++) cin >> query[i];
//
//    //vector<vector<int>> ret;
//    //for (int& e : query) {
//    //    ret.push_back(binarySearch(arr, e));
//    //}
//    
//    vector<vector<int>> ret;
//    ret.push_back(binarySearch(arr, 3));
//
//    for (auto& e : ret) {
//        cout << e[0] << " " << e[1] << endl;
//    }
//}

// 利用二分法来解答
// 停止条件是左右区间的间隔不足1e-8
//#include <iostream>
//using namespace std;
//
//int main() {
//    double num = 0;
//    cin >> num;
//
//    double left = -10000, right = 10000;
//    while (right - left > 1e-8) {
//        double mid = (left + right) / 2;
//        if ((mid * mid * mid) >= num) right = mid;
//        else left = mid;
//    }
//
//    printf("%lf\n", left);
//}