//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
	
	void printTriangle(int n) {
	    
	    
	    for(int i=n; i>=1; i--){
	        
	        int j;
	        for(j=n; j>i; j--)
	        cout<<" ";
	        
	        for(int k=j; k>=1; k--)
	        cout<<"*";
	        
	        for(int l=1; l<i; l++)
	        cout<<"*";
	        
	        cout<<endl;
	    }
	    
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends