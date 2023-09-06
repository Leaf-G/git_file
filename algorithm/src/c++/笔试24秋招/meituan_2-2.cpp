//
// Created by gcc on 9/6/23.
//
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >>  a[i];
    }
    int result = 0;
    int sum = accumulate(a.begin(),a.end(), 0);
    int remainder = sum % n;
    int maxValue = *max_element(a.begin(),a.end());
    if (maxValue > remainder)
    if (remainder == 0) {
        int div_result = sum / n;
        for (int i = 0; i < n; ++i) {
            if (a[i] < div_result)
                result += (div_result -a[i]);
        }
    }
    cout << result << endl;
}
// 64 位输出请用 printf("%lld")