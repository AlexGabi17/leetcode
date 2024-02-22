class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count  = 0;

        unordered_map<int, int> mp;

        for(int num : nums){
            if(mp.find(num) != mp.end()){
                mp[num] ++;
            }
            else
                mp[num] = 1;
        }
        
        for(int num : nums){
            if(mp[abs(num - k)] && num != abs(num-k)){
                count += mp[num - k];
            }
        }
        return count;
    }
};