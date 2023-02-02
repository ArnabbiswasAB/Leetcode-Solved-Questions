//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = 1e9 + 7;
    
    int f(int i,int sum, vector<int>& arr, vector<vector<int>>& dp){
        
        if(i == 0){
            if(sum == 0 && arr[0] == 0)
            return 2;
            if(sum == 0 || arr[0] == sum)
            return 1;
            
            return 0;
        }
        
        if(dp[i][sum] != -1)
        return dp[i][sum];
        
        int notTaken = f(i-1,sum,arr,dp)%mod;
        int taken = 0;
        
        if(arr[i] <= sum)
           taken = f(i-1,sum - arr[i], arr, dp)%mod;
           
        return dp[i][sum] = (notTaken + taken)%mod;   
    }
    
    
    
    int countPartitions(int n, int diff, vector<int>& arr) {
        
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
        }
        
       if(sum - diff < 0)
       return 0;
       
       if((sum-diff)%2 == 1)
       return 0;
       
       int target = (sum - diff)/2;
        
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return f(n-1, target, arr, dp);
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