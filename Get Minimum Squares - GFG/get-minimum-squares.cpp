//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	
	int helper(int target, int ind, vector<vector<int>> &dp){
	    
	     if(ind*ind > target){
            if(!target)
                return 0;
            
            return 1e9;
        }
        else if(ind*ind == target)
            return 1;
	    
	    if(dp[ind][target] != -1)
	    return dp[ind][target];
	    
	    int notPick = helper(target, ind+1, dp);
	    int pick = 0;
	    
	    if(ind*ind <= target)
	        pick = 1 + helper(target - ind*ind, ind, dp);
	        
	    return dp[ind][target] = min(notPick, pick);     
	}
	
	
	int MinSquares(int n)
	{
	    // Code here
	    
	    vector<vector<int>> dp(sqrt(n)+1, vector<int>(n+1,-1));
	    return helper(n,1,dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends