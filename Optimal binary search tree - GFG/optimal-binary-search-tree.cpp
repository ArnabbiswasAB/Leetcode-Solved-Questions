//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

/*
Time Complexity: O(n³)

Space Complexity: O(n²) auxiliary + O(n) stack space
*/
class Solution{
    public:
    vector<vector<int>> dp;
    int getAns(int i, int j, int freq[]){
        if(i==j) return freq[i];
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            ans=min(ans,getAns(i,k-1,freq)+getAns(k+1,j,freq));
        }
        for(int k=i;k<=j;k++)
            ans+=freq[k];
        return dp[i][j]=ans;
    }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        dp.assign(n,vector<int> (n,-1));
        return getAns(0, n-1 ,freq);
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
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends