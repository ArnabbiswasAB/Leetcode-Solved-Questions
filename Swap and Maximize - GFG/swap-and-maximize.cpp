//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    long long int sum=0;

    sort(arr,arr+n);

    int start=0,end=n-1;

    while(start<end)

    {

        sum+=abs(arr[start]-arr[end]);

        start++;

        end--;

    }

    return sum*2;
}