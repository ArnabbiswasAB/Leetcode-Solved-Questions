//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    // Code here.
		  int temp = n>0 ? n : -n;

        int ans = 0;

        while(temp>0){

            int rem = temp%10;

            ans = ans*10 + rem;

            temp /= 10;

        }

        ans = n<0 ? -ans : ans;

        return ans==n ? "Yes" : "No";
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends