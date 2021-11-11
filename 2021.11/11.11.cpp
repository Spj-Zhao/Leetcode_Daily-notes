class Solution {
// private:
//     static constexpr int mod = 1000000007;

// public:
//     int kInversePairs(int n, int k) {
//         vector<vector<int>> dp (n + 1, vector<int>(k + 1));
//         dp[0][0] = 1;
//         for(int i = 1; i <= n; ++i){
//             for(int j = 0; j <= k; ++j){
//                 dp[i][j] = (j - 1 >= 0 ? dp[i][j-1]  : 0)  - (j - i >= 0 ? dp[i-1][j-i]  : 0)  + dp[i-1][j] ;
//                 if (dp[i][j] >= mod) {
//                     dp[i][j] -= mod;
//                 }
//                 else if (dp[i][j] < 0) {
//                     dp[i][j] += mod;
//                 }
//             }
//         }
//         return dp[n][k];
//     }
// };


class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> f(2, vector<int>(k + 1));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                int cur = i & 1, prev = cur ^ 1;
                f[cur][j] = (j - 1 >= 0 ? f[cur][j - 1] : 0) - (j - i >= 0 ? f[prev][j - i] : 0) + f[prev][j];
                if (f[cur][j] >= mod) {
                    f[cur][j] -= mod;
                }
                else if (f[cur][j] < 0) {
                    f[cur][j] += mod;
                }
            }
        }
        return f[n & 1][k];
    }
};


