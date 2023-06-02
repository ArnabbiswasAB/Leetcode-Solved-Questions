//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        
        unordered_map<int,int>mapi;
       long long count=0;
       for(int i=0;i<n;i++){
           int val=A[i]%K;
           if(mapi.find(K-val)!=mapi.end()){
               count+=mapi[K-val];
           }
           if(val==0)val=K;
             mapi[val]++;
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
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends