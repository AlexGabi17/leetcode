class Solution {
    bool verifyDiagonal(vector<vector<int>>& matrix, int row, int col){
        int prev = matrix[row][col];
        for(int i=row, j=col; i<matrix.size() && j<matrix[0].size(); i++, j++){
            if(matrix[i][j] != prev){
                return false;
            }
            else{
                prev = matrix[i][j];
            }
        }
        return true;
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix[0].size(); i++){
            if(!verifyDiagonal(matrix, 0, i)) return false;
        }
        for(int j=1; j<matrix.size(); j++){
            if(!verifyDiagonal(matrix, j, 0)) return false;
        }
        return true;
    }
};