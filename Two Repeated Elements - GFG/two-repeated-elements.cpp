//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
  
   /*
   Time complexity O(n) | space complexity O(1)
go to arr[abs(arr[i])] multiply it with -1.

if the arr[i] is repeated then arr[abs(arr[i])] will 
be +ve the second time we multiply it with -1.  
   */
   
    vector<int> twoRepeated (int arr[], int N) {
        // Your code here
        
        vector<int> ans;
        
        for(int i=0; i<N+2; i++){
            
            arr[abs(arr[i])] = (-1)*arr[abs(arr[i])];
            
            if(arr[abs(arr[i])] > 0)
            ans.push_back(abs(arr[i]));
        }
        
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends