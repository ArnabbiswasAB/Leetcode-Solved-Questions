//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    
    vector<int>res(256,-1);
    int i=0,j=0, n = s.size(), ans = 0;
    
    while(i<n){
        
        if(res[s[i]] != -1)
           j = max(j, res[s[i]] + 1);
           
        res[s[i]] = i;
        ans = max(ans, i - j + 1);
        i++;
    }
    
    return ans;
}