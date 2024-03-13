class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        vector<vector<int>> res(rows*cols, vector<int>(2));
        queue<vector<int>> q;
        q.push({rCenter, cCenter});
        int i = 0;
        while(!q.empty()){
            vector<int> cell = q.front();
            q.pop();
            int r = cell[0], c = cell[1];
            if(r < 0 || r >= rows || c < 0 || c >= cols){
                continue;
            }
            if(visited[r][c]){
                continue;
            }
            res[i] = cell;
            i++;
            visited[r][c] = true;
            q.push({r, c-1});
            q.push({r, c+1});
            q.push({r-1, c});
            q.push({r+1, c});
        }
        return res;
    }
};