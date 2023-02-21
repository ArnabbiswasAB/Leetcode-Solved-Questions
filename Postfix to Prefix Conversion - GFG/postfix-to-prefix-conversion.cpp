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
  
    string postToPre(string post_exp) {
        // Write your code here
        
        int n = post_exp.length();
        stack<string>st;
        
        for(int i=0; i<n; i++){
            
            if(operators(post_exp[i])){
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                
                string result = post_exp[i] + op2 + op1;
                st.push(result);
            }
            else{
                st.push(string(1,post_exp[i]));
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
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends