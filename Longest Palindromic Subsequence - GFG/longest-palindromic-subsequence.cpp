//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int helper(string A, int i, string temp, int j, vector<vector<int>> &dp){
        
        if(i<0 || j<0)
        return 0;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        if(A[i] == temp[j])
          return dp[i][j] = helper(A,i-1,temp,j-1,dp) + 1;
        
        return dp[i][j] = max(helper(A,i-1,temp,j,dp), helper(A,i,temp,j-1,dp));  
    }
    
    int longestPalinSubseq(string A) {
       
        int n = A.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        string temp = A;
        reverse(temp.begin(),temp.end());
        
        return helper(A,n-1, temp, n-1, dp);
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