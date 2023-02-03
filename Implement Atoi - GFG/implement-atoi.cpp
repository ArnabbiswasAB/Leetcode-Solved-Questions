//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        
        int num = 0, n = str.size();
        int sign = 1;
        
        if(str[0] == '-')
          sign = -1;
          
        int i = 0;
        i = (str[0] == '-' || str[0] == '+')?1:0;
        
        while(i<n){
            
            if(str[i]<48 || str[i]>57)
            return -1;
            
            num = num*10 +(str[i] - '0');
            i++;
        }
        
        if(sign == -1)
        num *= sign;
        
        return num;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends