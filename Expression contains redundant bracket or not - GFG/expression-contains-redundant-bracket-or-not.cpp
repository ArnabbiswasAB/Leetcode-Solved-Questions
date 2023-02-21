//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char>st;
        int n = s.length();
        
        for(int i=0; i<n; i++){
            
            if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
            st.push(s[i]);
            else if(s[i] == ')'){
                
                bool redundant = true;
                
                while(st.top() != '('){
                    if(st.top() == '+' || st.top() == '-' || st.top() == '/' || st.top() == '*'){
                      st.pop();
                      redundant = false;
                    }
                }
                
                st.pop();
                
                if(redundant)
                return 1;
            }
        }
        
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends