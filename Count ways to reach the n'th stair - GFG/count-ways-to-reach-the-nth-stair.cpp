//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int MOD = 1e9 + 7;
    
       int mem(int n, vector<int> &dp){

        if(n==1) return 1;

        if(n==2 )return 2;

        if(dp[n]!=-1) return dp[n];

        return dp[n]=(mem(n-1, dp)+mem(n-2, dp))%MOD;

    }

    int tab(int n){

        int prevprev=1;

        int prev=2;

        if(n==1) return prevprev;

        if(n==2) return prev;

        int curr;

        for(int i=3;i<=n;i++){

            curr=(prevprev+prev)%MOD;

            prevprev=prev;

            prev=curr;

        }

        return prev;

    }

    int countWays(int n)

    {

        // vector<int>dp(n+1, -1);

        // return mem(n, dp);

        return tab(n);

    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends