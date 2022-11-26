//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void palin(string s, int start, int end, string &ans){
     
     while(start>=0 && end<s.size()){
         
         if(s[start] != s[end])
         break;
         
         start--;
         end++;
     }
        
        if(end - start - 1 > ans.size())
        ans = s.substr(start + 1, end - start - 1);
    }
    
    
    string longestPalin (string s) {
        // code here
        
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; i++){
            
            palin(s,i,i, ans);
            palin(s,i,i+1,ans);
        }
        
      return ans;  
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends