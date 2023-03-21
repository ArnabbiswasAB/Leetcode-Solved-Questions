//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string s)
{
    // your code here
    
    vector<int>freq(26,0);
    
    for(int i=0; i<s.length(); i++){
        freq[s[i] - 'a']++;
    }
    
    int odd_freq = 0;
    for(int i=0; i<26; i++){
        if(freq[i] % 2 == 1)
          odd_freq++;
    }
    
    if(odd_freq > 1 )
    return 0;
    
    return 1;
}