//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  bool operators(char ch){
      
      if(ch == '+' || ch == '-' || ch == '/' || ch == '*')
      return true;
      
      return false;
  }
  
  
    string preToInfix(string pre_exp) {
        // Write your code here
        
        stack<string>st;
        int n = pre_exp.length();
       // string result = "";
        
        for(int i=n-1; i>=0; i--){
            
            if(operators(pre_exp[i])){
                
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                
                string result = '(' + op1 + pre_exp[i] + op2 + ')';
                st.push(result);
            }
            else{
                st.push(string(1,pre_exp[i]));
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
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends