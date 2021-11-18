11.13
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n == 1){
            return true;
        }
        int flag = 0;
        if(isupper(word[0])){
            flag = 1;
        }
        if(flag == 1){
            if(isupper(word[1])){
                for(int i = 2; i < n; ++i){
                    if(islower(word[i])){
                        return false;
                    }
                }
            }else{
                for(int i = 2; i < n; ++i){
                    if(isupper(word[i])){
                        return false;
                    }
                }
            }
        }
        if(flag == 0){
            for(int i = 1; i < n; ++i){
                if(isupper(word[i])){
                    return false;
                }
            }
        }
        return true;
    }
};

11.14
class MapSum {
public:
    MapSum() {

    }
    
    void insert(string key, int val) {
        cnt[key] = val;
    }
    
    int sum(string prefix) {
        int res = 0;
        for (auto & [key,val] : cnt) {
            if (key.substr(0, prefix.size()) == prefix) {
                res += val;
            }
        }
        return res;
    }
private:
    unordered_map<string, int> cnt;
};

11.15
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n + 0.5);
    }
};

11.16
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<string, int> mp;
        for(vector<int>& rec : rectangles){
            string LU = to_string(rec[0]) + ',' + to_string(rec[3]);
            string LD = to_string(rec[0]) + ',' + to_string(rec[1]);
            string RU = to_string(rec[2]) + ',' + to_string(rec[3]);
            string RD = to_string(rec[2]) + ',' + to_string(rec[1]);
            if(++mp[LU] == 0){
                mp.erase(LU);
            }
            if(++mp[RD] == 0){
                mp.erase(RD);
            }
            if(--mp[LD] == 0){
                mp.erase(LD);
            }
            if(--mp[RU] == 0){
                mp.erase(RU);
            }
        }
        int flag1 = 0, flag2 = 0;
        for(auto & a : mp){
            if(a.second == 1){
                ++flag1;
            }
            if(a.second == -1){
                ++flag2;
            }
        }
        return mp.size() == 4 && flag1 ==2 && flag2 == 2;
    }
};

11.17
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> mp;
        for(string& word : words){
            int mask = 0;
            for(char c : word){
                mask |= 1 << (c - 'a');
            }
            if(mp.count(mask)){
                if(word.size() > mp[mask]){
                    mp[mask] = word.size();
                }
            }else{
                mp[mask] = word.size();
            }
        }
        int ans = 0;
        for(auto & [mask1, _] : mp){
            for(auto & [mask2, _] : mp){
                if((mask1 & mask2) == 0){
                    ans = max(ans, mp[mask1] * mp[mask2]);
                }
            }
        }
        return ans;
    }
};

11.18
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans = 0;
public:
    int findTilt(TreeNode* root) {
        if(!root){
            return 0;
        }
        sum(root);
        return ans;
       
    }
    int sum(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftsum = sum(root->left);
        int rightsum = sum(root->right);
        ans += abs(leftsum - rightsum);
        return  leftsum + rightsum + root->val;
    }
};
