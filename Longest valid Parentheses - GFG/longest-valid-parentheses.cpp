//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s){
       
       
       stack<int>st;
       int ans = 0, n = s.length();
       st.push(-1);
       
       for(int i=0; i<n; i++){
           
           if(s[i] == '('){
               st.push(i);
           }else{
               
               st.pop();
               
               if(st.empty())
                 st.push(i);
               else{
                   int curr = i - st.top();
                   ans = max(ans, curr);
               }     
           }
       }
       
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends