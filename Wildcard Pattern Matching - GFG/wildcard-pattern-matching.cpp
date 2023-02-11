//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool f(int i, int j, string p, string s, vector<vector<int>>& dp){
       
       if(i<0 && j<0)
       return true;
       if(i<0 && j>=0)
       return false;
       if(j<0 && i>=0){
           for(int k=i; k>=0; k--){
               if(p[k] != '*')
               return false;
           }
           return true;
       }
       
       if(dp[i][j] != -1)
       return dp[i][j];
       
       
       if(p[i] == s[j] || p[i] == '?')
         return dp[i][j] = f(i-1,j-1,p,s,dp);
         
         
        if(p[i] == '*'){
            return dp[i][j] = f(i,j-1,p,s,dp) || f(i-1,j,p,s,dp);
        } 
        
        return dp[i][j] = false;
    }
    
    
    int wildCard(string pattern,string str)
    {
        int n = pattern.size();
        int m = str.size();
        
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return f(n-1,m-1,pattern, str, dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends