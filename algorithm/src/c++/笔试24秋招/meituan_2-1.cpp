//
// Created by gcc on 9/6/23.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<long> a;
    long tem;
    cin >> n;
    long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tem;
        sum += tem;
        a.push_back(tem);
    }
    long target = a[0] * a[1] - a[0] - a[1];
    for (int i = 1; i < n - 1; ++i) {
        long sum_mul = a[i] * a[i +1] - a[i] - a[i +1];
        if (target < sum_mul)
            target = sum_mul;
    }
    cout << target +sum << endl;
}
// 64 位输出请用 printf("%lld")