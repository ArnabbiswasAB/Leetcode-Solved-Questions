//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        
        
        stack<long long>st;
        vector<long long>ans(n,-1);
        
        for(int i = n-1; i>=0; i--){
            
            while(!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
            
            if(!st.empty())
            ans[i] = arr[st.top()];
            
            st.push(i);
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
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends