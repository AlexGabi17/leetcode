class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count1(101, 0);
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            count1[nums[i]] ++;
        }
       for(int i=1; i< 101; i++){
            count1[i] += count1[i-1];
        }
        for(int i=0; i< nums.size(); i++){
            if(nums[i] == 0) res.push_back(nums[i]);
            else res.push_back(count1[nums[i]-1]);
        }
      
        return res;

    }
};