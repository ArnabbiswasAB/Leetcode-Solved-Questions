//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool valid(string s)
{
    // code here
    int n = s.length();
    if(n == 0)
    return true;
    
    stack<char>st;
    
    for(int i=0; i<n; i++){
        
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        st.push(s[i]);
        else{
            if(st.empty())
            return false;
            else if(st.top() == '(' && s[i] != ')')
            return false;
            else if(st.top() == '{' && s[i] != '}')
            return false;
            else if(st.top() == '[' && s[i] != ']')
            return false;
            else
            st.pop();
        }
    }
    
    if(!st.empty())
    return false;
    
    return true;
}