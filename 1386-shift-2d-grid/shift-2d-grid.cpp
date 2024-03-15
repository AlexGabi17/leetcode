class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size()));
        k = k % (grid.size() * grid[0].size());
        //cout << k<<"\n";
        int x=0, y=0;
        while(x<grid.size() && k){
            while(y<grid[0].size() && k){
                k --;
                y ++;
  
            }
            if(k == 0) break;
            y=0;
            x ++;
        }
        cout<<x<<" "<<y<<'\n';
        if(y == grid[0].size()){
            y = 0;
            x ++;
        }
        cout<<"\n\n";
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                res[x][y] = grid[i][j];
                // cout<<x<<" "<<y<<'\n';
                if(y + 1 < grid[0].size()){
                    y++;
                }
                else{
                    if(x + 1 < grid.size()){
                        x ++;
                    }
                    else{
                        x = 0;
                    }
                    y=0;
                }
            }
        }
        return res;
    }
};