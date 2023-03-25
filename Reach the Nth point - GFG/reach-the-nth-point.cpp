//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int mod = 1e9 + 7;
	    
	    int helper(int ind, vector<int>& dp){
	        
	        if(ind < 0)
	        return 0;
	        
	        if(ind == 0)
	        return 1;
	        
	        if(dp[ind] != -1)
	        return dp[ind] % mod;
	        
	        int ways = 0;
	        for(int i=1; i<=2; i++){
	            ways = (ways + helper(ind - i, dp)%mod)%mod;
	        }
	        
	        return dp[ind] = ways;
	    }
	    
	    
		int nthPoint(int n){
		    
		    vector<int>dp(n+1,-1);
		    
		    return helper(n,dp);
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
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends