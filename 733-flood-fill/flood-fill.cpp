class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int >> q;
        int init = image[sr][sc];
        if(init == color) return image;
        q.push({sr,sc});
        while(!q.empty()){
            pair<int, int> pos = q.front();
            q.pop();
            cout<<pos.first<<" "<<pos.second<<'\n';
            image[pos.first][pos.second] = color;

            if(pos.first + 1 < image.size() && image[pos.first + 1][pos.second] == init){
                q.push({pos.first + 1, pos.second});
            }
            if(pos.first - 1 >= 0 && image[pos.first - 1][pos.second] == init){
                q.push({pos.first - 1, pos.second});
            }
            if(pos.second + 1 < image[0].size() && image[pos.first][pos.second + 1] == init){
                q.push({pos.first, pos.second + 1});
            }
            if(pos.second - 1 >= 0 && image[pos.first][pos.second - 1] == init){
                q.push({pos.first, pos.second - 1});
            }

        }
        return image;
    }
};