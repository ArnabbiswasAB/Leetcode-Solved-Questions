//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void generate(int open, int close,string s,int n,vector<string>& ans){
        
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }
        
        if(open<n){
            generate(open+1,close,s+'(',n,ans);
        }
        
        if(close<open){
            generate(open,close+1,s+')',n,ans);
        }
         
         return;
    }


    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>ans;
        generate(0,0,"",n,ans);
        return ans;
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends