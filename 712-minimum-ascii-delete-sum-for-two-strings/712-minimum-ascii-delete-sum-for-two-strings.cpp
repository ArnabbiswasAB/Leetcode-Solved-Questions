class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        
         int m=s1.length(),n=s2.length();
        int dp[m+1][n+1];
        int sum1=0,sum2=0;
        
        for(int i=0;i<m;i++)
            sum1+=s1[i];
        
        
          for(int i=0;i<n;i++)
              sum2+=s2[i];
        
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                else{
                   
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return sum1+sum2-2*dp[m][n];
        
    }
};