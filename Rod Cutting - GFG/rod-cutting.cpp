//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
  int f(int ind, int price[], int N, vector<vector<int>>& dp){
      
      if(ind == 0){
          return N*price[0];
      }
      
      if(dp[ind][N] != -1)
      return dp[ind][N];
      
      int notTaken = f(ind - 1, price, N, dp);
      
      int taken = INT_MIN;
      int len = ind + 1;
      if(len <= N)
      taken = price[ind] + f(ind ,price, N-len, dp);
      
      return dp[ind][N] = max(notTaken, taken);
      
  }
  
  
    int cutRod(int price[], int n) {
        //code here
        
        vector<vector<int>>dp (n, vector<int>(n+1,-1));
        return f(n-1,price,n,dp);
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