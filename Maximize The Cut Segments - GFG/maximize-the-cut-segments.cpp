//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int helper(int N,int x,int y,int z,vector<int>& dp){
     
     if(N == 0)
     return 0;
     
     if(N<0)
     return INT_MIN;
     
     if(dp[N] != -1)
     return dp[N];
     
     int a = 0, b = 0, c = 0;
     
     
         a = 1 + helper(N-x,x,y,z,dp);
          
    
         b = 1 + helper(N-y,x,y,z,dp);
         
     
         c = 1 + helper(N-z,x,y,z,dp); 
         
         
     return dp[N] = max(a, max(b,c));         
    }
    
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,-1);
        int ans =  helper(n,x,y,z,dp);
        
        if(ans < 0)
        return 0;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends