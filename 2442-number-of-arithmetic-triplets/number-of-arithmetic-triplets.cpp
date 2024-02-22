class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        uint8_t count = 0;

        unordered_set<int> set;

        for(int num : nums) set.insert(num);

        for(auto num : nums)
            if(set.find(num - diff) != set.end() && set.find(num + diff) != set.end())
                count ++;
        
        return count;
    }
};