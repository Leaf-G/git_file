//
// Created by gcc on 9/6/23.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> stor_num;
    unordered_map<string, string> stor_add;
    vector<string> input;
    for (int i = 0; i < n; ++i) {
        getline(cin, input[i]);
        stringstream edit;
        edit << input[i];
        string stor, add;
        int num;
        edit >> stor;
        edit >> add;
        stor_add.insert({stor, add});

//        find_fist
    }

}
// 64 位输出请用 printf("%lld")