//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    
	    
	    // application of modified kadane's algorithm
	    
	    int start = 0, s = 0, end = 0, sum = 0, maxSum = 0;
	    
	    for(int i=0; i<n; i++){
	        
	        sum += a[i];
	        
	        if(sum < 0 || a[i] < 0){
	            sum = 0;
	            start = i+1;
	        }
	        
	        if(sum > maxSum){
	            maxSum = sum;
	            s = start;
	            end = i;
	        }else if(sum == maxSum){
	        
	            if(i - start + 1 > end - s + 1){
	                s = start;
	                end = i;
	            }
	        }
	    }
	    
	    vector<int>ans;
	    
	    for(int i=s; i<=end; i++){
	        ans.push_back(a[i]);
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends