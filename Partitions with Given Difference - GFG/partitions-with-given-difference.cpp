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
    
    
    
    int countPartitions(int n, int diff, vector<int>& num) {
        
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += num[i];
        }
        
       if(sum - diff < 0)
       return 0;
       
       if((sum-diff)%2 == 1)
       return 0;
       
       int tar = (sum - diff)/2;
        
        vector<vector<int>>dp(n, vector<int>(tar+1, 0));
       // return f(n-1, target, arr, dp);
       
       
        if(num[0] == 0)
        dp[0][0] =2;  // 2 cases -pick and not pick
        else
        dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) 
    dp[0][num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken)%mod;
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