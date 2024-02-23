class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            unordered_set<int> set;
            for(int j=i; j<nums.size(); j++){
                if(set.find(nums[j]) == set.end()){
                    set.insert(nums[j]);
                }
                res += set.size() * set.size();
            }
            
        }
        return res;
    }
};