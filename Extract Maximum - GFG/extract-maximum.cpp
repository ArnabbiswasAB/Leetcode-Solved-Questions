//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
  public:
    
    int extractMaximum(string S) 
    { 
        //code here.
        int ans = -1;
        int count = 0;
        
        for(int i=0; i<S.length(); i++){
            
            if(isalpha(S[i])){
                count = 0;
            }else{
                count = count * 10 + (S[i] - '0');
                ans = max(ans, count);
            }
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.extractMaximum(S)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends