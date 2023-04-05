//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    int helper(vector<int>& a,int i, int j, vector<vector<int>>& dp){
     
     if(i>j)
     return 0;
     
     if(dp[i][j] != -1)
     return dp[i][j];
     
     int maxi = INT_MIN;
     
     for(int k=i; k<=j; k++){
         
         int cost = a[i-1]*a[k]*a[j+1] + helper(a,i,k-1,dp) + 
         helper(a,k+1,j,dp);
         maxi = max(maxi, cost);
     }
     
     return dp[i][j] = maxi;
    }
    
    
        int maxCoins(int N, vector <int> &a)
        {
                // write your code here
                int n = a.size();
                a.push_back(1);
                a.insert(a.begin(),1);
                
                vector<vector<int>> dp(N+1, vector<int>(N+1,-1));
                
                int ans = helper(a,1,n,dp);
                return ans;
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends