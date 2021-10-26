class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans(n1);
        unordered_map<int, int> mp;
        for(int i = n2 - 1; i >= 0; --i){
            while(!stk.empty() && nums2[i] >= stk.top()){
                stk.pop();
            }
            mp[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }
        for(int i = 0; i < n1; ++i){
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};
