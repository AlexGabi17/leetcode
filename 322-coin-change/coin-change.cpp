class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int i, dp[10001];
        dp[0]=0;
        for(i=1; i<=amount; i++)
            dp[i]=INT_MAX;
        
        for(i=1; i<=amount; i++){
            for(auto c: coins){
                if(i - c >= 0){
                    if(dp[i-c] != INT_MAX)
                        dp[i] = min(dp[i], dp[i-c]+1);
                }
            }
        }
        if(dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};