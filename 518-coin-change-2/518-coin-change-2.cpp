class Solution {
public:
   int countWaysToMakeChangeUtil(vector<int>& arr,int ind, int amt, vector<vector<int>>& dp){
       
    if(ind == 0){
        return ( amt%arr[0]==0);
    }
    
    if(dp[ind][ amt]!=-1)
        return dp[ind][ amt];
        
    int notTaken = countWaysToMakeChangeUtil(arr,ind-1, amt ,dp);
    
    int taken = 0;
    if(arr[ind] <= amt)
        taken = countWaysToMakeChangeUtil(arr,ind,amt -arr[ind],dp);
        
    return dp[ind][amt] = notTaken + taken;
}
    
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
         vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    return countWaysToMakeChangeUtil(coins,n-1, amount, dp);
    }
};