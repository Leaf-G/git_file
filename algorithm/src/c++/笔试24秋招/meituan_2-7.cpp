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
    int cout_list_flag = 0;
    unordered_map<int, string> list_cout;
    unordered_map<string, int> stor_num;
    unordered_map<string, string> stor_add;
    unordered_multimap<string, string> record;
    for (int i = 0; i < n; ++i) {
        string stor, add;
        cin >> stor >> add;
        bool flag1 = false;
        auto it_re = record.find(stor);
        while (it_re != record.end()){
            if (it_re->second == add) {
                flag1 = true;
                break;
            }
            it_re++;
        }
        if (flag1 == true)
            continue;
        else
            record.insert({stor, add});
        bool flag2 = false;
        for (int j = 0; j < stor.size(); ++j) {
            if (isupper(stor[j])) {
                flag2 = true;
                break;
            }
        }
        if (flag2 == true)
            continue;
        auto tar1 = stor_add.find(stor);
        if (stor_add.end() == tar1){
            stor_add.insert({stor, add});
            stor_num.insert({stor, 0});
            list_cout.insert({cout_list_flag, stor});
            cout_list_flag++;
        } else{
            if (tar1->second == add)
                continue;
            auto tar2 = stor_num.find(stor);
            tar2->second += 1;
        }
    }
//    for (int i = 0; i < list_cout.size(); ++i) {
//        auto cout_name = list_cout.find(i);
//        cout << stor_add.find(cout_name->second)->first << " " <<  stor_add.find(cout_name->second)->second << " " << stor_num.find(cout_name->second)->second << endl;
//    }
    for (auto it : stor_add) {
        cout << it.first << " " <<  it.second << " " << stor_num.find(it.first)->second << endl;
    }
}