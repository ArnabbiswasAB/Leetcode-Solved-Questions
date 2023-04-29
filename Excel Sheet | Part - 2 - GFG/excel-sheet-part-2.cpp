//{ Driver Code Starts
//Initial template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    int ExcelColumnNumber(string s)
    {
        
        int col = 0, p = 0;
        
        for(int i=s.length()-1; i>=0; i--){
            
            char c = s[i];
            int val = c - 65 + 1;
            col += val*pow(26,p);
            p++;
        }
        
        return col;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.ExcelColumnNumber(s)<<endl;
    }
}
// } Driver Code Ends