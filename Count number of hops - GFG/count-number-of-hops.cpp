//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
     int mod = 1e9 + 7;
   
    long long helper(int n, vector<long long> &dp){
        
        if(n<0)
        return 0;
        
        
        if(n == 0)
        return 1;
        
        if(dp[n] != -1)
        return dp[n];
        
        int ways = 0;
        for(int i=1; i<=3; i++){
            ways = (ways %  mod + helper(n-i, dp) % mod)%mod;
        }
        
        return dp[n] = ways;
    }
   
    long long countWays(int n)
    {
     vector<long long>dp(n+1,-1);
     return helper(n, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends