//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    
    bool palindrome(string s, int i, int j){
        
        while(i<=j){
             
             if(s[i] != s[j])
             return false;
             
             i++; 
             j--;
        }
        
        return true;
    }
    
    
    int f(string s,int i, vector<int>& dp){
       
          if(i == s.size())
            return 0;
        
          if(dp[i] != -1)
          return dp[i];
          
          int cuts = INT_MAX;
          
          for(int k = i; k<s.length(); k++){
              
              if(palindrome(s,i,k)){
                  int cost = 1 + f(s,k+1,dp);
                  cuts = min(cuts,cost);
              }
          }
          
          
          return dp[i] = cuts;
    }
    
    
    int palindromicPartition(string str)
    {
        // code here
       vector<int>dp(str.size(),-1);
       return f(str,0,dp) - 1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends