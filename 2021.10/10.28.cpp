string countDigits(int n) {
    string cnt(10, 0);
    while (n) {
        ++cnt[n % 10];
        n /= 10;
    }
    return cnt;
}

unordered_set<string> powerOf2Digits;

int init = []() {
    for (int n = 1; n <= 1e9; n <<= 1) {
        powerOf2Digits.insert(countDigits(n));
    }
    return 0;
}();

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        return powerOf2Digits.count(countDigits(n));
    }
};




////////////////////
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "limits.h"
using namespace  std;

class Solution {
public:
    unordered_map<int,int> mmm;
    bool flag = false;
    bool reorderedPowerOf2(int n) {
        int tem = 1;
        //2的幂存放哈希表中
        unordered_map<int, int> mp;
        while(tem <= 10e9){
            mp[tem]++;
            if(tem > INT_MAX / 2){
                break;
            }
            tem *= 2;
        }
        //回溯 全排列问题
        int m = 0;
        vector<int> nums;
        while(n > 0){
            nums.push_back(n % 10);
            n /= 10;
            ++m;
        }
        string s = "";
        vector<bool> status(m, false);

        backtrack(nums, status, mp, s);


        return flag;


    }
    void backtrack(vector<int>& nums, vector<bool>& status, unordered_map<int, int>& mp, string& s){
        if(s.size() == nums.size()){
            if(mp[stoi(s)]){
                flag = true;
            }
            mmm[stoi(s)]++;
            return;
        }
        if(s[0] == '0'){
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(flag){
                return;
            }
            if(status[i]){
                continue;
            }
            s += to_string(nums[i]);
            status[i] = true;
            backtrack(nums, status, mp, s);
            s.pop_back();
            status[i] = false;

        }
    }
};

int main() {
    Solution s;
    cout << s.reorderedPowerOf2(1000000000) << endl;
    return 0;
}
