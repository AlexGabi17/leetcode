class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        for(int i=0; i<matrix.size(); i++){
            int minim = matrix[i][0];
            int j_pos = 0;
            for(int j=0; j<matrix[i].size(); j++){
                if(minim > matrix[i][j]){
                    minim = matrix[i][j];
                    j_pos = j;
                }
            }
            bool check = true;
            for(int col = 0; col<matrix.size(); col++){
                if(minim<matrix[col][j_pos])
                    check = false;
            }
            if(check)
                res.push_back(minim);
        }
        return res;
    }
};