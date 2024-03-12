class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> res;
        unordered_map<int, int> freq;
        int doubled, count_ = 0;
        for(auto row: grid){
            for(int elem: row){
                if(freq.find(elem) == freq.end()){
                    freq[elem] = 1;
                    count_ += elem;
                }
                else{
                    freq[elem] = freq[elem] + 1;
                    doubled = elem;
                }
            }
        }
        res.push_back(doubled);
        res.push_back((grid.size() * grid.size()*(grid.size() * grid.size()+1))/2 - count_);
        return res;
    }
};