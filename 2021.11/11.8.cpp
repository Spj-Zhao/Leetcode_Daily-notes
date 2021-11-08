class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0,  B = 0;
        int n = secret.size();
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(int i = 0; i < n; ++i){
            if(secret[i] == guess[i]){
                ++A;
            }
            ++mp1[secret[i]];
            ++mp2[guess[i]];
        }
        for(auto& p : mp1){
            B += min(p.second, mp2[p.first]);
        }
        string ans = "";
        ans = ans + to_string(A) + 'A' + to_string(B - A) + 'B';
        return ans;
    }
};
