class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
      //  vector<vector<int>>dp(n,vector<int>(amount+1,0));
        vector<int>prev(amount+1,0);
        
        for(int i=0; i<=amount; i++)
            if(i%coins[0] == 0)
                prev[i] = 1;
        
        for(int i=1; i<n; i++){
            vector<int>curr(amount+1,0);
            for(int j=0; j<=amount; j++){
                
                int notTaken = prev[j];
                int taken = 0;
                if(coins[i]<=j)
                    taken = curr[j-coins[i]];
                
                curr[j] = notTaken + taken;
            }
            prev=curr;
        }
        
        return prev[amount];
    }
};