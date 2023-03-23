//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int helper(int s,int e,int arr[],vector<vector<int>>& dp){
	    
	    if(s>=e)
	    return 0;
	    
	    if(dp[s][e] != -1)
	    return dp[s][e];
	    
	    int op1 = arr[s] + min(helper(s+1,e-1,arr,dp), helper(s+2,e,arr,dp));
	    int op2 = arr[e] + min(helper(s+1,e-1,arr,dp), helper(s,e-2,arr,dp));
	    
	    return dp[s][e] = max(op1,op2);
	}
	
	
	int maxAmount(int arr[], int n)
	{
		
		vector<vector<int>> dp(n, vector<int>(n,-1));
		return helper(0,n-1,arr,dp);
	}
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

	   

	    Solution ob;
	    cout << ob.maxAmount(a, n) << "\n";

	     
    }
    return 0;
}

// } Driver Code Ends