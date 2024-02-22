class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        uint8_t count = 0;

        unordered_map<int, bool> mp;

        for(int num : nums) mp[num] = true;

        for(auto num : nums)
            if(mp[num - diff] && mp[num + diff]) count ++;
        
        return count;
    }
};