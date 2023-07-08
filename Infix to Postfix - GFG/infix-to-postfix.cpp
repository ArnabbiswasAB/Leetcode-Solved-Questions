//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char ch){
        
        if(ch == '^')
        return 3;
        else if(ch == '/' || ch == '*')
        return 2;
        else if(ch == '+' || ch == '-')
        return 1;
        
        return -1;
    }
    
    
    string infixToPostfix(string s) {
        // Your code here
        
        stack<char>st;
        string post = "";
        
        for(int i=0; i<s.length(); i++){
            
            if(isalpha(s[i]) || isdigit(s[i])){
                post += s[i];
            }else if(s[i] == '('){
                st.push('(');
            }else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    post += st.top();
                    st.pop();
                }
                
                st.pop();
            }else{
                while(!st.empty() && precedence(s[i]) <= precedence(st.top())){
                    post += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            post += st.top();
            st.pop();
        }
        
        return post;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends