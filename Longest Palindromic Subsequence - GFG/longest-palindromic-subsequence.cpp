//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
  int helper(string A,string B,int m,int n,vector<vector<int>>& dp){
   
   if(m < 0 || n < 0)
   return 0;
   
   if(dp[m][n] != -1)
   return dp[m][n];
   
   if(A[m] == B[n])
      return dp[m][n] = 1 + helper(A,B, m-1, n-1, dp);
      
   
   return dp[m][n] = max(helper(A,B,m-1,n,dp), helper(A,B,m,n-1,dp));      
  }
  
  
    int longestPalinSubseq(string A) {
        //code here
        string B = A;
        reverse(B.begin(), B.end());
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return helper(A,B,n-1,n-1,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends