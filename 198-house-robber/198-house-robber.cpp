class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n= nums.size();
        int dp[n];
        
        if(n>=1)
            dp[0] = nums[0];
        
        if(n>=2)
            dp[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<n; i++)
        {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        
      return dp[n-1];  
    }
};