//
// Created by gcc on 9/6/23.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int q;
    cin >> q;
    int m,x;
    vector<vector<int>> record(q,vector<int>(2, 0));
    for (int i = 0; i < q; ++i) {
        cin >> m >> x;
        record[i][0] = m;
        record[i][1] = x;
    }
    for (auto target : record) {
        int result = target[1] % target[0];
        if (result == 0)
            result = target[0];
        cout << result << endl;
    }
}
