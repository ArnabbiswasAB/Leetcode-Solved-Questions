//{ Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> findMaxGuests(int arr[], int dep[], int n)
	{
	    sort(arr,arr+n);
	    sort(dep,dep+n);
	    
	    int i=1;
	    int j=0;
	    int res=1;
	    int curr=1;
	    
	    int mintime=arr[0];
	     
	    while(i<n)
	    {
	        if(arr[i]<=dep[j])
	        {
	            curr++;
	            i++;
	        }
	        else
	        {
	            curr--;
	            j++;
	        }
	        if(curr>res)
	        {
	            res=curr;
	            mintime=arr[i-1];
	        }
	    }
	    
	    vector<int> ans={res,mintime};
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
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends