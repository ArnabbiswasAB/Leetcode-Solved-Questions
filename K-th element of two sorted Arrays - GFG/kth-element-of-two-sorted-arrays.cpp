//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
    
    if(n>m){
    return kthElement(arr2,arr1,m,n,k);
    }
    
    // Apply BS on smaller array    
        // K is larger than arr2 length
    int start=max(0,k-m);
    // k is smaller than arr1 length
    int end=min(k,n);
    
    while(start<=end){
        int cut1=start +(end-start)/2;
        int cut2=k-cut1;
        int l1=cut1!=0?arr1[cut1-1]:INT_MIN;
        int l2=cut2!=0?arr2[cut2-1]:INT_MIN;
        int r1=cut1!=n?arr1[cut1]:INT_MAX;
        int r2=cut2!=m?arr2[cut2]:INT_MAX;
        
        // ans is found
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            end=cut1-1; // search on the right side
            
        }
        else{
            start=cut1+1 ; // seach on the left side;
        }
    }
    return 1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends