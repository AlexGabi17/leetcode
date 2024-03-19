class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        vector<vector<int>> prefSum(n+1, vector<int>(m+1, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i-1 >= 0 && j-1 >=0){
                    prefSum[i][j] -= prefSum[i-1][j-1];
                }
                if(i - 1>=0){
                    prefSum[i][j] += prefSum[i-1][j];
                }
                if(j-1 >=0){
                    prefSum[i][j] += prefSum[i][j-1];
                }
                prefSum[i][j] += matrix[i][j];
            }
        }

        for(int x1 = 0; x1 < n; x1 ++){
            for(int y1 = 0; y1 < m; y1 ++){
                for(int x2 = x1; x2<n; x2 ++){
                    for(int y2 = y1; y2<m; y2 ++){
                        int subSum = prefSum[x2][y2];
                        if(y1 - 1 >=0){
                            subSum -= prefSum[x2][y1-1];
                        }
                        if(x1 - 1 >= 0){
                            subSum -= prefSum[x1-1][y2];
                        }
                        if(x1-1 >=0 && y1-1 >=0){
                            subSum += prefSum[x1-1][y1-1];
                        }
                        if(subSum == target){
                            res ++;
                        }
                    }
                }

            }
        }

        return res;
    }
};