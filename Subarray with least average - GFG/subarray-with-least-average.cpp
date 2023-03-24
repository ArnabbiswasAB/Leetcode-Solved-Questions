//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int least_average(vector<int>a, int k)
	{
	    int sum=0;
	    int n=a.size();
	    for(int i=0;i<k;i++)
	        sum+=a[i];
	    int res=1;
	    int tam=sum;
	    for(int i=k;i<n;i++){
	        tam=tam-a[i-k]+a[i];
	        if(tam<sum)
	            res=i-k+2,sum=tam;
	    }
	    return res;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.least_average(nums, k);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends