class Solution {
public:
    int RecursionAndMemoization(string &s, int i , string &t, int j, vector<vector<int>> &dp){
        if(j == 0) return 1;
        if(i == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = RecursionAndMemoization(s, i-1, t, j, dp);
        if(s[i - 1] == t[j-1] )
            ans += RecursionAndMemoization(s, i-1, t , j-1, dp);
        return dp[i][j] = ans;
    }
    int numDistinct(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
    
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<m+1;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            
            if(s1[i-1]==s2[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    
    return (int)dp[n][m];
    }
};