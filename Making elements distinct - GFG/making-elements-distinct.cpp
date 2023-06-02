//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// To find minimum sum of unique elements.
long long int minSum(int arr[], int n);




int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << minSum(a, n) << endl;
        
    }
}
// } Driver Code Ends


long long int minSum(int arr[], int n)
{
	// Complete the function
	
long long sum = arr[0], prev = arr[0];
 
    for (int i = 1; i < n; i++) {
 
        // If violation happens, make current
        // value as 1 plus previous value and
        // add to sum.
        if (arr[i] <= prev) {
            prev = prev + 1;
            sum = sum + prev;
        }
 
        // No violation.
        else {
            sum = sum + arr[i];
            prev = arr[i];
        }
    }
 
    return sum;
}