//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        int n = str1.size();
        int m = str2.size();
        
        if(n != m)
        return false;
        
        if(n == 1){
            return str1 == str2;
        }
        
        string prefix = str1.substr(2) + str1.substr(0,2);
        string suffix = str1.substr(n-2) +  str1.substr(0, n - 2);
        
        if(str2 == prefix || str2 == suffix)
        return true;
        
        return false;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends