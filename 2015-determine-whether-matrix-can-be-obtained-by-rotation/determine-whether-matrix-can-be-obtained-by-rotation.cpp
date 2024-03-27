class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<bool> r(4, true);
        int n = mat.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] != target[i][j]) r[0] = false;
                if(mat[i][j] != target[n-j-1][i]) r[1] = false;
                if(mat[i][j] != target[n-i-1][n-j-1]) r[2] = false;
                if(mat[i][j] != target[j][n-i-1]) r[3] = false;
            }
        }
        return r[0] || r[1] || r[2] || r[3];

        /*
        [1,2,3] ---> [7,4,1] 
        [4,5,6]      [8,5,2]
        [7,8,9]      [9,6,3]
        
        mat[0][3] = 3
        mat[3][n-i-1]
        */

    }
};