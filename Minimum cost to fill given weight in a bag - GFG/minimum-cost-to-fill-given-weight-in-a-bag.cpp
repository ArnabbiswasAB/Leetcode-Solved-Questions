//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
	public:
	
int f(int i,int cost[], int W,vector<vector<int>>&dp){
	    
	    if(W == 0)
	    return 0;
	    
	    if(i == 0 || W<0)
	    return INT_MAX;
	    
	    if(dp[i][W] != -1)
	    return dp[i][W];
	    
	     int pick = 1e8;
	    if(W>=i && cost[i-1] != -1){
	        pick = cost[i-1] + f(i,cost,W-i,dp);
	    }
	    
	    int notPick = 0 + f(i-1,cost,W,dp);
	    
	    return dp[i][W] = min(pick, notPick);
	}
	

	
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        vector<vector<int>> dp(N+1, vector<int>(W+1,-1));
       int ans = f(N,cost,W,dp);
        if(ans == 1e8)
        return -1;
        
        return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends