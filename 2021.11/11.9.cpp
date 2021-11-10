class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if(n == 1){
            return duration;
        }
        int ans = 0;
        for(int i = 1; i < n; ++i){
            if(timeSeries[i] - timeSeries[i - 1] < duration){
                ans += timeSeries[i] - timeSeries[i - 1];
            }else{
                ans += duration;
            }
        }
        return ans + duration;
    }
};
