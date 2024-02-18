class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        unordered_set<int> set;

        for(auto e : nums)
            set.insert(e);

        for(int i=0; i<nums.size(); i++)
            if(set.find(i) == set.end()) return i;

        return nums.size();
    }
};