//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> Arr){
        //code here
        
        vector<int> minLeft(N, 0);
        int mini=INT_MAX;
        for(int i=N-1;i>=0;i--){
            mini=min(mini, Arr[i]);
            minLeft[i]=mini;
        }
        for(int i=0;i<N;i++){
            int l=i+1, r=N-1;
            int tar=Arr[i], first=-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(minLeft[mid]<tar){
                    first=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            Arr[i]=first;
        }
        return Arr;
    }
};

//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}
// } Driver Code Ends