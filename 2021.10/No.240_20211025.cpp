class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, clom = n - 1;
        while(row < m && clom >= 0){
            if(matrix[row][clom] == target){
                return true;
            }else if(matrix[row][clom] > target){
                --clom;
            }else{
                ++row;
            }
        }
        return false;
    }
};
