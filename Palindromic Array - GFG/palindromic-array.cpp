//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

#include<bits/stdc++.h>

class Solution {
public:
    
    bool check(string s){
        
        string temp = s;
        reverse(temp.begin(),temp.end());
        
        return s == temp;
    }
    
    int PalinArray(int a[], int n)
    {
    	// code here
    	for(int i=0; i<n; i++){
    	   string ans = to_string(a[i]);
    	   if(check(ans) == false)
    	   return 0;
    	}
    	
    	return 1;
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
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends