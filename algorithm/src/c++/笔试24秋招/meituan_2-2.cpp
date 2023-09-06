//
// Created by gcc on 9/6/23.
//
//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> a(n, 0);
//    for (int i = 0; i < n; ++i) {
//        cin >>  a[i];
//    }
//    int result = 0;
//    int sum = accumulate(a.begin(),a.end(), 0);
//    int remainder = sum % n;
//    int maxValue = *max_element(a.begin(),a.end());
//    if (maxValue > remainder)
//    if (remainder == 0) {
//        int div_result = sum / n;
//        for (int i = 0; i < n; ++i) {
//            if (a[i] < div_result)
//                result += (div_result -a[i]);
//        }
//    }
//    cout << result << endl;
//}
//// 64 位输出请用 printf("%lld")
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i=0; i<n; ++i) {
        cin >> nums[i];
    }
    long long sum = accumulate(nums.begin(), nums.end(), (long long)0);
    if (sum%n==0) {
        long long avg = sum/n;
        long long ans = 0;
        for (auto a:nums) {
            ans += abs(a-avg);
        }
        cout << ans/2 << endl;
        return 0;
    }
    sort(nums.begin(), nums.end());
    function<long long(vector<long long>&, int, int)> comp = [&](vector<long long>& nums, int l, int r) {
        long long tot = 0;
        for (int i=l; i<=r; ++i) {
            tot += nums[i];
        }
        long long avg = tot/(r-l+1);
        long long avg2 = avg+1;
        long long a = 0;
        long long b = 0;
        long long c = 0;
        long long d = 0;
        for (int i=l; i<=r; ++i) {
            if (nums[i]>=avg) a+=nums[i]-avg;
            else b+=avg-nums[i];
            if (nums[i]>=avg2) c+=nums[i]-avg2;
            else d+=avg2-nums[i];
        }
        return min(max(a, b), max(c, d));
    };
    long long res1 = comp(nums, 0, n-2);
    long long res2 = comp(nums, 1, n-1);
    cout << min(res1, res2) << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")

