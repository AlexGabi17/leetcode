class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) return vector<vector<int>>();
        
        vector<vector<int>> res(m, vector<int>(n, 0));
        uint16_t x = 0, y = 0;
        for(int i = 0; i < original.size(); i ++){
            res[x][y] = original[i];
            if(y + 1 == n){
                y = 0;
                x ++;
            }
            else{
                y ++;
            }
        }

        return res;
    }
};