//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int lcs(string text1, string text2, int size1, int size2, vector<vector<int>>& dp) {
        
        for (int i = 0; i <= size1; i++) dp[i][0] = 0;
        for (int j = 0; j <= size2; j++) dp[0][j] = 0;
        
        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (text1[i-1] == text2[j-1]) 
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[size1][size2];
    }
    
    
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        int size1 = X.size();
        int size2 = Y.size();
        vector<vector<int>> dp(size1+1, vector<int>(size2+1));

        int commonLength = lcs(X, Y, size1, size2, dp);
        int i = size1, j = size2;
        string ans = "";
        
        
        while(i>0 && j>0){
        
          if(X[i-1] == Y[j-1]){
              ans += X[i-1];
              i--;
              j--;
          }
          else{
              if(dp[i-1][j] > dp[i][j-1]){
                  ans += X[i-1];
                  i--;
              }
              else{
                  ans += Y[j-1];
                  j--;
              }
          }
        }
        
        if(i>0){
            while(i>0){
                ans += X[i-1];
                i--;
            }
        }
        
        if(j>0){
            while(j>0){
                ans += Y[j-1];
                j--;
            }
        }
        
        
        reverse(ans.begin() , ans.end());
        return ans.size();
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends