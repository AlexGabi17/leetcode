class Solution {
    int countNeighbours(vector<vector<int>>& grid, int i, int j){
        int count = 0;
        if(i - 1 >= 0){
            if(grid[i-1][j] != 1) count ++;
        }
        else
            count ++;
        if(j- 1 >= 0){
            if(grid[i][j-1] != 1) count ++;
        }
        else
            count ++;
        if(i + 1 < grid.size()){
            if(grid[i+1][j] != 1) count ++;
        }
        else
            count ++;
        if(j + 1 < grid[0].size()){
            if(grid[i][j+1] != 1 ) count ++;
        }
        else count ++;
        return count;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int total = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    // out<< i<<" "<<j<<"->"<<countNeighbours(grid, i, j)<<'\n';
                    total += countNeighbours(grid, i, j);
                }
            }
        }
        return total;
    }
};