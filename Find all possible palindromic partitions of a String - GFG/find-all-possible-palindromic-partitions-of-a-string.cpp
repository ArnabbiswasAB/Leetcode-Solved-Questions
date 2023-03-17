//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
   vector<vector<string>> ans;
      bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
  
    void helper(string s, int ind, vector<string> &temp){
        
        if(s.length() == ind){
            ans.push_back(temp);
            return;
        }
        
        for(int i=ind; i<s.length(); i++){
            
            if(isPalindrome(s, ind , i)){
                temp.push_back(s.substr(ind, i - ind + 1));
                helper(s, i+1, temp);
                temp.pop_back();
            }
        }
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