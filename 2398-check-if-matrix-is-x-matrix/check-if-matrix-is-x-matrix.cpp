class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid.size(); j++){
                if((i == j) || (grid.size() - 1 - i == j)){
                    // cout<<grid[i][j]<<" ";
                    if(grid[i][j] == 0) {return false;}
                }
                else{
                    if(grid[i][j] !=0) {return false;}
                }
            }
        }
        return true;
    }
};