//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int helper(int A[],int ind,int N,int buy,int cap, vector<vector<vector<int>>> &dp){
   
   if(ind == N || cap == 0)
   return 0;
   
   
   if(dp[ind][buy][cap] != -1)
   return dp[ind][buy][cap];
   
   int profit = 0;
   
   if(buy == 0){
       profit = max(-A[ind] + helper(A,ind+1,N,1,cap,dp),
       helper(A,ind+1,N,0,cap,dp));
   }
   
   
   if(buy == 1){
       profit = max(A[ind] + helper(A,ind+1,N,0,cap-1,dp),
       helper(A,ind+1,N,1,cap,dp));
   }
   
   
   return dp[ind][buy][cap] = profit;
  }
  
  
    int maxProfit(int K, int N, int A[]) {
        // code here
        
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(2,vector<int>(K+1,-1)));
        return helper(A,0,N,0,K,dp);        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends