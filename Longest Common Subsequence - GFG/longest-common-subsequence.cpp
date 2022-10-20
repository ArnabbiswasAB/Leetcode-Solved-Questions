//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    int lcs(string text1, string text2, int i, int j, vector<vector<int>>& dp){
        

        if(i < 0 || j < 0)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        if(text1[i] == text2[j])
           return dp[i][j] =  1 + lcs(text1, text2, i-1,j-1, dp);

        return dp[i][j] = max(lcs(text1, text2, i-1,j, dp),lcs(text1, text2, i,j-1, dp));
    } 
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m, vector<int>(n,-1));
        return lcs(s1, s2, m-1, n-1, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends