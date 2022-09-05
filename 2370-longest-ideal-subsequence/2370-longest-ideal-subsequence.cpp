class Solution {
public:
    //Tim eComplexity - O(K*N)
    int longestIdealString(string s, int k) {
        
       vector<int> dp(26,0);
    for (int i=0;i<s.length();i++)
    {
        int ptr=int(s[i])-int('a');
        int l=max(0,ptr-k);
        int r=min(25,ptr+k);
        int ele=0;
        for (int j=l;j<=r;j++)
        {
            ele=max(ele,dp[j]);
        }
        dp[ptr]=ele+1;  
    }
    int ans=0;
    for (int i=0;i<dp.size();i++)
    {
        ans=max(ans,dp[i]);
    }
    return ans;
    }
};