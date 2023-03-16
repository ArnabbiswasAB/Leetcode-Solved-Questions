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
	    
	    vector<int>arr;
	    
	    for(int i=1; i*i<=n; i++){
	        arr.push_back(i*i);
	    }
	    
	    int m = arr.size();
	    vector<vector<int>> dp(m+1, vector<int>(n+1,0));
	  
	    for(int i=1; i<n+1; i++){
	        dp[m][i] = 1e9;
	    }
	      
	      
	    for(int i=m-1; i>=0; i--){
	        for(int j=0; j<n+1; j++){
	            
	            int notPick = dp[i+1][j];
	            int pick = 1e9;
	            
	            if(arr[i] <= j)
	              pick = 1 + dp[i][j-arr[i]];
	            
	            dp[i][j] = min(pick,notPick);  
	        }
	    }  
	    
	    return dp[0][n];
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