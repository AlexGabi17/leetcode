class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        dp[0]=1;
        for(int i=1; i<nums.size(); i++)
            dp[i]=-1;

        for(int i=1; i< nums.size(); i++)
        {
            bool found = false;
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                    found = true;
                }
            }
            if(found == false)
                dp[i]=1;
        }
        int longest=-1;
        for(int i=0; i<nums.size();i++)
            if(dp[i]>longest) longest = dp[i];
        return longest;
    }
};