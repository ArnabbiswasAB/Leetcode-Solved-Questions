//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
  int helper(int price[], int ind, int rod, vector<vector<int>>& dp){
    
    if(ind == 0)
    return price[0] * rod;
    
    if(dp[ind][rod] != -1)
    return dp[ind][rod];
    
    int notTaken = helper(price, ind-1, rod, dp);
    int take = INT_MIN;
    int length = ind+1;
    
    if(length <= rod)
      take = price[ind] + helper(price, ind, rod - length, dp);
      
    return dp[ind][rod] = max(notTaken, take);  
  }
  
    int cutRod(int price[], int n) {
        //code here
        
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return helper(price, n - 1, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends