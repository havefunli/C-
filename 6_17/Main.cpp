#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �鲢������Ҫ��ע��������Ҫ�ǽ�������
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

// ���ù鲢������Ѱ��������
// ��һ����Ҫע���������� ����ֵ��Ҫʹ�� long long ���洢������Խ������
// �ڶ�����Ҫע���������� ��ô����¼Ѱ�ҵ���������
// ��Ϊ��ʹ�ù鲢�������������������Ѿ����������
// ���������������A������
// �������������ʱ��������ΪA�����������Ҳ������������������
// ���� ret = mid - i + 1; 
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
// ���ַ�
// ��������Է�Ϊ����һ��������������ģ���һ���ǲ�����������
// ѡȡ mid(���Ҹ��²�һ�£��������ʱ��Ҫ�����1)
// �ж� mid �� ��������������ٽ�ֵ�Ĺ�ϵ
// ���ݺ��ʵ�����������������ұ߽�
// ���һ�����ҵ��ñ߽�ֵ(�������)
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

// ���ö��ַ������
// ֹͣ��������������ļ������1e-8
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