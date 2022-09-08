class Solution {
public:
    int solve(vector<int>& nums , int i, int e , vector<vector<int>> &dp){
     
        if(i>e) 
            return 0;
        
        if(dp[i][e] != -1)
            return dp[i][e];
        
        int op1 = nums[i] + min(solve(nums,i+2,e,dp), solve(nums,i+1,e-1,dp));
        
        int op2 = nums[e] + min(solve(nums,i,e-2,dp), solve(nums,i+1,e-1,dp));
        
        return dp[i][e] = max(op1,op2);
    }
    
    
    bool PredictTheWinner(vector<int>& nums) {
         // if both player will play optimally then
        // palyer 1 will pick best optimall index and then player 2 will choose optimal index too to win
        // let us find total sum and then find if player 1 play optimally then his score and then see .
        int tsum = 0;
        for(int x: nums) tsum += x;
        vector<vector<int>> dp(nums.size() , vector<int> (nums.size(), -1));
        int s = solve(nums,0 , nums.size()-1 , dp);
        return s >= tsum-s ? 1:0;
    }
};