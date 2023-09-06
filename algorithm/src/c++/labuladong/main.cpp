//
// Created by gcc on 8/29/23.
//
//#include "01/maxDepth.h"
//#include "01/mindis.h"
//#include "01/binarySearch.h"
//#include "02-dp/lengthOfLIS.h"
//#include <iostream>
//#include <sstream>
//using namespace std;
//int main() {
//    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
//    std::vector<vector<int>> tar = {{5,4},{6,4},{6,7},{2,3}};
//    std::vector<vector<int>> tar1 = {{1,1},{1,1},{1,1},{1,1}};
//    string s1 = {"babcde"}, s2 = {"ace"};
//    TreeNode* root = buildTree();
//
////    Solution s;
////    int result = maxEnvelopes(tar);
//    int result = longestCommonSubsequence(s1, s2);
//
//    cout << " " << result << endl;
////    cout << result.size() << endl;
//
//    return 0;
//}

//#include <iostream>
//#include <unordered_map>
//
//using namespace std;
//
//int main()
//{
//    unordered_multimap<std::string, int>
//            first,
//            second = { { "AAPL", 200 }, { "GOOG", 100 } };
//
//    pair<std::string, int> mypair("MSFT", 500);
//
//    first.insert(mypair);                            // copy insertion
//    first.insert(make_pair("GOOG", 50)); // move insertion
//    first.insert(second.begin(), second.end());  // range insertion
//    first.insert({ { "ORCL", 100 }, { "GOOG", 100 } });    // initializer list insertion
//
//    unordered_multimap<string, string> myumm = {
//            { "strawberry", "red" },
//            { "banana", "yellow" },
//            { "orange", "orange" },
//            { "lemon", "yellow" },
//            { "apple", "red" },
//            { "apple", "green" },
//            { "pear", "green" },
//    };
//    cout << myumm.find("apple")->second << endl;
//
//
//    // erase examples:
//    myumm.erase(myumm.begin());     // erasing by iterator
//    myumm.erase("apple");             // erasing by key (erases 2 elements)
//    myumm.erase(myumm.find("orange"), myumm.end()); // erasing by range
//
//    unordered_multimap<string, string>
//            a = { { "orange", "FL" }, { "apple", "NY" }, { "apple", "WA" } },
//            b = { { "strawberry", "LA" }, { "strawberry", "NC" }, { "pear", "OR" } };
//
//    a.swap(b);
//
//    cout << myumm.empty() << endl;
//    cout << myumm.size() << endl;
//    cout << myumm.max_size() << endl;
//
//    system("pause");
//    return 0;
//}


#include <iostream>
#include<set>
#include<string>
#include<map>
#include<unordered_map>

using namespace std;

int main()
{
    multimap<string,int> m={{"s",1},{"s",1},{"s",3},{"s",4},{"sb",5}};
    string str="s";
    int num=m.count(str);
    multimap<string,int>::iterator it=m.find(str);
    while(num>0)
    {
        cout<<it->first<<" "<<it->second<<endl;
        ++it;
        num--;
    }
    return 0;
}
