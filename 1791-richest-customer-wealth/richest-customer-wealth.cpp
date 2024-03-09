class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_ = INT_MIN, sum_;
        for(vector<int> row: accounts){
            sum_ = 0;
            for(int elem: row){
                sum_ += elem;
            }
            if(sum_ > max_) max_ = sum_;
        }
        
        return max_;
    }
};