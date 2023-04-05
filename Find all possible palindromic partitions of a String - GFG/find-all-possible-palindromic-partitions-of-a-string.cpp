//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  vector<vector<string>> ans;
  bool palin(string s, int i, int j){
      
      while(i<=j){
          if(s[i] != s[j])
          return false;
          
          i++;
          j--;
      }
      
      return true;
  }
  
  
  void helper(string s,int ind, vector<string> temp){
      
      if(ind == s.length()){
          ans.push_back(temp);
          return;
      }
      
      for(int i=ind; i<s.length(); i++){
          
          if(palin(s,ind,i)){
              temp.push_back(s.substr(ind,i-ind+1));
              helper(s,i+1,temp);
              temp.pop_back();
          }
      }
      
      return;
  }
  
  
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        
        vector<string>temp;
        helper(S,0,temp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends