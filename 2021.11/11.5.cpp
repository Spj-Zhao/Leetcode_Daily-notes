class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<int> dp(n, 1);
        //储存下标,时间复杂度变  O(n)
        unordered_map<int, vector<int>> mp;
        int ans = -1;
        for(int i = 0; i < n; ++i){
            vector<int> tar = mp[arr[i] - difference];
            if(tar.size()){
                for(int j : tar){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                
            }
            mp[arr[i]].push_back(i);
            // for(int j = 0; j < i; ++j){
            //     if(arr[i] == arr[j] + difference){
            //         dp[i] = max(dp[i], dp[j] + 1);
            //     }
            // }
            ans = max(ans ,dp[i]);
        }
        return ans;
    }
};
