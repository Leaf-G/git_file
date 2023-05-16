//
// Created by gcc on 5/5/23.
//
#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;


int main()
{
    int i;
    int ia[5] = { 1,2,3,4,5 };
    set<int> s(ia, ia + 5);
    cout << s.size() << endl; // 5
    cout << s.count(3) << endl; // 1
    cout << s.count(10) << endl; // 0

    s.insert(3); //再插入一个3
    cout << s.size() << endl; // 5
    cout << s.count(3) << endl; // 1

    s.erase(1);
    cout << s.size() << endl; // 4

    set<int>::iterator b = s.begin();
    set<int>::iterator e = s.end();
    for (; b != e; ++b)
        cout << *b << " "; // 2 3 4 5
    cout << endl;

    b = find(s.begin(), s.end(), 5);
    if (b != s.end())
        cout << "5 found" << endl; // 5 found

    b = s.find(2);
    if (b != s.end())
        cout << "2 found" << endl; // 2 found

    b = s.find(1);
    if (b == s.end())
        cout << "1 not found" << endl; // 1 not found

    unordered_set<int> us;

    us.insert(10);
    us.insert(99);
    us.insert(48);
    us.insert(27);
    us.insert(16);

    //迭代器遍历无序
    unordered_set<int>::iterator uit = us.begin();
    while (uit != us.end())
    {
        cout << *uit << " ";
        uit++;
    }
    cout << endl;

    set<int> u_s;
    u_s.insert(5);
    u_s.insert(1);
    u_s.insert(6);
    u_s.insert(3);
    u_s.insert(7);
    u_s.insert(2);

    cout << "Elements of unordered_set: \n";
    for (auto it : u_s)
        cout << it << " ";
    cout << endl;
    map<int, int> map_1;
    map_1.insert(make_pair(1, 3));
    map_1.insert(make_pair(3, 3));
    map_1.insert(make_pair(2, 3));
    for (auto it = map_1.begin(); it != map_1.end(); ++it) {
        cout << (*it).first << ":" << (*it).second << endl;
    }
    auto a = map_1.find(2);
    cout << (*a).first <<endl;
//    return 0;
}
