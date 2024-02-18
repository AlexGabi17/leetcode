class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp = nums;
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        if(n == 3) return max({nums[0], nums[1], nums[2]});
        int max_ = INT_MIN;
        for(int i=2; i<n-1; i++){ // calculate without last house
            for(int j=0; j<=i-2; j++){
                // cout<<i<<"\n";
                dp[i] = max(dp[i], dp[j] + nums[i]);
                if(dp[i] > max_) max_ = dp[i];
            }
        }
        dp = nums;
        for(int i=2; i<n; i++){ // calculate without first element
            for(int j=1; j<=i-2; j++){
                dp[i] = max(dp[i], dp[j] + nums[i]);
                if(dp[i] > max_) max_ = dp[i];
            }
        }
        return max_;
    }
};