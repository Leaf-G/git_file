//
// Created by gcc on 9/6/23.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    int n,k;
    vector<bool> result(t, true);
    for (int i = 0; i < t; ++i) {
        cin >> n;
        cin >> k;
        vector<int> a(n, 0);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        vector<vector<int>> opt(k,vector<int>(2, 0));
        for (int j = 0; j < k; ++j) {
            cin >> opt[j][0] >> opt[j][1];
        }
        for (int j = 0; j < k; ++j) {
            a[opt[j][0] - 1]++;
            a[opt[j][1] - 1]--;
        }
        for (int j = 0; j < n - 1; ++j) {
            if (a[j] > a[j + 1])
                result[i] = false;
        }
    }
    for (int i = 0; i < t; ++i) {
        if (result[i] == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
// 64 位输出请用 printf("%lld")