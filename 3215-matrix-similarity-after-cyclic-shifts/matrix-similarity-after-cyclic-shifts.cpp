class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        for(const auto& row: mat){
            uint8_t n = row.size();
            for(int i=0; i<n; ++i){
                if(row[i] != row[(i+k)%n]){
                    return false;
                }
            }
        }
        return true;
    }
};