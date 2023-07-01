//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        
        string ans = "";
        stack<pair<char,int>>st;
        
        
        for(int i=0; i<s.length(); i++){
            
            pair<char,int>it;
            
            if(s[i] == '('){
                st.push({s[i],i});
            }else if(!st.empty() && st.top().first == '(' && s[i] == ')'){
                it = st.top();
                st.pop();
            }
            
            if(st.empty())
            ans += s.substr(it.second+1, i - it.second - 1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends