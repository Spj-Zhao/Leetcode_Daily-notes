class Solution {
public:
    int distributeCandies(vector<int> &candyType) {
        return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
    }
};

///////
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        sort(candyType.begin(), candyType.end());
        int pre = 100001;
        int ans = 0;
        for(int i = 0; i < n && ans <= n / 2; ++i){
            if(candyType[i] != pre){
                ++ans;
                pre = candyType[i];
            }
        }
        return ans > n / 2 ? n / 2 : ans;
    }
};
