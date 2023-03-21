//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    void helper(string s, int i, int j, string &ans){
        
        while(i>=0 && j<s.length()){
            
            if(s[i] != s[j])
            break;
            
            i--;
            j++;
        }
        
        if(ans.size() < (j-1) - (i+1) + 1){
            ans = s.substr(i+1, j - i - 1);
        }
    }
    
    string longestPalindrome(string s){
        // code here 
        
        string ans = "";
        
        for(int i=0; i<s.length(); i++){
             
             helper(s, i, i, ans);
             helper(s, i,i+1,ans);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends