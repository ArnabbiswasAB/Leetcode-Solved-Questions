class Solution {
public:
    
    /*
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
    
    */
     int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
         int dp[n+1][amount+1];
         
         for(int i=0; i<n+1; i++){
             for(int j=0; j<amount+1; j++){
                 
                 if(i == 0)
                     dp[i][j] = 0;
                 else if(j == 0)
                     dp[i][j] = 1;
                 else if(j < coins[i-1])
                     dp[i][j] = dp[i-1][j];
                 else
                     dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
             }
         }
         
         return dp[n][amount];
    }
};