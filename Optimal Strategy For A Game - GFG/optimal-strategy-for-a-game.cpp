//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    
    long long helper(int arr[],int start, int end,vector<vector<long long>> &dp){
      
      if(start > end)
      return 0;
      
      if(dp[start][end] != -1)
      return dp[start][end];
      
      long long int op1 = arr[start] + min(helper(arr,start+1,end-1,dp),
       helper(arr,start+2,end,dp));
       
       
      long long int op2 = arr[end] + min(helper(arr,start,end-2,dp),
      helper(arr,start+1,end-1,dp));
       
      return dp[start][end] = max(op1,op2); 
    }
    
    
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<long long>> dp(n, vector<long long>(n,-1));
        return helper(arr, 0 , n-1, dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends