//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  void helper(string &s, string t, string &ans){
      
      int i=0, j=0, m = s.length(), n = t.length();
      
      if(n > m)
      return;
      
      while(i<m && j<n){
      
          if(s[i] == t[j]){
              i++;
              j++;
          }
          else
          i++;
      }
      
      if(j == n){
          if(ans.length() < t.length())
             ans = t;
          else if(ans.length() == t.length() && t < ans)
          ans = t;
      }
      return;
  }
  
    string findLongestWord(string s, vector<string> d) {
       
       string ans = "";
       for(int i=0; i<d.size(); i++){
           helper(s, d[i], ans);
       }
       
       return ans;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> d(n + 1);
        for (int i = 0; i < n; i++) cin >> d[i];
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findLongestWord(S, d) << endl;
    }
    return 0;
}

// } Driver Code Ends