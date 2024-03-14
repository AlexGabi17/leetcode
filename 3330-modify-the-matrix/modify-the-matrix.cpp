class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res = matrix;
        vector<int> max_col(matrix[0].size(), INT_MIN);
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                max_col[j] = max(max_col[j], matrix[i][j]);
            }
        }
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == -1){
                    res[i][j] = max_col[j];
                }
            }
        }
        return res;
    }
};