class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        unordered_map<char, int> mp3;
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        for(char c : s1){
            ++mp1[c];
            ++mp1[c - 32];
        }
        for(char c : s2){
            ++mp2[c];
            ++mp2[c - 32];
        }
        for(char c : s3){
            ++mp3[c];
            ++mp3[c - 32];
        }
        vector<string> ans;
        for(string& s : words){
            if(mp1.count(s[0])){
                for(int i = 0; i < s.size(); ++i){
                    if(mp1[s[i]] && i == s.size() - 1){
                        ans.push_back(s);
                    }
                    if(mp1[s[i]] == 0){
                        break;
                    }
                }
            }
            if(mp2.count(s[0])){
                for(int i = 0; i < s.size(); ++i){
                    if(mp2[s[i]] && i == s.size() - 1){
                        ans.push_back(s);
                    }
                    if(mp2[s[i]] == 0){
                        break;
                    }
                }
            }
            if(mp3.count(s[0])){
                for(int i = 0; i < s.size(); ++i){
                    if(mp3[s[i]] && i == s.size() - 1){
                        ans.push_back(s);
                    }
                    if(mp3[s[i]] == 0){
                        break;
                    }
                }
            }
        }
        return ans;

    }
};
