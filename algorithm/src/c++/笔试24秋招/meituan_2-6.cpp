//
// Created by gcc on 9/6/23.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;

    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<vector<long>> dp(n + 1, vector<long>(sum + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            for (int k = 1; k <= j - i + 1; k++) {
                if (a[i - 1] == k) continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
            }
        }
    }
    cout<<dp[n][sum]<<endl;
//    cout << dp[1][n] % 1000000007;
}

// 64 位输出请用 printf("%lld")