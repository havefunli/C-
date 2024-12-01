#include <climits>
#include <cmath>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int Num = 0;
    cin >> Num;

    int prev = INT_MAX;
    int i = 0;
    for (i = 0; i < Num; i++)
    {
        if (abs(i * i - Num) > prev) break;
        prev = abs(i * i - Num);
    }

    cout << i;
}