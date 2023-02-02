//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    long long f(int i,int buy,vector<long long>& prices,vector<vector<long long>>& dp){
      
      if(i>=prices.size())
      return 0;
      
      if(dp[i][buy] != -1)
      return dp[i][buy];
      
      long long profit = 0;
      
      if(buy == 0){
          profit = max(-prices[i] + f(i+1,1,prices,dp), f(i+1,0,prices,dp));
      }
      
      if(buy == 1){
          profit = max(prices[i] + f(i+2,0,prices,dp), f(i+1,1,prices,dp));
      }
      
      return dp[i][buy] =  profit;
    }
    
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        
        //vector<vector<long long>> dp(n+2, vector<long long>(2,0));
     //   return f(0,0,prices,dp);
     
     vector<long long>curr(2,0);
     vector<long long>front1(2,0);
      vector<long long>front2(2,0);
     
     for(int i=n-1; i>=0; i--){
         
         for(int buy =0; buy<2; buy++){
             
             long long profit = 0;
             
             if(buy == 0){
                 profit = max(-prices[i] + front1[1], front1[0]);
             }
             
             if(buy == 1){
                 profit = max(prices[i] + front2[0], front1[1]);
             }
             
             curr[buy] = profit;
         }
         front2 = front1;
         front1 = curr;
     }
     
     return curr[0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends