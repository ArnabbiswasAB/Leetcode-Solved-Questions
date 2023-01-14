//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string LCP(string arr[], int n)
    {
        // code here
        
        string curr = arr[0];
        int maxi = INT_MAX;
        
        for(int i=1; i<n; i++){
            
            string temp = arr[i];
            int a = 0, j = 0, k = 0;
            
            while(j<curr.size() && k<temp.size()){
                if(curr[j] != temp[k])
                break;
                else
                a++;
                
                j++;
                k++;
            }
            
            maxi = min(maxi,a);
            
        }
        
        if(maxi == 0)
        return "-1";
        
        return curr.substr(0,maxi);
    }
};

//{ Driver Code Starts.

int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}
// } Driver Code Ends