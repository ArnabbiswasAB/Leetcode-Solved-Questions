class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        if(n==1)
            return 1;
        
        int maxi = INT_MIN;
        int dp[n];
        dp[0]=1;
        sort(pairs.begin(), pairs.end());
        
        for(int i=1; i<n; i++){
            dp[i]=1;
            for(int j=0; j<i; j++){
                
            
                if( pairs[j][1] < pairs[i][0])
                {
                    dp[i] = max(dp[i] , dp[j] + 1);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        
        return maxi;
    }
};