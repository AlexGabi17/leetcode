class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2));
        int index1 = 0, index2 = 0;
        for(int i = 0; i< n - 2; ++i)
            for(int j = 0; j< n - 2; ++j)
                for(int ii = i; ii<i+3; ++ii)
                    for(int jj = j; jj<j+3; ++jj)
                        res[i][j] = max(res[i][j], grid[ii][jj]);
        return res;
    }
};