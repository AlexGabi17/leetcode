class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // frequency hashmap
        int count = 0;
        unordered_map<int, int> mp;
        for(auto x : nums){
            if(mp.find(x) == mp.end()) mp[x] = 0;
            else mp[x] = mp[x] + 1;
        }
        for(auto e : mp){
            if(e.second !=0) count += ( (e.second+1) * ( (e.second + 1) - 1 ) ) / 2;
        }
        return count;
    }
};