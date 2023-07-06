//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = 1e9+7;
  
    int helper(vector<int>& arr, int ind, int tar, vector<vector<int>>& dp){
         
        if(ind == 0){
            if(arr[0] == 0 && tar == 0)
            return 2;
            else if(arr[0] == tar || tar == 0)
            return 1;
            
            return 0;
        }      
        
        
        if(dp[ind][tar] != -1)
        return dp[ind][tar];
        
        int nt = helper(arr, ind-1, tar, dp)%mod;
        int t = 0;
        
        if(arr[ind] <= tar)
          t = helper(arr, ind-1, tar-arr[ind], dp)%mod;
          
        return dp[ind][tar] = (nt + t)%mod;  
    }
    
    
    int countPartitions(int n, int diff, vector<int>& arr) {
        // Code here
        
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
        }
        
        if((sum - diff) % 2 != 0 || (sum - diff < 0))
        return 0;
        
        int tar = (sum - diff)/2;
        
        vector<vector<int>> dp(n, vector<int>(tar+1, 0));
        //return helper(arr, n-1, tar, dp);
        
        if(arr[0] == 0)
        dp[0][0] = 2;
        else
        dp[0][0] = 1;
        
        
        if(arr[0] != 0 && arr[0] <= tar)
        dp[0][arr[0]] = 1;
        
        
        for(int i=1; i<n; i++){
            for(int j=0; j<tar+1; j++){
                
                int nt = dp[i-1][j] % mod;
                
                int t = 0;
                if(arr[i] <= j)
                t = dp[i-1][j-arr[i]] % mod;
                
                dp[i][j] = (nt + t)%mod;
            }
        }
        
        return dp[n-1][tar];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends