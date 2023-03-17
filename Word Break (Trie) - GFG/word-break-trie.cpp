//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    unordered_map<string,bool> mp,dp;
    
    bool helper(string s){
        
        if(s.length() == 0)
        return true;
        
        if(dp.find(s) != dp.end())
        return true;
        
        for(int i=1; i<=s.length(); i++){
            
            string left = s.substr(0,i);
            
            if(mp.find(left) != mp.end() && helper(s.substr(i))){
                return dp[s] = true;
            }
        }
        
        return dp[s] = false;
    }
    
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        
        for(int i=0; i<B.size(); i++)
        {
            mp[B[i]] = true;
        }
        
        return helper(A);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends