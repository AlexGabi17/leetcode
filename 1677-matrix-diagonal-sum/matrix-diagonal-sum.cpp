class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum_ = 0, i, n = mat.size();
        for(i=0; i<n; i++)
            sum_ += mat[i][i];
        for(i=n-1; i > -1; i --)
            if(n-1-i != i)
                sum_ += mat[i][n-1-i]; 
        return sum_;
    }
};