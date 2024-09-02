#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

string Test() {
    vector<string> v1;
    vector<string>::iterator a1;

    v1.push_back("zhao");
    v1.push_back("qian");
    v1.push_back("sun");
    v1.push_back("li");

    vector<string> v2;
    vector<string>::iterator a2;

    v2.push_back("zhao");
    v2.push_back("qian");
    v2.push_back("zhou");
    v2.push_back("wu");

    vector<string> v3;
    vector<string>::iterator a3;

    v3.push_back("zhao");
    v3.push_back("haung");

    for (int i = 0; i < v2.size(); i++)
    {
        a1 = find(v1.begin(), v1.end(), v2[i]);
        if (a1 != v1.end()) {
            a3 = find(v3.begin(), v3.end(), v2[i]);
            if (a3 == v3.end()) {
                return v2[i];
            }
        }
    }

    return 0;
}

void Test1(){
    int num = 1;
}

int main() {
    //cout << Test();
    Test1();

    return 0;
}