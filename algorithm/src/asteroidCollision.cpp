//
// Created by gcc on 5/8/23.
//
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> record;
        vector<int> result;
        int ta = true;
        for (int i = 0; i < asteroids.size(); ++i) {
            int as = asteroids[i];
            if (ta) {
                record.push(as);
                if (as > 0)
                    ta = false;
                continue;
            }
            if (abs(asteroids[i] + record.top()) > abs(max(abs(record.top()),abs(asteroids[i])))) {
                record.push(as);
                continue;
            }
            while (!record.empty()){
                if (as > 0) {
                    record.push(as);
                    break;
                } else if (as + record.top() == 0) {
                    record.pop();
                    break;
                } else if (abs(asteroids[i] + record.top()) > abs(max(abs(record.top()),abs(asteroids[i])))){
                    record.push(as);
                    break;
                }else if (abs(as) - abs(record.top()) > 0) {
                    record.pop();
                }  else{
                    break;
                }
            }
            if (record.empty())
                record.push(as);
        }
        int target = record.size();
        stack<int> result1;
        for (int i = target - 1; i >= 0; --i) {
            result1.push(record.top());
            record.pop();
        }
        for (int i = target - 1; i >= 0; --i) {
            result.push_back(result1.top());
            result1.pop();
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> asteroids = {1,-2,-2,-2};
    vector<int> result = s.asteroidCollision(asteroids);
}