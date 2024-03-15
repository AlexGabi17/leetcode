class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s; 
        if(s.size() == 2 && s[0]!=s[1]) return s.substr(0, 1);
        else if(s.size() == 2 && s[0] == s[1]) return s; 
        int n = s.size(), max_length = -1, max_index;
        int startIndex = 0; int maxlen = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            dp[i][i]=1;
        }
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(j-i == 1 && s[i] == s[j]){
                    dp[i][j]=1;
                } 
                else{
                    dp[i][j]=0;
                }
                if(dp[i+1][j-1] == 1 && s[i] == s[j]){
                    dp[i][j]=1;
                }

            }
        }

        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                if(dp[i][j] == 1){
                    if(j-i+1>max_length){
                        max_index = i;
                        max_length = j-i+1;
                    }
                }
            }
        }
        if(max_length == 0) return "";
        return s.substr(max_index, max_length);
    }
};