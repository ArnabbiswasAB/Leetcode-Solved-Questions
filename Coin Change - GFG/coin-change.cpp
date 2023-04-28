//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int helper(int coins[], int ind, int sum,vector<vector<long long>> &dp){
        
        if(sum == 0)
        return 1;
        
        if(ind == 0){
            if(sum % coins[ind] == 0)
            return 1;
            
            return 0;
        }
        
        if(dp[ind][sum] != -1)
        return dp[ind][sum];
        
        long long int nT = helper(coins, ind-1, sum, dp);
        long long int t = 0;
        
        if(coins[ind] <= sum)
           t = helper(coins, ind, sum - coins[ind], dp);
           
        return dp[ind][sum] = nT + t;   
        
    }
    
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long>> dp(N, vector<long long>(sum + 1, -1));
        return helper(coins, N-1, sum, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends