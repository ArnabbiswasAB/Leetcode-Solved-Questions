//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int helper(string s, int k){	
        
        if(k < 0)
        return 0;
        
        int mp[26] = {0};
    	int i=0, j=0, count=0;
    	long long res = 0;
    	
    
    	while(i<s.length()){
    	    
    	    mp[s[i] - 'a']++;
    	    if(mp[s[i] - 'a'] == 1)
    	    count++;
    	    
    	    while(count>k){
    	        mp[s[j] - 'a']--;
    	        if(mp[s[j] - 'a'] == 0)
    	        count--;
    	        
    	        j++;
    	    }
    	    
    	    
    	    res += (i-j+1);
    	    
    	    i++;
    	}
    	
    	return res;
}

    long long int substrCount (string s, int k) {
    	
    	return helper(s,k) - helper(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends