//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool operatorsch(char ch){
        
        if(ch == '/' || ch == '*' || ch == '+' || ch == '-')
        return true;
        
        return false;
    }
    
    
    string preToPost(string s) {
        
        stack<string>st;
        int n = s.length();
    
        
        for(int i=n-1; i>=0; i--){
            
            if(operatorsch(s[i])){
                
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                
                string res =  a + b + s[i];
                st.push(res);
            }else{
                st.push(string(1,s[i]));
            }
        }
        
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends