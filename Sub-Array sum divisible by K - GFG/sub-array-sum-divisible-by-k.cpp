//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long subCount(long long arr[], int N, long long K)
	{
	    // Your code goes here
	    
	    unordered_map<int,int>mp;
	    
	    mp[0] = 1;
	    long long sum = 0, count = 0;
	    
	    for(int i=0; i<N; i++){
	        
	        sum += arr[i];
	        
	        long long rem = sum%K;
	        
	        if(rem < 0)
	          rem += K;
	          
	        if(mp.find(rem) != mp.end()){
	            count += mp[rem];
	        }
	        
	            mp[rem]++;
	          
	    }
	    
	    
	    return count;
	}



};


//{ Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends