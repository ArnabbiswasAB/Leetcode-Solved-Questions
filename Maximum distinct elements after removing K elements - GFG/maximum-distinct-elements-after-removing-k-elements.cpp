//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxDistinctNum(int arr[], int n, int k)
    {
    	unordered_map<int,int>mp;
    	
    	for(int i=0; i<n; i++)
    	mp[arr[i]]++;
    	
    	priority_queue<int>pq;
    	
    	for(auto it : mp){
    	    pq.push(it.second);
    	}
    	
    	while(!pq.empty() && k--){
    	    
    	    int top = pq.top();
    	    pq.pop();
    	    
    	    top--;
    	    
    	    if(top>0)
    	    pq.push(top);
    	}
    	
    	return pq.size();
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i,k;
	cin>>n>>k;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout <<ob.maxDistinctNum(arr, n, k)<<"\n";
	  }
	return 0;
}

// } Driver Code Ends