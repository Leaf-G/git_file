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

#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool check(string str){

    for(int i=0;i<str.size();i++){
        if(!islower(str[i]))
            return false;
    }

    return true;
}

int main() {

    int n;

    map<string,vector<string>> business;
    vector<string> exist;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string name, address;

        cin >> name >> address;

        if(check(name) && check(address)){

            bool flag=true;
            for(int i=0;i<exist.size();i++){
                if(!exist[i].compare(name+address))
                    flag=false;
            }

            if(flag){
                business[name].push_back(address);
                exist.push_back(name+address);
            }
        }

    }

    for(auto i=business.begin();i!=business.end();i++)
        cout<<i->first<<" "<<i->second[0]<<" "<<i->second.size()-1<<endl;
}