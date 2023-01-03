//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int helper(string A,string B,string C,int l1,int l2,int l3,vector<vector<int>>& dp){
        
        if(l1 < 0 && l2 < 0 && l3 < 0)
        return true;
        
        if(l1>=0 && l2>=0 && dp[l1][l2] != -1)
        return dp[l1][l2];
        
        if(l1>=0 && A[l1] == C[l3] && l2>=0 && B[l2] == C[l3])
        return dp[l1][l2] = helper(A,B,C,l1-1,l2,l3-1,dp) ||
                            helper(A,B,C,l1,l2-1,l3-1,dp);
                            
                            
        else if(l1>=0 && A[l1] == C[l3])
        return helper(A,B,C,l1-1,l2,l3-1,dp);
        else if(l2>=0 && B[l2] == C[l3])
        return helper(A,B,C,l1,l2-1,l3-1,dp);
        else
        return false;
    }
    
    
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        
        if(A.size() + B.size() != C.size())
        return false;
        
        
        vector<vector<int>> dp(A.size(), vector<int>(B.size(),-1));
        return helper(A,B,C,A.size()-1,B.size()-1,C.size()-1,dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends